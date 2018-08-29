//
//  offsetfinder.h
//  Meridian
//
//  Created by Ben Sparkes on 08/03/2018.
//  Copyright © 2018 Ben Sparkes. All rights reserved.
//

#ifndef offsetfinder_h
#define offsetfinder_h

#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"

typedef struct
{
    kptr_t base;
    // Structure offsets
    kptr_t sizeof_task;
    kptr_t task_itk_self;
    kptr_t task_itk_registered;
    kptr_t task_bsd_info;
    kptr_t proc_ucred;
    kptr_t vm_map_hdr;
    kptr_t ipc_space_is_task;
    kptr_t realhost_special;
    kptr_t iouserclient_ipc;
    kptr_t vtab_get_retain_count;
    kptr_t vtab_get_external_trap_for_index;
    // Data
    kptr_t zone_map;
    kptr_t kernel_map;
    kptr_t kernel_task;
    kptr_t realhost;
    // Code
    kptr_t copyin;
    kptr_t copyout;
    kptr_t chgproccnt;
    kptr_t kauth_cred_ref;
    kptr_t ipc_port_alloc_special;
    kptr_t ipc_kobject_set;
    kptr_t ipc_port_make_send;
    kptr_t osserializer_serialize;
    kptr_t rop_ldr_x0_x0_0x10;
    // Remount
    kptr_t root_vnode;
    // AMFID stuff
    kptr_t vfs_context_current;
    kptr_t vnode_getfromfd;
    kptr_t vnode_getattr;
    kptr_t vnode_put;
    kptr_t csblob_ent_dict_set;
    kptr_t sha1_init;
    kptr_t sha1_update;
    kptr_t sha1_final;
    // Extra
    kptr_t proc_find;
    kptr_t proc_name;
    kptr_t proc_rele;
} offsets_t;

#ifndef HEADLESS
offsets_t *get_offsets(void);
#endif

#ifdef __cplusplus
}
#endif

#endif /* offsetfinder_h */