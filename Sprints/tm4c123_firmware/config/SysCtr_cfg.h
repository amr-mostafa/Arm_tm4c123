/*
 * SysCtr_cfg.h
 *
 *  Created on: Aug 2, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef E15_ARM_REPO_CONFIG_SYSCTR_CFG_H_
#define E15_ARM_REPO_CONFIG_SYSCTR_CFG_H_

/************************************************************************/
/*                              INCLUDES                                */
/************************************************************************/
#include "../utils/STD_Types.h"
#include "../mcal/SysCtr/SysCtr_types.h"
/************************************************************************/
/*                                 DEFINES                              */
/************************************************************************/

/*TODO implement suitable container to store the followings
 *
 * which peripheral clock gate Enabled
 * Desired System clock Source
 * Desired System CLock Frequency
 * */
#define MAX_NUMBER_peripheral   4

extern const PeripheralSysClkCfg_t arr_PeripheralSysClkCfg[MAX_NUMBER_peripheral];
extern const SYSCLOCK_Config      SYSCLOCK;
extern const uint32               Main_OscVlaue;

#endif /* E15_ARM_REPO_CONFIG_SYSCTR_CFG_H_ */
