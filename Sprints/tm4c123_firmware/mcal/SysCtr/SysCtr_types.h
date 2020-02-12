/*
 * SysCtr_Types.h
 *
 *  Created on: Dec 2, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef TM4C123_FIRMWARE_MCAL_SYSCTR_SYSCTR_TYPES_H_
#define TM4C123_FIRMWARE_MCAL_SYSCTR_SYSCTR_TYPES_H_


/************************************************************************/
/*                              DEFINES                                 */
/************************************************************************/



typedef struct
{
    uint16      u16_Peripheral;
    uint16      u16_PeripheralChannel;
}PeripheralSysClkCfg_t;

typedef struct
{
    uint8       u8_System_clock_Source;
    uint8       u8_System_CLock_Frequency;
}SYSCLOCK_Config;


#endif /* TM4C123_FIRMWARE_MCAL_SYSCTR_SYSCTR_TYPES_H_ */
