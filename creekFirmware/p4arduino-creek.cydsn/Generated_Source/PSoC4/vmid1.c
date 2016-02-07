/*******************************************************************************
* File Name: vmid1.c  
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
#include "vmid1.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        vmid1_PC =   (vmid1_PC & \
                                (uint32)(~(uint32)(vmid1_DRIVE_MODE_IND_MASK << (vmid1_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (vmid1_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: vmid1_Write
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
void vmid1_Write(uint8 value) 
{
    uint8 drVal = (uint8)(vmid1_DR & (uint8)(~vmid1_MASK));
    drVal = (drVal | ((uint8)(value << vmid1_SHIFT) & vmid1_MASK));
    vmid1_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: vmid1_SetDriveMode
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
void vmid1_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(vmid1__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: vmid1_Read
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
*  Macro vmid1_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 vmid1_Read(void) 
{
    return (uint8)((vmid1_PS & vmid1_MASK) >> vmid1_SHIFT);
}


/*******************************************************************************
* Function Name: vmid1_ReadDataReg
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
uint8 vmid1_ReadDataReg(void) 
{
    return (uint8)((vmid1_DR & vmid1_MASK) >> vmid1_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(vmid1_INTSTAT) 

    /*******************************************************************************
    * Function Name: vmid1_ClearInterrupt
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
    uint8 vmid1_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(vmid1_INTSTAT & vmid1_MASK);
		vmid1_INTSTAT = maskedStatus;
        return maskedStatus >> vmid1_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
