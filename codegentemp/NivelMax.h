/*******************************************************************************
* File Name: NivelMax.h  
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

#if !defined(CY_PINS_NivelMax_H) /* Pins NivelMax_H */
#define CY_PINS_NivelMax_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "NivelMax_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 NivelMax__PORT == 15 && ((NivelMax__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    NivelMax_Write(uint8 value);
void    NivelMax_SetDriveMode(uint8 mode);
uint8   NivelMax_ReadDataReg(void);
uint8   NivelMax_Read(void);
void    NivelMax_SetInterruptMode(uint16 position, uint16 mode);
uint8   NivelMax_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the NivelMax_SetDriveMode() function.
     *  @{
     */
        #define NivelMax_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define NivelMax_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define NivelMax_DM_RES_UP          PIN_DM_RES_UP
        #define NivelMax_DM_RES_DWN         PIN_DM_RES_DWN
        #define NivelMax_DM_OD_LO           PIN_DM_OD_LO
        #define NivelMax_DM_OD_HI           PIN_DM_OD_HI
        #define NivelMax_DM_STRONG          PIN_DM_STRONG
        #define NivelMax_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define NivelMax_MASK               NivelMax__MASK
#define NivelMax_SHIFT              NivelMax__SHIFT
#define NivelMax_WIDTH              1u

/* Interrupt constants */
#if defined(NivelMax__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in NivelMax_SetInterruptMode() function.
     *  @{
     */
        #define NivelMax_INTR_NONE      (uint16)(0x0000u)
        #define NivelMax_INTR_RISING    (uint16)(0x0001u)
        #define NivelMax_INTR_FALLING   (uint16)(0x0002u)
        #define NivelMax_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define NivelMax_INTR_MASK      (0x01u) 
#endif /* (NivelMax__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define NivelMax_PS                     (* (reg8 *) NivelMax__PS)
/* Data Register */
#define NivelMax_DR                     (* (reg8 *) NivelMax__DR)
/* Port Number */
#define NivelMax_PRT_NUM                (* (reg8 *) NivelMax__PRT) 
/* Connect to Analog Globals */                                                  
#define NivelMax_AG                     (* (reg8 *) NivelMax__AG)                       
/* Analog MUX bux enable */
#define NivelMax_AMUX                   (* (reg8 *) NivelMax__AMUX) 
/* Bidirectional Enable */                                                        
#define NivelMax_BIE                    (* (reg8 *) NivelMax__BIE)
/* Bit-mask for Aliased Register Access */
#define NivelMax_BIT_MASK               (* (reg8 *) NivelMax__BIT_MASK)
/* Bypass Enable */
#define NivelMax_BYP                    (* (reg8 *) NivelMax__BYP)
/* Port wide control signals */                                                   
#define NivelMax_CTL                    (* (reg8 *) NivelMax__CTL)
/* Drive Modes */
#define NivelMax_DM0                    (* (reg8 *) NivelMax__DM0) 
#define NivelMax_DM1                    (* (reg8 *) NivelMax__DM1)
#define NivelMax_DM2                    (* (reg8 *) NivelMax__DM2) 
/* Input Buffer Disable Override */
#define NivelMax_INP_DIS                (* (reg8 *) NivelMax__INP_DIS)
/* LCD Common or Segment Drive */
#define NivelMax_LCD_COM_SEG            (* (reg8 *) NivelMax__LCD_COM_SEG)
/* Enable Segment LCD */
#define NivelMax_LCD_EN                 (* (reg8 *) NivelMax__LCD_EN)
/* Slew Rate Control */
#define NivelMax_SLW                    (* (reg8 *) NivelMax__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define NivelMax_PRTDSI__CAPS_SEL       (* (reg8 *) NivelMax__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define NivelMax_PRTDSI__DBL_SYNC_IN    (* (reg8 *) NivelMax__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define NivelMax_PRTDSI__OE_SEL0        (* (reg8 *) NivelMax__PRTDSI__OE_SEL0) 
#define NivelMax_PRTDSI__OE_SEL1        (* (reg8 *) NivelMax__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define NivelMax_PRTDSI__OUT_SEL0       (* (reg8 *) NivelMax__PRTDSI__OUT_SEL0) 
#define NivelMax_PRTDSI__OUT_SEL1       (* (reg8 *) NivelMax__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define NivelMax_PRTDSI__SYNC_OUT       (* (reg8 *) NivelMax__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(NivelMax__SIO_CFG)
    #define NivelMax_SIO_HYST_EN        (* (reg8 *) NivelMax__SIO_HYST_EN)
    #define NivelMax_SIO_REG_HIFREQ     (* (reg8 *) NivelMax__SIO_REG_HIFREQ)
    #define NivelMax_SIO_CFG            (* (reg8 *) NivelMax__SIO_CFG)
    #define NivelMax_SIO_DIFF           (* (reg8 *) NivelMax__SIO_DIFF)
#endif /* (NivelMax__SIO_CFG) */

/* Interrupt Registers */
#if defined(NivelMax__INTSTAT)
    #define NivelMax_INTSTAT            (* (reg8 *) NivelMax__INTSTAT)
    #define NivelMax_SNAP               (* (reg8 *) NivelMax__SNAP)
    
	#define NivelMax_0_INTTYPE_REG 		(* (reg8 *) NivelMax__0__INTTYPE)
#endif /* (NivelMax__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_NivelMax_H */


/* [] END OF FILE */
