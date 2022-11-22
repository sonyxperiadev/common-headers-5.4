/****************************************************************************
 ****************************************************************************
 ***
 ***   This header was automatically generated from a Linux kernel header
 ***   of the same name, to make information necessary for userspace to
 ***   call into the kernel available to libc.  It contains only constants,
 ***   structures, and macros generated from the original header, and thus,
 ***   contains no copyrightable information.
 ***
 ***   To edit the content of this header, modify the corresponding
 ***   source file (e.g. under external/kernel-headers/original/) then
 ***   run bionic/libc/kernel/tools/update_all.py
 ***
 ***   Any manual change here will be lost the next time this script will
 ***   be run. You've been warned!
 ***
 ****************************************************************************
 ****************************************************************************/
#ifndef _UAPI_LINUX_MEM_BUF_H
#define _UAPI_LINUX_MEM_BUF_H
#include <linux/ioctl.h>
#include <linux/types.h>
#define MEM_BUF_IOC_MAGIC 'M'
enum mem_buf_mem_type {
  MEM_BUF_ION_MEM_TYPE,
  MEM_BUF_MAX_MEM_TYPE,
};
#define MEM_BUF_VMID_PRIMARY_VM 0
#define MEM_BUF_VMID_TRUSTED_VM 1
#define MEM_BUF_PERM_FLAG_READ (1U << 0)
#define MEM_BUF_PERM_FLAG_WRITE (1U << 1)
#define MEM_BUF_PERM_FLAG_EXEC (1U << 2)
#define MEM_BUF_PERM_VALID_FLAGS (MEM_BUF_PERM_FLAG_READ | MEM_BUF_PERM_FLAG_WRITE | MEM_BUF_PERM_FLAG_EXEC)
#define MEM_BUF_MAX_NR_ACL_ENTS 16
struct acl_entry {
  __u32 vmid;
  __u32 perms;
};
struct mem_buf_ion_data {
  __u32 heap_id;
};
struct mem_buf_alloc_ioctl_arg {
  __u64 size;
  __u64 acl_list;
  __u32 nr_acl_entries;
  __u32 src_mem_type;
  __u64 src_data;
  __u32 dst_mem_type;
  __u32 mem_buf_fd;
  __u64 dst_data;
  __u64 reserved0;
  __u64 reserved1;
  __u64 reserved2;
};
#define MEM_BUF_IOC_ALLOC _IOWR(MEM_BUF_IOC_MAGIC, 0, struct mem_buf_alloc_ioctl_arg)
struct mem_buf_export_ioctl_arg {
  __u32 dma_buf_fd;
  __u32 nr_acl_entries;
  __u64 acl_list;
  __u32 export_fd;
  __u32 memparcel_hdl;
  __u64 reserved0;
  __u64 reserved1;
  __u64 reserved2;
};
#define MEM_BUF_IOC_EXPORT _IOWR(MEM_BUF_IOC_MAGIC, 1, struct mem_buf_export_ioctl_arg)
struct mem_buf_import_ioctl_arg {
  __u32 memparcel_hdl;
  __u32 nr_acl_entries;
  __u64 acl_list;
  __u32 dma_buf_import_fd;
  __u32 reserved0;
  __u64 reserved1;
  __u64 reserved2;
  __u64 reserved3;
};
#define MEM_BUF_IOC_IMPORT _IOWR(MEM_BUF_IOC_MAGIC, 2, struct mem_buf_import_ioctl_arg)
#endif
