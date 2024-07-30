/*******************************************************************************
* File Name: MQ2.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_MQ2_ALIASES_H) /* Pins MQ2_ALIASES_H */
#define CY_PINS_MQ2_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define MQ2_0			(MQ2__0__PC)
#define MQ2_0_INTR	((uint16)((uint16)0x0001u << MQ2__0__SHIFT))

#define MQ2_INTR_ALL	 ((uint16)(MQ2_0_INTR))

#endif /* End Pins MQ2_ALIASES_H */


/* [] END OF FILE */
