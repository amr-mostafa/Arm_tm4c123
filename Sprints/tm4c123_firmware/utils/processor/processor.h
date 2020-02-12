/*
 * processor.h
 *
 *  Created on: Dec 2, 2019
 *      Author: Muhammad.Elzeiny
 */
#ifndef TM4C123_FIRMWARE_UTILS_PROCESSOR_PROCESSOR_H_
#define TM4C123_FIRMWARE_UTILS_PROCESSOR_PROCESSOR_H_
/************************************************************************/
/*                              INCLUDES                                */
/************************************************************************/
#include "Std_Types.h"
/************************************************************************/
/*                              DEFINES                                 */
/************************************************************************/
typedef uint8 PROCESSOR_ModeType;
#define PROCESSOR_ModePrivilege                 (uint8)0
#define PROCESSOR_ModeNonPrivilege              (uint8)1
/*******************************************************************************
*  Function name:      PROCESSOR_switchMode
*
*  Brief:              switch Processor status (PROCESSOR_ModePrivilege or PROCESSOR_ModeNonPrivilege)
*
*  Details:            switching is caused by SVC -> supervisor call handler,Note : This Function triggers the SVC
*
*  Arguments:
*      -               PROCESSOR_ModeType -> PROCESSOR_ModePrivilege or PROCESSOR_ModeNonPrivilege
*
*  Return:             void
*      -
*******************************************************************************/
void PROCESSOR_switchMode(PROCESSOR_ModeType Mode);
/*******************************************************************************
*  Function name:      PROCESSOR_enableGlobalInt
*
*  Brief:              switch the PROCESSOR Status to ModePrivilegen to Enable the global interrupt
*
*  Details:
*
*  Arguments:          void
*      -
*  Return:             void
*      -
*******************************************************************************/
void PROCESSOR_enableGlobalInt(void);
/*******************************************************************************
*  Function name:      PROCESSOR_disableGlobalInt
*
*  Brief:              switch the PROCESSOR Status to ModePrivilegen to disable the global interrupt
*
*  Details:
*
*  Arguments:          void
*      -
*  Return:             void
*      -
*******************************************************************************/
void PROCESSOR_disableGlobalInt(void);

#endif /* TM4C123_FIRMWARE_UTILS_PROCESSOR_PROCESSOR_H_ */
