//===-- AArch64MachObjectWriter.cpp - ARM Mach Object Writer --------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "MCTargetDesc/AArch64FixupKinds.h"
#include "MCTargetDesc/AArch64MCTargetDesc.h"
#include "llvm/ADT/Twine.h"
#include "llvm/MC/MCAsmInfo.h"
#include "llvm/MC/MCAsmLayout.h"
#include "llvm/MC/MCAssembler.h"
#include "llvm/MC/MCContext.h"
#include "llvm/MC/MCExpr.h"
#include "llvm/MC/MCFixup.h"
#include "llvm/MC/MCMachObjectWriter.h"
#include "llvm/MC/MCSectionMachO.h"
#include "llvm/MC/MCValue.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/MachO.h"
using namespace llvm;

namespace {
class AArch64MachObjectWriter : public MCMachObjectTargetWriter {
  bool getAArch64FixupKindMachOInfo(const MCFixup &Fixup, unsigned &RelocType,
                                  const MCSymbolRefExpr *Sym,
                                  unsigned &Log2Size, const MCAssembler &Asm);

public:
  AArch64MachObjectWriter(uint32_t CPUType, uint32_t CPUSubtype)
      : MCMachObjectTargetWriter(true /* is64Bit */, CPUType, CPUSubtype) {}

  void recordRelocation(MachObjectWriter *Writer, MCAssembler &Asm,
                        const MCAsmLayout &Layout, const MCFragment *Fragment,
                        const MCFixup &Fixup, MCValue Target,
                        uint64_t &FixedValue) override;
};
} // namespace

bool AArch64MachObjectWriter::getAArch64FixupKindMachOInfo(
    const MCFixup &Fixup, unsigned &RelocType, const MCSymbolRefExpr *Sym,
    unsigned &Log2Size, const MCAssembler &Asm) {
  RelocType = unsigned(MachO::ARM64_RELOC_UNSIGNED);
  Log2Size = ~0U;

  switch ((unsigned)Fixup.getKind()) {
  default:
    return false;

  case FK_Data_1:
    Log2Size = llvm::Log2_32(1);
    return true;
  case FK_Data_2:
    Log2Size = llvm::Log2_32(2);
    return true;
  case FK_Data_4:
    Log2Size = llvm::Log2_32(4);
    if (Sym->getKind() == MCSymbolRefExpr::VK_GOT)
      RelocType = unsigned(MachO::ARM64_RELOC_POINTER_TO_GOT);
    return true;
  case FK_Data_8:
    Log2Size = llvm::Log2_32(8);
    if (Sym->getKind() == MCSymbolRefExpr::VK_GOT)
      RelocType = unsigned(MachO::ARM64_RELOC_POINTER_TO_GOT);
    return true;
  case AArch64::fixup_aarch64_add_imm12:
  case AArch64::fixup_aarch64_ldst_imm12_scale1:
  case AArch64::fixup_aarch64_ldst_imm12_scale2:
  case AArch64::fixup_aarch64_ldst_imm12_scale4:
  case AArch64::fixup_aarch64_ldst_imm12_scale8:
  case AArch64::fixup_aarch64_ldst_imm12_scale16:
    Log2Size = llvm::Log2_32(4);
    switch (Sym->getKind()) {
    default:
      llvm_unreachable("Unexpected symbol reference variant kind!");
    case MCSymbolRefExpr::VK_PAGEOFF:
      RelocType = unsigned(MachO::ARM64_RELOC_PAGEOFF12);
      return true;
    case MCSymbolRefExpr::VK_GOTPAGEOFF:
      RelocType = unsigned(MachO::ARM64_RELOC_GOT_LOAD_PAGEOFF12);
      return true;
    case MCSymbolRefExpr::VK_TLVPPAGEOFF:
      RelocType = unsigned(MachO::ARM64_RELOC_TLVP_LOAD_PAGEOFF12);
      return true;
    }
  case AArch64::fixup_aarch64_pcrel_adrp_imm21:
    Log2Size = llvm::Log2_32(4);
    // This encompasses the relocation for the whole 21-bit value.
    switch (Sym->getKind()) {
    default:
      Asm.getContext().reportFatalError(Fixup.getLoc(),
                                  "ADR/ADRP relocations must be GOT relative");
    case MCSymbolRefExpr::VK_PAGE:
      RelocType = unsigned(MachO::ARM64_RELOC_PAGE21);
      return true;
    case MCSymbolRefExpr::VK_GOTPAGE:
      RelocType = unsigned(MachO::ARM64_RELOC_GOT_LOAD_PAGE21);
      return true;
    case MCSymbolRefExpr::VK_TLVPPAGE:
      RelocType = unsigned(MachO::ARM64_RELOC_TLVP_LOAD_PAGE21);
      return true;
    }
    return true;
  case AArch64::fixup_aarch64_pcrel_branch26:
  case AArch64::fixup_aarch64_pcrel_call26:
    Log2Size = llvm::Log2_32(4);
    RelocType = unsigned(MachO::ARM64_RELOC_BRANCH26);
    return true;
  }
}

static bool canUseLocalRelocation(const MCSectionMachO &Section,
                                  const MCSymbol &Symbol, unsigned Log2Size) {
  // Debug info sections can use local relocations.
  if (Section.hasAttribute(MachO::S_ATTR_DEBUG))
    return true;

  // Otherwise, only pointer sized relocations are supported.
  if (Log2Size != 3)
    return false;

  // But only if they don't point to a few forbidden sections.
  if (!Symbol.isInSection())
    return true;
  const MCSectionMachO &RefSec = cast<MCSectionMachO>(Symbol.getSection());
  if (RefSec.getType() == MachO::S_CSTRING_LITERALS)
    return false;

  if (RefSec.getSegmentName() == "__DATA" &&
      RefSec.getSectionName() == "__objc_classrefs")
    return false;

  // FIXME: ld64 currently handles internal pointer-sized relocations
  // incorrectly (applying the addend twice). We should be able to return true
  // unconditionally by this point when that's fixed.
  return false;
}

void AArch64MachObjectWriter::recordRelocation(
    MachObjectWriter *Writer, MCAssembler &Asm, const MCAsmLayout &Layout,
    const MCFragment *Fragment, const MCFixup &Fixup, MCValue Target,
    uint64_t &FixedValue) {
  unsigned IsPCRel = Writer->isFixupKindPCRel(Asm, Fixup.getKind());

  // See <reloc.h>.
  uint32_t FixupOffset = Layout.getFragmentOffset(Fragment);
  unsigned Log2Size = 0;
  int64_t Value = 0;
  unsigned Index = 0;
  unsigned Type = 0;
  unsigned Kind = Fixup.getKind();
  const MCSymbol *RelSymbol = nullptr;

  FixupOffset += Fixup.getOffset();

  // AArch64 pcrel relocation addends do not include the section offset.
  if (IsPCRel)
    FixedValue += FixupOffset;

  // ADRP fixups use relocations for the whole symbol value and only
  // put the addend in the instruction itself. Clear out any value the
  // generic code figured out from the sybmol definition.
  if (Kind == AArch64::fixup_aarch64_pcrel_adrp_imm21)
    FixedValue = 0;

  // imm19 relocations are for conditional branches, which require
  // assembler local symbols. If we got here, that's not what we have,
  // so complain loudly.
  if (Kind == AArch64::fixup_aarch64_pcrel_branch19) {
    Asm.getContext().reportFatalError(Fixup.getLoc(),
                                "conditional branch requires assembler-local"
                                " label. '" +
                                    Target.getSymA()->getSymbol().getName() +
                                    "' is external.");
    return;
  }

  // 14-bit branch relocations should only target internal labels, and so
  // should never get here.
  if (Kind == AArch64::fixup_aarch64_pcrel_branch14) {
    Asm.getContext().reportFatalError(Fixup.getLoc(),
                                "Invalid relocation on conditional branch!");
    return;
  }

  if (!getAArch64FixupKindMachOInfo(Fixup, Type, Target.getSymA(), Log2Size,
                                  Asm)) {
    Asm.getContext().reportFatalError(Fixup.getLoc(), "unknown AArch64 fixup kind!");
    return;
  }

  Value = Target.getConstant();

  if (Target.isAbsolute()) { // constant
    // FIXME: Should this always be extern?
    // SymbolNum of 0 indicates the absolute section.
    Type = MachO::ARM64_RELOC_UNSIGNED;

    if (IsPCRel) {
      Asm.getContext().reportFatalError(Fixup.getLoc(),
                                  "PC relative absolute relocation!");

      // FIXME: x86_64 sets the type to a branch reloc here. Should we do
      // something similar?
    }
  } else if (Target.getSymB()) { // A - B + constant
    const MCSymbol *A = &Target.getSymA()->getSymbol();
    const MCSymbol *A_Base = Asm.getAtom(*A);

    const MCSymbol *B = &Target.getSymB()->getSymbol();
    const MCSymbol *B_Base = Asm.getAtom(*B);

    // Check for "_foo@got - .", which comes through here as:
    // Ltmp0:
    //    ... _foo@got - Ltmp0
    if (Target.getSymA()->getKind() == MCSymbolRefExpr::VK_GOT &&
        Target.getSymB()->getKind() == MCSymbolRefExpr::VK_None &&
        Layout.getSymbolOffset(*B) ==
            Layout.getFragmentOffset(Fragment) + Fixup.getOffset()) {
      // SymB is the PC, so use a PC-rel pointer-to-GOT relocation.
      Type = MachO::ARM64_RELOC_POINTER_TO_GOT;
      IsPCRel = 1;
      MachO::any_relocation_info MRE;
      MRE.r_word0 = FixupOffset;
      MRE.r_word1 = (IsPCRel << 24) | (Log2Size << 25) | (Type << 28);
      Writer->addRelocation(A_Base, Fragment->getParent(), MRE);
      return;
    } else if (Target.getSymA()->getKind() != MCSymbolRefExpr::VK_None ||
               Target.getSymB()->getKind() != MCSymbolRefExpr::VK_None)
      // Otherwise, neither symbol can be modified.
      Asm.getContext().reportFatalError(Fixup.getLoc(),
                                  "unsupported relocation of modified symbol");

    // We don't support PCrel relocations of differences.
    if (IsPCRel)
      Asm.getContext().reportFatalError(Fixup.getLoc(),
                                  "unsupported pc-relative relocation of "
                                  "difference");

    // AArch64 always uses external relocations. If there is no symbol to use as
    // a base address (a local symbol with no preceding non-local symbol),
    // error out.
    //
    // FIXME: We should probably just synthesize an external symbol and use
    // that.
    if (!A_Base)
      Asm.getContext().reportFatalError(
          Fixup.getLoc(),
          "unsupported relocation of local symbol '" + A->getName() +
              "'. Must have non-local symbol earlier in section.");
    if (!B_Base)
      Asm.getContext().reportFatalError(
          Fixup.getLoc(),
          "unsupported relocation of local symbol '" + B->getName() +
              "'. Must have non-local symbol earlier in section.");

    if (A_Base == B_Base && A_Base)
      Asm.getContext().reportFatalError(Fixup.getLoc(),
                                  "unsupported relocation with identical base");

    Value += (!A->getFragment() ? 0 : Writer->getSymbolAddress(*A, Layout)) -
             (!A_Base || !A_Base->getFragment() ? 0 : Writer->getSymbolAddress(
                                                          *A_Base, Layout));
    Value -= (!B->getFragment() ? 0 : Writer->getSymbolAddress(*B, Layout)) -
             (!B_Base || !B_Base->getFragment() ? 0 : Writer->getSymbolAddress(
                                                          *B_Base, Layout));

    Type = MachO::ARM64_RELOC_UNSIGNED;

    MachO::any_relocation_info MRE;
    MRE.r_word0 = FixupOffset;
    MRE.r_word1 = (IsPCRel << 24) | (Log2Size << 25) | (Type << 28);
    Writer->addRelocation(A_Base, Fragment->getParent(), MRE);

    RelSymbol = B_Base;
    Type = MachO::ARM64_RELOC_SUBTRACTOR;
  } else { // A + constant
    const MCSymbol *Symbol = &Target.getSymA()->getSymbol();
    const MCSectionMachO &Section =
        static_cast<const MCSectionMachO &>(*Fragment->getParent());

    bool CanUseLocalRelocation =
        canUseLocalRelocation(Section, *Symbol, Log2Size);
    if (Symbol->isTemporary() && (Value || !CanUseLocalRelocation)) {
      const MCSection &Sec = Symbol->getSection();
      if (!Asm.getContext().getAsmInfo()->isSectionAtomizableBySymbols(Sec))
        Symbol->setUsedInReloc();
    }

    const MCSymbol *Base = Asm.getAtom(*Symbol);

    // If the symbol is a variable and we weren't able to get a Base for it
    // (i.e., it's not in the symbol table associated with a section) resolve
    // the relocation based its expansion instead.
    if (Symbol->isVariable() && !Base) {
      // If the evaluation is an absolute value, just use that directly
      // to keep things easy.
      int64_t Res;
      if (Symbol->getVariableValue()->evaluateAsAbsolute(
              Res, Layout, Writer->getSectionAddressMap())) {
        FixedValue = Res;
        return;
      }

      // FIXME: Will the Target we already have ever have any data in it
      // we need to preserve and merge with the new Target? How about
      // the FixedValue?
      if (!Symbol->getVariableValue()->evaluateAsRelocatable(Target, &Layout,
                                                             &Fixup))
        Asm.getContext().reportFatalError(Fixup.getLoc(),
                                    "unable to resolve variable '" +
                                        Symbol->getName() + "'");
      return recordRelocation(Writer, Asm, Layout, Fragment, Fixup, Target,
                              FixedValue);
    }

    // Relocations inside debug sections always use local relocations when
    // possible. This seems to be done because the debugger doesn't fully
    // understand relocation entries and expects to find values that
    // have already been fixed up.
    if (Symbol->isInSection()) {
      if (Section.hasAttribute(MachO::S_ATTR_DEBUG))
        Base = nullptr;
    }

    // AArch64 uses external relocations as much as possible. For debug
    // sections, and for pointer-sized relocations (.quad), we allow section
    // relocations.  It's code sections that run into trouble.
    if (Base) {
      RelSymbol = Base;

      // Add the local offset, if needed.
      if (Base != Symbol)
        Value +=
            Layout.getSymbolOffset(*Symbol) - Layout.getSymbolOffset(*Base);
    } else if (Symbol->isInSection()) {
      if (!CanUseLocalRelocation)
        Asm.getContext().reportFatalError(
            Fixup.getLoc(),
            "unsupported relocation of local symbol '" + Symbol->getName() +
                "'. Must have non-local symbol earlier in section.");
      // Adjust the relocation to be section-relative.
      // The index is the section ordinal (1-based).
      const MCSection &Sec = Symbol->getSection();
      Index = Sec.getOrdinal() + 1;
      Value += Writer->getSymbolAddress(*Symbol, Layout);

      if (IsPCRel)
        Value -= Writer->getFragmentAddress(Fragment, Layout) +
                 Fixup.getOffset() + (1ULL << Log2Size);
    } else {
      // Resolve constant variables.
      if (Symbol->isVariable()) {
        int64_t Res;
        if (Symbol->getVariableValue()->evaluateAsAbsolute(
                Res, Layout, Writer->getSectionAddressMap())) {
          FixedValue = Res;
          return;
        }
      }
      Asm.getContext().reportFatalError(Fixup.getLoc(),
                                  "unsupported relocation of variable '" +
                                      Symbol->getName() + "'");
    }
  }

  // If the relocation kind is Branch26, Page21, or Pageoff12, any addend
  // is represented via an Addend relocation, not encoded directly into
  // the instruction.
  if ((Type == MachO::ARM64_RELOC_BRANCH26 ||
       Type == MachO::ARM64_RELOC_PAGE21 ||
       Type == MachO::ARM64_RELOC_PAGEOFF12) &&
      Value) {
    assert((Value & 0xff000000) == 0 && "Added relocation out of range!");

    MachO::any_relocation_info MRE;
    MRE.r_word0 = FixupOffset;
    MRE.r_word1 =
        (Index << 0) | (IsPCRel << 24) | (Log2Size << 25) | (Type << 28);
    Writer->addRelocation(RelSymbol, Fragment->getParent(), MRE);

    // Now set up the Addend relocation.
    Type = MachO::ARM64_RELOC_ADDEND;
    Index = Value;
    RelSymbol = nullptr;
    IsPCRel = 0;
    Log2Size = 2;

    // Put zero into the instruction itself. The addend is in the relocation.
    Value = 0;
  }

  // If there's any addend left to handle, encode it in the instruction.
  FixedValue = Value;

  // struct relocation_info (8 bytes)
  MachO::any_relocation_info MRE;
  MRE.r_word0 = FixupOffset;
  MRE.r_word1 =
      (Index << 0) | (IsPCRel << 24) | (Log2Size << 25) | (Type << 28);
  Writer->addRelocation(RelSymbol, Fragment->getParent(), MRE);
}

MCObjectWriter *llvm::createAArch64MachObjectWriter(raw_pwrite_stream &OS,
                                                    uint32_t CPUType,
                                                    uint32_t CPUSubtype) {
  return createMachObjectWriter(
      new AArch64MachObjectWriter(CPUType, CPUSubtype), OS,
      /*IsLittleEndian=*/true);
}
