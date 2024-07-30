/*******************************************************************************
* File Name: Bomba.h  
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

#if !defined(CY_PINS_Bomba_H) /* Pins Bomba_H */
#define CY_PINS_Bomba_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Bomba_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Bomba__PORT == 15 && ((Bomba__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Bomba_Write(uint8 value);
void    Bomba_SetDriveMode(uint8 mode);
uint8   Bomba_ReadDataReg(void);
uint8   Bomba_Read(void);
void    Bomba_SetInterruptMode(uint16 position, uint16 mode);
uint8   Bomba_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Bomba_SetDriveMode() function.
     *  @{
     */
        #define Bomba_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Bomba_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Bomba_DM_RES_UP          PIN_DM_RES_UP
        #define Bomba_DM_RES_DWN         PIN_DM_RES_DWN
        #define Bomba_DM_OD_LO           PIN_DM_OD_LO
        #define Bomba_DM_OD_HI           PIN_DM_OD_HI
        #define Bomba_DM_STRONG          PIN_DM_STRONG
        #define Bomba_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Bomba_MASK               Bomba__MASK
#define Bomba_SHIFT              Bomba__SHIFT
#define Bomba_WIDTH              1u

/* Interrupt constants */
#if defined(Bomba__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Bomba_SetInterruptMode() function.
     *  @{
     */
        #define Bomba_INTR_NONE      (uint16)(0x0000u)
        #define Bomba_INTR_RISING    (uint16)(0x0001u)
        #define Bomba_INTR_FALLING   (uint16)(0x0002u)
        #define Bomba_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Bomba_INTR_MASK      (0x01u) 
#endif /* (Bomba__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Bomba_PS                     (* (reg8 *) Bomba__PS)
/* Data Register */
#define Bomba_DR                     (* (reg8 *) Bomba__DR)
/* Port Number */
#define Bomba_PRT_NUM                (* (reg8 *) Bomba__PRT) 
/* Connect to Analog Globals */                                                  
#define Bomba_AG                     (* (reg8 *) Bomba__AG)                       
/* Analog MUX bux enable */
#define Bomba_AMUX                   (* (reg8 *) Bomba__AMUX) 
/* Bidirectional Enable */                                                        
#define Bomba_BIE                    (* (reg8 *) Bomba__BIE)
/* Bit-mask for Aliased Register Access */
#define Bomba_BIT_MASK               (* (reg8 *) Bomba__BIT_MASK)
/* Bypass Enable */
#define Bomba_BYP                    (* (reg8 *) Bomba__BYP)
/* Port wide control signals */                                                   
#define Bomba_CTL                    (* (reg8 *) Bomba__CTL)
/* Drive Modes */
#define Bomba_DM0                    (* (reg8 *) Bomba__DM0) 
#define Bomba_DM1                    (* (reg8 *) Bomba__DM1)
#define Bomba_DM2                    (* (reg8 *) Bomba__DM2) 
/* Input Buffer Disable Override */
#define Bomba_INP_DIS                (* (reg8 *) Bomba__INP_DIS)
/* LCD Common or Segment Drive */
#define Bomba_LCD_COM_SEG            (* (reg8 *) Bomba__LCD_COM_SEG)
/* Enable Segment LCD */
#define Bomba_LCD_EN                 (* (reg8 *) Bomba__LCD_EN)
/* Slew Rate Control */
#define Bomba_SLW                    (* (reg8 *) Bomba__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Bomba_PRTDSI__CAPS_SEL       (* (reg8 *) Bomba__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Bomba_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Bomba__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Bomba_PRTDSI__OE_SEL0        (* (reg8 *) Bomba__PRTDSI__OE_SEL0) 
#define Bomba_PRTDSI__OE_SEL1        (* (reg8 *) Bomba__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Bomba_PRTDSI__OUT_SEL0       (* (reg8 *) Bomba__PRTDSI__OUT_SEL0) 
#define Bomba_PRTDSI__OUT_SEL1       (* (reg8 *) Bomba__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Bomba_PRTDSI__SYNC_OUT       (* (reg8 *) Bomba__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Bomba__SIO_CFG)
    #define Bomba_SIO_HYST_EN        (* (reg8 *) Bomba__SIO_HYST_EN)
    #define Bomba_SIO_REG_HIFREQ     (* (reg8 *) Bomba__SIO_REG_HIFREQ)
    #define Bomba_SIO_CFG            (* (reg8 *) Bomba__SIO_CFG)
    #define Bomba_SIO_DIFF           (* (reg8 *) Bomba__SIO_DIFF)
#endif /* (Bomba__SIO_CFG) */

/* Interrupt Registers */
#if defined(Bomba__INTSTAT)
    #define Bomba_INTSTAT            (* (reg8 *) Bomba__INTSTAT)
    #define Bomba_SNAP               (* (reg8 *) Bomba__SNAP)
    
	#define Bomba_0_INTTYPE_REG 		(* (reg8 *) Bomba__0__INTTYPE)
#endif /* (Bomba__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Bomba_H */


/* [] END OF FILE */
