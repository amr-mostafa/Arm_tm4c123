
/*
 * port.c
 *
 *  Created on: Nov 12, 2019
 *      Author: Muammad Elzeiny
 */


/************************************************************************/
/*				               Includes                                 */
/************************************************************************/
#include "STD_types.h"
#include "../../utils/Bit_Math.h"
#include "../../config/port_cfg.h"
#include "port_lcfg.h"
#include "../mcu_hw.h"
#include "port_types.h"
#include "port.h"

/************************************************************************/
/*				               Defines                                  */
/************************************************************************/
#define MAX_NUM_OF_CH_IN_PORT       8
#define MAX_NUM_OF_PORTS            6

/************************************************************************/
/*		                Global and static Variables                     */
/************************************************************************/
static volatile PORT_RegType* BaseAddrArr[MAX_NUM_OF_PORTS] = {PORTA_BaseAddr,PORTB_BaseAddr,
															   PORTC_BaseAddr,PORTD_BaseAddr,
															   PORTE_BaseAddr,PORTF_BaseAddr};



/************************************************************************/
/*		           FUNCTIONS' Definition		                        */
/************************************************************************/


/**
 * Input:
 * Output:
 * In/Out:
 * Return:
 * Description: Initiates the GPIO module by initializing its : Direction, Attached Resistance, Mode,
 *  Lock state and pin Rated ampere.
 *
 *
 */

void PORT_init(void)
{
	uint8 CfgArrIndex;
	Port_IdType PortId;
	Port_ChIdType ChannelId;
	uint8 ChannelPosInPort;
	volatile PORT_RegType* BaseAddr;

	for (CfgArrIndex = 0; CfgArrIndex < PORT_NUM_OF_ACTIVATED_CH; ++CfgArrIndex)
	{
		/*get channelID from CfgIndex*/
		ChannelId = PortCfgArr[CfgArrIndex].Channel;

		/*get PORTId using ChannelId*/
		PortId =(Port_IdType)( ChannelId / MAX_NUM_OF_CH_IN_PORT);

		/*get baseAddress using PortId*/
		BaseAddr = BaseAddrArr[PortId];

		/*get Channel Position in PortGroup using ChannelId */
		ChannelPosInPort = ChannelId % MAX_NUM_OF_CH_IN_PORT;


		/**********set channel direction *********/
		if(PortCfgArr[CfgArrIndex].Dir==port_Dir_Output)
		{
			BaseAddr->GPIODIR |=(1<<ChannelPosInPort);
		}
		else if(PortCfgArr[CfgArrIndex].Dir==port_Dir_Input)
		{
			BaseAddr->GPIODIR &=~(1<<ChannelPosInPort);

			/******* set Internal Attachment configuration *****/
			if(PortCfgArr[CfgArrIndex].AttachedRes==Port_InternalAttach_OpenDrain)
			{
				BaseAddr->GPIOODR|=(1<<ChannelPosInPort);;
			}
			else if(PortCfgArr[CfgArrIndex].AttachedRes==Port_InternalAttach_PullDownRes)
			{
				BaseAddr->GPIOPDR|=(1<<ChannelPosInPort);;
			}
			else if(PortCfgArr[CfgArrIndex].AttachedRes==Port_InternalAttach_PullUpRes)
			{
				BaseAddr->GPIOPUR|=(1<<ChannelPosInPort);;
			}
		}


		/********set channel mode *******/
		if(PortCfgArr[CfgArrIndex].Mode==PORT_MODE_PIN_X_DIO)
		{
			BaseAddr->GPIOAFSEL&=~(1<<ChannelPosInPort);
		}
		else
		{
			BaseAddr->GPIOAFSEL|=(1<<ChannelPosInPort);  /****Alternative function of DIO pin***/
			BaseAddr->GPIOPCTL |=(PortCfgArr[CfgArrIndex].Mode)<<4*ChannelPosInPort;
		}

		/*Check if analog functionality is required*/
		if(PortCfgArr[CfgArrIndex].Mode != Port_Mode_AIN )
		{
			/**** enable digital and disable ADC  ****/
			BaseAddr->GPIODEN |= (1<<ChannelPosInPort);
			BaseAddr->GPIOAMSEL &=~(1<<ChannelPosInPort);
		}
		else
		{
			/**** disable digital and enable ADC ***/
			BaseAddr->GPIODEN&=~(1<<ChannelPosInPort);;
			BaseAddr->GPIOAMSEL|=(1<<ChannelPosInPort);
		}

		/********* set Interrupt configuration *********/
		if(PortCfgArr[CfgArrIndex].Interrupt == Port_IntDisable)
		{

			CLR_BIT(BaseAddr->GPIOIM, ChannelPosInPort);
		}
		else
		{


		}


		/***** set current strength configuration ******/
		if(PortCfgArr[CfgArrIndex].CurrentDrive== Port_CurrDrive_2mA)
		{
			BaseAddr->GPIODR2R |=(1<<ChannelPosInPort);;
		}
		else if(PortCfgArr[CfgArrIndex].CurrentDrive== Port_CurrDrive_4mA)
		{
			BaseAddr->GPIODR4R |=(1<<ChannelPosInPort);;
		}
		else if(PortCfgArr[CfgArrIndex].CurrentDrive== Port_CurrDrive_8mA)
		{
			BaseAddr->GPIODR8R |=(1<<ChannelPosInPort);;
		}


	}
}
