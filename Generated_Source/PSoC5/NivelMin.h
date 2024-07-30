/*******************************************************************************
* File Name: NivelMin.h  
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

#if !defined(CY_PINS_NivelMin_H) /* Pins NivelMin_H */
#define CY_PINS_NivelMin_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "NivelMin_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 NivelMin__PORT == 15 && ((NivelMin__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    NivelMin_Write(uint8 value);
void    NivelMin_SetDriveMode(uint8 mode);
uint8   NivelMin_ReadDataReg(void);
uint8   NivelMin_Read(void);
void    NivelMin_SetInterruptMode(uint16 position, uint16 mode);
uint8   NivelMin_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the NivelMin_SetDriveMode() function.
     *  @{
     */
        #define NivelMin_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define NivelMin_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define NivelMin_DM_RES_UP          PIN_DM_RES_UP
        #define NivelMin_DM_RES_DWN         PIN_DM_RES_DWN
        #define NivelMin_DM_OD_LO           PIN_DM_OD_LO
        #define NivelMin_DM_OD_HI           PIN_DM_OD_HI
        #define NivelMin_DM_STRONG          PIN_DM_STRONG
        #define NivelMin_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define NivelMin_MASK               NivelMin__MASK
#define NivelMin_SHIFT              NivelMin__SHIFT
#define NivelMin_WIDTH              1u

/* Interrupt constants */
#if defined(NivelMin__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in NivelMin_SetInterruptMode() function.
     *  @{
     */
        #define NivelMin_INTR_NONE      (uint16)(0x0000u)
        #define NivelMin_INTR_RISING    (uint16)(0x0001u)
        #define NivelMin_INTR_FALLING   (uint16)(0x0002u)
        #define NivelMin_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define NivelMin_INTR_MASK      (0x01u) 
#endif /* (NivelMin__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define NivelMin_PS                     (* (reg8 *) NivelMin__PS)
/* Data Register */
#define NivelMin_DR                     (* (reg8 *) NivelMin__DR)
/* Port Number */
#define NivelMin_PRT_NUM                (* (reg8 *) NivelMin__PRT) 
/* Connect to Analog Globals */                                                  
#define NivelMin_AG                     (* (reg8 *) NivelMin__AG)                       
/* Analog MUX bux enable */
#define NivelMin_AMUX                   (* (reg8 *) NivelMin__AMUX) 
/* Bidirectional Enable */                                                        
#define NivelMin_BIE                    (* (reg8 *) NivelMin__BIE)
/* Bit-mask for Aliased Register Access */
#define NivelMin_BIT_MASK               (* (reg8 *) NivelMin__BIT_MASK)
/* Bypass Enable */
#define NivelMin_BYP                    (* (reg8 *) NivelMin__BYP)
/* Port wide control signals */                                                   
#define NivelMin_CTL                    (* (reg8 *) NivelMin__CTL)
/* Drive Modes */
#define NivelMin_DM0                    (* (reg8 *) NivelMin__DM0) 
#define NivelMin_DM1                    (* (reg8 *) NivelMin__DM1)
#define NivelMin_DM2                    (* (reg8 *) NivelMin__DM2) 
/* Input Buffer Disable Override */
#define NivelMin_INP_DIS                (* (reg8 *) NivelMin__INP_DIS)
/* LCD Common or Segment Drive */
#define NivelMin_LCD_COM_SEG            (* (reg8 *) NivelMin__LCD_COM_SEG)
/* Enable Segment LCD */
#define NivelMin_LCD_EN                 (* (reg8 *) NivelMin__LCD_EN)
/* Slew Rate Control */
#define NivelMin_SLW                    (* (reg8 *) NivelMin__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define NivelMin_PRTDSI__CAPS_SEL       (* (reg8 *) NivelMin__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define NivelMin_PRTDSI__DBL_SYNC_IN    (* (reg8 *) NivelMin__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define NivelMin_PRTDSI__OE_SEL0        (* (reg8 *) NivelMin__PRTDSI__OE_SEL0) 
#define NivelMin_PRTDSI__OE_SEL1        (* (reg8 *) NivelMin__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define NivelMin_PRTDSI__OUT_SEL0       (* (reg8 *) NivelMin__PRTDSI__OUT_SEL0) 
#define NivelMin_PRTDSI__OUT_SEL1       (* (reg8 *) NivelMin__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define NivelMin_PRTDSI__SYNC_OUT       (* (reg8 *) NivelMin__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(NivelMin__SIO_CFG)
    #define NivelMin_SIO_HYST_EN        (* (reg8 *) NivelMin__SIO_HYST_EN)
    #define NivelMin_SIO_REG_HIFREQ     (* (reg8 *) NivelMin__SIO_REG_HIFREQ)
    #define NivelMin_SIO_CFG            (* (reg8 *) NivelMin__SIO_CFG)
    #define NivelMin_SIO_DIFF           (* (reg8 *) NivelMin__SIO_DIFF)
#endif /* (NivelMin__SIO_CFG) */

/* Interrupt Registers */
#if defined(NivelMin__INTSTAT)
    #define NivelMin_INTSTAT            (* (reg8 *) NivelMin__INTSTAT)
    #define NivelMin_SNAP               (* (reg8 *) NivelMin__SNAP)
    
	#define NivelMin_0_INTTYPE_REG 		(* (reg8 *) NivelMin__0__INTTYPE)
#endif /* (NivelMin__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_NivelMin_H */


/* [] END OF FILE */
