# Microsoft Developer Studio Generated NMAKE File, Based on apr.dsp
!IF "$(CFG)" == ""
CFG=apr - Win32 Release
!MESSAGE No configuration specified. Defaulting to apr - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "apr - Win32 Release" && "$(CFG)" != "apr - Win32 Debug" && "$(CFG)" != "apr - x64 Release" && "$(CFG)" != "apr - x64 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "apr.mak" CFG="apr - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "apr - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "apr - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "apr - x64 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "apr - x64 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "apr - Win32 Release"

OUTDIR=.\LibR
INTDIR=.\LibR
# Begin Custom Macros
OutDir=.\LibR
# End Custom Macros

ALL : ".\include\apr.h" ".\include\apr_escape.h" "$(OUTDIR)\apr-1.lib"


CLEAN :
	-@erase "$(INTDIR)\apr-1.idb"
	-@erase "$(INTDIR)\apr-1.pdb"
	-@erase "$(INTDIR)\apr_atomic.obj"
	-@erase "$(INTDIR)\apr_atomic64.obj"
	-@erase "$(INTDIR)\apr_cpystrn.obj"
	-@erase "$(INTDIR)\apr_cstr.obj"
	-@erase "$(INTDIR)\apr_encode.obj"
	-@erase "$(INTDIR)\apr_escape.obj"
	-@erase "$(INTDIR)\apr_fnmatch.obj"
	-@erase "$(INTDIR)\apr_getpass.obj"
	-@erase "$(INTDIR)\apr_hash.obj"
	-@erase "$(INTDIR)\apr_pools.obj"
	-@erase "$(INTDIR)\apr_random.obj"
	-@erase "$(INTDIR)\apr_skiplist.obj"
	-@erase "$(INTDIR)\apr_snprintf.obj"
	-@erase "$(INTDIR)\apr_strings.obj"
	-@erase "$(INTDIR)\apr_strnatcmp.obj"
	-@erase "$(INTDIR)\apr_strtok.obj"
	-@erase "$(INTDIR)\apr_tables.obj"
	-@erase "$(INTDIR)\buffer.obj"
	-@erase "$(INTDIR)\charset.obj"
	-@erase "$(INTDIR)\common.obj"
	-@erase "$(INTDIR)\copy.obj"
	-@erase "$(INTDIR)\dir.obj"
	-@erase "$(INTDIR)\dso.obj"
	-@erase "$(INTDIR)\env.obj"
	-@erase "$(INTDIR)\errorcodes.obj"
	-@erase "$(INTDIR)\fileacc.obj"
	-@erase "$(INTDIR)\filedup.obj"
	-@erase "$(INTDIR)\filepath.obj"
	-@erase "$(INTDIR)\filepath_util.obj"
	-@erase "$(INTDIR)\filestat.obj"
	-@erase "$(INTDIR)\filesys.obj"
	-@erase "$(INTDIR)\flock.obj"
	-@erase "$(INTDIR)\fullrw.obj"
	-@erase "$(INTDIR)\getopt.obj"
	-@erase "$(INTDIR)\groupinfo.obj"
	-@erase "$(INTDIR)\inet_ntop.obj"
	-@erase "$(INTDIR)\inet_pton.obj"
	-@erase "$(INTDIR)\internal.obj"
	-@erase "$(INTDIR)\misc.obj"
	-@erase "$(INTDIR)\mktemp.obj"
	-@erase "$(INTDIR)\mmap.obj"
	-@erase "$(INTDIR)\multicast.obj"
	-@erase "$(INTDIR)\open.obj"
	-@erase "$(INTDIR)\otherchild.obj"
	-@erase "$(INTDIR)\pipe.obj"
	-@erase "$(INTDIR)\poll.obj"
	-@erase "$(INTDIR)\pollcb.obj"
	-@erase "$(INTDIR)\pollset.obj"
	-@erase "$(INTDIR)\proc.obj"
	-@erase "$(INTDIR)\proc_mutex.obj"
	-@erase "$(INTDIR)\rand.obj"
	-@erase "$(INTDIR)\readwrite.obj"
	-@erase "$(INTDIR)\seek.obj"
	-@erase "$(INTDIR)\select.obj"
	-@erase "$(INTDIR)\sendrecv.obj"
	-@erase "$(INTDIR)\sha2.obj"
	-@erase "$(INTDIR)\sha2_glue.obj"
	-@erase "$(INTDIR)\shm.obj"
	-@erase "$(INTDIR)\signals.obj"
	-@erase "$(INTDIR)\sockaddr.obj"
	-@erase "$(INTDIR)\socket_util.obj"
	-@erase "$(INTDIR)\sockets.obj"
	-@erase "$(INTDIR)\sockopt.obj"
	-@erase "$(INTDIR)\start.obj"
	-@erase "$(INTDIR)\tempdir.obj"
	-@erase "$(INTDIR)\thread.obj"
	-@erase "$(INTDIR)\thread_cond.obj"
	-@erase "$(INTDIR)\thread_mutex.obj"
	-@erase "$(INTDIR)\thread_rwlock.obj"
	-@erase "$(INTDIR)\threadpriv.obj"
	-@erase "$(INTDIR)\time.obj"
	-@erase "$(INTDIR)\timestr.obj"
	-@erase "$(INTDIR)\userinfo.obj"
	-@erase "$(INTDIR)\utf8.obj"
	-@erase "$(INTDIR)\version.obj"
	-@erase "$(INTDIR)\wakeup.obj"
	-@erase "$(OUTDIR)\apr-1.lib"
	-@erase ".\include\apr.h"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /Zi /O2 /Oy- /I "./include" /I "./include/arch" /I "./include/arch/win32" /I "./include/arch/unix" /I "./include/private"  /D "NDEBUG" /D "APR_DECLARE_STATIC" /D "WIN32" /D "WINNT" /D "_WINDOWS" /Fo"$(INTDIR)\\" /Fd"$(OUTDIR)\apr-1" /FD /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\apr.bsc" 
BSC32_SBRS= \
	
LIB32=link.exe -lib
LIB32_FLAGS=/nologo /out:"$(OUTDIR)\apr-1.lib" 
LIB32_OBJS= \
	"$(INTDIR)\apr_atomic.obj" \
	"$(INTDIR)\apr_atomic64.obj" \
	"$(INTDIR)\dso.obj" \
	"$(INTDIR)\apr_encode.obj" \
	"$(INTDIR)\apr_escape.obj" \
	"$(INTDIR)\buffer.obj" \
	"$(INTDIR)\copy.obj" \
	"$(INTDIR)\dir.obj" \
	"$(INTDIR)\fileacc.obj" \
	"$(INTDIR)\filedup.obj" \
	"$(INTDIR)\filepath.obj" \
	"$(INTDIR)\filepath_util.obj" \
	"$(INTDIR)\filestat.obj" \
	"$(INTDIR)\filesys.obj" \
	"$(INTDIR)\flock.obj" \
	"$(INTDIR)\fullrw.obj" \
	"$(INTDIR)\mktemp.obj" \
	"$(INTDIR)\open.obj" \
	"$(INTDIR)\pipe.obj" \
	"$(INTDIR)\readwrite.obj" \
	"$(INTDIR)\seek.obj" \
	"$(INTDIR)\tempdir.obj" \
	"$(INTDIR)\proc_mutex.obj" \
	"$(INTDIR)\thread_cond.obj" \
	"$(INTDIR)\thread_mutex.obj" \
	"$(INTDIR)\thread_rwlock.obj" \
	"$(INTDIR)\apr_pools.obj" \
	"$(INTDIR)\charset.obj" \
	"$(INTDIR)\env.obj" \
	"$(INTDIR)\errorcodes.obj" \
	"$(INTDIR)\getopt.obj" \
	"$(INTDIR)\internal.obj" \
	"$(INTDIR)\misc.obj" \
	"$(INTDIR)\otherchild.obj" \
	"$(INTDIR)\rand.obj" \
	"$(INTDIR)\start.obj" \
	"$(INTDIR)\utf8.obj" \
	"$(INTDIR)\version.obj" \
	"$(INTDIR)\common.obj" \
	"$(INTDIR)\mmap.obj" \
	"$(INTDIR)\inet_ntop.obj" \
	"$(INTDIR)\inet_pton.obj" \
	"$(INTDIR)\multicast.obj" \
	"$(INTDIR)\sendrecv.obj" \
	"$(INTDIR)\sockaddr.obj" \
	"$(INTDIR)\socket_util.obj" \
	"$(INTDIR)\sockets.obj" \
	"$(INTDIR)\sockopt.obj" \
	"$(INTDIR)\apr_getpass.obj" \
	"$(INTDIR)\poll.obj" \
	"$(INTDIR)\pollcb.obj" \
	"$(INTDIR)\pollset.obj" \
	"$(INTDIR)\select.obj" \
	"$(INTDIR)\wakeup.obj" \
	"$(INTDIR)\apr_random.obj" \
	"$(INTDIR)\sha2.obj" \
	"$(INTDIR)\sha2_glue.obj" \
	"$(INTDIR)\shm.obj" \
	"$(INTDIR)\apr_cpystrn.obj" \
	"$(INTDIR)\apr_cstr.obj" \
	"$(INTDIR)\apr_fnmatch.obj" \
	"$(INTDIR)\apr_snprintf.obj" \
	"$(INTDIR)\apr_strings.obj" \
	"$(INTDIR)\apr_strnatcmp.obj" \
	"$(INTDIR)\apr_strtok.obj" \
	"$(INTDIR)\apr_hash.obj" \
	"$(INTDIR)\apr_skiplist.obj" \
	"$(INTDIR)\apr_tables.obj" \
	"$(INTDIR)\proc.obj" \
	"$(INTDIR)\signals.obj" \
	"$(INTDIR)\thread.obj" \
	"$(INTDIR)\threadpriv.obj" \
	"$(INTDIR)\time.obj" \
	"$(INTDIR)\timestr.obj" \
	"$(INTDIR)\groupinfo.obj" \
	"$(INTDIR)\userinfo.obj"

"$(OUTDIR)\apr-1.lib" : "$(OUTDIR)" $(DEF_FILE) $(LIB32_OBJS)
    $(LIB32) @<<
  $(LIB32_FLAGS) $(DEF_FLAGS) $(LIB32_OBJS)
<<

!ELSEIF  "$(CFG)" == "apr - Win32 Debug"

OUTDIR=.\LibD
INTDIR=.\LibD
# Begin Custom Macros
OutDir=.\LibD
# End Custom Macros

ALL : ".\include\apr.h" ".\include\apr_escape.h" "$(OUTDIR)\apr-1.lib"


CLEAN :
	-@erase "$(INTDIR)\apr-1.idb"
	-@erase "$(INTDIR)\apr-1.pdb"
	-@erase "$(INTDIR)\apr_atomic.obj"
	-@erase "$(INTDIR)\apr_atomic64.obj"
	-@erase "$(INTDIR)\apr_cpystrn.obj"
	-@erase "$(INTDIR)\apr_cstr.obj"
	-@erase "$(INTDIR)\apr_encode.obj"
	-@erase "$(INTDIR)\apr_escape.obj"
	-@erase "$(INTDIR)\apr_fnmatch.obj"
	-@erase "$(INTDIR)\apr_getpass.obj"
	-@erase "$(INTDIR)\apr_hash.obj"
	-@erase "$(INTDIR)\apr_pools.obj"
	-@erase "$(INTDIR)\apr_random.obj"
	-@erase "$(INTDIR)\apr_skiplist.obj"
	-@erase "$(INTDIR)\apr_snprintf.obj"
	-@erase "$(INTDIR)\apr_strings.obj"
	-@erase "$(INTDIR)\apr_strnatcmp.obj"
	-@erase "$(INTDIR)\apr_strtok.obj"
	-@erase "$(INTDIR)\apr_tables.obj"
	-@erase "$(INTDIR)\buffer.obj"
	-@erase "$(INTDIR)\charset.obj"
	-@erase "$(INTDIR)\common.obj"
	-@erase "$(INTDIR)\copy.obj"
	-@erase "$(INTDIR)\dir.obj"
	-@erase "$(INTDIR)\dso.obj"
	-@erase "$(INTDIR)\env.obj"
	-@erase "$(INTDIR)\errorcodes.obj"
	-@erase "$(INTDIR)\fileacc.obj"
	-@erase "$(INTDIR)\filedup.obj"
	-@erase "$(INTDIR)\filepath.obj"
	-@erase "$(INTDIR)\filepath_util.obj"
	-@erase "$(INTDIR)\filestat.obj"
	-@erase "$(INTDIR)\filesys.obj"
	-@erase "$(INTDIR)\flock.obj"
	-@erase "$(INTDIR)\fullrw.obj"
	-@erase "$(INTDIR)\getopt.obj"
	-@erase "$(INTDIR)\groupinfo.obj"
	-@erase "$(INTDIR)\inet_ntop.obj"
	-@erase "$(INTDIR)\inet_pton.obj"
	-@erase "$(INTDIR)\internal.obj"
	-@erase "$(INTDIR)\misc.obj"
	-@erase "$(INTDIR)\mktemp.obj"
	-@erase "$(INTDIR)\mmap.obj"
	-@erase "$(INTDIR)\multicast.obj"
	-@erase "$(INTDIR)\open.obj"
	-@erase "$(INTDIR)\otherchild.obj"
	-@erase "$(INTDIR)\pipe.obj"
	-@erase "$(INTDIR)\poll.obj"
	-@erase "$(INTDIR)\pollcb.obj"
	-@erase "$(INTDIR)\pollset.obj"
	-@erase "$(INTDIR)\proc.obj"
	-@erase "$(INTDIR)\proc_mutex.obj"
	-@erase "$(INTDIR)\rand.obj"
	-@erase "$(INTDIR)\readwrite.obj"
	-@erase "$(INTDIR)\seek.obj"
	-@erase "$(INTDIR)\select.obj"
	-@erase "$(INTDIR)\sendrecv.obj"
	-@erase "$(INTDIR)\sha2.obj"
	-@erase "$(INTDIR)\sha2_glue.obj"
	-@erase "$(INTDIR)\shm.obj"
	-@erase "$(INTDIR)\signals.obj"
	-@erase "$(INTDIR)\sockaddr.obj"
	-@erase "$(INTDIR)\socket_util.obj"
	-@erase "$(INTDIR)\sockets.obj"
	-@erase "$(INTDIR)\sockopt.obj"
	-@erase "$(INTDIR)\start.obj"
	-@erase "$(INTDIR)\tempdir.obj"
	-@erase "$(INTDIR)\thread.obj"
	-@erase "$(INTDIR)\thread_cond.obj"
	-@erase "$(INTDIR)\thread_mutex.obj"
	-@erase "$(INTDIR)\thread_rwlock.obj"
	-@erase "$(INTDIR)\threadpriv.obj"
	-@erase "$(INTDIR)\time.obj"
	-@erase "$(INTDIR)\timestr.obj"
	-@erase "$(INTDIR)\userinfo.obj"
	-@erase "$(INTDIR)\utf8.obj"
	-@erase "$(INTDIR)\version.obj"
	-@erase "$(INTDIR)\wakeup.obj"
	-@erase "$(OUTDIR)\apr-1.lib"
	-@erase ".\include\apr.h"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Zi /Od /I "./include" /I "./include/arch" /I "./include/arch/win32" /I "./include/arch/unix" /I "./include/private" /D "_DEBUG" /D "APR_DECLARE_STATIC" /D "WIN32" /D "WINNT" /D "_WINDOWS" /Fo"$(INTDIR)\\" /Fd"$(OUTDIR)\apr-1" /FD /EHsc /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\apr.bsc" 
BSC32_SBRS= \
	
LIB32=link.exe -lib
LIB32_FLAGS=/nologo /out:"$(OUTDIR)\apr-1.lib" 
LIB32_OBJS= \
	"$(INTDIR)\apr_atomic.obj" \
	"$(INTDIR)\apr_atomic64.obj" \
	"$(INTDIR)\dso.obj" \
	"$(INTDIR)\apr_encode.obj" \
	"$(INTDIR)\apr_escape.obj" \
	"$(INTDIR)\buffer.obj" \
	"$(INTDIR)\copy.obj" \
	"$(INTDIR)\dir.obj" \
	"$(INTDIR)\fileacc.obj" \
	"$(INTDIR)\filedup.obj" \
	"$(INTDIR)\filepath.obj" \
	"$(INTDIR)\filepath_util.obj" \
	"$(INTDIR)\filestat.obj" \
	"$(INTDIR)\filesys.obj" \
	"$(INTDIR)\flock.obj" \
	"$(INTDIR)\fullrw.obj" \
	"$(INTDIR)\mktemp.obj" \
	"$(INTDIR)\open.obj" \
	"$(INTDIR)\pipe.obj" \
	"$(INTDIR)\readwrite.obj" \
	"$(INTDIR)\seek.obj" \
	"$(INTDIR)\tempdir.obj" \
	"$(INTDIR)\proc_mutex.obj" \
	"$(INTDIR)\thread_cond.obj" \
	"$(INTDIR)\thread_mutex.obj" \
	"$(INTDIR)\thread_rwlock.obj" \
	"$(INTDIR)\apr_pools.obj" \
	"$(INTDIR)\charset.obj" \
	"$(INTDIR)\env.obj" \
	"$(INTDIR)\errorcodes.obj" \
	"$(INTDIR)\getopt.obj" \
	"$(INTDIR)\internal.obj" \
	"$(INTDIR)\misc.obj" \
	"$(INTDIR)\otherchild.obj" \
	"$(INTDIR)\rand.obj" \
	"$(INTDIR)\start.obj" \
	"$(INTDIR)\utf8.obj" \
	"$(INTDIR)\version.obj" \
	"$(INTDIR)\common.obj" \
	"$(INTDIR)\mmap.obj" \
	"$(INTDIR)\inet_ntop.obj" \
	"$(INTDIR)\inet_pton.obj" \
	"$(INTDIR)\multicast.obj" \
	"$(INTDIR)\sendrecv.obj" \
	"$(INTDIR)\sockaddr.obj" \
	"$(INTDIR)\socket_util.obj" \
	"$(INTDIR)\sockets.obj" \
	"$(INTDIR)\sockopt.obj" \
	"$(INTDIR)\apr_getpass.obj" \
	"$(INTDIR)\poll.obj" \
	"$(INTDIR)\pollcb.obj" \
	"$(INTDIR)\pollset.obj" \
	"$(INTDIR)\select.obj" \
	"$(INTDIR)\wakeup.obj" \
	"$(INTDIR)\apr_random.obj" \
	"$(INTDIR)\sha2.obj" \
	"$(INTDIR)\sha2_glue.obj" \
	"$(INTDIR)\shm.obj" \
	"$(INTDIR)\apr_cpystrn.obj" \
	"$(INTDIR)\apr_cstr.obj" \
	"$(INTDIR)\apr_fnmatch.obj" \
	"$(INTDIR)\apr_snprintf.obj" \
	"$(INTDIR)\apr_strings.obj" \
	"$(INTDIR)\apr_strnatcmp.obj" \
	"$(INTDIR)\apr_strtok.obj" \
	"$(INTDIR)\apr_hash.obj" \
	"$(INTDIR)\apr_skiplist.obj" \
	"$(INTDIR)\apr_tables.obj" \
	"$(INTDIR)\proc.obj" \
	"$(INTDIR)\signals.obj" \
	"$(INTDIR)\thread.obj" \
	"$(INTDIR)\threadpriv.obj" \
	"$(INTDIR)\time.obj" \
	"$(INTDIR)\timestr.obj" \
	"$(INTDIR)\groupinfo.obj" \
	"$(INTDIR)\userinfo.obj"

"$(OUTDIR)\apr-1.lib" : "$(OUTDIR)" $(DEF_FILE) $(LIB32_OBJS)
    $(LIB32) @<<
  $(LIB32_FLAGS) $(DEF_FLAGS) $(LIB32_OBJS)
<<

!ELSEIF  "$(CFG)" == "apr - x64 Release"

OUTDIR=.\x64\LibR
INTDIR=.\x64\LibR
# Begin Custom Macros
OutDir=.\x64\LibR
# End Custom Macros

ALL : ".\include\apr.h" ".\include\apr_escape.h" "$(OUTDIR)\apr-1.lib"


CLEAN :
	-@erase "$(INTDIR)\apr-1.idb"
	-@erase "$(INTDIR)\apr-1.pdb"
	-@erase "$(INTDIR)\apr_atomic.obj"
	-@erase "$(INTDIR)\apr_atomic64.obj"
	-@erase "$(INTDIR)\apr_cpystrn.obj"
	-@erase "$(INTDIR)\apr_cstr.obj"
	-@erase "$(INTDIR)\apr_encode.obj"
	-@erase "$(INTDIR)\apr_escape.obj"
	-@erase "$(INTDIR)\apr_fnmatch.obj"
	-@erase "$(INTDIR)\apr_getpass.obj"
	-@erase "$(INTDIR)\apr_hash.obj"
	-@erase "$(INTDIR)\apr_pools.obj"
	-@erase "$(INTDIR)\apr_random.obj"
	-@erase "$(INTDIR)\apr_skiplist.obj"
	-@erase "$(INTDIR)\apr_snprintf.obj"
	-@erase "$(INTDIR)\apr_strings.obj"
	-@erase "$(INTDIR)\apr_strnatcmp.obj"
	-@erase "$(INTDIR)\apr_strtok.obj"
	-@erase "$(INTDIR)\apr_tables.obj"
	-@erase "$(INTDIR)\buffer.obj"
	-@erase "$(INTDIR)\charset.obj"
	-@erase "$(INTDIR)\common.obj"
	-@erase "$(INTDIR)\copy.obj"
	-@erase "$(INTDIR)\dir.obj"
	-@erase "$(INTDIR)\dso.obj"
	-@erase "$(INTDIR)\env.obj"
	-@erase "$(INTDIR)\errorcodes.obj"
	-@erase "$(INTDIR)\fileacc.obj"
	-@erase "$(INTDIR)\filedup.obj"
	-@erase "$(INTDIR)\filepath.obj"
	-@erase "$(INTDIR)\filepath_util.obj"
	-@erase "$(INTDIR)\filestat.obj"
	-@erase "$(INTDIR)\filesys.obj"
	-@erase "$(INTDIR)\flock.obj"
	-@erase "$(INTDIR)\fullrw.obj"
	-@erase "$(INTDIR)\getopt.obj"
	-@erase "$(INTDIR)\groupinfo.obj"
	-@erase "$(INTDIR)\inet_ntop.obj"
	-@erase "$(INTDIR)\inet_pton.obj"
	-@erase "$(INTDIR)\internal.obj"
	-@erase "$(INTDIR)\misc.obj"
	-@erase "$(INTDIR)\mktemp.obj"
	-@erase "$(INTDIR)\mmap.obj"
	-@erase "$(INTDIR)\multicast.obj"
	-@erase "$(INTDIR)\open.obj"
	-@erase "$(INTDIR)\otherchild.obj"
	-@erase "$(INTDIR)\pipe.obj"
	-@erase "$(INTDIR)\poll.obj"
	-@erase "$(INTDIR)\pollcb.obj"
	-@erase "$(INTDIR)\pollset.obj"
	-@erase "$(INTDIR)\proc.obj"
	-@erase "$(INTDIR)\proc_mutex.obj"
	-@erase "$(INTDIR)\rand.obj"
	-@erase "$(INTDIR)\readwrite.obj"
	-@erase "$(INTDIR)\seek.obj"
	-@erase "$(INTDIR)\select.obj"
	-@erase "$(INTDIR)\sendrecv.obj"
	-@erase "$(INTDIR)\sha2.obj"
	-@erase "$(INTDIR)\sha2_glue.obj"
	-@erase "$(INTDIR)\shm.obj"
	-@erase "$(INTDIR)\signals.obj"
	-@erase "$(INTDIR)\sockaddr.obj"
	-@erase "$(INTDIR)\socket_util.obj"
	-@erase "$(INTDIR)\sockets.obj"
	-@erase "$(INTDIR)\sockopt.obj"
	-@erase "$(INTDIR)\start.obj"
	-@erase "$(INTDIR)\tempdir.obj"
	-@erase "$(INTDIR)\thread.obj"
	-@erase "$(INTDIR)\thread_cond.obj"
	-@erase "$(INTDIR)\thread_mutex.obj"
	-@erase "$(INTDIR)\thread_rwlock.obj"
	-@erase "$(INTDIR)\threadpriv.obj"
	-@erase "$(INTDIR)\time.obj"
	-@erase "$(INTDIR)\timestr.obj"
	-@erase "$(INTDIR)\userinfo.obj"
	-@erase "$(INTDIR)\utf8.obj"
	-@erase "$(INTDIR)\version.obj"
	-@erase "$(INTDIR)\wakeup.obj"
	-@erase "$(OUTDIR)\apr-1.lib"
	-@erase ".\include\apr.h"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /Zi /O2 /Oy- /I "./include" /I "./include/arch" /I "./include/arch/win32" /I "./include/arch/unix" /I "./include/private" /D "NDEBUG" /D "APR_DECLARE_STATIC" /D "WIN32" /D "WINNT" /D "_WINDOWS" /Fo"$(INTDIR)\\" /Fd"$(OUTDIR)\apr-1" /FD /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\apr.bsc" 
BSC32_SBRS= \
	
LIB32=link.exe -lib
LIB32_FLAGS=/nologo /out:"$(OUTDIR)\apr-1.lib" 
LIB32_OBJS= \
	"$(INTDIR)\apr_atomic.obj" \
	"$(INTDIR)\apr_atomic64.obj" \
	"$(INTDIR)\dso.obj" \
	"$(INTDIR)\apr_encode.obj" \
	"$(INTDIR)\apr_escape.obj" \
	"$(INTDIR)\buffer.obj" \
	"$(INTDIR)\copy.obj" \
	"$(INTDIR)\dir.obj" \
	"$(INTDIR)\fileacc.obj" \
	"$(INTDIR)\filedup.obj" \
	"$(INTDIR)\filepath.obj" \
	"$(INTDIR)\filepath_util.obj" \
	"$(INTDIR)\filestat.obj" \
	"$(INTDIR)\filesys.obj" \
	"$(INTDIR)\flock.obj" \
	"$(INTDIR)\fullrw.obj" \
	"$(INTDIR)\mktemp.obj" \
	"$(INTDIR)\open.obj" \
	"$(INTDIR)\pipe.obj" \
	"$(INTDIR)\readwrite.obj" \
	"$(INTDIR)\seek.obj" \
	"$(INTDIR)\tempdir.obj" \
	"$(INTDIR)\proc_mutex.obj" \
	"$(INTDIR)\thread_cond.obj" \
	"$(INTDIR)\thread_mutex.obj" \
	"$(INTDIR)\thread_rwlock.obj" \
	"$(INTDIR)\apr_pools.obj" \
	"$(INTDIR)\charset.obj" \
	"$(INTDIR)\env.obj" \
	"$(INTDIR)\errorcodes.obj" \
	"$(INTDIR)\getopt.obj" \
	"$(INTDIR)\internal.obj" \
	"$(INTDIR)\misc.obj" \
	"$(INTDIR)\otherchild.obj" \
	"$(INTDIR)\rand.obj" \
	"$(INTDIR)\start.obj" \
	"$(INTDIR)\utf8.obj" \
	"$(INTDIR)\version.obj" \
	"$(INTDIR)\common.obj" \
	"$(INTDIR)\mmap.obj" \
	"$(INTDIR)\inet_ntop.obj" \
	"$(INTDIR)\inet_pton.obj" \
	"$(INTDIR)\multicast.obj" \
	"$(INTDIR)\sendrecv.obj" \
	"$(INTDIR)\sockaddr.obj" \
	"$(INTDIR)\socket_util.obj" \
	"$(INTDIR)\sockets.obj" \
	"$(INTDIR)\sockopt.obj" \
	"$(INTDIR)\apr_getpass.obj" \
	"$(INTDIR)\poll.obj" \
	"$(INTDIR)\pollcb.obj" \
	"$(INTDIR)\pollset.obj" \
	"$(INTDIR)\select.obj" \
	"$(INTDIR)\wakeup.obj" \
	"$(INTDIR)\apr_random.obj" \
	"$(INTDIR)\sha2.obj" \
	"$(INTDIR)\sha2_glue.obj" \
	"$(INTDIR)\shm.obj" \
	"$(INTDIR)\apr_cpystrn.obj" \
	"$(INTDIR)\apr_cstr.obj" \
	"$(INTDIR)\apr_fnmatch.obj" \
	"$(INTDIR)\apr_snprintf.obj" \
	"$(INTDIR)\apr_strings.obj" \
	"$(INTDIR)\apr_strnatcmp.obj" \
	"$(INTDIR)\apr_strtok.obj" \
	"$(INTDIR)\apr_hash.obj" \
	"$(INTDIR)\apr_skiplist.obj" \
	"$(INTDIR)\apr_tables.obj" \
	"$(INTDIR)\proc.obj" \
	"$(INTDIR)\signals.obj" \
	"$(INTDIR)\thread.obj" \
	"$(INTDIR)\threadpriv.obj" \
	"$(INTDIR)\time.obj" \
	"$(INTDIR)\timestr.obj" \
	"$(INTDIR)\groupinfo.obj" \
	"$(INTDIR)\userinfo.obj"

"$(OUTDIR)\apr-1.lib" : "$(OUTDIR)" $(DEF_FILE) $(LIB32_OBJS)
    $(LIB32) @<<
  $(LIB32_FLAGS) $(DEF_FLAGS) $(LIB32_OBJS)
<<

!ELSEIF  "$(CFG)" == "apr - x64 Debug"

OUTDIR=.\x64\LibD
INTDIR=.\x64\LibD
# Begin Custom Macros
OutDir=.\x64\LibD
# End Custom Macros

ALL : ".\include\apr.h" ".\include\apr_escape.h" "$(OUTDIR)\apr-1.lib"


CLEAN :
	-@erase "$(INTDIR)\apr-1.idb"
	-@erase "$(INTDIR)\apr-1.pdb"
	-@erase "$(INTDIR)\apr_atomic.obj"
	-@erase "$(INTDIR)\apr_atomic64.obj"
	-@erase "$(INTDIR)\apr_cpystrn.obj"
	-@erase "$(INTDIR)\apr_cstr.obj"
	-@erase "$(INTDIR)\apr_encode.obj"
	-@erase "$(INTDIR)\apr_escape.obj"
	-@erase "$(INTDIR)\apr_fnmatch.obj"
	-@erase "$(INTDIR)\apr_getpass.obj"
	-@erase "$(INTDIR)\apr_hash.obj"
	-@erase "$(INTDIR)\apr_pools.obj"
	-@erase "$(INTDIR)\apr_random.obj"
	-@erase "$(INTDIR)\apr_skiplist.obj"
	-@erase "$(INTDIR)\apr_snprintf.obj"
	-@erase "$(INTDIR)\apr_strings.obj"
	-@erase "$(INTDIR)\apr_strnatcmp.obj"
	-@erase "$(INTDIR)\apr_strtok.obj"
	-@erase "$(INTDIR)\apr_tables.obj"
	-@erase "$(INTDIR)\buffer.obj"
	-@erase "$(INTDIR)\charset.obj"
	-@erase "$(INTDIR)\common.obj"
	-@erase "$(INTDIR)\copy.obj"
	-@erase "$(INTDIR)\dir.obj"
	-@erase "$(INTDIR)\dso.obj"
	-@erase "$(INTDIR)\env.obj"
	-@erase "$(INTDIR)\errorcodes.obj"
	-@erase "$(INTDIR)\fileacc.obj"
	-@erase "$(INTDIR)\filedup.obj"
	-@erase "$(INTDIR)\filepath.obj"
	-@erase "$(INTDIR)\filepath_util.obj"
	-@erase "$(INTDIR)\filestat.obj"
	-@erase "$(INTDIR)\filesys.obj"
	-@erase "$(INTDIR)\flock.obj"
	-@erase "$(INTDIR)\fullrw.obj"
	-@erase "$(INTDIR)\getopt.obj"
	-@erase "$(INTDIR)\groupinfo.obj"
	-@erase "$(INTDIR)\inet_ntop.obj"
	-@erase "$(INTDIR)\inet_pton.obj"
	-@erase "$(INTDIR)\internal.obj"
	-@erase "$(INTDIR)\misc.obj"
	-@erase "$(INTDIR)\mktemp.obj"
	-@erase "$(INTDIR)\mmap.obj"
	-@erase "$(INTDIR)\multicast.obj"
	-@erase "$(INTDIR)\open.obj"
	-@erase "$(INTDIR)\otherchild.obj"
	-@erase "$(INTDIR)\pipe.obj"
	-@erase "$(INTDIR)\poll.obj"
	-@erase "$(INTDIR)\pollcb.obj"
	-@erase "$(INTDIR)\pollset.obj"
	-@erase "$(INTDIR)\proc.obj"
	-@erase "$(INTDIR)\proc_mutex.obj"
	-@erase "$(INTDIR)\rand.obj"
	-@erase "$(INTDIR)\readwrite.obj"
	-@erase "$(INTDIR)\seek.obj"
	-@erase "$(INTDIR)\select.obj"
	-@erase "$(INTDIR)\sendrecv.obj"
	-@erase "$(INTDIR)\sha2.obj"
	-@erase "$(INTDIR)\sha2_glue.obj"
	-@erase "$(INTDIR)\shm.obj"
	-@erase "$(INTDIR)\signals.obj"
	-@erase "$(INTDIR)\sockaddr.obj"
	-@erase "$(INTDIR)\socket_util.obj"
	-@erase "$(INTDIR)\sockets.obj"
	-@erase "$(INTDIR)\sockopt.obj"
	-@erase "$(INTDIR)\start.obj"
	-@erase "$(INTDIR)\tempdir.obj"
	-@erase "$(INTDIR)\thread.obj"
	-@erase "$(INTDIR)\thread_cond.obj"
	-@erase "$(INTDIR)\thread_mutex.obj"
	-@erase "$(INTDIR)\thread_rwlock.obj"
	-@erase "$(INTDIR)\threadpriv.obj"
	-@erase "$(INTDIR)\time.obj"
	-@erase "$(INTDIR)\timestr.obj"
	-@erase "$(INTDIR)\userinfo.obj"
	-@erase "$(INTDIR)\utf8.obj"
	-@erase "$(INTDIR)\version.obj"
	-@erase "$(INTDIR)\wakeup.obj"
	-@erase "$(OUTDIR)\apr-1.lib"
	-@erase ".\include\apr.h"
	-@erase ".\include\apr_escape_test_char.h"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Zi /Od /I "./include" /I "./include/arch" /I "./include/arch/win32" /I "./include/arch/unix" /I "./include/private" /D "_DEBUG" /D "APR_DECLARE_STATIC" /D "WIN32" /D "WINNT" /D "_WINDOWS" /Fo"$(INTDIR)\\" /Fd"$(OUTDIR)\apr-1" /FD /EHsc /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\apr.bsc" 
BSC32_SBRS= \
	
LIB32=link.exe -lib
LIB32_FLAGS=/nologo /out:"$(OUTDIR)\apr-1.lib" 
LIB32_OBJS= \
	"$(INTDIR)\apr_atomic.obj" \
	"$(INTDIR)\apr_atomic64.obj" \
	"$(INTDIR)\dso.obj" \
	"$(INTDIR)\apr_encode.obj" \
	"$(INTDIR)\apr_escape.obj" \
	"$(INTDIR)\buffer.obj" \
	"$(INTDIR)\copy.obj" \
	"$(INTDIR)\dir.obj" \
	"$(INTDIR)\fileacc.obj" \
	"$(INTDIR)\filedup.obj" \
	"$(INTDIR)\filepath.obj" \
	"$(INTDIR)\filepath_util.obj" \
	"$(INTDIR)\filestat.obj" \
	"$(INTDIR)\filesys.obj" \
	"$(INTDIR)\flock.obj" \
	"$(INTDIR)\fullrw.obj" \
	"$(INTDIR)\mktemp.obj" \
	"$(INTDIR)\open.obj" \
	"$(INTDIR)\pipe.obj" \
	"$(INTDIR)\readwrite.obj" \
	"$(INTDIR)\seek.obj" \
	"$(INTDIR)\tempdir.obj" \
	"$(INTDIR)\proc_mutex.obj" \
	"$(INTDIR)\thread_cond.obj" \
	"$(INTDIR)\thread_mutex.obj" \
	"$(INTDIR)\thread_rwlock.obj" \
	"$(INTDIR)\apr_pools.obj" \
	"$(INTDIR)\charset.obj" \
	"$(INTDIR)\env.obj" \
	"$(INTDIR)\errorcodes.obj" \
	"$(INTDIR)\getopt.obj" \
	"$(INTDIR)\internal.obj" \
	"$(INTDIR)\misc.obj" \
	"$(INTDIR)\otherchild.obj" \
	"$(INTDIR)\rand.obj" \
	"$(INTDIR)\start.obj" \
	"$(INTDIR)\utf8.obj" \
	"$(INTDIR)\version.obj" \
	"$(INTDIR)\common.obj" \
	"$(INTDIR)\mmap.obj" \
	"$(INTDIR)\inet_ntop.obj" \
	"$(INTDIR)\inet_pton.obj" \
	"$(INTDIR)\multicast.obj" \
	"$(INTDIR)\sendrecv.obj" \
	"$(INTDIR)\sockaddr.obj" \
	"$(INTDIR)\socket_util.obj" \
	"$(INTDIR)\sockets.obj" \
	"$(INTDIR)\sockopt.obj" \
	"$(INTDIR)\apr_getpass.obj" \
	"$(INTDIR)\poll.obj" \
	"$(INTDIR)\pollcb.obj" \
	"$(INTDIR)\pollset.obj" \
	"$(INTDIR)\select.obj" \
	"$(INTDIR)\wakeup.obj" \
	"$(INTDIR)\apr_random.obj" \
	"$(INTDIR)\sha2.obj" \
	"$(INTDIR)\sha2_glue.obj" \
	"$(INTDIR)\shm.obj" \
	"$(INTDIR)\apr_cpystrn.obj" \
	"$(INTDIR)\apr_cstr.obj" \
	"$(INTDIR)\apr_fnmatch.obj" \
	"$(INTDIR)\apr_snprintf.obj" \
	"$(INTDIR)\apr_strings.obj" \
	"$(INTDIR)\apr_strnatcmp.obj" \
	"$(INTDIR)\apr_strtok.obj" \
	"$(INTDIR)\apr_hash.obj" \
	"$(INTDIR)\apr_skiplist.obj" \
	"$(INTDIR)\apr_tables.obj" \
	"$(INTDIR)\proc.obj" \
	"$(INTDIR)\signals.obj" \
	"$(INTDIR)\thread.obj" \
	"$(INTDIR)\threadpriv.obj" \
	"$(INTDIR)\time.obj" \
	"$(INTDIR)\timestr.obj" \
	"$(INTDIR)\groupinfo.obj" \
	"$(INTDIR)\userinfo.obj"

"$(OUTDIR)\apr-1.lib" : "$(OUTDIR)" $(DEF_FILE) $(LIB32_OBJS)
    $(LIB32) @<<
  $(LIB32_FLAGS) $(DEF_FLAGS) $(LIB32_OBJS)
<<

!ENDIF 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("apr.dep")
!INCLUDE "apr.dep"
!ELSE 
!MESSAGE Warning: cannot find "apr.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "apr - Win32 Release" || "$(CFG)" == "apr - Win32 Debug" || "$(CFG)" == "apr - x64 Release" || "$(CFG)" == "apr - x64 Debug"
SOURCE=.\atomic\win32\apr_atomic.c

"$(INTDIR)\apr_atomic.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\atomic\win32\apr_atomic64.c

"$(INTDIR)\apr_atomic64.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\dso\win32\dso.c

"$(INTDIR)\dso.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\encoding\apr_encode.c

"$(INTDIR)\apr_encode.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\encoding\apr_escape.c

"$(INTDIR)\apr_escape.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\file_io\win32\buffer.c

"$(INTDIR)\buffer.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\file_io\unix\copy.c

"$(INTDIR)\copy.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\file_io\win32\dir.c

"$(INTDIR)\dir.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\file_io\unix\fileacc.c

"$(INTDIR)\fileacc.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\file_io\win32\filedup.c

"$(INTDIR)\filedup.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\file_io\win32\filepath.c

"$(INTDIR)\filepath.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\file_io\unix\filepath_util.c

"$(INTDIR)\filepath_util.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\file_io\win32\filestat.c

"$(INTDIR)\filestat.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\file_io\win32\filesys.c

"$(INTDIR)\filesys.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\file_io\win32\flock.c

"$(INTDIR)\flock.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\file_io\unix\fullrw.c

"$(INTDIR)\fullrw.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\file_io\unix\mktemp.c

"$(INTDIR)\mktemp.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\file_io\win32\open.c

"$(INTDIR)\open.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\file_io\win32\pipe.c

"$(INTDIR)\pipe.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\file_io\win32\readwrite.c

"$(INTDIR)\readwrite.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\file_io\win32\seek.c

"$(INTDIR)\seek.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\file_io\unix\tempdir.c

"$(INTDIR)\tempdir.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\locks\win32\proc_mutex.c

"$(INTDIR)\proc_mutex.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\locks\win32\thread_cond.c

"$(INTDIR)\thread_cond.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\locks\win32\thread_mutex.c

"$(INTDIR)\thread_mutex.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\locks\win32\thread_rwlock.c

"$(INTDIR)\thread_rwlock.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\memory\unix\apr_pools.c

"$(INTDIR)\apr_pools.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\misc\win32\apr_app.c
SOURCE=.\misc\win32\charset.c

"$(INTDIR)\charset.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\misc\win32\env.c

"$(INTDIR)\env.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\misc\unix\errorcodes.c

"$(INTDIR)\errorcodes.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\misc\unix\getopt.c

"$(INTDIR)\getopt.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\misc\win32\internal.c

"$(INTDIR)\internal.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\misc\win32\misc.c

"$(INTDIR)\misc.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\misc\unix\otherchild.c

"$(INTDIR)\otherchild.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\misc\win32\rand.c

"$(INTDIR)\rand.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\misc\win32\start.c

"$(INTDIR)\start.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\misc\win32\utf8.c

"$(INTDIR)\utf8.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\misc\unix\version.c

"$(INTDIR)\version.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\mmap\unix\common.c

"$(INTDIR)\common.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\mmap\win32\mmap.c

"$(INTDIR)\mmap.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\network_io\unix\inet_ntop.c

"$(INTDIR)\inet_ntop.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\network_io\unix\inet_pton.c

"$(INTDIR)\inet_pton.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\network_io\unix\multicast.c

"$(INTDIR)\multicast.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\network_io\win32\sendrecv.c

"$(INTDIR)\sendrecv.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\network_io\unix\sockaddr.c

"$(INTDIR)\sockaddr.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\network_io\unix\socket_util.c

"$(INTDIR)\socket_util.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\network_io\win32\sockets.c

"$(INTDIR)\sockets.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\network_io\win32\sockopt.c

"$(INTDIR)\sockopt.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\passwd\apr_getpass.c

"$(INTDIR)\apr_getpass.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\poll\unix\poll.c

"$(INTDIR)\poll.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\poll\unix\pollcb.c

"$(INTDIR)\pollcb.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\poll\unix\pollset.c

"$(INTDIR)\pollset.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\poll\unix\select.c

"$(INTDIR)\select.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\poll\unix\wakeup.c

"$(INTDIR)\wakeup.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\random\unix\apr_random.c

"$(INTDIR)\apr_random.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\random\unix\sha2.c

"$(INTDIR)\sha2.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\random\unix\sha2_glue.c

"$(INTDIR)\sha2_glue.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\shmem\win32\shm.c

"$(INTDIR)\shm.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\strings\apr_cpystrn.c

"$(INTDIR)\apr_cpystrn.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\strings\apr_cstr.c

"$(INTDIR)\apr_cstr.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\strings\apr_fnmatch.c

"$(INTDIR)\apr_fnmatch.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\strings\apr_snprintf.c

"$(INTDIR)\apr_snprintf.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\strings\apr_strings.c

"$(INTDIR)\apr_strings.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\strings\apr_strnatcmp.c

"$(INTDIR)\apr_strnatcmp.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\strings\apr_strtok.c

"$(INTDIR)\apr_strtok.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\tables\apr_hash.c

"$(INTDIR)\apr_hash.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\tables\apr_skiplist.c

"$(INTDIR)\apr_skiplist.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\tables\apr_tables.c

"$(INTDIR)\apr_tables.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\threadproc\win32\proc.c

"$(INTDIR)\proc.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\threadproc\win32\signals.c

"$(INTDIR)\signals.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\threadproc\win32\thread.c

"$(INTDIR)\thread.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\threadproc\win32\threadpriv.c

"$(INTDIR)\threadpriv.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\time\win32\time.c

"$(INTDIR)\time.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\time\win32\timestr.c

"$(INTDIR)\timestr.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\user\win32\groupinfo.c

"$(INTDIR)\groupinfo.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\user\win32\userinfo.c

"$(INTDIR)\userinfo.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\include\apr.hw

!IF  "$(CFG)" == "apr - Win32 Release"

InputPath=.\include\apr.hw

".\include\apr.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	type .\include\apr.hw > .\include\apr.h
<< 
	

!ELSEIF  "$(CFG)" == "apr - Win32 Debug"

InputPath=.\include\apr.hw

".\include\apr.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	type .\include\apr.hw > .\include\apr.h
<< 
	

!ELSEIF  "$(CFG)" == "apr - x64 Release"

InputPath=.\include\apr.hw

".\include\apr.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	type .\include\apr.hw > .\include\apr.h
<< 
	

!ELSEIF  "$(CFG)" == "apr - x64 Debug"

InputPath=.\include\apr.hw

".\include\apr.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	type .\include\apr.hw > .\include\apr.h
<< 
	

!ENDIF 

SOURCE=.\include\apr_escape.h

!IF  "$(CFG)" == "apr - Win32 Release"

InputPath=.\include\apr_escape.h

".\include\apr_escape_test_char.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	cl.exe /nologo /W3 /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /FD /I ".\include" /Fo.\LibR\gen_test_char /Fe.\LibR\gen_test_char.exe .\tools\gen_test_char.c 
	.\LibR\gen_test_char.exe > .\include\apr_escape_test_char.h
<< 
	

!ELSEIF  "$(CFG)" == "apr - Win32 Debug"

InputPath=.\include\apr_escape.h

".\include\apr_escape_test_char.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	cl.exe /nologo /W3 /EHsc /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FD /I ".\include" /Fo.\LibD\gen_test_char /Fe.\LibD\gen_test_char.exe .\tools\gen_test_char.c 
	.\LibD\gen_test_char.exe > .\include\apr_escape_test_char.h
<< 
	

!ELSEIF  "$(CFG)" == "apr - x64 Release"

InputPath=.\include\apr_escape.h

".\include\apr_escape_test_char.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	cl.exe /nologo /W3 /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /FD /I ".\include" /Fo.\x64\LibR\gen_test_char /Fe.\x64\LibR\gen_test_char.exe .\tools\gen_test_char.c 
	.\x64\LibR\gen_test_char.exe > .\include\apr_escape_test_char.h
<< 
	

!ELSEIF  "$(CFG)" == "apr - x64 Debug"

InputPath=.\include\apr_escape.h

".\include\apr_escape_test_char.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	cl.exe /nologo /W3 /EHsc /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FD /I ".\include" /Fo.\x64\LibD\gen_test_char /Fe.\x64\LibD\gen_test_char.exe .\tools\gen_test_char.c 
	.\x64\LibD\gen_test_char.exe > .\include\apr_escape_test_char.h
<< 
	

!ENDIF 


!ENDIF 

