/*******************************************************************************
* File Name: RXint.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_RXint_H)
#define CY_ISR_RXint_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void RXint_Start(void);
void RXint_StartEx(cyisraddress address);
void RXint_Stop(void);

CY_ISR_PROTO(RXint_Interrupt);

void RXint_SetVector(cyisraddress address);
cyisraddress RXint_GetVector(void);

void RXint_SetPriority(uint8 priority);
uint8 RXint_GetPriority(void);

void RXint_Enable(void);
uint8 RXint_GetState(void);
void RXint_Disable(void);

void RXint_SetPending(void);
void RXint_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the RXint ISR. */
#define RXint_INTC_VECTOR            ((reg32 *) RXint__INTC_VECT)

/* Address of the RXint ISR priority. */
#define RXint_INTC_PRIOR             ((reg8 *) RXint__INTC_PRIOR_REG)

/* Priority of the RXint interrupt. */
#define RXint_INTC_PRIOR_NUMBER      RXint__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable RXint interrupt. */
#define RXint_INTC_SET_EN            ((reg32 *) RXint__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the RXint interrupt. */
#define RXint_INTC_CLR_EN            ((reg32 *) RXint__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the RXint interrupt state to pending. */
#define RXint_INTC_SET_PD            ((reg32 *) RXint__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the RXint interrupt. */
#define RXint_INTC_CLR_PD            ((reg32 *) RXint__INTC_CLR_PD_REG)


#endif /* CY_ISR_RXint_H */


/* [] END OF FILE */
