/*
 * processor.c
 *
 *  Created on: Dec 2, 2019
 *      Author: Muhammad.Elzeiny
 */
/************************************************************************/
/*                              INCLUDES                                */
/************************************************************************/
#include "processor.h"
/************************************************************************/
/*                           GLOBAL VARIABLES                           */
/************************************************************************/
static PROCESSOR_ModeType REQUIRED_MODE =PROCESSOR_ModeNonPrivilege;
/************************************************************************/
/*                       FUNCTIONS' IMPLMENTATION                       */
/************************************************************************/
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
void PROCESSOR_switchMode(PROCESSOR_ModeType Mode)
{
    /*  use Svc assembly instruction to switch to handler mode*/
    REQUIRED_MODE=Mode;
    __asm(" SVC #1");
}
/******** NOTE: Put the following function address in Vector table *************/
/*******************************************************************************
*  Function name:      PROCESSOR_SvcHandler
*
*  Brief:               when the SVC is fired switching Processor status (PROCESSOR_ModePrivilege or PROCESSOR_ModeNonPrivilege)
*
*  Details:            switching is caused by SVC -> supervisor call handler,Note : This Function triggers the SVC
*
*  Arguments:          PROCESSOR_ModeType -> PROCESSOR_ModePrivilege or PROCESSOR_ModeNonPrivilege
*      -
*  Return:             void
*      -
*******************************************************************************/
void PROCESSOR_SvcHandler(void)
{
    /* TMPL bit field in CONTROL Register to switch between
     * privilege and non-privilege modes */
    switch(REQUIRED_MODE)
    {
    case PROCESSOR_ModePrivilege:
        __asm(" MOV R0, #0");
        __asm(" MSR CONTROL, R0");
        break;
    case PROCESSOR_ModeNonPrivilege:
        __asm(" MOV R0, #1");
        __asm(" MSR CONTROL, R0");
        break;
    default:
        break;
    }
}
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
void PROCESSOR_enableGlobalInt(void)
{
    /*Enable Golabal interrupt*/
    PROCESSOR_switchMode(PROCESSOR_ModePrivilege);
    __asm("    cpsie   i\n");
    PROCESSOR_switchMode(PROCESSOR_ModeNonPrivilege);
}
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
void PROCESSOR_disableGlobalInt(void)
{
    /*disable Global interrupt*/
    PROCESSOR_switchMode(PROCESSOR_ModePrivilege);
    __asm("    cpsid   i\n");
    PROCESSOR_switchMode(PROCESSOR_ModeNonPrivilege);
}

