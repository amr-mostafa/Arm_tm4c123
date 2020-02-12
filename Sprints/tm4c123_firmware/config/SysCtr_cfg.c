/*
 * SysCtr_cfg.c
 *
 *  Created on: Feb 11, 2020
 *      Author: Ahmed
 */

#include "../mcal/SysCtr/SysCtr.h"
#include "../mcal/SysCtr/SysCtr_types.h"
#include "SysCtr_cfg.h"


const uint32  Main_OscVlaue = CRYSTAL_FREQ_16MHZ;

const PeripheralSysClkCfg_t arr_PeripheralSysClkCfg[MAX_NUMBER_peripheral]=
{
 { SYSCTL_PERIPH_GPIO, SYSCTL_PERIPH_GPIOA },
 { SYSCTL_PERIPH_GPIO, SYSCTL_PERIPH_GPIOF },
 { SYSCTL_PERIPH_UART, SYSCTL_PERIPH_UART0 },
 { SYSCTL_PERIPH_UART, SYSCTL_PERIPH_UART7 }
};

const SYSCLOCK_Config SYSCLOCK={
                                 MOSC,
                                 SYS_CLK_FREQ_80_000
                                };
