/*******************************************************************************
* File Name: Llama.h  
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

#if !defined(CY_PINS_Llama_H) /* Pins Llama_H */
#define CY_PINS_Llama_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Llama_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Llama__PORT == 15 && ((Llama__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Llama_Write(uint8 value);
void    Llama_SetDriveMode(uint8 mode);
uint8   Llama_ReadDataReg(void);
uint8   Llama_Read(void);
void    Llama_SetInterruptMode(uint16 position, uint16 mode);
uint8   Llama_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Llama_SetDriveMode() function.
     *  @{
     */
        #define Llama_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Llama_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Llama_DM_RES_UP          PIN_DM_RES_UP
        #define Llama_DM_RES_DWN         PIN_DM_RES_DWN
        #define Llama_DM_OD_LO           PIN_DM_OD_LO
        #define Llama_DM_OD_HI           PIN_DM_OD_HI
        #define Llama_DM_STRONG          PIN_DM_STRONG
        #define Llama_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Llama_MASK               Llama__MASK
#define Llama_SHIFT              Llama__SHIFT
#define Llama_WIDTH              1u

/* Interrupt constants */
#if defined(Llama__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Llama_SetInterruptMode() function.
     *  @{
     */
        #define Llama_INTR_NONE      (uint16)(0x0000u)
        #define Llama_INTR_RISING    (uint16)(0x0001u)
        #define Llama_INTR_FALLING   (uint16)(0x0002u)
        #define Llama_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Llama_INTR_MASK      (0x01u) 
#endif /* (Llama__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Llama_PS                     (* (reg8 *) Llama__PS)
/* Data Register */
#define Llama_DR                     (* (reg8 *) Llama__DR)
/* Port Number */
#define Llama_PRT_NUM                (* (reg8 *) Llama__PRT) 
/* Connect to Analog Globals */                                                  
#define Llama_AG                     (* (reg8 *) Llama__AG)                       
/* Analog MUX bux enable */
#define Llama_AMUX                   (* (reg8 *) Llama__AMUX) 
/* Bidirectional Enable */                                                        
#define Llama_BIE                    (* (reg8 *) Llama__BIE)
/* Bit-mask for Aliased Register Access */
#define Llama_BIT_MASK               (* (reg8 *) Llama__BIT_MASK)
/* Bypass Enable */
#define Llama_BYP                    (* (reg8 *) Llama__BYP)
/* Port wide control signals */                                                   
#define Llama_CTL                    (* (reg8 *) Llama__CTL)
/* Drive Modes */
#define Llama_DM0                    (* (reg8 *) Llama__DM0) 
#define Llama_DM1                    (* (reg8 *) Llama__DM1)
#define Llama_DM2                    (* (reg8 *) Llama__DM2) 
/* Input Buffer Disable Override */
#define Llama_INP_DIS                (* (reg8 *) Llama__INP_DIS)
/* LCD Common or Segment Drive */
#define Llama_LCD_COM_SEG            (* (reg8 *) Llama__LCD_COM_SEG)
/* Enable Segment LCD */
#define Llama_LCD_EN                 (* (reg8 *) Llama__LCD_EN)
/* Slew Rate Control */
#define Llama_SLW                    (* (reg8 *) Llama__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Llama_PRTDSI__CAPS_SEL       (* (reg8 *) Llama__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Llama_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Llama__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Llama_PRTDSI__OE_SEL0        (* (reg8 *) Llama__PRTDSI__OE_SEL0) 
#define Llama_PRTDSI__OE_SEL1        (* (reg8 *) Llama__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Llama_PRTDSI__OUT_SEL0       (* (reg8 *) Llama__PRTDSI__OUT_SEL0) 
#define Llama_PRTDSI__OUT_SEL1       (* (reg8 *) Llama__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Llama_PRTDSI__SYNC_OUT       (* (reg8 *) Llama__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Llama__SIO_CFG)
    #define Llama_SIO_HYST_EN        (* (reg8 *) Llama__SIO_HYST_EN)
    #define Llama_SIO_REG_HIFREQ     (* (reg8 *) Llama__SIO_REG_HIFREQ)
    #define Llama_SIO_CFG            (* (reg8 *) Llama__SIO_CFG)
    #define Llama_SIO_DIFF           (* (reg8 *) Llama__SIO_DIFF)
#endif /* (Llama__SIO_CFG) */

/* Interrupt Registers */
#if defined(Llama__INTSTAT)
    #define Llama_INTSTAT            (* (reg8 *) Llama__INTSTAT)
    #define Llama_SNAP               (* (reg8 *) Llama__SNAP)
    
	#define Llama_0_INTTYPE_REG 		(* (reg8 *) Llama__0__INTTYPE)
#endif /* (Llama__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Llama_H */


/* [] END OF FILE */
