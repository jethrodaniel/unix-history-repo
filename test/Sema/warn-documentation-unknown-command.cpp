// RUN: %clang_cc1 -std=c++11 -fsyntax-only -Wdocumentation-unknown-command -verify %s
// RUN: %clang_cc1 -std=c++11 -fsyntax-only -Werror -Wno-documentation-unknown-command %s

// expected-warning@+1 {{unknown command tag name}}
/// aaa \unknown
int test_unknown_comand_1;

// expected-warning@+1 {{unknown command tag name 'retur'; did you mean 'return'?}}
/// \retur aaa
int test_unknown_comand_2();

// RUN: c-index-test -test-load-source all -Wdocumentation-unknown-command %s > /dev/null 2> %t.err
// RUN: FileCheck < %t.err -check-prefix=CHECK-RANGE %s
// CHECK-RANGE: warn-documentation-unknown-command.cpp:5:9:{5:9-5:17}: warning: unknown command tag name
// CHECK-RANGE: warn-documentation-unknown-command.cpp:9:5:{9:5-9:11}: warning: unknown command tag name 'retur'; did you mean 'return'?
