/*
 * SysCtr.c
 *
 *  Created on: Aug 2, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "SysCtr.h"
#include "../mcu_hw.h"
#include "../../utils/STD_types.h"
#include "../../utils/Bit_Math.h"
/* include SysCtr_cfg.h*/
#include "../../config/SysCtr_cfg.h"

void SysCtr_init(void)
{
    uint8 u8_Counter;


    /*TODO Set System CLock Source as configured*/
    /*TODO set CLock Frequency as configured -
         * use Figure 5-5. Main Clock Tree Page.222 in DATASHEET as reference.* */
    RCC2_REG.B.USERCC2 = 1;
    RCC2_REG.B.BYPASS2 = 1;
    if( SYSCLOCK.u8_System_clock_Source == MOSC )
    {
        RCC2_REG.B.OSCSRC2 = MOSC;
        RCC_REG.B.XTAL = 0;
        RCC_REG.B.XTAL = Main_OscVlaue;
    }
    else
    {
        /* Do Nothing */
    }

    RCC2_REG.B.PWRDN2 = 0;
    RCC2_REG.B.SYSDIV2 = SYSCLOCK.u8_System_CLock_Frequency;
    while( RIS_REG.B.PLLLRIS == 0 );
    RCC2_REG.B.BYPASS2 = 0;

    /*TODO Enable configured Peripherals CLock gates*/
    for( u8_Counter=0; u8_Counter<MAX_NUMBER_peripheral; u8_Counter++ )
    {
        GET_REG(SYSCTL_PERIPH_BASE_ADDRESS, uint32, (uint32)(arr_PeripheralSysClkCfg[u8_Counter].u16_Peripheral) ) |= arr_PeripheralSysClkCfg[u8_Counter].u16_PeripheralChannel;
    }
}
uint32 SysCtr_getSysClockFreq(void)
{
    /*TODO return the current system clock frequency */

}

