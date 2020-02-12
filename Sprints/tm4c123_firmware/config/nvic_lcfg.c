/*
 * nvic_lcfg.c
 *
 *  Created on: Dec 2, 2019
 *      Author: Muhammad.Elzeiny
 */

#include "nvic_lcfg.h"
#include "nvic_cfg.h"
#include "../mcal/nvic/nvic_types.h"

#define NVIC_GPIOPort_A                          (0U)
#define NVIC_GPIOPort_B                          (1U)
#define I2C_2                                    (68U)
#define Timer_2A                                 (98U)

const NVIC_CfgType NVIC_CfgArr[NVIC_NUM_OF_ENABLED_INT]={

   /*TODO Configure each Enabled Interrupt */
   /* InterruptNum, PriorityGroup, PrioritySubGroup */
   {NVIC_GPIOPort_A,    0, 7},
   {NVIC_GPIOPort_B,    0, 6},
   {I2C_2,              0, 1},
   {Timer_2A,           0, 0}
};

const uint8 NVIC_GroupsSubsCfg = NVIC_PRIORITY_GROUPS_1_SUB_8;
