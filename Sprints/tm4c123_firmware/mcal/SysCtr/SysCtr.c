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


/* look up table for returning the frequency */
static const uint32 garrayOfU32_FreqLookupTable[] = { 0, 0, 0, 0, 80000, 66667, 0, 50000,
                                            44444, 40000, 36364, 33333, 30769,
                                            28571, 26667, 25000, 23529, 22222,
                                            21053, 20000, 19048, 18182, 17391,
                                            16667, 16000, 15385, 14815, 14286,
                                            13793, 13333, 12903, 12500, 12121,
                                            11765, 11429, 11111, 10811, 10526,
                                            10256, 10000, 9756, 9524, 9302,
                                            9091, 8889, 8696, 8511, 8333, 8163,
                                            8000, 7843, 7692, 7547, 7407, 7273,
                                            7143, 7018, 6897, 6780, 6667, 6557,
                                            6452, 6349, 6250, 6154, 6061, 5970,
                                            5882, 5797, 5714, 5634, 5556, 5479,
                                            5405, 5333, 5263, 5195, 5128, 5063,
                                            5000, 4938, 4878, 4819, 4762, 4706,
                                            4651, 4598, 4545, 4494, 4444, 4396,
                                            4348, 4301, 4255, 4211, 4167, 4124,
                                            4082, 4040, 4000, 3960, 3922, 3883,
                                            3846, 3810, 3774, 3738, 3704, 3670,
                                            3636, 3604, 3571, 3540, 3509, 3478,
                                            3448, 3419, 3390, 3361, 3333, 3306,
                                            3279, 3252, 3226, 3200, 3175, 3150,
                                            3125 };

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
    uint32 u32_FreqKHz;

    /*TODO return the current system clock frequency */

    /* if we bypassed the PLL that means user has selected the internal OSC which is 16MHz */
    if( RCC2_REG.B.BYPASS2 == 0 )
    {
        u32_FreqKHz = 16000;
    }
    /* else, means the user selected an external crystal, so we return its value from the look up table */
    else
    {
        u32_FreqKHz = garrayOfU32_FreqLookupTable[RCC2_REG.B.SYSDIV2];
    }

    return u32_FreqKHz;
}

