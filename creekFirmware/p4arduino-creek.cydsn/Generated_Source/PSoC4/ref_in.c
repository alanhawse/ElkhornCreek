/*******************************************************************************
* File Name: ref_in.c  
* Version 1.90
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "ref_in.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        ref_in_PC =   (ref_in_PC & \
                                (uint32)(~(uint32)(ref_in_DRIVE_MODE_IND_MASK << (ref_in_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (ref_in_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: ref_in_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void ref_in_Write(uint8 value) 
{
    uint8 drVal = (uint8)(ref_in_DR & (uint8)(~ref_in_MASK));
    drVal = (drVal | ((uint8)(value << ref_in_SHIFT) & ref_in_MASK));
    ref_in_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: ref_in_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to this drive mode.
*
* Return: 
*  None
*
*******************************************************************************/
void ref_in_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(ref_in__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: ref_in_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro ref_in_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 ref_in_Read(void) 
{
    return (uint8)((ref_in_PS & ref_in_MASK) >> ref_in_SHIFT);
}


/*******************************************************************************
* Function Name: ref_in_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 ref_in_ReadDataReg(void) 
{
    return (uint8)((ref_in_DR & ref_in_MASK) >> ref_in_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(ref_in_INTSTAT) 

    /*******************************************************************************
    * Function Name: ref_in_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 ref_in_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(ref_in_INTSTAT & ref_in_MASK);
		ref_in_INTSTAT = maskedStatus;
        return maskedStatus >> ref_in_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
