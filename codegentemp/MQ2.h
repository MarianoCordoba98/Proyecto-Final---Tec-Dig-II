/*******************************************************************************
* File Name: MQ2.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_MQ2_H) /* Pins MQ2_H */
#define CY_PINS_MQ2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "MQ2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 MQ2__PORT == 15 && ((MQ2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    MQ2_Write(uint8 value);
void    MQ2_SetDriveMode(uint8 mode);
uint8   MQ2_ReadDataReg(void);
uint8   MQ2_Read(void);
void    MQ2_SetInterruptMode(uint16 position, uint16 mode);
uint8   MQ2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the MQ2_SetDriveMode() function.
     *  @{
     */
        #define MQ2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define MQ2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define MQ2_DM_RES_UP          PIN_DM_RES_UP
        #define MQ2_DM_RES_DWN         PIN_DM_RES_DWN
        #define MQ2_DM_OD_LO           PIN_DM_OD_LO
        #define MQ2_DM_OD_HI           PIN_DM_OD_HI
        #define MQ2_DM_STRONG          PIN_DM_STRONG
        #define MQ2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define MQ2_MASK               MQ2__MASK
#define MQ2_SHIFT              MQ2__SHIFT
#define MQ2_WIDTH              1u

/* Interrupt constants */
#if defined(MQ2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in MQ2_SetInterruptMode() function.
     *  @{
     */
        #define MQ2_INTR_NONE      (uint16)(0x0000u)
        #define MQ2_INTR_RISING    (uint16)(0x0001u)
        #define MQ2_INTR_FALLING   (uint16)(0x0002u)
        #define MQ2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define MQ2_INTR_MASK      (0x01u) 
#endif /* (MQ2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MQ2_PS                     (* (reg8 *) MQ2__PS)
/* Data Register */
#define MQ2_DR                     (* (reg8 *) MQ2__DR)
/* Port Number */
#define MQ2_PRT_NUM                (* (reg8 *) MQ2__PRT) 
/* Connect to Analog Globals */                                                  
#define MQ2_AG                     (* (reg8 *) MQ2__AG)                       
/* Analog MUX bux enable */
#define MQ2_AMUX                   (* (reg8 *) MQ2__AMUX) 
/* Bidirectional Enable */                                                        
#define MQ2_BIE                    (* (reg8 *) MQ2__BIE)
/* Bit-mask for Aliased Register Access */
#define MQ2_BIT_MASK               (* (reg8 *) MQ2__BIT_MASK)
/* Bypass Enable */
#define MQ2_BYP                    (* (reg8 *) MQ2__BYP)
/* Port wide control signals */                                                   
#define MQ2_CTL                    (* (reg8 *) MQ2__CTL)
/* Drive Modes */
#define MQ2_DM0                    (* (reg8 *) MQ2__DM0) 
#define MQ2_DM1                    (* (reg8 *) MQ2__DM1)
#define MQ2_DM2                    (* (reg8 *) MQ2__DM2) 
/* Input Buffer Disable Override */
#define MQ2_INP_DIS                (* (reg8 *) MQ2__INP_DIS)
/* LCD Common or Segment Drive */
#define MQ2_LCD_COM_SEG            (* (reg8 *) MQ2__LCD_COM_SEG)
/* Enable Segment LCD */
#define MQ2_LCD_EN                 (* (reg8 *) MQ2__LCD_EN)
/* Slew Rate Control */
#define MQ2_SLW                    (* (reg8 *) MQ2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define MQ2_PRTDSI__CAPS_SEL       (* (reg8 *) MQ2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define MQ2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) MQ2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define MQ2_PRTDSI__OE_SEL0        (* (reg8 *) MQ2__PRTDSI__OE_SEL0) 
#define MQ2_PRTDSI__OE_SEL1        (* (reg8 *) MQ2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define MQ2_PRTDSI__OUT_SEL0       (* (reg8 *) MQ2__PRTDSI__OUT_SEL0) 
#define MQ2_PRTDSI__OUT_SEL1       (* (reg8 *) MQ2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define MQ2_PRTDSI__SYNC_OUT       (* (reg8 *) MQ2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(MQ2__SIO_CFG)
    #define MQ2_SIO_HYST_EN        (* (reg8 *) MQ2__SIO_HYST_EN)
    #define MQ2_SIO_REG_HIFREQ     (* (reg8 *) MQ2__SIO_REG_HIFREQ)
    #define MQ2_SIO_CFG            (* (reg8 *) MQ2__SIO_CFG)
    #define MQ2_SIO_DIFF           (* (reg8 *) MQ2__SIO_DIFF)
#endif /* (MQ2__SIO_CFG) */

/* Interrupt Registers */
#if defined(MQ2__INTSTAT)
    #define MQ2_INTSTAT            (* (reg8 *) MQ2__INTSTAT)
    #define MQ2_SNAP               (* (reg8 *) MQ2__SNAP)
    
	#define MQ2_0_INTTYPE_REG 		(* (reg8 *) MQ2__0__INTTYPE)
#endif /* (MQ2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_MQ2_H */


/* [] END OF FILE */
