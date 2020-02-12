/*
 * dio.c
 *
 *  Created on: Jul 8, 2019
 *      Author: Muhammad.Elzeiny
 */
/************************************************************************/
/*				               Includes                                 */
/************************************************************************/
#include "../../utils/Bit_Math.h"
#include "../../utils/STD_Types.h"
#include "../mcu_hw.h"
#include "dio.h"

/************************************************************************/
/*				               Defines                                  */
/************************************************************************/
#define MAX_NUM_OF_PORTS            (6)
/************************************************************************/
/*		                Global and static Variables                     */
/************************************************************************/
static volatile PORT_RegType* BaseAddrArr[MAX_NUM_OF_PORTS] = {PORTA_BaseAddr,PORTB_BaseAddr,
															   PORTC_BaseAddr,PORTD_BaseAddr,
															   PORTE_BaseAddr,PORTF_BaseAddr};


static volatile PORT_RegType* BaseAddr;



/************************************************************************/
/*		           FUNCTIONS' Definition		                        */
/************************************************************************/


/**
 * Input: Channel Id.
 * Output:
 * In/Out:
 * Return: Pin Level (HIGH or LOW).
 * Description: Read Pin value and return it's level (HIGH or LOW).
 *
 *
 */
Std_levelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
	Std_levelType ret;
	Dio_PortType PortId =(Dio_PortType) (ChannelId / 8);
	Dio_ChannelType ChannelPos =(Dio_ChannelType)(ChannelId % 8);
	/*get baseAddress using PortId*/
	BaseAddr=BaseAddrArr[PortId];

	/**** Return the level value of given Channel ****/
	ret= (Std_levelType)(BaseAddr->GPIODATA &(1<<ChannelPos));

	return ret;

}


/**
 * Input:ChannelId, Pin level(HIGH or LOW).
 * Output:
 * In/Out:
 * Return:
 * Description: Write Pin value (HIGH or LOW).
 *
 *
 */
void Dio_WriteChannel(Dio_ChannelType ChannelId, Std_levelType Level)
{
	Dio_PortType PortId =(Dio_PortType) (ChannelId / 8);
	Dio_ChannelType ChannelPos =(Dio_ChannelType) (ChannelId % 8);

	/*get baseAddress using PortId*/
	BaseAddr=BaseAddrArr[PortId];

	/*** Write the input value in the corresponding ChannelId ****/
	if(Level==STD_high)
	{
		BaseAddr->GPIODATA |=(1<<ChannelPos);
	}
	else if(Level==STD_low)
	{
		BaseAddr->GPIODATA &=~(1<<ChannelPos);
	}

}



/**
 * Input:PortId
 * Output:
 * In/Out:
 * Return: Value of Chosen Port.
 * Description: Return value of port entered by user.
 *
 *
 */
uint8 Dio_ReadPort(Dio_PortType PortId )
{
	uint8 ret;

	/*get baseAddress using PortId*/
	BaseAddr=BaseAddrArr[PortId];


	/**** Return the Port Value*/
	ret=(BaseAddr->GPIODATA &0xFF);

	return ret;
}



/**
 * Input:PortId, Port value.
 * Output:
 * In/Out:
 * Return:
 * Description: Insert value into chosen Port Id.
 *
 *
 */
void Dio_WritePort( Dio_PortType PortId, uint8 value)
{

	/*get baseAddress using PortId*/
	BaseAddr=BaseAddrArr[PortId];

	/***** Write the input value in the corresponding PortId ****/
	BaseAddr->GPIODATA=value;


}


/**
 * Input:ChannelId
 * Output:
 * In/Out:
 * Return:
 * Description: Toggle Pin value.
 *
 *
 */
void Dio_FlipChannel( Dio_ChannelType ChannelId)
{
	Dio_PortType PortId =(Dio_PortType) (ChannelId / 8);
	Dio_ChannelType ChannelPos =(Dio_ChannelType) (ChannelId % 8);

	/*get baseAddress using PortId*/
	BaseAddr=BaseAddrArr[PortId];

	/**** toggle the corresponding ChannelId ****/
	BaseAddr->GPIODATA ^=(1<<ChannelPos);


}


/**
 * Input:PortId
 * Output:
 * In/Out:
 * Return:
 * Description: Toggle Port value.
 *
 *
 */
void Dio_FlipPort(Dio_PortType PortId)
{
	/*get baseAddress using PortId*/
	BaseAddr=BaseAddrArr[PortId];

	/**** toggle the port value ******/
	BaseAddr->GPIODATA ^=0xFF;


}



