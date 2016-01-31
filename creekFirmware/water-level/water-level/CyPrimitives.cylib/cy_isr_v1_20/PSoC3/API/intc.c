/*******************************************************************************
* File Name: `$INSTANCE_NAME`_intc.c  
* Version `$CY_MAJOR_VERSION`.`$CY_MINOR_VERSION`
*
*  Description:
*   API for controlling the state of an interrupt.
*
*
*  Note:
*
********************************************************************************
* Copyright 2008-2009, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/


#include <CYDEVICE.H>
#include <`$INSTANCE_NAME`.H>


/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START `$INSTANCE_NAME`_intc` */
    
    
/* `#END` */


/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_Start
********************************************************************************
* Summary:
*  Set up the interrupt and enable it.
*
* Parameters:  
*   void.
*
*
* Return:
*   void.
*
*******************************************************************************/
void `$INSTANCE_NAME`_Start(void)
{
    /* For all we know the interrupt is active. */
    `$INSTANCE_NAME`_Disable();

    /* Set the ISR to point to the `$INSTANCE_NAME` Interrupt. */
    `$INSTANCE_NAME`_SetVector(`$INSTANCE_NAME`_Interrupt);

    /* Set the priority. */
    `$INSTANCE_NAME`_SetPriority(`$INSTANCE_NAME`_INTC_PRIOR_NUMBER);

    /* Enable it. */
    `$INSTANCE_NAME`_Enable();
}

/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_Stop
********************************************************************************
* Summary:
*   Disables and removes the interrupt.
*
* Parameters:  
*
*
* Return:
*   void.
*
*******************************************************************************/
void `$INSTANCE_NAME`_Stop(void)
{
    /* Disable this interrupt. */
    `$INSTANCE_NAME`_Disable();

    /* Set the ISR to point to the passive one. */
//    `$INSTANCE_NAME`_SetVector(CyDefaultInterrupt);
}

/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_Interrupt
********************************************************************************
* Summary:
*   The default Interrupt Service Routine for `$INSTANCE_NAME`.
*
*   Add custom code between the coments to keep the next version of this file
*   from over writting your code.
*
*
*
* Parameters:  
*
*
* Return:
*   void.
*
*******************************************************************************/
CY_ISR(`$INSTANCE_NAME`_Interrupt)
{
    /*  Place your Interrupt code here. */
    /* `#START `$INSTANCE_NAME`_Interrupt` */


    /* `#END` */

    /* PSoC3 ES1, ES2 RTC ISR PATCH  */ 
    #if(CYDEV_CHIP_DIE_EXPECT == CYDEV_CHIP_DIE_LEOPARD)
        #if((CYDEV_CHIP_REV_EXPECT <= CYDEV_CHIP_REV_LEOPARD_ES2) && (`$INSTANCE_NAME`__ES2_PATCH ))      
            `$INSTANCE_NAME`_ISR_PATCH();
        #endif
    #endif
}


/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_SetVector
********************************************************************************
* Summary:
*   Change the ISR vector for the Interrupt.
*
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
*
* Return:
*   void.
*
*
*******************************************************************************/
void `$INSTANCE_NAME`_SetVector(cyisraddress address)
{
    CY_SET_REG16(`$INSTANCE_NAME`_INTC_VECTOR, (uint16) address);
}

/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_GetVector
********************************************************************************
* Summary:
*   Gets the "address" of the current ISR vector for the Interrupt.
*
*
* Parameters:
*   void.
*
*
* Return:
*   Address of the ISR in the interrupt vector table.
*
*
*******************************************************************************/
cyisraddress `$INSTANCE_NAME`_GetVector(void)
{
    return (cyisraddress) CY_GET_REG16(`$INSTANCE_NAME`_INTC_VECTOR);
}

/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_SetPriority
********************************************************************************
* Summary:
*   Sets the Priority of the Interrupt.
*
*
* Parameters:
*   priority: Priority of the interrupt. 0 - 7, 0 being the highest.
*
*
* Return:
*   void.
*
*
*******************************************************************************/
void `$INSTANCE_NAME`_SetPriority(uint8 priority)
{
    *`$INSTANCE_NAME`_INTC_PRIOR = priority << 5;
}

/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_GetPriority
********************************************************************************
* Summary:
*   Gets the Priority of the Interrupt.
*
*
* Parameters:
*   void.
*
*
* Return:
*   Priority of the interrupt. 0 - 7, 0 being the highest.
*
*
*******************************************************************************/
uint8 `$INSTANCE_NAME`_GetPriority(void)
{
    uint8 priority;


    priority = *`$INSTANCE_NAME`_INTC_PRIOR >> 5;

    return priority;
}

/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_Enable
********************************************************************************
* Summary:
*   Enables the interrupt.
*
*
* Parameters:
*   void.
*
*
* Return:
*   void.
*
*
*******************************************************************************/
void `$INSTANCE_NAME`_Enable(void)
{
    /* Enable the general interrupt. */
    *`$INSTANCE_NAME`_INTC_SET_EN = `$INSTANCE_NAME`__INTC_MASK;
}

/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_GetState
********************************************************************************
* Summary:
*   Gets the state (enabled, disabled) of the Interrupt.
*
*
* Parameters:
*   void.
*
*
* Return:
*   1 if enabled, 0 if disabled.
*
*
*******************************************************************************/
uint8 `$INSTANCE_NAME`_GetState(void)
{
    /* Get the state of the general interrupt. */
    return (*`$INSTANCE_NAME`_INTC_SET_EN & `$INSTANCE_NAME`__INTC_MASK) ? 1:0;
}

/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_Disable
********************************************************************************
* Summary:
*   Disables the Interrupt.
*
*
* Parameters:
*   void.
*
*
* Return:
*   void.
*
*
*******************************************************************************/
void `$INSTANCE_NAME`_Disable(void)
{
    /* Disable the general interrupt. */
    *`$INSTANCE_NAME`_INTC_CLR_EN = `$INSTANCE_NAME`__INTC_MASK;
}

/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_SetPending
********************************************************************************
* Summary:
*   Causes the Interrupt to enter the pending state, a software method of
*   generating the interrupt.
*
*
* Parameters:
*   void.
*
*
* Return:
*   void.
*
*
*******************************************************************************/
void `$INSTANCE_NAME`_SetPending(void)
{
    *`$INSTANCE_NAME`_INTC_SET_PD = `$INSTANCE_NAME`__INTC_MASK;
}

/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_ClearPending
********************************************************************************
* Summary:
*   Clears a pending interrupt.
*
* Parameters:
*   void.
*
*
* Return:
*   void.
*
*
*******************************************************************************/
void `$INSTANCE_NAME`_ClearPending(void)
{
    *`$INSTANCE_NAME`_INTC_CLR_PD = `$INSTANCE_NAME`__INTC_MASK;
}


















































