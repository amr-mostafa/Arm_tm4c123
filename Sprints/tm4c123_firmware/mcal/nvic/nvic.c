/*
 * nvic.c
 *
 *  Created on: Aug 17, 2019
 *      Author: kareem
 */


#include "../../utils/Std_Types.h"
#include "../../utils/Bit_Math.h"
/*TODO include processor.h*/

#include "../../config/nvic_cfg.h"
#include "../../config/nvic_lcfg.h"
#include "../mcu_hw.h"
#include "nvic_types.h"
#include "nvic.h"
#include "processor.h"

#define INT_EN0_REG_ADD         (volatile uint32*)(0xE000E000 + 0x100)
#define INT_PRI0_REG_ADD        (volatile uint32*)(0xE000E000 + 0x400)

void NVIC_init(void)
{
    uint8 u8_Counter;
    uint32* u32_RegAdd;
    uint32 u32_BitNumber;
    uint32 u32_TotalPriority;
    /*TODO : switch to privilege mode - use switch function in processor.h*/
    PROCESSOR_switchMode(PROCESSOR_ModePrivilege);

    /*TODO :loop for NVIC_CfgArr configure each Interrupt
     *  as stated in Cfg (Enable/Priority/sub-priority)
     *  */
    *( (volatile uint32*) (0xE000E000 + 0xD0C) ) = ( (0x05FA<<16) + (NVIC_GroupsSubsCfg<<8) );

    for(u8_Counter=0; u8_Counter<NVIC_NUM_OF_ENABLED_INT; u8_Counter++)
    {
        /* enable the corresponding interrupt */
        u32_RegAdd = (uint32*)(INT_EN0_REG_ADD + ( (NVIC_CfgArr[u8_Counter].InterruptNum / 32) * 4 ) );
        u32_BitNumber = NVIC_CfgArr[u8_Counter].InterruptNum % 32;
        *u32_RegAdd |=1<<u32_BitNumber;

        /* set the priority */
        u32_RegAdd = (uint32*)(INT_PRI0_REG_ADD + ( (NVIC_CfgArr[u8_Counter].InterruptNum / 4) * 4 ) );
        u32_BitNumber = (NVIC_CfgArr[u8_Counter].InterruptNum % 4);
        u32_BitNumber = (u32_BitNumber * 8) + 5;
        u32_TotalPriority = (NVIC_CfgArr[u8_Counter].PriorityGroup << (NVIC_GroupsSubsCfg-0x4) ) | (NVIC_CfgArr[u8_Counter].PrioritySubGroup);
        *u32_RegAdd |= u32_TotalPriority << u32_BitNumber;
    }


    /*TODO : return to non-privilege mode */
    PROCESSOR_switchMode(PROCESSOR_ModeNonPrivilege);
}



