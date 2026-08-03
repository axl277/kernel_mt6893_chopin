/*
 * Copyright (C) 2015 MediaTek Inc.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#ifndef __MDP_M4U_H__
#define __MDP_M4U_H__

#ifdef CONFIG_MTK_IOMMU_V2
#include "mach/mt_iommu.h"
#include <soc/mediatek/smi.h>
#endif
#include <ion_priv.h>
#include <linux/types.h>

/* implemented in pseudo_m4u_v2.c: live byte usage of the shared
 * multimedia IOVA domain that MDP ports allocate from
 */
unsigned long long m4u_mm_domain_usage(void);
/* ...and the share of it held by one process, so a submitter can be told
 * whether it is itself the one filling the domain
 */
unsigned long long m4u_mm_domain_usage_tgid(pid_t tgid);

void mdp_ion_create(const char *name);
void mdp_ion_destroy(void);
int mdp_ion_get_mva(struct ion_handle *handle,
	unsigned long *mva, unsigned long fixed_mva, int port);
struct ion_handle *mdp_ion_import_handle(int fd);
void mdp_ion_free_handle(struct ion_handle *handle);
void mdp_ion_cache_flush(struct ion_handle *handle);
#ifdef CONFIG_MTK_IN_HOUSE_TEE_SUPPORT
void  mdp_ion_import_sec_handle(int fd, ion_phys_addr_t *sec_handle);
#endif


#endif
