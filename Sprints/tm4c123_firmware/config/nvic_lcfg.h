/**
 * FIle: nvic_lcfg.h
 * Author: Amr
 * Date: 10 Feb, 2020
 *
 * */

#ifndef _NVIC_LCFG_H
#define _NVIC_LCFG_H

#include "nvic_cfg.h"
#include "../mcal/nvic/nvic_types.h"

#define NVIC_PRIORITY_GROUPS_8_SUB_1                     0x4
#define NVIC_PRIORITY_GROUPS_1_SUB_8                     0x7
#define NVIC_PRIORITY_GROUPS_4_SUB_2                     0x5
#define NVIC_PRIORITY_GROUPS_2_SUB_4                     0x6

extern const NVIC_CfgType NVIC_CfgArr[NVIC_NUM_OF_ENABLED_INT];
extern const uint8 NVIC_GroupsSubsCfg;

#endif
