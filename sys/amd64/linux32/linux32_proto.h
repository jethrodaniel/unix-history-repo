/*
 * System call prototypes.
 *
 * DO NOT EDIT-- this file is automatically @generated.
 * $FreeBSD$
 */

#ifndef _LINUX32_SYSPROTO_H_
#define	_LINUX32_SYSPROTO_H_

#include <sys/signal.h>
#include <sys/acl.h>
#include <sys/cpuset.h>
#include <sys/domainset.h>
#include <sys/_ffcounter.h>
#include <sys/_semaphore.h>
#include <sys/ucontext.h>
#include <sys/wait.h>

#include <bsm/audit_kevents.h>

struct proc;

struct thread;

#define	PAD_(t)	(sizeof(register_t) <= sizeof(t) ? \
		0 : sizeof(register_t) - sizeof(t))

#if BYTE_ORDER == LITTLE_ENDIAN
#define	PADL_(t)	0
#define	PADR_(t)	PAD_(t)
#else
#define	PADL_(t)	PAD_(t)
#define	PADR_(t)	0
#endif

#define	nosys	linux_nosys
struct linux_exit_args {
	char rval_l_[PADL_(int)]; int rval; char rval_r_[PADR_(int)];
};
struct linux_fork_args {
	register_t dummy;
};
struct linux_open_args {
	char path_l_[PADL_(char *)]; char * path; char path_r_[PADR_(char *)];
	char flags_l_[PADL_(l_int)]; l_int flags; char flags_r_[PADR_(l_int)];
	char mode_l_[PADL_(l_int)]; l_int mode; char mode_r_[PADR_(l_int)];
};
struct linux_waitpid_args {
	char pid_l_[PADL_(l_pid_t)]; l_pid_t pid; char pid_r_[PADR_(l_pid_t)];
	char status_l_[PADL_(l_int *)]; l_int * status; char status_r_[PADR_(l_int *)];
	char options_l_[PADL_(l_int)]; l_int options; char options_r_[PADR_(l_int)];
};
struct linux_creat_args {
	char path_l_[PADL_(char *)]; char * path; char path_r_[PADR_(char *)];
	char mode_l_[PADL_(l_int)]; l_int mode; char mode_r_[PADR_(l_int)];
};
struct linux_link_args {
	char path_l_[PADL_(char *)]; char * path; char path_r_[PADR_(char *)];
	char to_l_[PADL_(char *)]; char * to; char to_r_[PADR_(char *)];
};
struct linux_unlink_args {
	char path_l_[PADL_(char *)]; char * path; char path_r_[PADR_(char *)];
};
struct linux_execve_args {
	char path_l_[PADL_(char *)]; char * path; char path_r_[PADR_(char *)];
	char argp_l_[PADL_(uint32_t *)]; uint32_t * argp; char argp_r_[PADR_(uint32_t *)];
	char envp_l_[PADL_(uint32_t *)]; uint32_t * envp; char envp_r_[PADR_(uint32_t *)];
};
struct linux_chdir_args {
	char path_l_[PADL_(char *)]; char * path; char path_r_[PADR_(char *)];
};
struct linux_time_args {
	char tm_l_[PADL_(l_time_t *)]; l_time_t * tm; char tm_r_[PADR_(l_time_t *)];
};
struct linux_mknod_args {
	char path_l_[PADL_(char *)]; char * path; char path_r_[PADR_(char *)];
	char mode_l_[PADL_(l_int)]; l_int mode; char mode_r_[PADR_(l_int)];
	char dev_l_[PADL_(l_dev_t)]; l_dev_t dev; char dev_r_[PADR_(l_dev_t)];
};
struct linux_chmod_args {
	char path_l_[PADL_(char *)]; char * path; char path_r_[PADR_(char *)];
	char mode_l_[PADL_(l_mode_t)]; l_mode_t mode; char mode_r_[PADR_(l_mode_t)];
};
struct linux_lchown16_args {
	char path_l_[PADL_(char *)]; char * path; char path_r_[PADR_(char *)];
	char uid_l_[PADL_(l_uid16_t)]; l_uid16_t uid; char uid_r_[PADR_(l_uid16_t)];
	char gid_l_[PADL_(l_gid16_t)]; l_gid16_t gid; char gid_r_[PADR_(l_gid16_t)];
};
struct linux_stat_args {
	char path_l_[PADL_(char *)]; char * path; char path_r_[PADR_(char *)];
	char up_l_[PADL_(struct linux_stat *)]; struct linux_stat * up; char up_r_[PADR_(struct linux_stat *)];
};
struct linux_lseek_args {
	char fdes_l_[PADL_(l_uint)]; l_uint fdes; char fdes_r_[PADR_(l_uint)];
	char off_l_[PADL_(l_off_t)]; l_off_t off; char off_r_[PADR_(l_off_t)];
	char whence_l_[PADL_(l_int)]; l_int whence; char whence_r_[PADR_(l_int)];
};
struct linux_getpid_args {
	register_t dummy;
};
struct linux_mount_args {
	char specialfile_l_[PADL_(char *)]; char * specialfile; char specialfile_r_[PADR_(char *)];
	char dir_l_[PADL_(char *)]; char * dir; char dir_r_[PADR_(char *)];
	char filesystemtype_l_[PADL_(char *)]; char * filesystemtype; char filesystemtype_r_[PADR_(char *)];
	char rwflag_l_[PADL_(l_ulong)]; l_ulong rwflag; char rwflag_r_[PADR_(l_ulong)];
	char data_l_[PADL_(void *)]; void * data; char data_r_[PADR_(void *)];
};
struct linux_oldumount_args {
	char path_l_[PADL_(char *)]; char * path; char path_r_[PADR_(char *)];
};
struct linux_setuid16_args {
	char uid_l_[PADL_(l_uid16_t)]; l_uid16_t uid; char uid_r_[PADR_(l_uid16_t)];
};
struct linux_getuid16_args {
	register_t dummy;
};
struct linux_stime_args {
	register_t dummy;
};
struct linux_ptrace_args {
	char req_l_[PADL_(l_long)]; l_long req; char req_r_[PADR_(l_long)];
	char pid_l_[PADL_(l_long)]; l_long pid; char pid_r_[PADR_(l_long)];
	char addr_l_[PADL_(l_long)]; l_long addr; char addr_r_[PADR_(l_long)];
	char data_l_[PADL_(l_long)]; l_long data; char data_r_[PADR_(l_long)];
};
struct linux_alarm_args {
	char secs_l_[PADL_(l_uint)]; l_uint secs; char secs_r_[PADR_(l_uint)];
};
struct linux_pause_args {
	register_t dummy;
};
struct linux_utime_args {
	char fname_l_[PADL_(char *)]; char * fname; char fname_r_[PADR_(char *)];
	char times_l_[PADL_(struct l_utimbuf *)]; struct l_utimbuf * times; char times_r_[PADR_(struct l_utimbuf *)];
};
struct linux_access_args {
	char path_l_[PADL_(char *)]; char * path; char path_r_[PADR_(char *)];
	char amode_l_[PADL_(l_int)]; l_int amode; char amode_r_[PADR_(l_int)];
};
struct linux_nice_args {
	char inc_l_[PADL_(l_int)]; l_int inc; char inc_r_[PADR_(l_int)];
};
struct linux_kill_args {
	char pid_l_[PADL_(l_int)]; l_int pid; char pid_r_[PADR_(l_int)];
	char signum_l_[PADL_(l_int)]; l_int signum; char signum_r_[PADR_(l_int)];
};
struct linux_rename_args {
	char from_l_[PADL_(char *)]; char * from; char from_r_[PADR_(char *)];
	char to_l_[PADL_(char *)]; char * to; char to_r_[PADR_(char *)];
};
struct linux_mkdir_args {
	char path_l_[PADL_(char *)]; char * path; char path_r_[PADR_(char *)];
	char mode_l_[PADL_(l_int)]; l_int mode; char mode_r_[PADR_(l_int)];
};
struct linux_rmdir_args {
	char path_l_[PADL_(char *)]; char * path; char path_r_[PADR_(char *)];
};
struct linux_pipe_args {
	char pipefds_l_[PADL_(l_int *)]; l_int * pipefds; char pipefds_r_[PADR_(l_int *)];
};
struct linux_times_args {
	char buf_l_[PADL_(struct l_times_argv *)]; struct l_times_argv * buf; char buf_r_[PADR_(struct l_times_argv *)];
};
struct linux_brk_args {
	char dsend_l_[PADL_(l_ulong)]; l_ulong dsend; char dsend_r_[PADR_(l_ulong)];
};
struct linux_setgid16_args {
	char gid_l_[PADL_(l_gid16_t)]; l_gid16_t gid; char gid_r_[PADR_(l_gid16_t)];
};
struct linux_getgid16_args {
	register_t dummy;
};
struct linux_signal_args {
	char sig_l_[PADL_(l_int)]; l_int sig; char sig_r_[PADR_(l_int)];
	char handler_l_[PADL_(l_handler_t)]; l_handler_t handler; char handler_r_[PADR_(l_handler_t)];
};
struct linux_geteuid16_args {
	register_t dummy;
};
struct linux_getegid16_args {
	register_t dummy;
};
struct linux_umount_args {
	char path_l_[PADL_(char *)]; char * path; char path_r_[PADR_(char *)];
	char flags_l_[PADL_(l_int)]; l_int flags; char flags_r_[PADR_(l_int)];
};
struct linux_ioctl_args {
	char fd_l_[PADL_(l_uint)]; l_uint fd; char fd_r_[PADR_(l_uint)];
	char cmd_l_[PADL_(l_uint)]; l_uint cmd; char cmd_r_[PADR_(l_uint)];
	char arg_l_[PADL_(uintptr_t)]; uintptr_t arg; char arg_r_[PADR_(uintptr_t)];
};
struct linux_fcntl_args {
	char fd_l_[PADL_(l_uint)]; l_uint fd; char fd_r_[PADR_(l_uint)];
	char cmd_l_[PADL_(l_uint)]; l_uint cmd; char cmd_r_[PADR_(l_uint)];
	char arg_l_[PADL_(uintptr_t)]; uintptr_t arg; char arg_r_[PADR_(uintptr_t)];
};
struct linux_olduname_args {
	register_t dummy;
};
struct linux_ustat_args {
	char dev_l_[PADL_(l_dev_t)]; l_dev_t dev; char dev_r_[PADR_(l_dev_t)];
	char ubuf_l_[PADL_(struct l_ustat *)]; struct l_ustat * ubuf; char ubuf_r_[PADR_(struct l_ustat *)];
};
struct linux_getppid_args {
	register_t dummy;
};
struct linux_sigaction_args {
	char sig_l_[PADL_(l_int)]; l_int sig; char sig_r_[PADR_(l_int)];
	char nsa_l_[PADL_(l_osigaction_t *)]; l_osigaction_t * nsa; char nsa_r_[PADR_(l_osigaction_t *)];
	char osa_l_[PADL_(l_osigaction_t *)]; l_osigaction_t * osa; char osa_r_[PADR_(l_osigaction_t *)];
};
struct linux_sgetmask_args {
	register_t dummy;
};
struct linux_ssetmask_args {
	char mask_l_[PADL_(l_osigset_t)]; l_osigset_t mask; char mask_r_[PADR_(l_osigset_t)];
};
struct linux_setreuid16_args {
	char ruid_l_[PADL_(l_uid16_t)]; l_uid16_t ruid; char ruid_r_[PADR_(l_uid16_t)];
	char euid_l_[PADL_(l_uid16_t)]; l_uid16_t euid; char euid_r_[PADR_(l_uid16_t)];
};
struct linux_setregid16_args {
	char rgid_l_[PADL_(l_gid16_t)]; l_gid16_t rgid; char rgid_r_[PADR_(l_gid16_t)];
	char egid_l_[PADL_(l_gid16_t)]; l_gid16_t egid; char egid_r_[PADR_(l_gid16_t)];
};
struct linux_sigsuspend_args {
	char hist0_l_[PADL_(l_int)]; l_int hist0; char hist0_r_[PADR_(l_int)];
	char hist1_l_[PADL_(l_int)]; l_int hist1; char hist1_r_[PADR_(l_int)];
	char mask_l_[PADL_(l_osigset_t)]; l_osigset_t mask; char mask_r_[PADR_(l_osigset_t)];
};
struct linux_sigpending_args {
	char mask_l_[PADL_(l_osigset_t *)]; l_osigset_t * mask; char mask_r_[PADR_(l_osigset_t *)];
};
struct linux_sethostname_args {
	char hostname_l_[PADL_(char *)]; char * hostname; char hostname_r_[PADR_(char *)];
	char len_l_[PADL_(u_int)]; u_int len; char len_r_[PADR_(u_int)];
};
struct linux_setrlimit_args {
	char resource_l_[PADL_(l_uint)]; l_uint resource; char resource_r_[PADR_(l_uint)];
	char rlim_l_[PADL_(struct l_rlimit *)]; struct l_rlimit * rlim; char rlim_r_[PADR_(struct l_rlimit *)];
};
struct linux_old_getrlimit_args {
	char resource_l_[PADL_(l_uint)]; l_uint resource; char resource_r_[PADR_(l_uint)];
	char rlim_l_[PADL_(struct l_rlimit *)]; struct l_rlimit * rlim; char rlim_r_[PADR_(struct l_rlimit *)];
};
struct linux_getrusage_args {
	char who_l_[PADL_(int)]; int who; char who_r_[PADR_(int)];
	char rusage_l_[PADL_(struct l_rusage *)]; struct l_rusage * rusage; char rusage_r_[PADR_(struct l_rusage *)];
};
struct linux_gettimeofday_args {
	char tp_l_[PADL_(struct l_timeval *)]; struct l_timeval * tp; char tp_r_[PADR_(struct l_timeval *)];
	char tzp_l_[PADL_(struct timezone *)]; struct timezone * tzp; char tzp_r_[PADR_(struct timezone *)];
};
struct linux_settimeofday_args {
	char tp_l_[PADL_(struct l_timeval *)]; struct l_timeval * tp; char tp_r_[PADR_(struct l_timeval *)];
	char tzp_l_[PADL_(struct timezone *)]; struct timezone * tzp; char tzp_r_[PADR_(struct timezone *)];
};
struct linux_getgroups16_args {
	char gidsetsize_l_[PADL_(l_uint)]; l_uint gidsetsize; char gidsetsize_r_[PADR_(l_uint)];
	char gidset_l_[PADL_(l_gid16_t *)]; l_gid16_t * gidset; char gidset_r_[PADR_(l_gid16_t *)];
};
struct linux_setgroups16_args {
	char gidsetsize_l_[PADL_(l_uint)]; l_uint gidsetsize; char gidsetsize_r_[PADR_(l_uint)];
	char gidset_l_[PADL_(l_gid16_t *)]; l_gid16_t * gidset; char gidset_r_[PADR_(l_gid16_t *)];
};
struct linux_old_select_args {
	char ptr_l_[PADL_(struct l_old_select_argv *)]; struct l_old_select_argv * ptr; char ptr_r_[PADR_(struct l_old_select_argv *)];
};
struct linux_symlink_args {
	char path_l_[PADL_(char *)]; char * path; char path_r_[PADR_(char *)];
	char to_l_[PADL_(char *)]; char * to; char to_r_[PADR_(char *)];
};
struct linux_lstat_args {
	char path_l_[PADL_(char *)]; char * path; char path_r_[PADR_(char *)];
	char up_l_[PADL_(struct linux_lstat *)]; struct linux_lstat * up; char up_r_[PADR_(struct linux_lstat *)];
};
struct linux_readlink_args {
	char name_l_[PADL_(char *)]; char * name; char name_r_[PADR_(char *)];
	char buf_l_[PADL_(char *)]; char * buf; char buf_r_[PADR_(char *)];
	char count_l_[PADL_(l_int)]; l_int count; char count_r_[PADR_(l_int)];
};
struct linux_reboot_args {
	char magic1_l_[PADL_(l_int)]; l_int magic1; char magic1_r_[PADR_(l_int)];
	char magic2_l_[PADL_(l_int)]; l_int magic2; char magic2_r_[PADR_(l_int)];
	char cmd_l_[PADL_(l_uint)]; l_uint cmd; char cmd_r_[PADR_(l_uint)];
	char arg_l_[PADL_(void *)]; void * arg; char arg_r_[PADR_(void *)];
};
struct linux_readdir_args {
	char fd_l_[PADL_(l_uint)]; l_uint fd; char fd_r_[PADR_(l_uint)];
	char dent_l_[PADL_(struct l_dirent *)]; struct l_dirent * dent; char dent_r_[PADR_(struct l_dirent *)];
	char count_l_[PADL_(l_uint)]; l_uint count; char count_r_[PADR_(l_uint)];
};
struct linux_mmap_args {
	char ptr_l_[PADL_(struct l_mmap_argv *)]; struct l_mmap_argv * ptr; char ptr_r_[PADR_(struct l_mmap_argv *)];
};
struct linux_truncate_args {
	char path_l_[PADL_(char *)]; char * path; char path_r_[PADR_(char *)];
	char length_l_[PADL_(l_ulong)]; l_ulong length; char length_r_[PADR_(l_ulong)];
};
struct linux_ftruncate_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char length_l_[PADL_(long)]; long length; char length_r_[PADR_(long)];
};
struct linux_getpriority_args {
	char which_l_[PADL_(int)]; int which; char which_r_[PADR_(int)];
	char who_l_[PADL_(int)]; int who; char who_r_[PADR_(int)];
};
struct linux_statfs_args {
	char path_l_[PADL_(char *)]; char * path; char path_r_[PADR_(char *)];
	char buf_l_[PADL_(struct l_statfs_buf *)]; struct l_statfs_buf * buf; char buf_r_[PADR_(struct l_statfs_buf *)];
};
struct linux_fstatfs_args {
	char fd_l_[PADL_(l_uint)]; l_uint fd; char fd_r_[PADR_(l_uint)];
	char buf_l_[PADL_(struct l_statfs_buf *)]; struct l_statfs_buf * buf; char buf_r_[PADR_(struct l_statfs_buf *)];
};
struct linux_socketcall_args {
	char what_l_[PADL_(l_int)]; l_int what; char what_r_[PADR_(l_int)];
	char args_l_[PADL_(l_ulong)]; l_ulong args; char args_r_[PADR_(l_ulong)];
};
struct linux_syslog_args {
	char type_l_[PADL_(l_int)]; l_int type; char type_r_[PADR_(l_int)];
	char buf_l_[PADL_(char *)]; char * buf; char buf_r_[PADR_(char *)];
	char len_l_[PADL_(l_int)]; l_int len; char len_r_[PADR_(l_int)];
};
struct linux_setitimer_args {
	char which_l_[PADL_(l_int)]; l_int which; char which_r_[PADR_(l_int)];
	char itv_l_[PADL_(struct l_itimerval *)]; struct l_itimerval * itv; char itv_r_[PADR_(struct l_itimerval *)];
	char oitv_l_[PADL_(struct l_itimerval *)]; struct l_itimerval * oitv; char oitv_r_[PADR_(struct l_itimerval *)];
};
struct linux_getitimer_args {
	char which_l_[PADL_(l_int)]; l_int which; char which_r_[PADR_(l_int)];
	char itv_l_[PADL_(struct l_itimerval *)]; struct l_itimerval * itv; char itv_r_[PADR_(struct l_itimerval *)];
};
struct linux_newstat_args {
	char path_l_[PADL_(char *)]; char * path; char path_r_[PADR_(char *)];
	char buf_l_[PADL_(struct l_newstat *)]; struct l_newstat * buf; char buf_r_[PADR_(struct l_newstat *)];
};
struct linux_newlstat_args {
	char path_l_[PADL_(char *)]; char * path; char path_r_[PADR_(char *)];
	char buf_l_[PADL_(struct l_newstat *)]; struct l_newstat * buf; char buf_r_[PADR_(struct l_newstat *)];
};
struct linux_newfstat_args {
	char fd_l_[PADL_(l_uint)]; l_uint fd; char fd_r_[PADR_(l_uint)];
	char buf_l_[PADL_(struct l_newstat *)]; struct l_newstat * buf; char buf_r_[PADR_(struct l_newstat *)];
};
struct linux_uname_args {
	register_t dummy;
};
struct linux_iopl_args {
	char level_l_[PADL_(l_int)]; l_int level; char level_r_[PADR_(l_int)];
};
struct linux_vhangup_args {
	register_t dummy;
};
struct linux_wait4_args {
	char pid_l_[PADL_(l_pid_t)]; l_pid_t pid; char pid_r_[PADR_(l_pid_t)];
	char status_l_[PADL_(l_int *)]; l_int * status; char status_r_[PADR_(l_int *)];
	char options_l_[PADL_(l_int)]; l_int options; char options_r_[PADR_(l_int)];
	char rusage_l_[PADL_(struct l_rusage *)]; struct l_rusage * rusage; char rusage_r_[PADR_(struct l_rusage *)];
};
struct linux_swapoff_args {
	register_t dummy;
};
struct linux_sysinfo_args {
	char info_l_[PADL_(struct l_sysinfo *)]; struct l_sysinfo * info; char info_r_[PADR_(struct l_sysinfo *)];
};
struct linux_ipc_args {
	char what_l_[PADL_(l_uint)]; l_uint what; char what_r_[PADR_(l_uint)];
	char arg1_l_[PADL_(l_int)]; l_int arg1; char arg1_r_[PADR_(l_int)];
	char arg2_l_[PADL_(l_int)]; l_int arg2; char arg2_r_[PADR_(l_int)];
	char arg3_l_[PADL_(l_uint)]; l_uint arg3; char arg3_r_[PADR_(l_uint)];
	char ptr_l_[PADL_(l_uintptr_t)]; l_uintptr_t ptr; char ptr_r_[PADR_(l_uintptr_t)];
	char arg5_l_[PADL_(l_uint)]; l_uint arg5; char arg5_r_[PADR_(l_uint)];
};
struct linux_sigreturn_args {
	char sfp_l_[PADL_(struct l_sigframe *)]; struct l_sigframe * sfp; char sfp_r_[PADR_(struct l_sigframe *)];
};
struct linux_clone_args {
	char flags_l_[PADL_(l_int)]; l_int flags; char flags_r_[PADR_(l_int)];
	char stack_l_[PADL_(void *)]; void * stack; char stack_r_[PADR_(void *)];
	char parent_tidptr_l_[PADL_(void *)]; void * parent_tidptr; char parent_tidptr_r_[PADR_(void *)];
	char tls_l_[PADL_(void *)]; void * tls; char tls_r_[PADR_(void *)];
	char child_tidptr_l_[PADL_(void *)]; void * child_tidptr; char child_tidptr_r_[PADR_(void *)];
};
struct linux_setdomainname_args {
	char name_l_[PADL_(char *)]; char * name; char name_r_[PADR_(char *)];
	char len_l_[PADL_(int)]; int len; char len_r_[PADR_(int)];
};
struct linux_newuname_args {
	char buf_l_[PADL_(struct l_new_utsname *)]; struct l_new_utsname * buf; char buf_r_[PADR_(struct l_new_utsname *)];
};
struct linux_adjtimex_args {
	register_t dummy;
};
struct linux_mprotect_args {
	char addr_l_[PADL_(caddr_t)]; caddr_t addr; char addr_r_[PADR_(caddr_t)];
	char len_l_[PADL_(int)]; int len; char len_r_[PADR_(int)];
	char prot_l_[PADL_(int)]; int prot; char prot_r_[PADR_(int)];
};
struct linux_sigprocmask_args {
	char how_l_[PADL_(l_int)]; l_int how; char how_r_[PADR_(l_int)];
	char mask_l_[PADL_(l_osigset_t *)]; l_osigset_t * mask; char mask_r_[PADR_(l_osigset_t *)];
	char omask_l_[PADL_(l_osigset_t *)]; l_osigset_t * omask; char omask_r_[PADR_(l_osigset_t *)];
};
struct linux_init_module_args {
	register_t dummy;
};
struct linux_delete_module_args {
	register_t dummy;
};
struct linux_quotactl_args {
	register_t dummy;
};
struct linux_bdflush_args {
	register_t dummy;
};
struct linux_sysfs_args {
	char option_l_[PADL_(l_int)]; l_int option; char option_r_[PADR_(l_int)];
	char arg1_l_[PADL_(l_ulong)]; l_ulong arg1; char arg1_r_[PADR_(l_ulong)];
	char arg2_l_[PADL_(l_ulong)]; l_ulong arg2; char arg2_r_[PADR_(l_ulong)];
};
struct linux_personality_args {
	char per_l_[PADL_(l_uint)]; l_uint per; char per_r_[PADR_(l_uint)];
};
struct linux_setfsuid16_args {
	char uid_l_[PADL_(l_uid16_t)]; l_uid16_t uid; char uid_r_[PADR_(l_uid16_t)];
};
struct linux_setfsgid16_args {
	char gid_l_[PADL_(l_gid16_t)]; l_gid16_t gid; char gid_r_[PADR_(l_gid16_t)];
};
struct linux_llseek_args {
	char fd_l_[PADL_(l_int)]; l_int fd; char fd_r_[PADR_(l_int)];
	char ohigh_l_[PADL_(l_ulong)]; l_ulong ohigh; char ohigh_r_[PADR_(l_ulong)];
	char olow_l_[PADL_(l_ulong)]; l_ulong olow; char olow_r_[PADR_(l_ulong)];
	char res_l_[PADL_(l_loff_t *)]; l_loff_t * res; char res_r_[PADR_(l_loff_t *)];
	char whence_l_[PADL_(l_uint)]; l_uint whence; char whence_r_[PADR_(l_uint)];
};
struct linux_getdents_args {
	char fd_l_[PADL_(l_uint)]; l_uint fd; char fd_r_[PADR_(l_uint)];
	char dent_l_[PADL_(void *)]; void * dent; char dent_r_[PADR_(void *)];
	char count_l_[PADL_(l_uint)]; l_uint count; char count_r_[PADR_(l_uint)];
};
struct linux_select_args {
	char nfds_l_[PADL_(l_int)]; l_int nfds; char nfds_r_[PADR_(l_int)];
	char readfds_l_[PADL_(l_fd_set *)]; l_fd_set * readfds; char readfds_r_[PADR_(l_fd_set *)];
	char writefds_l_[PADL_(l_fd_set *)]; l_fd_set * writefds; char writefds_r_[PADR_(l_fd_set *)];
	char exceptfds_l_[PADL_(l_fd_set *)]; l_fd_set * exceptfds; char exceptfds_r_[PADR_(l_fd_set *)];
	char timeout_l_[PADL_(struct l_timeval *)]; struct l_timeval * timeout; char timeout_r_[PADR_(struct l_timeval *)];
};
struct linux_msync_args {
	char addr_l_[PADL_(l_ulong)]; l_ulong addr; char addr_r_[PADR_(l_ulong)];
	char len_l_[PADL_(l_size_t)]; l_size_t len; char len_r_[PADR_(l_size_t)];
	char fl_l_[PADL_(l_int)]; l_int fl; char fl_r_[PADR_(l_int)];
};
struct linux_readv_args {
	char fd_l_[PADL_(l_ulong)]; l_ulong fd; char fd_r_[PADR_(l_ulong)];
	char iovp_l_[PADL_(struct l_iovec32 *)]; struct l_iovec32 * iovp; char iovp_r_[PADR_(struct l_iovec32 *)];
	char iovcnt_l_[PADL_(l_ulong)]; l_ulong iovcnt; char iovcnt_r_[PADR_(l_ulong)];
};
struct linux_writev_args {
	char fd_l_[PADL_(l_ulong)]; l_ulong fd; char fd_r_[PADR_(l_ulong)];
	char iovp_l_[PADL_(struct l_iovec32 *)]; struct l_iovec32 * iovp; char iovp_r_[PADR_(struct l_iovec32 *)];
	char iovcnt_l_[PADL_(l_ulong)]; l_ulong iovcnt; char iovcnt_r_[PADR_(l_ulong)];
};
struct linux_getsid_args {
	char pid_l_[PADL_(l_pid_t)]; l_pid_t pid; char pid_r_[PADR_(l_pid_t)];
};
struct linux_fdatasync_args {
	char fd_l_[PADL_(l_uint)]; l_uint fd; char fd_r_[PADR_(l_uint)];
};
struct linux_sysctl_args {
	char args_l_[PADL_(struct l___sysctl_args *)]; struct l___sysctl_args * args; char args_r_[PADR_(struct l___sysctl_args *)];
};
struct linux_sched_setparam_args {
	char pid_l_[PADL_(l_pid_t)]; l_pid_t pid; char pid_r_[PADR_(l_pid_t)];
	char param_l_[PADL_(struct sched_param *)]; struct sched_param * param; char param_r_[PADR_(struct sched_param *)];
};
struct linux_sched_getparam_args {
	char pid_l_[PADL_(l_pid_t)]; l_pid_t pid; char pid_r_[PADR_(l_pid_t)];
	char param_l_[PADL_(struct sched_param *)]; struct sched_param * param; char param_r_[PADR_(struct sched_param *)];
};
struct linux_sched_setscheduler_args {
	char pid_l_[PADL_(l_pid_t)]; l_pid_t pid; char pid_r_[PADR_(l_pid_t)];
	char policy_l_[PADL_(l_int)]; l_int policy; char policy_r_[PADR_(l_int)];
	char param_l_[PADL_(struct sched_param *)]; struct sched_param * param; char param_r_[PADR_(struct sched_param *)];
};
struct linux_sched_getscheduler_args {
	char pid_l_[PADL_(l_pid_t)]; l_pid_t pid; char pid_r_[PADR_(l_pid_t)];
};
struct linux_sched_get_priority_max_args {
	char policy_l_[PADL_(l_int)]; l_int policy; char policy_r_[PADR_(l_int)];
};
struct linux_sched_get_priority_min_args {
	char policy_l_[PADL_(l_int)]; l_int policy; char policy_r_[PADR_(l_int)];
};
struct linux_sched_rr_get_interval_args {
	char pid_l_[PADL_(l_pid_t)]; l_pid_t pid; char pid_r_[PADR_(l_pid_t)];
	char interval_l_[PADL_(struct l_timespec *)]; struct l_timespec * interval; char interval_r_[PADR_(struct l_timespec *)];
};
struct linux_nanosleep_args {
	char rqtp_l_[PADL_(const struct l_timespec *)]; const struct l_timespec * rqtp; char rqtp_r_[PADR_(const struct l_timespec *)];
	char rmtp_l_[PADL_(struct l_timespec *)]; struct l_timespec * rmtp; char rmtp_r_[PADR_(struct l_timespec *)];
};
struct linux_mremap_args {
	char addr_l_[PADL_(l_ulong)]; l_ulong addr; char addr_r_[PADR_(l_ulong)];
	char old_len_l_[PADL_(l_ulong)]; l_ulong old_len; char old_len_r_[PADR_(l_ulong)];
	char new_len_l_[PADL_(l_ulong)]; l_ulong new_len; char new_len_r_[PADR_(l_ulong)];
	char flags_l_[PADL_(l_ulong)]; l_ulong flags; char flags_r_[PADR_(l_ulong)];
	char new_addr_l_[PADL_(l_ulong)]; l_ulong new_addr; char new_addr_r_[PADR_(l_ulong)];
};
struct linux_setresuid16_args {
	char ruid_l_[PADL_(l_uid16_t)]; l_uid16_t ruid; char ruid_r_[PADR_(l_uid16_t)];
	char euid_l_[PADL_(l_uid16_t)]; l_uid16_t euid; char euid_r_[PADR_(l_uid16_t)];
	char suid_l_[PADL_(l_uid16_t)]; l_uid16_t suid; char suid_r_[PADR_(l_uid16_t)];
};
struct linux_getresuid16_args {
	char ruid_l_[PADL_(l_uid16_t *)]; l_uid16_t * ruid; char ruid_r_[PADR_(l_uid16_t *)];
	char euid_l_[PADL_(l_uid16_t *)]; l_uid16_t * euid; char euid_r_[PADR_(l_uid16_t *)];
	char suid_l_[PADL_(l_uid16_t *)]; l_uid16_t * suid; char suid_r_[PADR_(l_uid16_t *)];
};
struct linux_setresgid16_args {
	char rgid_l_[PADL_(l_gid16_t)]; l_gid16_t rgid; char rgid_r_[PADR_(l_gid16_t)];
	char egid_l_[PADL_(l_gid16_t)]; l_gid16_t egid; char egid_r_[PADR_(l_gid16_t)];
	char sgid_l_[PADL_(l_gid16_t)]; l_gid16_t sgid; char sgid_r_[PADR_(l_gid16_t)];
};
struct linux_getresgid16_args {
	char rgid_l_[PADL_(l_gid16_t *)]; l_gid16_t * rgid; char rgid_r_[PADR_(l_gid16_t *)];
	char egid_l_[PADL_(l_gid16_t *)]; l_gid16_t * egid; char egid_r_[PADR_(l_gid16_t *)];
	char sgid_l_[PADL_(l_gid16_t *)]; l_gid16_t * sgid; char sgid_r_[PADR_(l_gid16_t *)];
};
struct linux_prctl_args {
	char option_l_[PADL_(l_int)]; l_int option; char option_r_[PADR_(l_int)];
	char arg2_l_[PADL_(l_int)]; l_int arg2; char arg2_r_[PADR_(l_int)];
	char arg3_l_[PADL_(l_int)]; l_int arg3; char arg3_r_[PADR_(l_int)];
	char arg4_l_[PADL_(l_int)]; l_int arg4; char arg4_r_[PADR_(l_int)];
	char arg5_l_[PADL_(l_int)]; l_int arg5; char arg5_r_[PADR_(l_int)];
};
struct linux_rt_sigreturn_args {
	char ucp_l_[PADL_(struct l_ucontext *)]; struct l_ucontext * ucp; char ucp_r_[PADR_(struct l_ucontext *)];
};
struct linux_rt_sigaction_args {
	char sig_l_[PADL_(l_int)]; l_int sig; char sig_r_[PADR_(l_int)];
	char act_l_[PADL_(l_sigaction_t *)]; l_sigaction_t * act; char act_r_[PADR_(l_sigaction_t *)];
	char oact_l_[PADL_(l_sigaction_t *)]; l_sigaction_t * oact; char oact_r_[PADR_(l_sigaction_t *)];
	char sigsetsize_l_[PADL_(l_size_t)]; l_size_t sigsetsize; char sigsetsize_r_[PADR_(l_size_t)];
};
struct linux_rt_sigprocmask_args {
	char how_l_[PADL_(l_int)]; l_int how; char how_r_[PADR_(l_int)];
	char mask_l_[PADL_(l_sigset_t *)]; l_sigset_t * mask; char mask_r_[PADR_(l_sigset_t *)];
	char omask_l_[PADL_(l_sigset_t *)]; l_sigset_t * omask; char omask_r_[PADR_(l_sigset_t *)];
	char sigsetsize_l_[PADL_(l_size_t)]; l_size_t sigsetsize; char sigsetsize_r_[PADR_(l_size_t)];
};
struct linux_rt_sigpending_args {
	char set_l_[PADL_(l_sigset_t *)]; l_sigset_t * set; char set_r_[PADR_(l_sigset_t *)];
	char sigsetsize_l_[PADL_(l_size_t)]; l_size_t sigsetsize; char sigsetsize_r_[PADR_(l_size_t)];
};
struct linux_rt_sigtimedwait_args {
	char mask_l_[PADL_(l_sigset_t *)]; l_sigset_t * mask; char mask_r_[PADR_(l_sigset_t *)];
	char ptr_l_[PADL_(l_siginfo_t *)]; l_siginfo_t * ptr; char ptr_r_[PADR_(l_siginfo_t *)];
	char timeout_l_[PADL_(struct l_timeval *)]; struct l_timeval * timeout; char timeout_r_[PADR_(struct l_timeval *)];
	char sigsetsize_l_[PADL_(l_size_t)]; l_size_t sigsetsize; char sigsetsize_r_[PADR_(l_size_t)];
};
struct linux_rt_sigqueueinfo_args {
	char pid_l_[PADL_(l_pid_t)]; l_pid_t pid; char pid_r_[PADR_(l_pid_t)];
	char sig_l_[PADL_(l_int)]; l_int sig; char sig_r_[PADR_(l_int)];
	char info_l_[PADL_(l_siginfo_t *)]; l_siginfo_t * info; char info_r_[PADR_(l_siginfo_t *)];
};
struct linux_rt_sigsuspend_args {
	char newset_l_[PADL_(l_sigset_t *)]; l_sigset_t * newset; char newset_r_[PADR_(l_sigset_t *)];
	char sigsetsize_l_[PADL_(l_size_t)]; l_size_t sigsetsize; char sigsetsize_r_[PADR_(l_size_t)];
};
struct linux_pread_args {
	char fd_l_[PADL_(l_uint)]; l_uint fd; char fd_r_[PADR_(l_uint)];
	char buf_l_[PADL_(char *)]; char * buf; char buf_r_[PADR_(char *)];
	char nbyte_l_[PADL_(l_size_t)]; l_size_t nbyte; char nbyte_r_[PADR_(l_size_t)];
	char offset_l_[PADL_(l_loff_t)]; l_loff_t offset; char offset_r_[PADR_(l_loff_t)];
};
struct linux_pwrite_args {
	char fd_l_[PADL_(l_uint)]; l_uint fd; char fd_r_[PADR_(l_uint)];
	char buf_l_[PADL_(char *)]; char * buf; char buf_r_[PADR_(char *)];
	char nbyte_l_[PADL_(l_size_t)]; l_size_t nbyte; char nbyte_r_[PADR_(l_size_t)];
	char offset_l_[PADL_(l_loff_t)]; l_loff_t offset; char offset_r_[PADR_(l_loff_t)];
};
struct linux_chown16_args {
	char path_l_[PADL_(char *)]; char * path; char path_r_[PADR_(char *)];
	char uid_l_[PADL_(l_uid16_t)]; l_uid16_t uid; char uid_r_[PADR_(l_uid16_t)];
	char gid_l_[PADL_(l_gid16_t)]; l_gid16_t gid; char gid_r_[PADR_(l_gid16_t)];
};
struct linux_getcwd_args {
	char buf_l_[PADL_(char *)]; char * buf; char buf_r_[PADR_(char *)];
	char bufsize_l_[PADL_(l_ulong)]; l_ulong bufsize; char bufsize_r_[PADR_(l_ulong)];
};
struct linux_capget_args {
	char hdrp_l_[PADL_(struct l_user_cap_header *)]; struct l_user_cap_header * hdrp; char hdrp_r_[PADR_(struct l_user_cap_header *)];
	char datap_l_[PADL_(struct l_user_cap_data *)]; struct l_user_cap_data * datap; char datap_r_[PADR_(struct l_user_cap_data *)];
};
struct linux_capset_args {
	char hdrp_l_[PADL_(struct l_user_cap_header *)]; struct l_user_cap_header * hdrp; char hdrp_r_[PADR_(struct l_user_cap_header *)];
	char datap_l_[PADL_(struct l_user_cap_data *)]; struct l_user_cap_data * datap; char datap_r_[PADR_(struct l_user_cap_data *)];
};
struct linux_sigaltstack_args {
	char uss_l_[PADL_(l_stack_t *)]; l_stack_t * uss; char uss_r_[PADR_(l_stack_t *)];
	char uoss_l_[PADL_(l_stack_t *)]; l_stack_t * uoss; char uoss_r_[PADR_(l_stack_t *)];
};
struct linux_sendfile_args {
	register_t dummy;
};
struct linux_vfork_args {
	register_t dummy;
};
struct linux_getrlimit_args {
	char resource_l_[PADL_(l_uint)]; l_uint resource; char resource_r_[PADR_(l_uint)];
	char rlim_l_[PADL_(struct l_rlimit *)]; struct l_rlimit * rlim; char rlim_r_[PADR_(struct l_rlimit *)];
};
struct linux_mmap2_args {
	char addr_l_[PADL_(l_ulong)]; l_ulong addr; char addr_r_[PADR_(l_ulong)];
	char len_l_[PADL_(l_ulong)]; l_ulong len; char len_r_[PADR_(l_ulong)];
	char prot_l_[PADL_(l_ulong)]; l_ulong prot; char prot_r_[PADR_(l_ulong)];
	char flags_l_[PADL_(l_ulong)]; l_ulong flags; char flags_r_[PADR_(l_ulong)];
	char fd_l_[PADL_(l_ulong)]; l_ulong fd; char fd_r_[PADR_(l_ulong)];
	char pgoff_l_[PADL_(l_ulong)]; l_ulong pgoff; char pgoff_r_[PADR_(l_ulong)];
};
struct linux_truncate64_args {
	char path_l_[PADL_(char *)]; char * path; char path_r_[PADR_(char *)];
	char length_l_[PADL_(l_loff_t)]; l_loff_t length; char length_r_[PADR_(l_loff_t)];
};
struct linux_ftruncate64_args {
	char fd_l_[PADL_(l_uint)]; l_uint fd; char fd_r_[PADR_(l_uint)];
	char length_l_[PADL_(l_loff_t)]; l_loff_t length; char length_r_[PADR_(l_loff_t)];
};
struct linux_stat64_args {
	char filename_l_[PADL_(const char *)]; const char * filename; char filename_r_[PADR_(const char *)];
	char statbuf_l_[PADL_(struct l_stat64 *)]; struct l_stat64 * statbuf; char statbuf_r_[PADR_(struct l_stat64 *)];
};
struct linux_lstat64_args {
	char filename_l_[PADL_(const char *)]; const char * filename; char filename_r_[PADR_(const char *)];
	char statbuf_l_[PADL_(struct l_stat64 *)]; struct l_stat64 * statbuf; char statbuf_r_[PADR_(struct l_stat64 *)];
};
struct linux_fstat64_args {
	char fd_l_[PADL_(l_int)]; l_int fd; char fd_r_[PADR_(l_int)];
	char statbuf_l_[PADL_(struct l_stat64 *)]; struct l_stat64 * statbuf; char statbuf_r_[PADR_(struct l_stat64 *)];
};
struct linux_lchown_args {
	char path_l_[PADL_(char *)]; char * path; char path_r_[PADR_(char *)];
	char uid_l_[PADL_(l_uid_t)]; l_uid_t uid; char uid_r_[PADR_(l_uid_t)];
	char gid_l_[PADL_(l_gid_t)]; l_gid_t gid; char gid_r_[PADR_(l_gid_t)];
};
struct linux_getuid_args {
	register_t dummy;
};
struct linux_getgid_args {
	register_t dummy;
};
struct linux_getgroups_args {
	char gidsetsize_l_[PADL_(l_int)]; l_int gidsetsize; char gidsetsize_r_[PADR_(l_int)];
	char grouplist_l_[PADL_(l_gid_t *)]; l_gid_t * grouplist; char grouplist_r_[PADR_(l_gid_t *)];
};
struct linux_setgroups_args {
	char gidsetsize_l_[PADL_(l_int)]; l_int gidsetsize; char gidsetsize_r_[PADR_(l_int)];
	char grouplist_l_[PADL_(l_gid_t *)]; l_gid_t * grouplist; char grouplist_r_[PADR_(l_gid_t *)];
};
struct linux_chown_args {
	char path_l_[PADL_(char *)]; char * path; char path_r_[PADR_(char *)];
	char uid_l_[PADL_(l_uid_t)]; l_uid_t uid; char uid_r_[PADR_(l_uid_t)];
	char gid_l_[PADL_(l_gid_t)]; l_gid_t gid; char gid_r_[PADR_(l_gid_t)];
};
struct linux_setfsuid_args {
	char uid_l_[PADL_(l_uid_t)]; l_uid_t uid; char uid_r_[PADR_(l_uid_t)];
};
struct linux_setfsgid_args {
	char gid_l_[PADL_(l_gid_t)]; l_gid_t gid; char gid_r_[PADR_(l_gid_t)];
};
struct linux_pivot_root_args {
	char new_root_l_[PADL_(char *)]; char * new_root; char new_root_r_[PADR_(char *)];
	char put_old_l_[PADL_(char *)]; char * put_old; char put_old_r_[PADR_(char *)];
};
struct linux_mincore_args {
	char start_l_[PADL_(l_ulong)]; l_ulong start; char start_r_[PADR_(l_ulong)];
	char len_l_[PADL_(l_size_t)]; l_size_t len; char len_r_[PADR_(l_size_t)];
	char vec_l_[PADL_(u_char *)]; u_char * vec; char vec_r_[PADR_(u_char *)];
};
struct linux_getdents64_args {
	char fd_l_[PADL_(l_uint)]; l_uint fd; char fd_r_[PADR_(l_uint)];
	char dirent_l_[PADL_(void *)]; void * dirent; char dirent_r_[PADR_(void *)];
	char count_l_[PADL_(l_uint)]; l_uint count; char count_r_[PADR_(l_uint)];
};
struct linux_fcntl64_args {
	char fd_l_[PADL_(l_uint)]; l_uint fd; char fd_r_[PADR_(l_uint)];
	char cmd_l_[PADL_(l_uint)]; l_uint cmd; char cmd_r_[PADR_(l_uint)];
	char arg_l_[PADL_(uintptr_t)]; uintptr_t arg; char arg_r_[PADR_(uintptr_t)];
};
struct linux_gettid_args {
	register_t dummy;
};
struct linux_setxattr_args {
	register_t dummy;
};
struct linux_lsetxattr_args {
	register_t dummy;
};
struct linux_fsetxattr_args {
	register_t dummy;
};
struct linux_getxattr_args {
	register_t dummy;
};
struct linux_lgetxattr_args {
	register_t dummy;
};
struct linux_fgetxattr_args {
	register_t dummy;
};
struct linux_listxattr_args {
	register_t dummy;
};
struct linux_llistxattr_args {
	register_t dummy;
};
struct linux_flistxattr_args {
	register_t dummy;
};
struct linux_removexattr_args {
	register_t dummy;
};
struct linux_lremovexattr_args {
	register_t dummy;
};
struct linux_fremovexattr_args {
	register_t dummy;
};
struct linux_tkill_args {
	char tid_l_[PADL_(int)]; int tid; char tid_r_[PADR_(int)];
	char sig_l_[PADL_(int)]; int sig; char sig_r_[PADR_(int)];
};
struct linux_sys_futex_args {
	char uaddr_l_[PADL_(void *)]; void * uaddr; char uaddr_r_[PADR_(void *)];
	char op_l_[PADL_(int)]; int op; char op_r_[PADR_(int)];
	char val_l_[PADL_(uint32_t)]; uint32_t val; char val_r_[PADR_(uint32_t)];
	char timeout_l_[PADL_(struct l_timespec *)]; struct l_timespec * timeout; char timeout_r_[PADR_(struct l_timespec *)];
	char uaddr2_l_[PADL_(uint32_t *)]; uint32_t * uaddr2; char uaddr2_r_[PADR_(uint32_t *)];
	char val3_l_[PADL_(uint32_t)]; uint32_t val3; char val3_r_[PADR_(uint32_t)];
};
struct linux_sched_setaffinity_args {
	char pid_l_[PADL_(l_pid_t)]; l_pid_t pid; char pid_r_[PADR_(l_pid_t)];
	char len_l_[PADL_(l_uint)]; l_uint len; char len_r_[PADR_(l_uint)];
	char user_mask_ptr_l_[PADL_(l_ulong *)]; l_ulong * user_mask_ptr; char user_mask_ptr_r_[PADR_(l_ulong *)];
};
struct linux_sched_getaffinity_args {
	char pid_l_[PADL_(l_pid_t)]; l_pid_t pid; char pid_r_[PADR_(l_pid_t)];
	char len_l_[PADL_(l_uint)]; l_uint len; char len_r_[PADR_(l_uint)];
	char user_mask_ptr_l_[PADL_(l_ulong *)]; l_ulong * user_mask_ptr; char user_mask_ptr_r_[PADR_(l_ulong *)];
};
struct linux_set_thread_area_args {
	char desc_l_[PADL_(struct l_user_desc *)]; struct l_user_desc * desc; char desc_r_[PADR_(struct l_user_desc *)];
};
struct linux_fadvise64_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char offset_l_[PADL_(l_loff_t)]; l_loff_t offset; char offset_r_[PADR_(l_loff_t)];
	char len_l_[PADL_(l_size_t)]; l_size_t len; char len_r_[PADR_(l_size_t)];
	char advice_l_[PADL_(int)]; int advice; char advice_r_[PADR_(int)];
};
struct linux_exit_group_args {
	char error_code_l_[PADL_(int)]; int error_code; char error_code_r_[PADR_(int)];
};
struct linux_lookup_dcookie_args {
	register_t dummy;
};
struct linux_epoll_create_args {
	char size_l_[PADL_(l_int)]; l_int size; char size_r_[PADR_(l_int)];
};
struct linux_epoll_ctl_args {
	char epfd_l_[PADL_(l_int)]; l_int epfd; char epfd_r_[PADR_(l_int)];
	char op_l_[PADL_(l_int)]; l_int op; char op_r_[PADR_(l_int)];
	char fd_l_[PADL_(l_int)]; l_int fd; char fd_r_[PADR_(l_int)];
	char event_l_[PADL_(struct epoll_event *)]; struct epoll_event * event; char event_r_[PADR_(struct epoll_event *)];
};
struct linux_epoll_wait_args {
	char epfd_l_[PADL_(l_int)]; l_int epfd; char epfd_r_[PADR_(l_int)];
	char events_l_[PADL_(struct epoll_event *)]; struct epoll_event * events; char events_r_[PADR_(struct epoll_event *)];
	char maxevents_l_[PADL_(l_int)]; l_int maxevents; char maxevents_r_[PADR_(l_int)];
	char timeout_l_[PADL_(l_int)]; l_int timeout; char timeout_r_[PADR_(l_int)];
};
struct linux_remap_file_pages_args {
	register_t dummy;
};
struct linux_set_tid_address_args {
	char tidptr_l_[PADL_(int *)]; int * tidptr; char tidptr_r_[PADR_(int *)];
};
struct linux_timer_create_args {
	char clock_id_l_[PADL_(clockid_t)]; clockid_t clock_id; char clock_id_r_[PADR_(clockid_t)];
	char evp_l_[PADL_(struct sigevent *)]; struct sigevent * evp; char evp_r_[PADR_(struct sigevent *)];
	char timerid_l_[PADL_(l_timer_t *)]; l_timer_t * timerid; char timerid_r_[PADR_(l_timer_t *)];
};
struct linux_timer_settime_args {
	char timerid_l_[PADL_(l_timer_t)]; l_timer_t timerid; char timerid_r_[PADR_(l_timer_t)];
	char flags_l_[PADL_(l_int)]; l_int flags; char flags_r_[PADR_(l_int)];
	char new_l_[PADL_(const struct itimerspec *)]; const struct itimerspec * new; char new_r_[PADR_(const struct itimerspec *)];
	char old_l_[PADL_(struct itimerspec *)]; struct itimerspec * old; char old_r_[PADR_(struct itimerspec *)];
};
struct linux_timer_gettime_args {
	char timerid_l_[PADL_(l_timer_t)]; l_timer_t timerid; char timerid_r_[PADR_(l_timer_t)];
	char setting_l_[PADL_(struct itimerspec *)]; struct itimerspec * setting; char setting_r_[PADR_(struct itimerspec *)];
};
struct linux_timer_getoverrun_args {
	char timerid_l_[PADL_(l_timer_t)]; l_timer_t timerid; char timerid_r_[PADR_(l_timer_t)];
};
struct linux_timer_delete_args {
	char timerid_l_[PADL_(l_timer_t)]; l_timer_t timerid; char timerid_r_[PADR_(l_timer_t)];
};
struct linux_clock_settime_args {
	char which_l_[PADL_(clockid_t)]; clockid_t which; char which_r_[PADR_(clockid_t)];
	char tp_l_[PADL_(struct l_timespec *)]; struct l_timespec * tp; char tp_r_[PADR_(struct l_timespec *)];
};
struct linux_clock_gettime_args {
	char which_l_[PADL_(clockid_t)]; clockid_t which; char which_r_[PADR_(clockid_t)];
	char tp_l_[PADL_(struct l_timespec *)]; struct l_timespec * tp; char tp_r_[PADR_(struct l_timespec *)];
};
struct linux_clock_getres_args {
	char which_l_[PADL_(clockid_t)]; clockid_t which; char which_r_[PADR_(clockid_t)];
	char tp_l_[PADL_(struct l_timespec *)]; struct l_timespec * tp; char tp_r_[PADR_(struct l_timespec *)];
};
struct linux_clock_nanosleep_args {
	char which_l_[PADL_(clockid_t)]; clockid_t which; char which_r_[PADR_(clockid_t)];
	char flags_l_[PADL_(int)]; int flags; char flags_r_[PADR_(int)];
	char rqtp_l_[PADL_(struct l_timespec *)]; struct l_timespec * rqtp; char rqtp_r_[PADR_(struct l_timespec *)];
	char rmtp_l_[PADL_(struct l_timespec *)]; struct l_timespec * rmtp; char rmtp_r_[PADR_(struct l_timespec *)];
};
struct linux_statfs64_args {
	char path_l_[PADL_(char *)]; char * path; char path_r_[PADR_(char *)];
	char bufsize_l_[PADL_(size_t)]; size_t bufsize; char bufsize_r_[PADR_(size_t)];
	char buf_l_[PADL_(struct l_statfs64_buf *)]; struct l_statfs64_buf * buf; char buf_r_[PADR_(struct l_statfs64_buf *)];
};
struct linux_fstatfs64_args {
	char fd_l_[PADL_(l_uint)]; l_uint fd; char fd_r_[PADR_(l_uint)];
	char bufsize_l_[PADL_(size_t)]; size_t bufsize; char bufsize_r_[PADR_(size_t)];
	char buf_l_[PADL_(struct l_statfs64_buf *)]; struct l_statfs64_buf * buf; char buf_r_[PADR_(struct l_statfs64_buf *)];
};
struct linux_tgkill_args {
	char tgid_l_[PADL_(int)]; int tgid; char tgid_r_[PADR_(int)];
	char pid_l_[PADL_(int)]; int pid; char pid_r_[PADR_(int)];
	char sig_l_[PADL_(int)]; int sig; char sig_r_[PADR_(int)];
};
struct linux_utimes_args {
	char fname_l_[PADL_(char *)]; char * fname; char fname_r_[PADR_(char *)];
	char tptr_l_[PADL_(struct l_timeval *)]; struct l_timeval * tptr; char tptr_r_[PADR_(struct l_timeval *)];
};
struct linux_fadvise64_64_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char offset_l_[PADL_(l_loff_t)]; l_loff_t offset; char offset_r_[PADR_(l_loff_t)];
	char len_l_[PADL_(l_loff_t)]; l_loff_t len; char len_r_[PADR_(l_loff_t)];
	char advice_l_[PADL_(int)]; int advice; char advice_r_[PADR_(int)];
};
struct linux_mbind_args {
	register_t dummy;
};
struct linux_get_mempolicy_args {
	register_t dummy;
};
struct linux_set_mempolicy_args {
	register_t dummy;
};
struct linux_mq_open_args {
	register_t dummy;
};
struct linux_mq_unlink_args {
	register_t dummy;
};
struct linux_mq_timedsend_args {
	register_t dummy;
};
struct linux_mq_timedreceive_args {
	register_t dummy;
};
struct linux_mq_notify_args {
	register_t dummy;
};
struct linux_mq_getsetattr_args {
	register_t dummy;
};
struct linux_kexec_load_args {
	register_t dummy;
};
struct linux_waitid_args {
	char idtype_l_[PADL_(int)]; int idtype; char idtype_r_[PADR_(int)];
	char id_l_[PADL_(l_pid_t)]; l_pid_t id; char id_r_[PADR_(l_pid_t)];
	char info_l_[PADL_(l_siginfo_t *)]; l_siginfo_t * info; char info_r_[PADR_(l_siginfo_t *)];
	char options_l_[PADL_(int)]; int options; char options_r_[PADR_(int)];
	char rusage_l_[PADL_(struct l_rusage *)]; struct l_rusage * rusage; char rusage_r_[PADR_(struct l_rusage *)];
};
struct linux_add_key_args {
	register_t dummy;
};
struct linux_request_key_args {
	register_t dummy;
};
struct linux_keyctl_args {
	register_t dummy;
};
struct linux_ioprio_set_args {
	register_t dummy;
};
struct linux_ioprio_get_args {
	register_t dummy;
};
struct linux_inotify_init_args {
	register_t dummy;
};
struct linux_inotify_add_watch_args {
	register_t dummy;
};
struct linux_inotify_rm_watch_args {
	register_t dummy;
};
struct linux_migrate_pages_args {
	register_t dummy;
};
struct linux_openat_args {
	char dfd_l_[PADL_(l_int)]; l_int dfd; char dfd_r_[PADR_(l_int)];
	char filename_l_[PADL_(const char *)]; const char * filename; char filename_r_[PADR_(const char *)];
	char flags_l_[PADL_(l_int)]; l_int flags; char flags_r_[PADR_(l_int)];
	char mode_l_[PADL_(l_int)]; l_int mode; char mode_r_[PADR_(l_int)];
};
struct linux_mkdirat_args {
	char dfd_l_[PADL_(l_int)]; l_int dfd; char dfd_r_[PADR_(l_int)];
	char pathname_l_[PADL_(const char *)]; const char * pathname; char pathname_r_[PADR_(const char *)];
	char mode_l_[PADL_(l_int)]; l_int mode; char mode_r_[PADR_(l_int)];
};
struct linux_mknodat_args {
	char dfd_l_[PADL_(l_int)]; l_int dfd; char dfd_r_[PADR_(l_int)];
	char filename_l_[PADL_(const char *)]; const char * filename; char filename_r_[PADR_(const char *)];
	char mode_l_[PADL_(l_int)]; l_int mode; char mode_r_[PADR_(l_int)];
	char dev_l_[PADL_(l_uint)]; l_uint dev; char dev_r_[PADR_(l_uint)];
};
struct linux_fchownat_args {
	char dfd_l_[PADL_(l_int)]; l_int dfd; char dfd_r_[PADR_(l_int)];
	char filename_l_[PADL_(const char *)]; const char * filename; char filename_r_[PADR_(const char *)];
	char uid_l_[PADL_(l_uid16_t)]; l_uid16_t uid; char uid_r_[PADR_(l_uid16_t)];
	char gid_l_[PADL_(l_gid16_t)]; l_gid16_t gid; char gid_r_[PADR_(l_gid16_t)];
	char flag_l_[PADL_(l_int)]; l_int flag; char flag_r_[PADR_(l_int)];
};
struct linux_futimesat_args {
	char dfd_l_[PADL_(l_int)]; l_int dfd; char dfd_r_[PADR_(l_int)];
	char filename_l_[PADL_(char *)]; char * filename; char filename_r_[PADR_(char *)];
	char utimes_l_[PADL_(struct l_timeval *)]; struct l_timeval * utimes; char utimes_r_[PADR_(struct l_timeval *)];
};
struct linux_fstatat64_args {
	char dfd_l_[PADL_(l_int)]; l_int dfd; char dfd_r_[PADR_(l_int)];
	char pathname_l_[PADL_(char *)]; char * pathname; char pathname_r_[PADR_(char *)];
	char statbuf_l_[PADL_(struct l_stat64 *)]; struct l_stat64 * statbuf; char statbuf_r_[PADR_(struct l_stat64 *)];
	char flag_l_[PADL_(l_int)]; l_int flag; char flag_r_[PADR_(l_int)];
};
struct linux_unlinkat_args {
	char dfd_l_[PADL_(l_int)]; l_int dfd; char dfd_r_[PADR_(l_int)];
	char pathname_l_[PADL_(const char *)]; const char * pathname; char pathname_r_[PADR_(const char *)];
	char flag_l_[PADL_(l_int)]; l_int flag; char flag_r_[PADR_(l_int)];
};
struct linux_renameat_args {
	char olddfd_l_[PADL_(l_int)]; l_int olddfd; char olddfd_r_[PADR_(l_int)];
	char oldname_l_[PADL_(const char *)]; const char * oldname; char oldname_r_[PADR_(const char *)];
	char newdfd_l_[PADL_(l_int)]; l_int newdfd; char newdfd_r_[PADR_(l_int)];
	char newname_l_[PADL_(const char *)]; const char * newname; char newname_r_[PADR_(const char *)];
};
struct linux_linkat_args {
	char olddfd_l_[PADL_(l_int)]; l_int olddfd; char olddfd_r_[PADR_(l_int)];
	char oldname_l_[PADL_(const char *)]; const char * oldname; char oldname_r_[PADR_(const char *)];
	char newdfd_l_[PADL_(l_int)]; l_int newdfd; char newdfd_r_[PADR_(l_int)];
	char newname_l_[PADL_(const char *)]; const char * newname; char newname_r_[PADR_(const char *)];
	char flag_l_[PADL_(l_int)]; l_int flag; char flag_r_[PADR_(l_int)];
};
struct linux_symlinkat_args {
	char oldname_l_[PADL_(const char *)]; const char * oldname; char oldname_r_[PADR_(const char *)];
	char newdfd_l_[PADL_(l_int)]; l_int newdfd; char newdfd_r_[PADR_(l_int)];
	char newname_l_[PADL_(const char *)]; const char * newname; char newname_r_[PADR_(const char *)];
};
struct linux_readlinkat_args {
	char dfd_l_[PADL_(l_int)]; l_int dfd; char dfd_r_[PADR_(l_int)];
	char path_l_[PADL_(const char *)]; const char * path; char path_r_[PADR_(const char *)];
	char buf_l_[PADL_(char *)]; char * buf; char buf_r_[PADR_(char *)];
	char bufsiz_l_[PADL_(l_int)]; l_int bufsiz; char bufsiz_r_[PADR_(l_int)];
};
struct linux_fchmodat_args {
	char dfd_l_[PADL_(l_int)]; l_int dfd; char dfd_r_[PADR_(l_int)];
	char filename_l_[PADL_(const char *)]; const char * filename; char filename_r_[PADR_(const char *)];
	char mode_l_[PADL_(l_mode_t)]; l_mode_t mode; char mode_r_[PADR_(l_mode_t)];
};
struct linux_faccessat_args {
	char dfd_l_[PADL_(l_int)]; l_int dfd; char dfd_r_[PADR_(l_int)];
	char filename_l_[PADL_(const char *)]; const char * filename; char filename_r_[PADR_(const char *)];
	char amode_l_[PADL_(l_int)]; l_int amode; char amode_r_[PADR_(l_int)];
};
struct linux_pselect6_args {
	char nfds_l_[PADL_(l_int)]; l_int nfds; char nfds_r_[PADR_(l_int)];
	char readfds_l_[PADL_(l_fd_set *)]; l_fd_set * readfds; char readfds_r_[PADR_(l_fd_set *)];
	char writefds_l_[PADL_(l_fd_set *)]; l_fd_set * writefds; char writefds_r_[PADR_(l_fd_set *)];
	char exceptfds_l_[PADL_(l_fd_set *)]; l_fd_set * exceptfds; char exceptfds_r_[PADR_(l_fd_set *)];
	char tsp_l_[PADL_(struct l_timespec *)]; struct l_timespec * tsp; char tsp_r_[PADR_(struct l_timespec *)];
	char sig_l_[PADL_(l_uintptr_t *)]; l_uintptr_t * sig; char sig_r_[PADR_(l_uintptr_t *)];
};
struct linux_ppoll_args {
	char fds_l_[PADL_(struct pollfd *)]; struct pollfd * fds; char fds_r_[PADR_(struct pollfd *)];
	char nfds_l_[PADL_(uint32_t)]; uint32_t nfds; char nfds_r_[PADR_(uint32_t)];
	char tsp_l_[PADL_(struct l_timespec *)]; struct l_timespec * tsp; char tsp_r_[PADR_(struct l_timespec *)];
	char sset_l_[PADL_(l_sigset_t *)]; l_sigset_t * sset; char sset_r_[PADR_(l_sigset_t *)];
	char ssize_l_[PADL_(l_size_t)]; l_size_t ssize; char ssize_r_[PADR_(l_size_t)];
};
struct linux_unshare_args {
	register_t dummy;
};
struct linux_set_robust_list_args {
	char head_l_[PADL_(struct linux_robust_list_head *)]; struct linux_robust_list_head * head; char head_r_[PADR_(struct linux_robust_list_head *)];
	char len_l_[PADL_(l_size_t)]; l_size_t len; char len_r_[PADR_(l_size_t)];
};
struct linux_get_robust_list_args {
	char pid_l_[PADL_(l_int)]; l_int pid; char pid_r_[PADR_(l_int)];
	char head_l_[PADL_(struct linux_robust_list_head **)]; struct linux_robust_list_head ** head; char head_r_[PADR_(struct linux_robust_list_head **)];
	char len_l_[PADL_(l_size_t *)]; l_size_t * len; char len_r_[PADR_(l_size_t *)];
};
struct linux_splice_args {
	register_t dummy;
};
struct linux_sync_file_range_args {
	register_t dummy;
};
struct linux_tee_args {
	register_t dummy;
};
struct linux_vmsplice_args {
	register_t dummy;
};
struct linux_move_pages_args {
	register_t dummy;
};
struct linux_getcpu_args {
	register_t dummy;
};
struct linux_epoll_pwait_args {
	char epfd_l_[PADL_(l_int)]; l_int epfd; char epfd_r_[PADR_(l_int)];
	char events_l_[PADL_(struct epoll_event *)]; struct epoll_event * events; char events_r_[PADR_(struct epoll_event *)];
	char maxevents_l_[PADL_(l_int)]; l_int maxevents; char maxevents_r_[PADR_(l_int)];
	char timeout_l_[PADL_(l_int)]; l_int timeout; char timeout_r_[PADR_(l_int)];
	char mask_l_[PADL_(l_sigset_t *)]; l_sigset_t * mask; char mask_r_[PADR_(l_sigset_t *)];
	char sigsetsize_l_[PADL_(l_size_t)]; l_size_t sigsetsize; char sigsetsize_r_[PADR_(l_size_t)];
};
struct linux_utimensat_args {
	char dfd_l_[PADL_(l_int)]; l_int dfd; char dfd_r_[PADR_(l_int)];
	char pathname_l_[PADL_(const char *)]; const char * pathname; char pathname_r_[PADR_(const char *)];
	char times_l_[PADL_(const struct l_timespec *)]; const struct l_timespec * times; char times_r_[PADR_(const struct l_timespec *)];
	char flags_l_[PADL_(l_int)]; l_int flags; char flags_r_[PADR_(l_int)];
};
struct linux_signalfd_args {
	register_t dummy;
};
struct linux_timerfd_create_args {
	char clockid_l_[PADL_(l_int)]; l_int clockid; char clockid_r_[PADR_(l_int)];
	char flags_l_[PADL_(l_int)]; l_int flags; char flags_r_[PADR_(l_int)];
};
struct linux_eventfd_args {
	char initval_l_[PADL_(l_uint)]; l_uint initval; char initval_r_[PADR_(l_uint)];
};
struct linux_fallocate_args {
	char fd_l_[PADL_(l_int)]; l_int fd; char fd_r_[PADR_(l_int)];
	char mode_l_[PADL_(l_int)]; l_int mode; char mode_r_[PADR_(l_int)];
	char offset_l_[PADL_(l_loff_t)]; l_loff_t offset; char offset_r_[PADR_(l_loff_t)];
	char len_l_[PADL_(l_loff_t)]; l_loff_t len; char len_r_[PADR_(l_loff_t)];
};
struct linux_timerfd_settime_args {
	char fd_l_[PADL_(l_int)]; l_int fd; char fd_r_[PADR_(l_int)];
	char flags_l_[PADL_(l_int)]; l_int flags; char flags_r_[PADR_(l_int)];
	char new_value_l_[PADL_(const struct l_itimerspec *)]; const struct l_itimerspec * new_value; char new_value_r_[PADR_(const struct l_itimerspec *)];
	char old_value_l_[PADL_(struct l_itimerspec *)]; struct l_itimerspec * old_value; char old_value_r_[PADR_(struct l_itimerspec *)];
};
struct linux_timerfd_gettime_args {
	char fd_l_[PADL_(l_int)]; l_int fd; char fd_r_[PADR_(l_int)];
	char old_value_l_[PADL_(struct l_itimerspec *)]; struct l_itimerspec * old_value; char old_value_r_[PADR_(struct l_itimerspec *)];
};
struct linux_signalfd4_args {
	register_t dummy;
};
struct linux_eventfd2_args {
	char initval_l_[PADL_(l_uint)]; l_uint initval; char initval_r_[PADR_(l_uint)];
	char flags_l_[PADL_(l_int)]; l_int flags; char flags_r_[PADR_(l_int)];
};
struct linux_epoll_create1_args {
	char flags_l_[PADL_(l_int)]; l_int flags; char flags_r_[PADR_(l_int)];
};
struct linux_dup3_args {
	char oldfd_l_[PADL_(l_int)]; l_int oldfd; char oldfd_r_[PADR_(l_int)];
	char newfd_l_[PADL_(l_int)]; l_int newfd; char newfd_r_[PADR_(l_int)];
	char flags_l_[PADL_(l_int)]; l_int flags; char flags_r_[PADR_(l_int)];
};
struct linux_pipe2_args {
	char pipefds_l_[PADL_(l_int *)]; l_int * pipefds; char pipefds_r_[PADR_(l_int *)];
	char flags_l_[PADL_(l_int)]; l_int flags; char flags_r_[PADR_(l_int)];
};
struct linux_inotify_init1_args {
	register_t dummy;
};
struct linux_preadv_args {
	char fd_l_[PADL_(l_ulong)]; l_ulong fd; char fd_r_[PADR_(l_ulong)];
	char vec_l_[PADL_(struct iovec *)]; struct iovec * vec; char vec_r_[PADR_(struct iovec *)];
	char vlen_l_[PADL_(l_ulong)]; l_ulong vlen; char vlen_r_[PADR_(l_ulong)];
	char pos_l_l_[PADL_(l_ulong)]; l_ulong pos_l; char pos_l_r_[PADR_(l_ulong)];
	char pos_h_l_[PADL_(l_ulong)]; l_ulong pos_h; char pos_h_r_[PADR_(l_ulong)];
};
struct linux_pwritev_args {
	char fd_l_[PADL_(l_ulong)]; l_ulong fd; char fd_r_[PADR_(l_ulong)];
	char vec_l_[PADL_(struct iovec *)]; struct iovec * vec; char vec_r_[PADR_(struct iovec *)];
	char vlen_l_[PADL_(l_ulong)]; l_ulong vlen; char vlen_r_[PADR_(l_ulong)];
	char pos_l_l_[PADL_(l_ulong)]; l_ulong pos_l; char pos_l_r_[PADR_(l_ulong)];
	char pos_h_l_[PADL_(l_ulong)]; l_ulong pos_h; char pos_h_r_[PADR_(l_ulong)];
};
struct linux_rt_tgsigqueueinfo_args {
	char tgid_l_[PADL_(l_pid_t)]; l_pid_t tgid; char tgid_r_[PADR_(l_pid_t)];
	char tid_l_[PADL_(l_pid_t)]; l_pid_t tid; char tid_r_[PADR_(l_pid_t)];
	char sig_l_[PADL_(l_int)]; l_int sig; char sig_r_[PADR_(l_int)];
	char uinfo_l_[PADL_(l_siginfo_t *)]; l_siginfo_t * uinfo; char uinfo_r_[PADR_(l_siginfo_t *)];
};
struct linux_perf_event_open_args {
	register_t dummy;
};
struct linux_recvmmsg_args {
	char s_l_[PADL_(l_int)]; l_int s; char s_r_[PADR_(l_int)];
	char msg_l_[PADL_(struct l_mmsghdr *)]; struct l_mmsghdr * msg; char msg_r_[PADR_(struct l_mmsghdr *)];
	char vlen_l_[PADL_(l_uint)]; l_uint vlen; char vlen_r_[PADR_(l_uint)];
	char flags_l_[PADL_(l_uint)]; l_uint flags; char flags_r_[PADR_(l_uint)];
	char timeout_l_[PADL_(struct l_timespec *)]; struct l_timespec * timeout; char timeout_r_[PADR_(struct l_timespec *)];
};
struct linux_fanotify_init_args {
	register_t dummy;
};
struct linux_fanotify_mark_args {
	register_t dummy;
};
struct linux_prlimit64_args {
	char pid_l_[PADL_(l_pid_t)]; l_pid_t pid; char pid_r_[PADR_(l_pid_t)];
	char resource_l_[PADL_(l_uint)]; l_uint resource; char resource_r_[PADR_(l_uint)];
	char new_l_[PADL_(struct rlimit *)]; struct rlimit * new; char new_r_[PADR_(struct rlimit *)];
	char old_l_[PADL_(struct rlimit *)]; struct rlimit * old; char old_r_[PADR_(struct rlimit *)];
};
struct linux_name_to_handle_at_args {
	register_t dummy;
};
struct linux_open_by_handle_at_args {
	register_t dummy;
};
struct linux_clock_adjtime_args {
	register_t dummy;
};
struct linux_syncfs_args {
	char fd_l_[PADL_(l_int)]; l_int fd; char fd_r_[PADR_(l_int)];
};
struct linux_sendmmsg_args {
	char s_l_[PADL_(l_int)]; l_int s; char s_r_[PADR_(l_int)];
	char msg_l_[PADL_(struct l_mmsghdr *)]; struct l_mmsghdr * msg; char msg_r_[PADR_(struct l_mmsghdr *)];
	char vlen_l_[PADL_(l_uint)]; l_uint vlen; char vlen_r_[PADR_(l_uint)];
	char flags_l_[PADL_(l_uint)]; l_uint flags; char flags_r_[PADR_(l_uint)];
};
struct linux_setns_args {
	register_t dummy;
};
struct linux_process_vm_readv_args {
	char pid_l_[PADL_(l_pid_t)]; l_pid_t pid; char pid_r_[PADR_(l_pid_t)];
	char lvec_l_[PADL_(const struct iovec *)]; const struct iovec * lvec; char lvec_r_[PADR_(const struct iovec *)];
	char liovcnt_l_[PADL_(l_ulong)]; l_ulong liovcnt; char liovcnt_r_[PADR_(l_ulong)];
	char rvec_l_[PADL_(const struct iovec *)]; const struct iovec * rvec; char rvec_r_[PADR_(const struct iovec *)];
	char riovcnt_l_[PADL_(l_ulong)]; l_ulong riovcnt; char riovcnt_r_[PADR_(l_ulong)];
	char flags_l_[PADL_(l_ulong)]; l_ulong flags; char flags_r_[PADR_(l_ulong)];
};
struct linux_process_vm_writev_args {
	char pid_l_[PADL_(l_pid_t)]; l_pid_t pid; char pid_r_[PADR_(l_pid_t)];
	char lvec_l_[PADL_(const struct iovec *)]; const struct iovec * lvec; char lvec_r_[PADR_(const struct iovec *)];
	char liovcnt_l_[PADL_(l_ulong)]; l_ulong liovcnt; char liovcnt_r_[PADR_(l_ulong)];
	char rvec_l_[PADL_(const struct iovec *)]; const struct iovec * rvec; char rvec_r_[PADR_(const struct iovec *)];
	char riovcnt_l_[PADL_(l_ulong)]; l_ulong riovcnt; char riovcnt_r_[PADR_(l_ulong)];
	char flags_l_[PADL_(l_ulong)]; l_ulong flags; char flags_r_[PADR_(l_ulong)];
};
struct linux_kcmp_args {
	char pid1_l_[PADL_(l_pid_t)]; l_pid_t pid1; char pid1_r_[PADR_(l_pid_t)];
	char pid2_l_[PADL_(l_pid_t)]; l_pid_t pid2; char pid2_r_[PADR_(l_pid_t)];
	char type_l_[PADL_(l_int)]; l_int type; char type_r_[PADR_(l_int)];
	char idx1_l_[PADL_(l_ulong)]; l_ulong idx1; char idx1_r_[PADR_(l_ulong)];
	char idx_l_[PADL_(l_ulong)]; l_ulong idx; char idx_r_[PADR_(l_ulong)];
};
struct linux_finit_module_args {
	char fd_l_[PADL_(l_int)]; l_int fd; char fd_r_[PADR_(l_int)];
	char uargs_l_[PADL_(const char *)]; const char * uargs; char uargs_r_[PADR_(const char *)];
	char flags_l_[PADL_(l_int)]; l_int flags; char flags_r_[PADR_(l_int)];
};
struct linux_sched_setattr_args {
	char pid_l_[PADL_(l_pid_t)]; l_pid_t pid; char pid_r_[PADR_(l_pid_t)];
	char attr_l_[PADL_(void *)]; void * attr; char attr_r_[PADR_(void *)];
	char flags_l_[PADL_(l_uint)]; l_uint flags; char flags_r_[PADR_(l_uint)];
};
struct linux_sched_getattr_args {
	char pid_l_[PADL_(l_pid_t)]; l_pid_t pid; char pid_r_[PADR_(l_pid_t)];
	char attr_l_[PADL_(void *)]; void * attr; char attr_r_[PADR_(void *)];
	char size_l_[PADL_(l_uint)]; l_uint size; char size_r_[PADR_(l_uint)];
	char flags_l_[PADL_(l_uint)]; l_uint flags; char flags_r_[PADR_(l_uint)];
};
struct linux_renameat2_args {
	char olddfd_l_[PADL_(l_int)]; l_int olddfd; char olddfd_r_[PADR_(l_int)];
	char oldname_l_[PADL_(const char *)]; const char * oldname; char oldname_r_[PADR_(const char *)];
	char newdfd_l_[PADL_(l_int)]; l_int newdfd; char newdfd_r_[PADR_(l_int)];
	char newname_l_[PADL_(const char *)]; const char * newname; char newname_r_[PADR_(const char *)];
	char flags_l_[PADL_(unsigned int)]; unsigned int flags; char flags_r_[PADR_(unsigned int)];
};
struct linux_seccomp_args {
	char op_l_[PADL_(l_uint)]; l_uint op; char op_r_[PADR_(l_uint)];
	char flags_l_[PADL_(l_uint)]; l_uint flags; char flags_r_[PADR_(l_uint)];
	char uargs_l_[PADL_(const char *)]; const char * uargs; char uargs_r_[PADR_(const char *)];
};
struct linux_getrandom_args {
	char buf_l_[PADL_(char *)]; char * buf; char buf_r_[PADR_(char *)];
	char count_l_[PADL_(l_size_t)]; l_size_t count; char count_r_[PADR_(l_size_t)];
	char flags_l_[PADL_(l_uint)]; l_uint flags; char flags_r_[PADR_(l_uint)];
};
struct linux_memfd_create_args {
	char uname_ptr_l_[PADL_(const char *)]; const char * uname_ptr; char uname_ptr_r_[PADR_(const char *)];
	char flags_l_[PADL_(l_uint)]; l_uint flags; char flags_r_[PADR_(l_uint)];
};
struct linux_bpf_args {
	char cmd_l_[PADL_(l_int)]; l_int cmd; char cmd_r_[PADR_(l_int)];
	char attr_l_[PADL_(void *)]; void * attr; char attr_r_[PADR_(void *)];
	char size_l_[PADL_(l_uint)]; l_uint size; char size_r_[PADR_(l_uint)];
};
struct linux_execveat_args {
	char dfd_l_[PADL_(l_int)]; l_int dfd; char dfd_r_[PADR_(l_int)];
	char filename_l_[PADL_(const char *)]; const char * filename; char filename_r_[PADR_(const char *)];
	char argv_l_[PADL_(const char **)]; const char ** argv; char argv_r_[PADR_(const char **)];
	char envp_l_[PADL_(const char **)]; const char ** envp; char envp_r_[PADR_(const char **)];
	char flags_l_[PADL_(l_int)]; l_int flags; char flags_r_[PADR_(l_int)];
};
struct linux_socket_args {
	char domain_l_[PADL_(l_int)]; l_int domain; char domain_r_[PADR_(l_int)];
	char type_l_[PADL_(l_int)]; l_int type; char type_r_[PADR_(l_int)];
	char protocol_l_[PADL_(l_int)]; l_int protocol; char protocol_r_[PADR_(l_int)];
};
struct linux_socketpair_args {
	char domain_l_[PADL_(l_int)]; l_int domain; char domain_r_[PADR_(l_int)];
	char type_l_[PADL_(l_int)]; l_int type; char type_r_[PADR_(l_int)];
	char protocol_l_[PADL_(l_int)]; l_int protocol; char protocol_r_[PADR_(l_int)];
	char rsv_l_[PADL_(l_uintptr_t)]; l_uintptr_t rsv; char rsv_r_[PADR_(l_uintptr_t)];
};
struct linux_bind_args {
	char s_l_[PADL_(l_int)]; l_int s; char s_r_[PADR_(l_int)];
	char name_l_[PADL_(l_uintptr_t)]; l_uintptr_t name; char name_r_[PADR_(l_uintptr_t)];
	char namelen_l_[PADL_(l_int)]; l_int namelen; char namelen_r_[PADR_(l_int)];
};
struct linux_connect_args {
	char s_l_[PADL_(l_int)]; l_int s; char s_r_[PADR_(l_int)];
	char name_l_[PADL_(l_uintptr_t)]; l_uintptr_t name; char name_r_[PADR_(l_uintptr_t)];
	char namelen_l_[PADL_(l_int)]; l_int namelen; char namelen_r_[PADR_(l_int)];
};
struct linux_listen_args {
	char s_l_[PADL_(l_int)]; l_int s; char s_r_[PADR_(l_int)];
	char backlog_l_[PADL_(l_int)]; l_int backlog; char backlog_r_[PADR_(l_int)];
};
struct linux_accept4_args {
	char s_l_[PADL_(l_int)]; l_int s; char s_r_[PADR_(l_int)];
	char addr_l_[PADL_(l_uintptr_t)]; l_uintptr_t addr; char addr_r_[PADR_(l_uintptr_t)];
	char namelen_l_[PADL_(l_uintptr_t)]; l_uintptr_t namelen; char namelen_r_[PADR_(l_uintptr_t)];
	char flags_l_[PADL_(l_int)]; l_int flags; char flags_r_[PADR_(l_int)];
};
struct linux_getsockopt_args {
	char s_l_[PADL_(l_int)]; l_int s; char s_r_[PADR_(l_int)];
	char level_l_[PADL_(l_int)]; l_int level; char level_r_[PADR_(l_int)];
	char optname_l_[PADL_(l_int)]; l_int optname; char optname_r_[PADR_(l_int)];
	char optval_l_[PADL_(l_uintptr_t)]; l_uintptr_t optval; char optval_r_[PADR_(l_uintptr_t)];
	char optlen_l_[PADL_(l_uintptr_t)]; l_uintptr_t optlen; char optlen_r_[PADR_(l_uintptr_t)];
};
struct linux_setsockopt_args {
	char s_l_[PADL_(l_int)]; l_int s; char s_r_[PADR_(l_int)];
	char level_l_[PADL_(l_int)]; l_int level; char level_r_[PADR_(l_int)];
	char optname_l_[PADL_(l_int)]; l_int optname; char optname_r_[PADR_(l_int)];
	char optval_l_[PADL_(l_uintptr_t)]; l_uintptr_t optval; char optval_r_[PADR_(l_uintptr_t)];
	char optlen_l_[PADL_(l_int)]; l_int optlen; char optlen_r_[PADR_(l_int)];
};
struct linux_getsockname_args {
	char s_l_[PADL_(l_int)]; l_int s; char s_r_[PADR_(l_int)];
	char addr_l_[PADL_(l_uintptr_t)]; l_uintptr_t addr; char addr_r_[PADR_(l_uintptr_t)];
	char namelen_l_[PADL_(l_uintptr_t)]; l_uintptr_t namelen; char namelen_r_[PADR_(l_uintptr_t)];
};
struct linux_getpeername_args {
	char s_l_[PADL_(l_int)]; l_int s; char s_r_[PADR_(l_int)];
	char addr_l_[PADL_(l_uintptr_t)]; l_uintptr_t addr; char addr_r_[PADR_(l_uintptr_t)];
	char namelen_l_[PADL_(l_uintptr_t)]; l_uintptr_t namelen; char namelen_r_[PADR_(l_uintptr_t)];
};
struct linux_sendto_args {
	char s_l_[PADL_(l_int)]; l_int s; char s_r_[PADR_(l_int)];
	char msg_l_[PADL_(l_uintptr_t)]; l_uintptr_t msg; char msg_r_[PADR_(l_uintptr_t)];
	char len_l_[PADL_(l_int)]; l_int len; char len_r_[PADR_(l_int)];
	char flags_l_[PADL_(l_int)]; l_int flags; char flags_r_[PADR_(l_int)];
	char to_l_[PADL_(l_uintptr_t)]; l_uintptr_t to; char to_r_[PADR_(l_uintptr_t)];
	char tolen_l_[PADL_(l_int)]; l_int tolen; char tolen_r_[PADR_(l_int)];
};
struct linux_sendmsg_args {
	char s_l_[PADL_(l_int)]; l_int s; char s_r_[PADR_(l_int)];
	char msg_l_[PADL_(l_uintptr_t)]; l_uintptr_t msg; char msg_r_[PADR_(l_uintptr_t)];
	char flags_l_[PADL_(l_int)]; l_int flags; char flags_r_[PADR_(l_int)];
};
struct linux_recvfrom_args {
	char s_l_[PADL_(l_int)]; l_int s; char s_r_[PADR_(l_int)];
	char buf_l_[PADL_(l_uintptr_t)]; l_uintptr_t buf; char buf_r_[PADR_(l_uintptr_t)];
	char len_l_[PADL_(l_size_t)]; l_size_t len; char len_r_[PADR_(l_size_t)];
	char flags_l_[PADL_(l_int)]; l_int flags; char flags_r_[PADR_(l_int)];
	char from_l_[PADL_(l_uintptr_t)]; l_uintptr_t from; char from_r_[PADR_(l_uintptr_t)];
	char fromlen_l_[PADL_(l_uintptr_t)]; l_uintptr_t fromlen; char fromlen_r_[PADR_(l_uintptr_t)];
};
struct linux_recvmsg_args {
	char s_l_[PADL_(l_int)]; l_int s; char s_r_[PADR_(l_int)];
	char msg_l_[PADL_(l_uintptr_t)]; l_uintptr_t msg; char msg_r_[PADR_(l_uintptr_t)];
	char flags_l_[PADL_(l_int)]; l_int flags; char flags_r_[PADR_(l_int)];
};
struct linux_shutdown_args {
	char s_l_[PADL_(l_int)]; l_int s; char s_r_[PADR_(l_int)];
	char how_l_[PADL_(l_int)]; l_int how; char how_r_[PADR_(l_int)];
};
struct linux_userfaultfd_args {
	char flags_l_[PADL_(l_int)]; l_int flags; char flags_r_[PADR_(l_int)];
};
struct linux_membarrier_args {
	char cmd_l_[PADL_(l_int)]; l_int cmd; char cmd_r_[PADR_(l_int)];
	char flags_l_[PADL_(l_int)]; l_int flags; char flags_r_[PADR_(l_int)];
};
struct linux_mlock2_args {
	char start_l_[PADL_(l_ulong)]; l_ulong start; char start_r_[PADR_(l_ulong)];
	char len_l_[PADL_(l_size_t)]; l_size_t len; char len_r_[PADR_(l_size_t)];
	char flags_l_[PADL_(l_int)]; l_int flags; char flags_r_[PADR_(l_int)];
};
struct linux_copy_file_range_args {
	char fd_in_l_[PADL_(l_int)]; l_int fd_in; char fd_in_r_[PADR_(l_int)];
	char off_in_l_[PADL_(l_loff_t *)]; l_loff_t * off_in; char off_in_r_[PADR_(l_loff_t *)];
	char fd_out_l_[PADL_(l_int)]; l_int fd_out; char fd_out_r_[PADR_(l_int)];
	char off_out_l_[PADL_(l_loff_t *)]; l_loff_t * off_out; char off_out_r_[PADR_(l_loff_t *)];
	char len_l_[PADL_(l_size_t)]; l_size_t len; char len_r_[PADR_(l_size_t)];
	char flags_l_[PADL_(l_uint)]; l_uint flags; char flags_r_[PADR_(l_uint)];
};
struct linux_preadv2_args {
	char fd_l_[PADL_(l_ulong)]; l_ulong fd; char fd_r_[PADR_(l_ulong)];
	char vec_l_[PADL_(const struct iovec *)]; const struct iovec * vec; char vec_r_[PADR_(const struct iovec *)];
	char vlen_l_[PADL_(l_ulong)]; l_ulong vlen; char vlen_r_[PADR_(l_ulong)];
	char pos_l_l_[PADL_(l_ulong)]; l_ulong pos_l; char pos_l_r_[PADR_(l_ulong)];
	char pos_h_l_[PADL_(l_ulong)]; l_ulong pos_h; char pos_h_r_[PADR_(l_ulong)];
	char flags_l_[PADL_(l_int)]; l_int flags; char flags_r_[PADR_(l_int)];
};
struct linux_pwritev2_args {
	char fd_l_[PADL_(l_ulong)]; l_ulong fd; char fd_r_[PADR_(l_ulong)];
	char vec_l_[PADL_(const struct iovec *)]; const struct iovec * vec; char vec_r_[PADR_(const struct iovec *)];
	char vlen_l_[PADL_(l_ulong)]; l_ulong vlen; char vlen_r_[PADR_(l_ulong)];
	char pos_l_l_[PADL_(l_ulong)]; l_ulong pos_l; char pos_l_r_[PADR_(l_ulong)];
	char pos_h_l_[PADL_(l_ulong)]; l_ulong pos_h; char pos_h_r_[PADR_(l_ulong)];
	char flags_l_[PADL_(l_int)]; l_int flags; char flags_r_[PADR_(l_int)];
};
struct linux_pkey_mprotect_args {
	char start_l_[PADL_(l_ulong)]; l_ulong start; char start_r_[PADR_(l_ulong)];
	char len_l_[PADL_(l_size_t)]; l_size_t len; char len_r_[PADR_(l_size_t)];
	char prot_l_[PADL_(l_ulong)]; l_ulong prot; char prot_r_[PADR_(l_ulong)];
	char pkey_l_[PADL_(l_int)]; l_int pkey; char pkey_r_[PADR_(l_int)];
};
struct linux_pkey_alloc_args {
	char flags_l_[PADL_(l_ulong)]; l_ulong flags; char flags_r_[PADR_(l_ulong)];
	char init_val_l_[PADL_(l_ulong)]; l_ulong init_val; char init_val_r_[PADR_(l_ulong)];
};
struct linux_pkey_free_args {
	char pkey_l_[PADL_(l_int)]; l_int pkey; char pkey_r_[PADR_(l_int)];
};
struct linux_statx_args {
	char dirfd_l_[PADL_(l_int)]; l_int dirfd; char dirfd_r_[PADR_(l_int)];
	char pathname_l_[PADL_(const char *)]; const char * pathname; char pathname_r_[PADR_(const char *)];
	char flags_l_[PADL_(l_uint)]; l_uint flags; char flags_r_[PADR_(l_uint)];
	char mask_l_[PADL_(l_uint)]; l_uint mask; char mask_r_[PADR_(l_uint)];
	char statxbuf_l_[PADL_(void *)]; void * statxbuf; char statxbuf_r_[PADR_(void *)];
};
struct linux_arch_prctl_args {
	char option_l_[PADL_(l_int)]; l_int option; char option_r_[PADR_(l_int)];
	char arg2_l_[PADL_(l_ulong)]; l_ulong arg2; char arg2_r_[PADR_(l_ulong)];
};
struct linux_io_pgetevents_args {
	register_t dummy;
};
struct linux_rseq_args {
	register_t dummy;
};
struct linux_semget_args {
	char key_l_[PADL_(l_key_t)]; l_key_t key; char key_r_[PADR_(l_key_t)];
	char nsems_l_[PADL_(l_int)]; l_int nsems; char nsems_r_[PADR_(l_int)];
	char semflg_l_[PADL_(l_int)]; l_int semflg; char semflg_r_[PADR_(l_int)];
};
struct linux_semctl_args {
	char semid_l_[PADL_(l_int)]; l_int semid; char semid_r_[PADR_(l_int)];
	char semnum_l_[PADL_(l_int)]; l_int semnum; char semnum_r_[PADR_(l_int)];
	char cmd_l_[PADL_(l_int)]; l_int cmd; char cmd_r_[PADR_(l_int)];
	char arg_l_[PADL_(union l_semun)]; union l_semun arg; char arg_r_[PADR_(union l_semun)];
};
struct linux_shmget_args {
	char key_l_[PADL_(l_key_t)]; l_key_t key; char key_r_[PADR_(l_key_t)];
	char size_l_[PADL_(l_size_t)]; l_size_t size; char size_r_[PADR_(l_size_t)];
	char shmflg_l_[PADL_(l_int)]; l_int shmflg; char shmflg_r_[PADR_(l_int)];
};
struct linux_shmctl_args {
	char shmid_l_[PADL_(l_int)]; l_int shmid; char shmid_r_[PADR_(l_int)];
	char cmd_l_[PADL_(l_int)]; l_int cmd; char cmd_r_[PADR_(l_int)];
	char buf_l_[PADL_(struct l_shmid_ds *)]; struct l_shmid_ds * buf; char buf_r_[PADR_(struct l_shmid_ds *)];
};
struct linux_shmat_args {
	char shmid_l_[PADL_(l_int)]; l_int shmid; char shmid_r_[PADR_(l_int)];
	char shmaddr_l_[PADL_(char *)]; char * shmaddr; char shmaddr_r_[PADR_(char *)];
	char shmflg_l_[PADL_(l_int)]; l_int shmflg; char shmflg_r_[PADR_(l_int)];
};
struct linux_shmdt_args {
	char shmaddr_l_[PADL_(char *)]; char * shmaddr; char shmaddr_r_[PADR_(char *)];
};
struct linux_msgget_args {
	char key_l_[PADL_(l_key_t)]; l_key_t key; char key_r_[PADR_(l_key_t)];
	char msgflg_l_[PADL_(l_int)]; l_int msgflg; char msgflg_r_[PADR_(l_int)];
};
struct linux_msgsnd_args {
	char msqid_l_[PADL_(l_int)]; l_int msqid; char msqid_r_[PADR_(l_int)];
	char msgp_l_[PADL_(struct l_msgbuf *)]; struct l_msgbuf * msgp; char msgp_r_[PADR_(struct l_msgbuf *)];
	char msgsz_l_[PADL_(l_size_t)]; l_size_t msgsz; char msgsz_r_[PADR_(l_size_t)];
	char msgflg_l_[PADL_(l_int)]; l_int msgflg; char msgflg_r_[PADR_(l_int)];
};
struct linux_msgrcv_args {
	char msqid_l_[PADL_(l_int)]; l_int msqid; char msqid_r_[PADR_(l_int)];
	char msgp_l_[PADL_(struct l_msgbuf *)]; struct l_msgbuf * msgp; char msgp_r_[PADR_(struct l_msgbuf *)];
	char msgsz_l_[PADL_(l_size_t)]; l_size_t msgsz; char msgsz_r_[PADR_(l_size_t)];
	char msgtyp_l_[PADL_(l_long)]; l_long msgtyp; char msgtyp_r_[PADR_(l_long)];
	char msgflg_l_[PADL_(l_int)]; l_int msgflg; char msgflg_r_[PADR_(l_int)];
};
struct linux_msgctl_args {
	char msqid_l_[PADL_(l_int)]; l_int msqid; char msqid_r_[PADR_(l_int)];
	char cmd_l_[PADL_(l_int)]; l_int cmd; char cmd_r_[PADR_(l_int)];
	char buf_l_[PADL_(struct l_msqid_ds *)]; struct l_msqid_ds * buf; char buf_r_[PADR_(struct l_msqid_ds *)];
};
struct linux_clock_gettime64_args {
	register_t dummy;
};
struct linux_clock_settime64_args {
	register_t dummy;
};
struct linux_clock_adjtime64_args {
	register_t dummy;
};
struct linux_clock_getres_time64_args {
	register_t dummy;
};
struct linux_clock_nanosleep_time64_args {
	register_t dummy;
};
struct linux_timer_gettime64_args {
	register_t dummy;
};
struct linux_timer_settime64_args {
	register_t dummy;
};
struct linux_timerfd_gettime64_args {
	register_t dummy;
};
struct linux_timerfd_settime64_args {
	register_t dummy;
};
struct linux_utimensat_time64_args {
	register_t dummy;
};
struct linux_pselect6_time64_args {
	register_t dummy;
};
struct linux_ppoll_time64_args {
	register_t dummy;
};
struct linux_io_pgetevents_time64_args {
	register_t dummy;
};
struct linux_recvmmsg_time64_args {
	register_t dummy;
};
struct linux_mq_timedsend_time64_args {
	register_t dummy;
};
struct linux_mq_timedreceive_time64_args {
	register_t dummy;
};
struct linux_semtimedop_time64_args {
	register_t dummy;
};
struct linux_rt_sigtimedwait_time64_args {
	register_t dummy;
};
struct linux_futex_time64_args {
	register_t dummy;
};
struct linux_sched_rr_get_interval_time64_args {
	register_t dummy;
};
struct linux_pidfd_send_signal_args {
	char pidfd_l_[PADL_(l_int)]; l_int pidfd; char pidfd_r_[PADR_(l_int)];
	char sig_l_[PADL_(l_int)]; l_int sig; char sig_r_[PADR_(l_int)];
	char info_l_[PADL_(l_siginfo_t *)]; l_siginfo_t * info; char info_r_[PADR_(l_siginfo_t *)];
	char flags_l_[PADL_(l_uint)]; l_uint flags; char flags_r_[PADR_(l_uint)];
};
struct linux_io_uring_setup_args {
	register_t dummy;
};
struct linux_io_uring_enter_args {
	register_t dummy;
};
struct linux_io_uring_register_args {
	register_t dummy;
};
#define	nosys	linux_nosys
int	linux_exit(struct thread *, struct linux_exit_args *);
int	linux_fork(struct thread *, struct linux_fork_args *);
int	linux_open(struct thread *, struct linux_open_args *);
int	linux_waitpid(struct thread *, struct linux_waitpid_args *);
int	linux_creat(struct thread *, struct linux_creat_args *);
int	linux_link(struct thread *, struct linux_link_args *);
int	linux_unlink(struct thread *, struct linux_unlink_args *);
int	linux_execve(struct thread *, struct linux_execve_args *);
int	linux_chdir(struct thread *, struct linux_chdir_args *);
int	linux_time(struct thread *, struct linux_time_args *);
int	linux_mknod(struct thread *, struct linux_mknod_args *);
int	linux_chmod(struct thread *, struct linux_chmod_args *);
int	linux_lchown16(struct thread *, struct linux_lchown16_args *);
int	linux_stat(struct thread *, struct linux_stat_args *);
int	linux_lseek(struct thread *, struct linux_lseek_args *);
int	linux_getpid(struct thread *, struct linux_getpid_args *);
int	linux_mount(struct thread *, struct linux_mount_args *);
int	linux_oldumount(struct thread *, struct linux_oldumount_args *);
int	linux_setuid16(struct thread *, struct linux_setuid16_args *);
int	linux_getuid16(struct thread *, struct linux_getuid16_args *);
int	linux_stime(struct thread *, struct linux_stime_args *);
int	linux_ptrace(struct thread *, struct linux_ptrace_args *);
int	linux_alarm(struct thread *, struct linux_alarm_args *);
int	linux_pause(struct thread *, struct linux_pause_args *);
int	linux_utime(struct thread *, struct linux_utime_args *);
int	linux_access(struct thread *, struct linux_access_args *);
int	linux_nice(struct thread *, struct linux_nice_args *);
int	linux_kill(struct thread *, struct linux_kill_args *);
int	linux_rename(struct thread *, struct linux_rename_args *);
int	linux_mkdir(struct thread *, struct linux_mkdir_args *);
int	linux_rmdir(struct thread *, struct linux_rmdir_args *);
int	linux_pipe(struct thread *, struct linux_pipe_args *);
int	linux_times(struct thread *, struct linux_times_args *);
int	linux_brk(struct thread *, struct linux_brk_args *);
int	linux_setgid16(struct thread *, struct linux_setgid16_args *);
int	linux_getgid16(struct thread *, struct linux_getgid16_args *);
int	linux_signal(struct thread *, struct linux_signal_args *);
int	linux_geteuid16(struct thread *, struct linux_geteuid16_args *);
int	linux_getegid16(struct thread *, struct linux_getegid16_args *);
int	linux_umount(struct thread *, struct linux_umount_args *);
int	linux_ioctl(struct thread *, struct linux_ioctl_args *);
int	linux_fcntl(struct thread *, struct linux_fcntl_args *);
int	linux_olduname(struct thread *, struct linux_olduname_args *);
int	linux_ustat(struct thread *, struct linux_ustat_args *);
int	linux_getppid(struct thread *, struct linux_getppid_args *);
int	linux_sigaction(struct thread *, struct linux_sigaction_args *);
int	linux_sgetmask(struct thread *, struct linux_sgetmask_args *);
int	linux_ssetmask(struct thread *, struct linux_ssetmask_args *);
int	linux_setreuid16(struct thread *, struct linux_setreuid16_args *);
int	linux_setregid16(struct thread *, struct linux_setregid16_args *);
int	linux_sigsuspend(struct thread *, struct linux_sigsuspend_args *);
int	linux_sigpending(struct thread *, struct linux_sigpending_args *);
int	linux_sethostname(struct thread *, struct linux_sethostname_args *);
int	linux_setrlimit(struct thread *, struct linux_setrlimit_args *);
int	linux_old_getrlimit(struct thread *, struct linux_old_getrlimit_args *);
int	linux_getrusage(struct thread *, struct linux_getrusage_args *);
int	linux_gettimeofday(struct thread *, struct linux_gettimeofday_args *);
int	linux_settimeofday(struct thread *, struct linux_settimeofday_args *);
int	linux_getgroups16(struct thread *, struct linux_getgroups16_args *);
int	linux_setgroups16(struct thread *, struct linux_setgroups16_args *);
int	linux_old_select(struct thread *, struct linux_old_select_args *);
int	linux_symlink(struct thread *, struct linux_symlink_args *);
int	linux_lstat(struct thread *, struct linux_lstat_args *);
int	linux_readlink(struct thread *, struct linux_readlink_args *);
int	linux_reboot(struct thread *, struct linux_reboot_args *);
int	linux_readdir(struct thread *, struct linux_readdir_args *);
int	linux_mmap(struct thread *, struct linux_mmap_args *);
int	linux_truncate(struct thread *, struct linux_truncate_args *);
int	linux_ftruncate(struct thread *, struct linux_ftruncate_args *);
int	linux_getpriority(struct thread *, struct linux_getpriority_args *);
int	linux_statfs(struct thread *, struct linux_statfs_args *);
int	linux_fstatfs(struct thread *, struct linux_fstatfs_args *);
int	linux_socketcall(struct thread *, struct linux_socketcall_args *);
int	linux_syslog(struct thread *, struct linux_syslog_args *);
int	linux_setitimer(struct thread *, struct linux_setitimer_args *);
int	linux_getitimer(struct thread *, struct linux_getitimer_args *);
int	linux_newstat(struct thread *, struct linux_newstat_args *);
int	linux_newlstat(struct thread *, struct linux_newlstat_args *);
int	linux_newfstat(struct thread *, struct linux_newfstat_args *);
int	linux_uname(struct thread *, struct linux_uname_args *);
int	linux_iopl(struct thread *, struct linux_iopl_args *);
int	linux_vhangup(struct thread *, struct linux_vhangup_args *);
int	linux_wait4(struct thread *, struct linux_wait4_args *);
int	linux_swapoff(struct thread *, struct linux_swapoff_args *);
int	linux_sysinfo(struct thread *, struct linux_sysinfo_args *);
int	linux_ipc(struct thread *, struct linux_ipc_args *);
int	linux_sigreturn(struct thread *, struct linux_sigreturn_args *);
int	linux_clone(struct thread *, struct linux_clone_args *);
int	linux_setdomainname(struct thread *, struct linux_setdomainname_args *);
int	linux_newuname(struct thread *, struct linux_newuname_args *);
int	linux_adjtimex(struct thread *, struct linux_adjtimex_args *);
int	linux_mprotect(struct thread *, struct linux_mprotect_args *);
int	linux_sigprocmask(struct thread *, struct linux_sigprocmask_args *);
int	linux_init_module(struct thread *, struct linux_init_module_args *);
int	linux_delete_module(struct thread *, struct linux_delete_module_args *);
int	linux_quotactl(struct thread *, struct linux_quotactl_args *);
int	linux_bdflush(struct thread *, struct linux_bdflush_args *);
int	linux_sysfs(struct thread *, struct linux_sysfs_args *);
int	linux_personality(struct thread *, struct linux_personality_args *);
int	linux_setfsuid16(struct thread *, struct linux_setfsuid16_args *);
int	linux_setfsgid16(struct thread *, struct linux_setfsgid16_args *);
int	linux_llseek(struct thread *, struct linux_llseek_args *);
int	linux_getdents(struct thread *, struct linux_getdents_args *);
int	linux_select(struct thread *, struct linux_select_args *);
int	linux_msync(struct thread *, struct linux_msync_args *);
int	linux_readv(struct thread *, struct linux_readv_args *);
int	linux_writev(struct thread *, struct linux_writev_args *);
int	linux_getsid(struct thread *, struct linux_getsid_args *);
int	linux_fdatasync(struct thread *, struct linux_fdatasync_args *);
int	linux_sysctl(struct thread *, struct linux_sysctl_args *);
int	linux_sched_setparam(struct thread *, struct linux_sched_setparam_args *);
int	linux_sched_getparam(struct thread *, struct linux_sched_getparam_args *);
int	linux_sched_setscheduler(struct thread *, struct linux_sched_setscheduler_args *);
int	linux_sched_getscheduler(struct thread *, struct linux_sched_getscheduler_args *);
int	linux_sched_get_priority_max(struct thread *, struct linux_sched_get_priority_max_args *);
int	linux_sched_get_priority_min(struct thread *, struct linux_sched_get_priority_min_args *);
int	linux_sched_rr_get_interval(struct thread *, struct linux_sched_rr_get_interval_args *);
int	linux_nanosleep(struct thread *, struct linux_nanosleep_args *);
int	linux_mremap(struct thread *, struct linux_mremap_args *);
int	linux_setresuid16(struct thread *, struct linux_setresuid16_args *);
int	linux_getresuid16(struct thread *, struct linux_getresuid16_args *);
int	linux_setresgid16(struct thread *, struct linux_setresgid16_args *);
int	linux_getresgid16(struct thread *, struct linux_getresgid16_args *);
int	linux_prctl(struct thread *, struct linux_prctl_args *);
int	linux_rt_sigreturn(struct thread *, struct linux_rt_sigreturn_args *);
int	linux_rt_sigaction(struct thread *, struct linux_rt_sigaction_args *);
int	linux_rt_sigprocmask(struct thread *, struct linux_rt_sigprocmask_args *);
int	linux_rt_sigpending(struct thread *, struct linux_rt_sigpending_args *);
int	linux_rt_sigtimedwait(struct thread *, struct linux_rt_sigtimedwait_args *);
int	linux_rt_sigqueueinfo(struct thread *, struct linux_rt_sigqueueinfo_args *);
int	linux_rt_sigsuspend(struct thread *, struct linux_rt_sigsuspend_args *);
int	linux_pread(struct thread *, struct linux_pread_args *);
int	linux_pwrite(struct thread *, struct linux_pwrite_args *);
int	linux_chown16(struct thread *, struct linux_chown16_args *);
int	linux_getcwd(struct thread *, struct linux_getcwd_args *);
int	linux_capget(struct thread *, struct linux_capget_args *);
int	linux_capset(struct thread *, struct linux_capset_args *);
int	linux_sigaltstack(struct thread *, struct linux_sigaltstack_args *);
int	linux_sendfile(struct thread *, struct linux_sendfile_args *);
int	linux_vfork(struct thread *, struct linux_vfork_args *);
int	linux_getrlimit(struct thread *, struct linux_getrlimit_args *);
int	linux_mmap2(struct thread *, struct linux_mmap2_args *);
int	linux_truncate64(struct thread *, struct linux_truncate64_args *);
int	linux_ftruncate64(struct thread *, struct linux_ftruncate64_args *);
int	linux_stat64(struct thread *, struct linux_stat64_args *);
int	linux_lstat64(struct thread *, struct linux_lstat64_args *);
int	linux_fstat64(struct thread *, struct linux_fstat64_args *);
int	linux_lchown(struct thread *, struct linux_lchown_args *);
int	linux_getuid(struct thread *, struct linux_getuid_args *);
int	linux_getgid(struct thread *, struct linux_getgid_args *);
int	linux_getgroups(struct thread *, struct linux_getgroups_args *);
int	linux_setgroups(struct thread *, struct linux_setgroups_args *);
int	linux_chown(struct thread *, struct linux_chown_args *);
int	linux_setfsuid(struct thread *, struct linux_setfsuid_args *);
int	linux_setfsgid(struct thread *, struct linux_setfsgid_args *);
int	linux_pivot_root(struct thread *, struct linux_pivot_root_args *);
int	linux_mincore(struct thread *, struct linux_mincore_args *);
int	linux_getdents64(struct thread *, struct linux_getdents64_args *);
int	linux_fcntl64(struct thread *, struct linux_fcntl64_args *);
int	linux_gettid(struct thread *, struct linux_gettid_args *);
int	linux_setxattr(struct thread *, struct linux_setxattr_args *);
int	linux_lsetxattr(struct thread *, struct linux_lsetxattr_args *);
int	linux_fsetxattr(struct thread *, struct linux_fsetxattr_args *);
int	linux_getxattr(struct thread *, struct linux_getxattr_args *);
int	linux_lgetxattr(struct thread *, struct linux_lgetxattr_args *);
int	linux_fgetxattr(struct thread *, struct linux_fgetxattr_args *);
int	linux_listxattr(struct thread *, struct linux_listxattr_args *);
int	linux_llistxattr(struct thread *, struct linux_llistxattr_args *);
int	linux_flistxattr(struct thread *, struct linux_flistxattr_args *);
int	linux_removexattr(struct thread *, struct linux_removexattr_args *);
int	linux_lremovexattr(struct thread *, struct linux_lremovexattr_args *);
int	linux_fremovexattr(struct thread *, struct linux_fremovexattr_args *);
int	linux_tkill(struct thread *, struct linux_tkill_args *);
int	linux_sys_futex(struct thread *, struct linux_sys_futex_args *);
int	linux_sched_setaffinity(struct thread *, struct linux_sched_setaffinity_args *);
int	linux_sched_getaffinity(struct thread *, struct linux_sched_getaffinity_args *);
int	linux_set_thread_area(struct thread *, struct linux_set_thread_area_args *);
int	linux_fadvise64(struct thread *, struct linux_fadvise64_args *);
int	linux_exit_group(struct thread *, struct linux_exit_group_args *);
int	linux_lookup_dcookie(struct thread *, struct linux_lookup_dcookie_args *);
int	linux_epoll_create(struct thread *, struct linux_epoll_create_args *);
int	linux_epoll_ctl(struct thread *, struct linux_epoll_ctl_args *);
int	linux_epoll_wait(struct thread *, struct linux_epoll_wait_args *);
int	linux_remap_file_pages(struct thread *, struct linux_remap_file_pages_args *);
int	linux_set_tid_address(struct thread *, struct linux_set_tid_address_args *);
int	linux_timer_create(struct thread *, struct linux_timer_create_args *);
int	linux_timer_settime(struct thread *, struct linux_timer_settime_args *);
int	linux_timer_gettime(struct thread *, struct linux_timer_gettime_args *);
int	linux_timer_getoverrun(struct thread *, struct linux_timer_getoverrun_args *);
int	linux_timer_delete(struct thread *, struct linux_timer_delete_args *);
int	linux_clock_settime(struct thread *, struct linux_clock_settime_args *);
int	linux_clock_gettime(struct thread *, struct linux_clock_gettime_args *);
int	linux_clock_getres(struct thread *, struct linux_clock_getres_args *);
int	linux_clock_nanosleep(struct thread *, struct linux_clock_nanosleep_args *);
int	linux_statfs64(struct thread *, struct linux_statfs64_args *);
int	linux_fstatfs64(struct thread *, struct linux_fstatfs64_args *);
int	linux_tgkill(struct thread *, struct linux_tgkill_args *);
int	linux_utimes(struct thread *, struct linux_utimes_args *);
int	linux_fadvise64_64(struct thread *, struct linux_fadvise64_64_args *);
int	linux_mbind(struct thread *, struct linux_mbind_args *);
int	linux_get_mempolicy(struct thread *, struct linux_get_mempolicy_args *);
int	linux_set_mempolicy(struct thread *, struct linux_set_mempolicy_args *);
int	linux_mq_open(struct thread *, struct linux_mq_open_args *);
int	linux_mq_unlink(struct thread *, struct linux_mq_unlink_args *);
int	linux_mq_timedsend(struct thread *, struct linux_mq_timedsend_args *);
int	linux_mq_timedreceive(struct thread *, struct linux_mq_timedreceive_args *);
int	linux_mq_notify(struct thread *, struct linux_mq_notify_args *);
int	linux_mq_getsetattr(struct thread *, struct linux_mq_getsetattr_args *);
int	linux_kexec_load(struct thread *, struct linux_kexec_load_args *);
int	linux_waitid(struct thread *, struct linux_waitid_args *);
int	linux_add_key(struct thread *, struct linux_add_key_args *);
int	linux_request_key(struct thread *, struct linux_request_key_args *);
int	linux_keyctl(struct thread *, struct linux_keyctl_args *);
int	linux_ioprio_set(struct thread *, struct linux_ioprio_set_args *);
int	linux_ioprio_get(struct thread *, struct linux_ioprio_get_args *);
int	linux_inotify_init(struct thread *, struct linux_inotify_init_args *);
int	linux_inotify_add_watch(struct thread *, struct linux_inotify_add_watch_args *);
int	linux_inotify_rm_watch(struct thread *, struct linux_inotify_rm_watch_args *);
int	linux_migrate_pages(struct thread *, struct linux_migrate_pages_args *);
int	linux_openat(struct thread *, struct linux_openat_args *);
int	linux_mkdirat(struct thread *, struct linux_mkdirat_args *);
int	linux_mknodat(struct thread *, struct linux_mknodat_args *);
int	linux_fchownat(struct thread *, struct linux_fchownat_args *);
int	linux_futimesat(struct thread *, struct linux_futimesat_args *);
int	linux_fstatat64(struct thread *, struct linux_fstatat64_args *);
int	linux_unlinkat(struct thread *, struct linux_unlinkat_args *);
int	linux_renameat(struct thread *, struct linux_renameat_args *);
int	linux_linkat(struct thread *, struct linux_linkat_args *);
int	linux_symlinkat(struct thread *, struct linux_symlinkat_args *);
int	linux_readlinkat(struct thread *, struct linux_readlinkat_args *);
int	linux_fchmodat(struct thread *, struct linux_fchmodat_args *);
int	linux_faccessat(struct thread *, struct linux_faccessat_args *);
int	linux_pselect6(struct thread *, struct linux_pselect6_args *);
int	linux_ppoll(struct thread *, struct linux_ppoll_args *);
int	linux_unshare(struct thread *, struct linux_unshare_args *);
int	linux_set_robust_list(struct thread *, struct linux_set_robust_list_args *);
int	linux_get_robust_list(struct thread *, struct linux_get_robust_list_args *);
int	linux_splice(struct thread *, struct linux_splice_args *);
int	linux_sync_file_range(struct thread *, struct linux_sync_file_range_args *);
int	linux_tee(struct thread *, struct linux_tee_args *);
int	linux_vmsplice(struct thread *, struct linux_vmsplice_args *);
int	linux_move_pages(struct thread *, struct linux_move_pages_args *);
int	linux_getcpu(struct thread *, struct linux_getcpu_args *);
int	linux_epoll_pwait(struct thread *, struct linux_epoll_pwait_args *);
int	linux_utimensat(struct thread *, struct linux_utimensat_args *);
int	linux_signalfd(struct thread *, struct linux_signalfd_args *);
int	linux_timerfd_create(struct thread *, struct linux_timerfd_create_args *);
int	linux_eventfd(struct thread *, struct linux_eventfd_args *);
int	linux_fallocate(struct thread *, struct linux_fallocate_args *);
int	linux_timerfd_settime(struct thread *, struct linux_timerfd_settime_args *);
int	linux_timerfd_gettime(struct thread *, struct linux_timerfd_gettime_args *);
int	linux_signalfd4(struct thread *, struct linux_signalfd4_args *);
int	linux_eventfd2(struct thread *, struct linux_eventfd2_args *);
int	linux_epoll_create1(struct thread *, struct linux_epoll_create1_args *);
int	linux_dup3(struct thread *, struct linux_dup3_args *);
int	linux_pipe2(struct thread *, struct linux_pipe2_args *);
int	linux_inotify_init1(struct thread *, struct linux_inotify_init1_args *);
int	linux_preadv(struct thread *, struct linux_preadv_args *);
int	linux_pwritev(struct thread *, struct linux_pwritev_args *);
int	linux_rt_tgsigqueueinfo(struct thread *, struct linux_rt_tgsigqueueinfo_args *);
int	linux_perf_event_open(struct thread *, struct linux_perf_event_open_args *);
int	linux_recvmmsg(struct thread *, struct linux_recvmmsg_args *);
int	linux_fanotify_init(struct thread *, struct linux_fanotify_init_args *);
int	linux_fanotify_mark(struct thread *, struct linux_fanotify_mark_args *);
int	linux_prlimit64(struct thread *, struct linux_prlimit64_args *);
int	linux_name_to_handle_at(struct thread *, struct linux_name_to_handle_at_args *);
int	linux_open_by_handle_at(struct thread *, struct linux_open_by_handle_at_args *);
int	linux_clock_adjtime(struct thread *, struct linux_clock_adjtime_args *);
int	linux_syncfs(struct thread *, struct linux_syncfs_args *);
int	linux_sendmmsg(struct thread *, struct linux_sendmmsg_args *);
int	linux_setns(struct thread *, struct linux_setns_args *);
int	linux_process_vm_readv(struct thread *, struct linux_process_vm_readv_args *);
int	linux_process_vm_writev(struct thread *, struct linux_process_vm_writev_args *);
int	linux_kcmp(struct thread *, struct linux_kcmp_args *);
int	linux_finit_module(struct thread *, struct linux_finit_module_args *);
int	linux_sched_setattr(struct thread *, struct linux_sched_setattr_args *);
int	linux_sched_getattr(struct thread *, struct linux_sched_getattr_args *);
int	linux_renameat2(struct thread *, struct linux_renameat2_args *);
int	linux_seccomp(struct thread *, struct linux_seccomp_args *);
int	linux_getrandom(struct thread *, struct linux_getrandom_args *);
int	linux_memfd_create(struct thread *, struct linux_memfd_create_args *);
int	linux_bpf(struct thread *, struct linux_bpf_args *);
int	linux_execveat(struct thread *, struct linux_execveat_args *);
int	linux_socket(struct thread *, struct linux_socket_args *);
int	linux_socketpair(struct thread *, struct linux_socketpair_args *);
int	linux_bind(struct thread *, struct linux_bind_args *);
int	linux_connect(struct thread *, struct linux_connect_args *);
int	linux_listen(struct thread *, struct linux_listen_args *);
int	linux_accept4(struct thread *, struct linux_accept4_args *);
int	linux_getsockopt(struct thread *, struct linux_getsockopt_args *);
int	linux_setsockopt(struct thread *, struct linux_setsockopt_args *);
int	linux_getsockname(struct thread *, struct linux_getsockname_args *);
int	linux_getpeername(struct thread *, struct linux_getpeername_args *);
int	linux_sendto(struct thread *, struct linux_sendto_args *);
int	linux_sendmsg(struct thread *, struct linux_sendmsg_args *);
int	linux_recvfrom(struct thread *, struct linux_recvfrom_args *);
int	linux_recvmsg(struct thread *, struct linux_recvmsg_args *);
int	linux_shutdown(struct thread *, struct linux_shutdown_args *);
int	linux_userfaultfd(struct thread *, struct linux_userfaultfd_args *);
int	linux_membarrier(struct thread *, struct linux_membarrier_args *);
int	linux_mlock2(struct thread *, struct linux_mlock2_args *);
int	linux_copy_file_range(struct thread *, struct linux_copy_file_range_args *);
int	linux_preadv2(struct thread *, struct linux_preadv2_args *);
int	linux_pwritev2(struct thread *, struct linux_pwritev2_args *);
int	linux_pkey_mprotect(struct thread *, struct linux_pkey_mprotect_args *);
int	linux_pkey_alloc(struct thread *, struct linux_pkey_alloc_args *);
int	linux_pkey_free(struct thread *, struct linux_pkey_free_args *);
int	linux_statx(struct thread *, struct linux_statx_args *);
int	linux_arch_prctl(struct thread *, struct linux_arch_prctl_args *);
int	linux_io_pgetevents(struct thread *, struct linux_io_pgetevents_args *);
int	linux_rseq(struct thread *, struct linux_rseq_args *);
int	linux_semget(struct thread *, struct linux_semget_args *);
int	linux_semctl(struct thread *, struct linux_semctl_args *);
int	linux_shmget(struct thread *, struct linux_shmget_args *);
int	linux_shmctl(struct thread *, struct linux_shmctl_args *);
int	linux_shmat(struct thread *, struct linux_shmat_args *);
int	linux_shmdt(struct thread *, struct linux_shmdt_args *);
int	linux_msgget(struct thread *, struct linux_msgget_args *);
int	linux_msgsnd(struct thread *, struct linux_msgsnd_args *);
int	linux_msgrcv(struct thread *, struct linux_msgrcv_args *);
int	linux_msgctl(struct thread *, struct linux_msgctl_args *);
int	linux_clock_gettime64(struct thread *, struct linux_clock_gettime64_args *);
int	linux_clock_settime64(struct thread *, struct linux_clock_settime64_args *);
int	linux_clock_adjtime64(struct thread *, struct linux_clock_adjtime64_args *);
int	linux_clock_getres_time64(struct thread *, struct linux_clock_getres_time64_args *);
int	linux_clock_nanosleep_time64(struct thread *, struct linux_clock_nanosleep_time64_args *);
int	linux_timer_gettime64(struct thread *, struct linux_timer_gettime64_args *);
int	linux_timer_settime64(struct thread *, struct linux_timer_settime64_args *);
int	linux_timerfd_gettime64(struct thread *, struct linux_timerfd_gettime64_args *);
int	linux_timerfd_settime64(struct thread *, struct linux_timerfd_settime64_args *);
int	linux_utimensat_time64(struct thread *, struct linux_utimensat_time64_args *);
int	linux_pselect6_time64(struct thread *, struct linux_pselect6_time64_args *);
int	linux_ppoll_time64(struct thread *, struct linux_ppoll_time64_args *);
int	linux_io_pgetevents_time64(struct thread *, struct linux_io_pgetevents_time64_args *);
int	linux_recvmmsg_time64(struct thread *, struct linux_recvmmsg_time64_args *);
int	linux_mq_timedsend_time64(struct thread *, struct linux_mq_timedsend_time64_args *);
int	linux_mq_timedreceive_time64(struct thread *, struct linux_mq_timedreceive_time64_args *);
int	linux_semtimedop_time64(struct thread *, struct linux_semtimedop_time64_args *);
int	linux_rt_sigtimedwait_time64(struct thread *, struct linux_rt_sigtimedwait_time64_args *);
int	linux_futex_time64(struct thread *, struct linux_futex_time64_args *);
int	linux_sched_rr_get_interval_time64(struct thread *, struct linux_sched_rr_get_interval_time64_args *);
int	linux_pidfd_send_signal(struct thread *, struct linux_pidfd_send_signal_args *);
int	linux_io_uring_setup(struct thread *, struct linux_io_uring_setup_args *);
int	linux_io_uring_enter(struct thread *, struct linux_io_uring_enter_args *);
int	linux_io_uring_register(struct thread *, struct linux_io_uring_register_args *);

#ifdef COMPAT_43

#define	nosys	linux_nosys

#endif /* COMPAT_43 */


#ifdef COMPAT_FREEBSD4

#define	nosys	linux_nosys

#endif /* COMPAT_FREEBSD4 */


#ifdef COMPAT_FREEBSD6

#define	nosys	linux_nosys

#endif /* COMPAT_FREEBSD6 */


#ifdef COMPAT_FREEBSD7

#define	nosys	linux_nosys

#endif /* COMPAT_FREEBSD7 */


#ifdef COMPAT_FREEBSD10

#define	nosys	linux_nosys

#endif /* COMPAT_FREEBSD10 */


#ifdef COMPAT_FREEBSD11

#define	nosys	linux_nosys

#endif /* COMPAT_FREEBSD11 */

#define	LINUX32_SYS_AUE_linux_exit	AUE_EXIT
#define	LINUX32_SYS_AUE_linux_fork	AUE_FORK
#define	LINUX32_SYS_AUE_linux_open	AUE_OPEN_RWTC
#define	LINUX32_SYS_AUE_linux_waitpid	AUE_WAIT4
#define	LINUX32_SYS_AUE_linux_creat	AUE_CREAT
#define	LINUX32_SYS_AUE_linux_link	AUE_LINK
#define	LINUX32_SYS_AUE_linux_unlink	AUE_UNLINK
#define	LINUX32_SYS_AUE_linux_execve	AUE_EXECVE
#define	LINUX32_SYS_AUE_linux_chdir	AUE_CHDIR
#define	LINUX32_SYS_AUE_linux_time	AUE_NULL
#define	LINUX32_SYS_AUE_linux_mknod	AUE_MKNOD
#define	LINUX32_SYS_AUE_linux_chmod	AUE_CHMOD
#define	LINUX32_SYS_AUE_linux_lchown16	AUE_LCHOWN
#define	LINUX32_SYS_AUE_linux_stat	AUE_STAT
#define	LINUX32_SYS_AUE_linux_lseek	AUE_LSEEK
#define	LINUX32_SYS_AUE_linux_getpid	AUE_GETPID
#define	LINUX32_SYS_AUE_linux_mount	AUE_MOUNT
#define	LINUX32_SYS_AUE_linux_oldumount	AUE_UMOUNT
#define	LINUX32_SYS_AUE_linux_setuid16	AUE_SETUID
#define	LINUX32_SYS_AUE_linux_getuid16	AUE_GETUID
#define	LINUX32_SYS_AUE_linux_stime	AUE_SETTIMEOFDAY
#define	LINUX32_SYS_AUE_linux_ptrace	AUE_PTRACE
#define	LINUX32_SYS_AUE_linux_alarm	AUE_NULL
#define	LINUX32_SYS_AUE_linux_pause	AUE_NULL
#define	LINUX32_SYS_AUE_linux_utime	AUE_UTIME
#define	LINUX32_SYS_AUE_linux_access	AUE_ACCESS
#define	LINUX32_SYS_AUE_linux_nice	AUE_NICE
#define	LINUX32_SYS_AUE_linux_kill	AUE_KILL
#define	LINUX32_SYS_AUE_linux_rename	AUE_RENAME
#define	LINUX32_SYS_AUE_linux_mkdir	AUE_MKDIR
#define	LINUX32_SYS_AUE_linux_rmdir	AUE_RMDIR
#define	LINUX32_SYS_AUE_linux_pipe	AUE_PIPE
#define	LINUX32_SYS_AUE_linux_times	AUE_NULL
#define	LINUX32_SYS_AUE_linux_brk	AUE_NULL
#define	LINUX32_SYS_AUE_linux_setgid16	AUE_SETGID
#define	LINUX32_SYS_AUE_linux_getgid16	AUE_GETGID
#define	LINUX32_SYS_AUE_linux_signal	AUE_NULL
#define	LINUX32_SYS_AUE_linux_geteuid16	AUE_GETEUID
#define	LINUX32_SYS_AUE_linux_getegid16	AUE_GETEGID
#define	LINUX32_SYS_AUE_linux_umount	AUE_UMOUNT
#define	LINUX32_SYS_AUE_linux_ioctl	AUE_IOCTL
#define	LINUX32_SYS_AUE_linux_fcntl	AUE_FCNTL
#define	LINUX32_SYS_AUE_linux_olduname	AUE_NULL
#define	LINUX32_SYS_AUE_linux_ustat	AUE_NULL
#define	LINUX32_SYS_AUE_linux_getppid	AUE_GETPPID
#define	LINUX32_SYS_AUE_linux_sigaction	AUE_NULL
#define	LINUX32_SYS_AUE_linux_sgetmask	AUE_NULL
#define	LINUX32_SYS_AUE_linux_ssetmask	AUE_NULL
#define	LINUX32_SYS_AUE_linux_setreuid16	AUE_SETREUID
#define	LINUX32_SYS_AUE_linux_setregid16	AUE_SETREGID
#define	LINUX32_SYS_AUE_linux_sigsuspend	AUE_NULL
#define	LINUX32_SYS_AUE_linux_sigpending	AUE_NULL
#define	LINUX32_SYS_AUE_linux_sethostname	AUE_SYSCTL
#define	LINUX32_SYS_AUE_linux_setrlimit	AUE_SETRLIMIT
#define	LINUX32_SYS_AUE_linux_old_getrlimit	AUE_GETRLIMIT
#define	LINUX32_SYS_AUE_linux_getrusage	AUE_GETRUSAGE
#define	LINUX32_SYS_AUE_linux_gettimeofday	AUE_NULL
#define	LINUX32_SYS_AUE_linux_settimeofday	AUE_SETTIMEOFDAY
#define	LINUX32_SYS_AUE_linux_getgroups16	AUE_GETGROUPS
#define	LINUX32_SYS_AUE_linux_setgroups16	AUE_SETGROUPS
#define	LINUX32_SYS_AUE_linux_old_select	AUE_SELECT
#define	LINUX32_SYS_AUE_linux_symlink	AUE_SYMLINK
#define	LINUX32_SYS_AUE_linux_lstat	AUE_LSTAT
#define	LINUX32_SYS_AUE_linux_readlink	AUE_READLINK
#define	LINUX32_SYS_AUE_linux_reboot	AUE_REBOOT
#define	LINUX32_SYS_AUE_linux_readdir	AUE_GETDIRENTRIES
#define	LINUX32_SYS_AUE_linux_mmap	AUE_MMAP
#define	LINUX32_SYS_AUE_linux_truncate	AUE_TRUNCATE
#define	LINUX32_SYS_AUE_linux_ftruncate	AUE_FTRUNCATE
#define	LINUX32_SYS_AUE_linux_getpriority	AUE_GETPRIORITY
#define	LINUX32_SYS_AUE_linux_statfs	AUE_STATFS
#define	LINUX32_SYS_AUE_linux_fstatfs	AUE_FSTATFS
#define	LINUX32_SYS_AUE_linux_socketcall	AUE_NULL
#define	LINUX32_SYS_AUE_linux_syslog	AUE_NULL
#define	LINUX32_SYS_AUE_linux_setitimer	AUE_SETITIMER
#define	LINUX32_SYS_AUE_linux_getitimer	AUE_GETITIMER
#define	LINUX32_SYS_AUE_linux_newstat	AUE_STAT
#define	LINUX32_SYS_AUE_linux_newlstat	AUE_LSTAT
#define	LINUX32_SYS_AUE_linux_newfstat	AUE_FSTAT
#define	LINUX32_SYS_AUE_linux_uname	AUE_NULL
#define	LINUX32_SYS_AUE_linux_iopl	AUE_NULL
#define	LINUX32_SYS_AUE_linux_vhangup	AUE_NULL
#define	LINUX32_SYS_AUE_linux_wait4	AUE_WAIT4
#define	LINUX32_SYS_AUE_linux_swapoff	AUE_SWAPOFF
#define	LINUX32_SYS_AUE_linux_sysinfo	AUE_NULL
#define	LINUX32_SYS_AUE_linux_ipc	AUE_NULL
#define	LINUX32_SYS_AUE_linux_sigreturn	AUE_SIGRETURN
#define	LINUX32_SYS_AUE_linux_clone	AUE_RFORK
#define	LINUX32_SYS_AUE_linux_setdomainname	AUE_SYSCTL
#define	LINUX32_SYS_AUE_linux_newuname	AUE_NULL
#define	LINUX32_SYS_AUE_linux_adjtimex	AUE_ADJTIME
#define	LINUX32_SYS_AUE_linux_mprotect	AUE_MPROTECT
#define	LINUX32_SYS_AUE_linux_sigprocmask	AUE_SIGPROCMASK
#define	LINUX32_SYS_AUE_linux_init_module	AUE_NULL
#define	LINUX32_SYS_AUE_linux_delete_module	AUE_NULL
#define	LINUX32_SYS_AUE_linux_quotactl	AUE_QUOTACTL
#define	LINUX32_SYS_AUE_linux_bdflush	AUE_BDFLUSH
#define	LINUX32_SYS_AUE_linux_sysfs	AUE_NULL
#define	LINUX32_SYS_AUE_linux_personality	AUE_PERSONALITY
#define	LINUX32_SYS_AUE_linux_setfsuid16	AUE_SETFSUID
#define	LINUX32_SYS_AUE_linux_setfsgid16	AUE_SETFSGID
#define	LINUX32_SYS_AUE_linux_llseek	AUE_LSEEK
#define	LINUX32_SYS_AUE_linux_getdents	AUE_GETDIRENTRIES
#define	LINUX32_SYS_AUE_linux_select	AUE_SELECT
#define	LINUX32_SYS_AUE_linux_msync	AUE_MSYNC
#define	LINUX32_SYS_AUE_linux_readv	AUE_READV
#define	LINUX32_SYS_AUE_linux_writev	AUE_WRITEV
#define	LINUX32_SYS_AUE_linux_getsid	AUE_GETSID
#define	LINUX32_SYS_AUE_linux_fdatasync	AUE_NULL
#define	LINUX32_SYS_AUE_linux_sysctl	AUE_SYSCTL
#define	LINUX32_SYS_AUE_linux_sched_setparam	AUE_SCHED_SETPARAM
#define	LINUX32_SYS_AUE_linux_sched_getparam	AUE_SCHED_GETPARAM
#define	LINUX32_SYS_AUE_linux_sched_setscheduler	AUE_SCHED_SETSCHEDULER
#define	LINUX32_SYS_AUE_linux_sched_getscheduler	AUE_SCHED_GETSCHEDULER
#define	LINUX32_SYS_AUE_linux_sched_get_priority_max	AUE_SCHED_GET_PRIORITY_MAX
#define	LINUX32_SYS_AUE_linux_sched_get_priority_min	AUE_SCHED_GET_PRIORITY_MIN
#define	LINUX32_SYS_AUE_linux_sched_rr_get_interval	AUE_SCHED_RR_GET_INTERVAL
#define	LINUX32_SYS_AUE_linux_nanosleep	AUE_NULL
#define	LINUX32_SYS_AUE_linux_mremap	AUE_NULL
#define	LINUX32_SYS_AUE_linux_setresuid16	AUE_SETRESUID
#define	LINUX32_SYS_AUE_linux_getresuid16	AUE_GETRESUID
#define	LINUX32_SYS_AUE_linux_setresgid16	AUE_SETRESGID
#define	LINUX32_SYS_AUE_linux_getresgid16	AUE_GETRESGID
#define	LINUX32_SYS_AUE_linux_prctl	AUE_PRCTL
#define	LINUX32_SYS_AUE_linux_rt_sigreturn	AUE_NULL
#define	LINUX32_SYS_AUE_linux_rt_sigaction	AUE_NULL
#define	LINUX32_SYS_AUE_linux_rt_sigprocmask	AUE_NULL
#define	LINUX32_SYS_AUE_linux_rt_sigpending	AUE_NULL
#define	LINUX32_SYS_AUE_linux_rt_sigtimedwait	AUE_NULL
#define	LINUX32_SYS_AUE_linux_rt_sigqueueinfo	AUE_NULL
#define	LINUX32_SYS_AUE_linux_rt_sigsuspend	AUE_NULL
#define	LINUX32_SYS_AUE_linux_pread	AUE_PREAD
#define	LINUX32_SYS_AUE_linux_pwrite	AUE_PWRITE
#define	LINUX32_SYS_AUE_linux_chown16	AUE_CHOWN
#define	LINUX32_SYS_AUE_linux_getcwd	AUE_GETCWD
#define	LINUX32_SYS_AUE_linux_capget	AUE_CAPGET
#define	LINUX32_SYS_AUE_linux_capset	AUE_CAPSET
#define	LINUX32_SYS_AUE_linux_sigaltstack	AUE_NULL
#define	LINUX32_SYS_AUE_linux_sendfile	AUE_SENDFILE
#define	LINUX32_SYS_AUE_linux_vfork	AUE_VFORK
#define	LINUX32_SYS_AUE_linux_getrlimit	AUE_GETRLIMIT
#define	LINUX32_SYS_AUE_linux_mmap2	AUE_MMAP
#define	LINUX32_SYS_AUE_linux_truncate64	AUE_TRUNCATE
#define	LINUX32_SYS_AUE_linux_ftruncate64	AUE_FTRUNCATE
#define	LINUX32_SYS_AUE_linux_stat64	AUE_STAT
#define	LINUX32_SYS_AUE_linux_lstat64	AUE_LSTAT
#define	LINUX32_SYS_AUE_linux_fstat64	AUE_FSTAT
#define	LINUX32_SYS_AUE_linux_lchown	AUE_LCHOWN
#define	LINUX32_SYS_AUE_linux_getuid	AUE_GETUID
#define	LINUX32_SYS_AUE_linux_getgid	AUE_GETGID
#define	LINUX32_SYS_AUE_linux_getgroups	AUE_GETGROUPS
#define	LINUX32_SYS_AUE_linux_setgroups	AUE_SETGROUPS
#define	LINUX32_SYS_AUE_linux_chown	AUE_CHOWN
#define	LINUX32_SYS_AUE_linux_setfsuid	AUE_SETFSUID
#define	LINUX32_SYS_AUE_linux_setfsgid	AUE_SETFSGID
#define	LINUX32_SYS_AUE_linux_pivot_root	AUE_PIVOT_ROOT
#define	LINUX32_SYS_AUE_linux_mincore	AUE_MINCORE
#define	LINUX32_SYS_AUE_linux_getdents64	AUE_GETDIRENTRIES
#define	LINUX32_SYS_AUE_linux_fcntl64	AUE_FCNTL
#define	LINUX32_SYS_AUE_linux_gettid	AUE_NULL
#define	LINUX32_SYS_AUE_linux_setxattr	AUE_NULL
#define	LINUX32_SYS_AUE_linux_lsetxattr	AUE_NULL
#define	LINUX32_SYS_AUE_linux_fsetxattr	AUE_NULL
#define	LINUX32_SYS_AUE_linux_getxattr	AUE_NULL
#define	LINUX32_SYS_AUE_linux_lgetxattr	AUE_NULL
#define	LINUX32_SYS_AUE_linux_fgetxattr	AUE_NULL
#define	LINUX32_SYS_AUE_linux_listxattr	AUE_NULL
#define	LINUX32_SYS_AUE_linux_llistxattr	AUE_NULL
#define	LINUX32_SYS_AUE_linux_flistxattr	AUE_NULL
#define	LINUX32_SYS_AUE_linux_removexattr	AUE_NULL
#define	LINUX32_SYS_AUE_linux_lremovexattr	AUE_NULL
#define	LINUX32_SYS_AUE_linux_fremovexattr	AUE_NULL
#define	LINUX32_SYS_AUE_linux_tkill	AUE_NULL
#define	LINUX32_SYS_AUE_linux_sys_futex	AUE_NULL
#define	LINUX32_SYS_AUE_linux_sched_setaffinity	AUE_NULL
#define	LINUX32_SYS_AUE_linux_sched_getaffinity	AUE_NULL
#define	LINUX32_SYS_AUE_linux_set_thread_area	AUE_NULL
#define	LINUX32_SYS_AUE_linux_fadvise64	AUE_NULL
#define	LINUX32_SYS_AUE_linux_exit_group	AUE_EXIT
#define	LINUX32_SYS_AUE_linux_lookup_dcookie	AUE_NULL
#define	LINUX32_SYS_AUE_linux_epoll_create	AUE_NULL
#define	LINUX32_SYS_AUE_linux_epoll_ctl	AUE_NULL
#define	LINUX32_SYS_AUE_linux_epoll_wait	AUE_NULL
#define	LINUX32_SYS_AUE_linux_remap_file_pages	AUE_NULL
#define	LINUX32_SYS_AUE_linux_set_tid_address	AUE_NULL
#define	LINUX32_SYS_AUE_linux_timer_create	AUE_NULL
#define	LINUX32_SYS_AUE_linux_timer_settime	AUE_NULL
#define	LINUX32_SYS_AUE_linux_timer_gettime	AUE_NULL
#define	LINUX32_SYS_AUE_linux_timer_getoverrun	AUE_NULL
#define	LINUX32_SYS_AUE_linux_timer_delete	AUE_NULL
#define	LINUX32_SYS_AUE_linux_clock_settime	AUE_CLOCK_SETTIME
#define	LINUX32_SYS_AUE_linux_clock_gettime	AUE_NULL
#define	LINUX32_SYS_AUE_linux_clock_getres	AUE_NULL
#define	LINUX32_SYS_AUE_linux_clock_nanosleep	AUE_NULL
#define	LINUX32_SYS_AUE_linux_statfs64	AUE_STATFS
#define	LINUX32_SYS_AUE_linux_fstatfs64	AUE_FSTATFS
#define	LINUX32_SYS_AUE_linux_tgkill	AUE_NULL
#define	LINUX32_SYS_AUE_linux_utimes	AUE_UTIMES
#define	LINUX32_SYS_AUE_linux_fadvise64_64	AUE_NULL
#define	LINUX32_SYS_AUE_linux_mbind	AUE_NULL
#define	LINUX32_SYS_AUE_linux_get_mempolicy	AUE_NULL
#define	LINUX32_SYS_AUE_linux_set_mempolicy	AUE_NULL
#define	LINUX32_SYS_AUE_linux_mq_open	AUE_NULL
#define	LINUX32_SYS_AUE_linux_mq_unlink	AUE_NULL
#define	LINUX32_SYS_AUE_linux_mq_timedsend	AUE_NULL
#define	LINUX32_SYS_AUE_linux_mq_timedreceive	AUE_NULL
#define	LINUX32_SYS_AUE_linux_mq_notify	AUE_NULL
#define	LINUX32_SYS_AUE_linux_mq_getsetattr	AUE_NULL
#define	LINUX32_SYS_AUE_linux_kexec_load	AUE_NULL
#define	LINUX32_SYS_AUE_linux_waitid	AUE_WAIT6
#define	LINUX32_SYS_AUE_linux_add_key	AUE_NULL
#define	LINUX32_SYS_AUE_linux_request_key	AUE_NULL
#define	LINUX32_SYS_AUE_linux_keyctl	AUE_NULL
#define	LINUX32_SYS_AUE_linux_ioprio_set	AUE_NULL
#define	LINUX32_SYS_AUE_linux_ioprio_get	AUE_NULL
#define	LINUX32_SYS_AUE_linux_inotify_init	AUE_NULL
#define	LINUX32_SYS_AUE_linux_inotify_add_watch	AUE_NULL
#define	LINUX32_SYS_AUE_linux_inotify_rm_watch	AUE_NULL
#define	LINUX32_SYS_AUE_linux_migrate_pages	AUE_NULL
#define	LINUX32_SYS_AUE_linux_openat	AUE_OPEN_RWTC
#define	LINUX32_SYS_AUE_linux_mkdirat	AUE_MKDIRAT
#define	LINUX32_SYS_AUE_linux_mknodat	AUE_MKNODAT
#define	LINUX32_SYS_AUE_linux_fchownat	AUE_FCHOWNAT
#define	LINUX32_SYS_AUE_linux_futimesat	AUE_FUTIMESAT
#define	LINUX32_SYS_AUE_linux_fstatat64	AUE_FSTATAT
#define	LINUX32_SYS_AUE_linux_unlinkat	AUE_UNLINKAT
#define	LINUX32_SYS_AUE_linux_renameat	AUE_RENAMEAT
#define	LINUX32_SYS_AUE_linux_linkat	AUE_LINKAT
#define	LINUX32_SYS_AUE_linux_symlinkat	AUE_SYMLINKAT
#define	LINUX32_SYS_AUE_linux_readlinkat	AUE_READLINKAT
#define	LINUX32_SYS_AUE_linux_fchmodat	AUE_FCHMODAT
#define	LINUX32_SYS_AUE_linux_faccessat	AUE_FACCESSAT
#define	LINUX32_SYS_AUE_linux_pselect6	AUE_SELECT
#define	LINUX32_SYS_AUE_linux_ppoll	AUE_POLL
#define	LINUX32_SYS_AUE_linux_unshare	AUE_NULL
#define	LINUX32_SYS_AUE_linux_set_robust_list	AUE_NULL
#define	LINUX32_SYS_AUE_linux_get_robust_list	AUE_NULL
#define	LINUX32_SYS_AUE_linux_splice	AUE_NULL
#define	LINUX32_SYS_AUE_linux_sync_file_range	AUE_NULL
#define	LINUX32_SYS_AUE_linux_tee	AUE_NULL
#define	LINUX32_SYS_AUE_linux_vmsplice	AUE_NULL
#define	LINUX32_SYS_AUE_linux_move_pages	AUE_NULL
#define	LINUX32_SYS_AUE_linux_getcpu	AUE_NULL
#define	LINUX32_SYS_AUE_linux_epoll_pwait	AUE_NULL
#define	LINUX32_SYS_AUE_linux_utimensat	AUE_FUTIMESAT
#define	LINUX32_SYS_AUE_linux_signalfd	AUE_NULL
#define	LINUX32_SYS_AUE_linux_timerfd_create	AUE_NULL
#define	LINUX32_SYS_AUE_linux_eventfd	AUE_NULL
#define	LINUX32_SYS_AUE_linux_fallocate	AUE_NULL
#define	LINUX32_SYS_AUE_linux_timerfd_settime	AUE_NULL
#define	LINUX32_SYS_AUE_linux_timerfd_gettime	AUE_NULL
#define	LINUX32_SYS_AUE_linux_signalfd4	AUE_NULL
#define	LINUX32_SYS_AUE_linux_eventfd2	AUE_NULL
#define	LINUX32_SYS_AUE_linux_epoll_create1	AUE_NULL
#define	LINUX32_SYS_AUE_linux_dup3	AUE_NULL
#define	LINUX32_SYS_AUE_linux_pipe2	AUE_NULL
#define	LINUX32_SYS_AUE_linux_inotify_init1	AUE_NULL
#define	LINUX32_SYS_AUE_linux_preadv	AUE_NULL
#define	LINUX32_SYS_AUE_linux_pwritev	AUE_NULL
#define	LINUX32_SYS_AUE_linux_rt_tgsigqueueinfo	AUE_NULL
#define	LINUX32_SYS_AUE_linux_perf_event_open	AUE_NULL
#define	LINUX32_SYS_AUE_linux_recvmmsg	AUE_NULL
#define	LINUX32_SYS_AUE_linux_fanotify_init	AUE_NULL
#define	LINUX32_SYS_AUE_linux_fanotify_mark	AUE_NULL
#define	LINUX32_SYS_AUE_linux_prlimit64	AUE_NULL
#define	LINUX32_SYS_AUE_linux_name_to_handle_at	AUE_NULL
#define	LINUX32_SYS_AUE_linux_open_by_handle_at	AUE_NULL
#define	LINUX32_SYS_AUE_linux_clock_adjtime	AUE_NULL
#define	LINUX32_SYS_AUE_linux_syncfs	AUE_SYNC
#define	LINUX32_SYS_AUE_linux_sendmmsg	AUE_NULL
#define	LINUX32_SYS_AUE_linux_setns	AUE_NULL
#define	LINUX32_SYS_AUE_linux_process_vm_readv	AUE_NULL
#define	LINUX32_SYS_AUE_linux_process_vm_writev	AUE_NULL
#define	LINUX32_SYS_AUE_linux_kcmp	AUE_NULL
#define	LINUX32_SYS_AUE_linux_finit_module	AUE_NULL
#define	LINUX32_SYS_AUE_linux_sched_setattr	AUE_NULL
#define	LINUX32_SYS_AUE_linux_sched_getattr	AUE_NULL
#define	LINUX32_SYS_AUE_linux_renameat2	AUE_NULL
#define	LINUX32_SYS_AUE_linux_seccomp	AUE_NULL
#define	LINUX32_SYS_AUE_linux_getrandom	AUE_NULL
#define	LINUX32_SYS_AUE_linux_memfd_create	AUE_NULL
#define	LINUX32_SYS_AUE_linux_bpf	AUE_NULL
#define	LINUX32_SYS_AUE_linux_execveat	AUE_NULL
#define	LINUX32_SYS_AUE_linux_socket	AUE_SOCKET
#define	LINUX32_SYS_AUE_linux_socketpair	AUE_SOCKETPAIR
#define	LINUX32_SYS_AUE_linux_bind	AUE_BIND
#define	LINUX32_SYS_AUE_linux_connect	AUE_CONNECT
#define	LINUX32_SYS_AUE_linux_listen	AUE_LISTEN
#define	LINUX32_SYS_AUE_linux_accept4	AUE_ACCEPT
#define	LINUX32_SYS_AUE_linux_getsockopt	AUE_GETSOCKOPT
#define	LINUX32_SYS_AUE_linux_setsockopt	AUE_SETSOCKOPT
#define	LINUX32_SYS_AUE_linux_getsockname	AUE_GETSOCKNAME
#define	LINUX32_SYS_AUE_linux_getpeername	AUE_GETPEERNAME
#define	LINUX32_SYS_AUE_linux_sendto	AUE_SENDTO
#define	LINUX32_SYS_AUE_linux_sendmsg	AUE_SENDMSG
#define	LINUX32_SYS_AUE_linux_recvfrom	AUE_RECVFROM
#define	LINUX32_SYS_AUE_linux_recvmsg	AUE_RECVMSG
#define	LINUX32_SYS_AUE_linux_shutdown	AUE_NULL
#define	LINUX32_SYS_AUE_linux_userfaultfd	AUE_NULL
#define	LINUX32_SYS_AUE_linux_membarrier	AUE_NULL
#define	LINUX32_SYS_AUE_linux_mlock2	AUE_NULL
#define	LINUX32_SYS_AUE_linux_copy_file_range	AUE_NULL
#define	LINUX32_SYS_AUE_linux_preadv2	AUE_NULL
#define	LINUX32_SYS_AUE_linux_pwritev2	AUE_NULL
#define	LINUX32_SYS_AUE_linux_pkey_mprotect	AUE_NULL
#define	LINUX32_SYS_AUE_linux_pkey_alloc	AUE_NULL
#define	LINUX32_SYS_AUE_linux_pkey_free	AUE_NULL
#define	LINUX32_SYS_AUE_linux_statx	AUE_NULL
#define	LINUX32_SYS_AUE_linux_arch_prctl	AUE_NULL
#define	LINUX32_SYS_AUE_linux_io_pgetevents	AUE_NULL
#define	LINUX32_SYS_AUE_linux_rseq	AUE_NULL
#define	LINUX32_SYS_AUE_linux_semget	AUE_NULL
#define	LINUX32_SYS_AUE_linux_semctl	AUE_NULL
#define	LINUX32_SYS_AUE_linux_shmget	AUE_NULL
#define	LINUX32_SYS_AUE_linux_shmctl	AUE_NULL
#define	LINUX32_SYS_AUE_linux_shmat	AUE_NULL
#define	LINUX32_SYS_AUE_linux_shmdt	AUE_NULL
#define	LINUX32_SYS_AUE_linux_msgget	AUE_NULL
#define	LINUX32_SYS_AUE_linux_msgsnd	AUE_NULL
#define	LINUX32_SYS_AUE_linux_msgrcv	AUE_NULL
#define	LINUX32_SYS_AUE_linux_msgctl	AUE_NULL
#define	LINUX32_SYS_AUE_linux_clock_gettime64	AUE_NULL
#define	LINUX32_SYS_AUE_linux_clock_settime64	AUE_NULL
#define	LINUX32_SYS_AUE_linux_clock_adjtime64	AUE_NULL
#define	LINUX32_SYS_AUE_linux_clock_getres_time64	AUE_NULL
#define	LINUX32_SYS_AUE_linux_clock_nanosleep_time64	AUE_NULL
#define	LINUX32_SYS_AUE_linux_timer_gettime64	AUE_NULL
#define	LINUX32_SYS_AUE_linux_timer_settime64	AUE_NULL
#define	LINUX32_SYS_AUE_linux_timerfd_gettime64	AUE_NULL
#define	LINUX32_SYS_AUE_linux_timerfd_settime64	AUE_NULL
#define	LINUX32_SYS_AUE_linux_utimensat_time64	AUE_NULL
#define	LINUX32_SYS_AUE_linux_pselect6_time64	AUE_NULL
#define	LINUX32_SYS_AUE_linux_ppoll_time64	AUE_NULL
#define	LINUX32_SYS_AUE_linux_io_pgetevents_time64	AUE_NULL
#define	LINUX32_SYS_AUE_linux_recvmmsg_time64	AUE_NULL
#define	LINUX32_SYS_AUE_linux_mq_timedsend_time64	AUE_NULL
#define	LINUX32_SYS_AUE_linux_mq_timedreceive_time64	AUE_NULL
#define	LINUX32_SYS_AUE_linux_semtimedop_time64	AUE_NULL
#define	LINUX32_SYS_AUE_linux_rt_sigtimedwait_time64	AUE_NULL
#define	LINUX32_SYS_AUE_linux_futex_time64	AUE_NULL
#define	LINUX32_SYS_AUE_linux_sched_rr_get_interval_time64	AUE_NULL
#define	LINUX32_SYS_AUE_linux_pidfd_send_signal	AUE_NULL
#define	LINUX32_SYS_AUE_linux_io_uring_setup	AUE_NULL
#define	LINUX32_SYS_AUE_linux_io_uring_enter	AUE_NULL
#define	LINUX32_SYS_AUE_linux_io_uring_register	AUE_NULL

#undef PAD_
#undef PADL_
#undef PADR_

#endif /* !_LINUX32_SYSPROTO_H_ */
