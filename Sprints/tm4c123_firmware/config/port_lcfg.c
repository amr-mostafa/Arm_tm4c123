/*
 * port_lcfg.c
 *
 *  Created on: Jul 8, 2019
 *      Author: Muhammad.Elzeiny
 */


/************************************************************************/
/*				               Includes                                 */
/************************************************************************/
#include "port_types.h"
#include "port_cfg.h"
#include "port_lcfg.h"


const Port_CfgType PortCfgArr[PORT_NUM_OF_ACTIVATED_CH] = {

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*    Channel                   Direction                Mode                          External Interrupt      Attached_Resistor                      Current_Drive_Strength      Lock_Status    */
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
{     Port_Channel_F0,          port_Dir_Output,         PORT_MODE_PIN_X_DIO,          Port_IntDisable,        Port_InternalAttach_PullUpRes,         Port_CurrDrive_8mA,         Port_Unlocked     },
{     Port_Channel_F1,          port_Dir_Output,         PORT_MODE_PIN_X_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_8mA,         Port_Unlocked     },
{     Port_Channel_F2,          port_Dir_Output,         PORT_MODE_PIN_X_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_8mA,         Port_Unlocked     },
{     Port_Channel_F4,          port_Dir_Input,          PORT_MODE_PIN_X_DIO,     		Port_IntDisable,       Port_InternalAttach_PullUpRes,      	Port_CurrDrive_8mA,         Port_Unlocked     },
{     Port_Channel_A4,          port_Dir_Input,          PORT_MODE_PIN_A4_SSI0Rx,      Port_IntDisable,        Port_InternalAttach_NA,                Port_CurrDrive_2mA,         Port_Unlocked     },
{     Port_Channel_A5,          port_Dir_Output,         PORT_MODE_PIN_A5_SSI0Tx,      Port_IntDisable,        Port_InternalAttach_NA,                Port_CurrDrive_2mA,         Port_Unlocked     },
{     Port_Channel_A6,          port_Dir_Input,          PORT_MODE_PIN_A6_I2C1SCL,     Port_IntDisable,        Port_InternalAttach_PullUpRes,         Port_CurrDrive_2mA,         Port_Unlocked     },
{     Port_Channel_A7,          port_Dir_Input,          PORT_MODE_PIN_A7_I2C1SDA,     Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_Unlocked     },

};
