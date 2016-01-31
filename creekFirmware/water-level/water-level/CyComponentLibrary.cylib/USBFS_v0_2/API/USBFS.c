/*******************************************************************************
* File Name: `$INSTANCE_NAME`.c
* Version `$CY_MAJOR_VERSION`.`$CY_MINOR_VERSION`
*
*  Description:
*    API for USBFS Component.
*
*   Note:
*   
*   Many of the functions use endpoint number.  RAM arrays are sized with 9
*   elements so they are indexed directly by bEPNumber.  The SIE and ARB
*   registers are indexed by variations of bEPNumber - 1.
*
********************************************************************************
* Copyright 2008-2009, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/



#include "device.h"
#include "cyfitter.h"
#include "`$INSTANCE_NAME`.h"

/*******************************************************************************
* External data references
********************************************************************************/
extern uint8 `$INSTANCE_NAME`_bConfiguration;
extern uint8 `$INSTANCE_NAME`_bDeviceAddress;
extern uint8 `$INSTANCE_NAME`_bDeviceStatus;
extern uint8 `$INSTANCE_NAME`_bEPHalt;
extern uint8 `$INSTANCE_NAME`_bDevice;
extern uint8 `$INSTANCE_NAME`_bTransferState;
extern T_`$INSTANCE_NAME`_EP_CTL_BLOCK `$INSTANCE_NAME`_EP[];

/*******************************************************************************
* Forward function references
********************************************************************************/
void `$INSTANCE_NAME`_EnableInt(uint8 bVector, uint8 bMask);
void `$INSTANCE_NAME`_SetVector(uint8 bVector, uint16 wAddress);
void `$INSTANCE_NAME`_SetPriority(uint8 bVector, uint8 bPriority);
void `$INSTANCE_NAME`_InitComponent(uint8 bDevice, uint8 bMode);

/*******************************************************************************
* External function references
********************************************************************************/
CY_ISR_PROTO(`$INSTANCE_NAME`_EP_0_ISR);
CY_ISR_PROTO(`$INSTANCE_NAME`_EP_1_ISR);
CY_ISR_PROTO(`$INSTANCE_NAME`_EP_2_ISR);
CY_ISR_PROTO(`$INSTANCE_NAME`_EP_3_ISR);
CY_ISR_PROTO(`$INSTANCE_NAME`_EP_4_ISR);
CY_ISR_PROTO(`$INSTANCE_NAME`_EP_5_ISR);
CY_ISR_PROTO(`$INSTANCE_NAME`_EP_6_ISR);
CY_ISR_PROTO(`$INSTANCE_NAME`_EP_7_ISR);
CY_ISR_PROTO(`$INSTANCE_NAME`_EP_8_ISR);
CY_ISR_PROTO(`$INSTANCE_NAME`_BUS_RESET_ISR);
CY_ISR_PROTO(`$INSTANCE_NAME`_SOF_ISR);

/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_Start
********************************************************************************
* Summary:
*   This function initialize the USB SIE, arbiter and the
*   endpoint APIs, including setting the D+ Pullup
*
* Parameters:  
*   None
*******************************************************************************/
void `$INSTANCE_NAME`_Start(uint8 bDevice, uint8 bMode)
{
    uint16 i;
    uint8 *p = &`@INSTANCE_NAME`_ARB_RW1_DR[0];
    
    /* Enable USB block */
    CY_SET_REG8(CYDEV_PM_ACT_CFG5, CY_GET_REG8(CYDEV_PM_ACT_CFG5) | 0x01);
    //TODO: pbvr: disable PM available for USB
    CY_SET_REG8(CYDEV_PM_AVAIL_CR6, CY_GET_REG8(CYDEV_PM_AVAIL_CR6) & ~0x10);
    /* Enable core clock */
    CY_SET_REG8(`$INSTANCE_NAME`_USB_CLK_EN, 0x01);
    
    /* Bus Reset Length */
    CY_SET_REG8(`$INSTANCE_NAME`_BUS_RST_CNT, 3);
    // TODO: pbvr: Enable PM available for USB
    CY_SET_REG8(CYDEV_PM_AVAIL_CR6, CY_GET_REG8(CYDEV_PM_AVAIL_CR6) | 0x10);
    /* If VBUS Monitoring is enable, setup the DR in the port reg */
#if (`$INSTANCE_NAME`_MON_VBUS == 1)
    CY_SET_REG8(`$INSTANCE_NAME`_VBUS_DR, CY_GET_REG8(`$INSTANCE_NAME`_VBUS_DR) | `$INSTANCE_NAME`_VBUS_MASK);
#endif

    /* Write WAx */
    CY_SET_REG8(&`$INSTANCE_NAME`_ARB_RW1_WA[0],     0);
    CY_SET_REG8(&`$INSTANCE_NAME`_ARB_RW1_WA_MSB[0], 0);
    
    /* Copy the data using the arbiter data register */
    for (i = 0; i < 512; i++)
    {
        CY_SET_REG8(p, 0xFF);
    }

    /* Set the bus reset Interrupt. */
    `@INSTANCE_NAME`_SetVector(`$INSTANCE_NAME`_BUS_RESET_VECT_NUM,   `$INSTANCE_NAME`_BUS_RESET_ISR);
    `@INSTANCE_NAME`_SetPriority(`$INSTANCE_NAME`_BUS_RESET_VECT_NUM, `$INSTANCE_NAME`_BUS_RESET_PRIOR);
    `@INSTANCE_NAME`_EnableInt(`$INSTANCE_NAME`_BUS_RESET_VECT_NUM,   `$INSTANCE_NAME`_BUS_RESET_MASK);

    /* Set the SOF Interrupt. */
    `@INSTANCE_NAME`_SetVector(`$INSTANCE_NAME`_SOF_VECT_NUM,   `$INSTANCE_NAME`_SOF_ISR);
    `@INSTANCE_NAME`_SetPriority(`$INSTANCE_NAME`_SOF_VECT_NUM, `$INSTANCE_NAME`_SOF_PRIOR);
    `@INSTANCE_NAME`_EnableInt(`$INSTANCE_NAME`_SOF_VECT_NUM,   `$INSTANCE_NAME`_SOF_MASK);

    /* Set the Control Endpoint Interrupt. */
    `@INSTANCE_NAME`_SetVector(`$INSTANCE_NAME`_EP_0_VECT_NUM,   `$INSTANCE_NAME`_EP_0_ISR);
    `@INSTANCE_NAME`_SetPriority(`$INSTANCE_NAME`_EP_0_VECT_NUM, `$INSTANCE_NAME`_EP_0_PRIOR);
    `@INSTANCE_NAME`_EnableInt(`$INSTANCE_NAME`_EP_0_VECT_NUM,   `$INSTANCE_NAME`_EP_0_MASK);

    /* Set the Data Endpoint 1 Interrupt. */
    `@INSTANCE_NAME`_SetVector(`$INSTANCE_NAME`_EP_1_VECT_NUM,   `$INSTANCE_NAME`_EP_1_ISR);
    `@INSTANCE_NAME`_SetPriority(`$INSTANCE_NAME`_EP_1_VECT_NUM, `$INSTANCE_NAME`_EP_1_PRIOR);
    `@INSTANCE_NAME`_EnableInt(`$INSTANCE_NAME`_EP_1_VECT_NUM,   `$INSTANCE_NAME`_EP_1_MASK);

    /* Set the Data Endpoint 2 Interrupt. */
    `@INSTANCE_NAME`_SetVector(`$INSTANCE_NAME`_EP_2_VECT_NUM,   `$INSTANCE_NAME`_EP_2_ISR);
    `@INSTANCE_NAME`_SetPriority(`$INSTANCE_NAME`_EP_2_VECT_NUM, `$INSTANCE_NAME`_EP_2_PRIOR);
    `@INSTANCE_NAME`_EnableInt(`$INSTANCE_NAME`_EP_2_VECT_NUM,   `$INSTANCE_NAME`_EP_2_MASK);

    /* Set the Data Endpoint 3 Interrupt. */
    `@INSTANCE_NAME`_SetVector(`$INSTANCE_NAME`_EP_3_VECT_NUM,   `$INSTANCE_NAME`_EP_3_ISR);
    `@INSTANCE_NAME`_SetPriority(`$INSTANCE_NAME`_EP_3_VECT_NUM, `$INSTANCE_NAME`_EP_3_PRIOR);
    `@INSTANCE_NAME`_EnableInt(`$INSTANCE_NAME`_EP_3_VECT_NUM,   `$INSTANCE_NAME`_EP_3_MASK);

    /* Set the Data Endpoint 4 Interrupt. */
    `@INSTANCE_NAME`_SetVector(`$INSTANCE_NAME`_EP_4_VECT_NUM,   `$INSTANCE_NAME`_EP_4_ISR);
    `@INSTANCE_NAME`_SetPriority(`$INSTANCE_NAME`_EP_4_VECT_NUM, `$INSTANCE_NAME`_EP_4_PRIOR);
    `@INSTANCE_NAME`_EnableInt(`$INSTANCE_NAME`_EP_4_VECT_NUM,   `$INSTANCE_NAME`_EP_4_MASK);

    /* Set the Data Endpoint 5 Interrupt. */
    `@INSTANCE_NAME`_SetVector(`$INSTANCE_NAME`_EP_5_VECT_NUM,   `$INSTANCE_NAME`_EP_5_ISR);
    `@INSTANCE_NAME`_SetPriority(`$INSTANCE_NAME`_EP_5_VECT_NUM, `$INSTANCE_NAME`_EP_5_PRIOR);
    `@INSTANCE_NAME`_EnableInt(`$INSTANCE_NAME`_EP_5_VECT_NUM,   `$INSTANCE_NAME`_EP_5_MASK);

    /* Set the Data Endpoint 6 Interrupt. */
    `@INSTANCE_NAME`_SetVector(`$INSTANCE_NAME`_EP_6_VECT_NUM,   `$INSTANCE_NAME`_EP_6_ISR);
    `@INSTANCE_NAME`_SetPriority(`$INSTANCE_NAME`_EP_6_VECT_NUM, `$INSTANCE_NAME`_EP_6_PRIOR);
    `@INSTANCE_NAME`_EnableInt(`$INSTANCE_NAME`_EP_6_VECT_NUM,   `$INSTANCE_NAME`_EP_6_MASK);

     /* Set the Data Endpoint 7 Interrupt. */
    `@INSTANCE_NAME`_SetVector(`$INSTANCE_NAME`_EP_7_VECT_NUM,   `$INSTANCE_NAME`_EP_7_ISR);
    `@INSTANCE_NAME`_SetPriority(`$INSTANCE_NAME`_EP_7_VECT_NUM, `$INSTANCE_NAME`_EP_7_PRIOR);
    `@INSTANCE_NAME`_EnableInt(`$INSTANCE_NAME`_EP_7_VECT_NUM,   `$INSTANCE_NAME`_EP_7_MASK);

    /* Set the Data Endpoint 8 Interrupt. */
    `@INSTANCE_NAME`_SetVector(`$INSTANCE_NAME`_EP_8_VECT_NUM,   `$INSTANCE_NAME`_EP_8_ISR);
    `@INSTANCE_NAME`_SetPriority(`$INSTANCE_NAME`_EP_8_VECT_NUM, `$INSTANCE_NAME`_EP_8_PRIOR);
    `@INSTANCE_NAME`_EnableInt(`$INSTANCE_NAME`_EP_8_VECT_NUM,   `$INSTANCE_NAME`_EP_8_MASK);
    
    `$INSTANCE_NAME`_InitComponent(bDevice, bMode);
}
/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_InitComponent
********************************************************************************
* Summary:
*   Initialize the component, except for the HW which is done one time in
*	the Start function.  This function pulls up D+.
*
* Parameters:  
*   None
*******************************************************************************/
void `$INSTANCE_NAME`_InitComponent(uint8 bDevice, uint8 bMode)
{
    /* USB Locking: Enabled, VRegulator: Disabled */
    CY_SET_REG8(`$INSTANCE_NAME`_CR1, (bMode | 0x02));

    /* Record the descriptor selection */
    `$INSTANCE_NAME`_bDevice = bDevice;

    /* Clear all of the component data */
    `$INSTANCE_NAME`_bConfiguration = 0;
    `$INSTANCE_NAME`_bDeviceAddress  = 0;
    `$INSTANCE_NAME`_bEPHalt = 0;
    `$INSTANCE_NAME`_bDeviceStatus = 0;
    `$INSTANCE_NAME`_bDeviceStatus = 0;
    `$INSTANCE_NAME`_bTransferState = `$INSTANCE_NAME`_TRANS_STATE_IDLE;

    /* STALL_IN_OUT */
    CY_SET_REG8(`$INSTANCE_NAME`_EP0_CR, `$INSTANCE_NAME`_MODE_STALL_IN_OUT);
    /* Enable the SIE with an address 0 */
    CY_SET_REG8(`$INSTANCE_NAME`_CR0, `$INSTANCE_NAME`_CR0_ENABLE );
    /* Finally, Enable d+ pullup */
    CY_SET_REG8(`$INSTANCE_NAME`_USBIO_CR1, `$INSTANCE_NAME`_USBIO_CR1_USBPUEN);
}
/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_Stop
********************************************************************************
* Summary:
*   This function shuts down the USB function including to release
*   the D+ Pullup and disabling the SIE.
*
* Parameters:  
*   None
*******************************************************************************/
void `@INSTANCE_NAME`_Stop(void)
{
    /* Disable the SIE with address 0 */
    CY_SET_REG8(`$INSTANCE_NAME`_CR0, 0x00);
    /* Disable the d+ pullup */
    CY_SET_REG8(`$INSTANCE_NAME`_USBIO_CR1, 0x00);
    /* Disable the reset interrupt */
// TODO:	`@INSTANCE_NAME`_DisableInt(`$INSTANCE_NAME`_BUS_RESET_VECT_NUM,   `$INSTANCE_NAME`_BUS_RESET_MASK);
// TODO:	`@INSTANCE_NAME`_EnableInt(`$INSTANCE_NAME`_EP_0_VECT_NUM,   `$INSTANCE_NAME`_EP_0_MASK);

    `$INSTANCE_NAME`_bConfiguration = 0;
    `$INSTANCE_NAME`_bDeviceAddress  = 0;
    `$INSTANCE_NAME`_bEPHalt = 0;
    `$INSTANCE_NAME`_bDeviceStatus = 0;
}
/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_bCheckActivity
********************************************************************************
* Summary:
*   Returns the activity status of the bus.  Clears the status hardware to
*   provide fresh activity status on the next call of this routine.
*
* Parameters:  
*   None
*******************************************************************************/
uint8  `@INSTANCE_NAME`_bCheckActivity(void)
{
    uint8 r = ((CY_GET_REG8(`$INSTANCE_NAME`_CR1) >> 2) & `$INSTANCE_NAME`_CR1_BUS_ACTIVITY);

    CY_SET_REG8(`$INSTANCE_NAME`_CR1, (CY_GET_REG8(`$INSTANCE_NAME`_CR1) & `$INSTANCE_NAME`_CR1_BUS_ACTIVITY));

    return r;
}
/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_bGetConfiguration
********************************************************************************
* Summary:
*   Returns the current configuration setting
*
* Parameters:  
*   None
*******************************************************************************/
uint8  `@INSTANCE_NAME`_bGetConfiguration(void)
{
    return `$INSTANCE_NAME`_bConfiguration;
}
/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_bGetEPState
********************************************************************************
* Summary:
*   Returned the state of the requested endpoint.
*
* Parameters:  
*   bEPNumber: Endpoint Number
*******************************************************************************/
uint8 `@INSTANCE_NAME`_bGetEPState(uint8 bEPNumber)
{
    return `$INSTANCE_NAME`_EP[bEPNumber].bAPIEPState;
}
/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_wGetEPCount
********************************************************************************
* Summary:
*   Returns the transfer count for the requested endpoint.  The the value from
*   the count registers includes 2 counts for the two byte checksum of the
*   packet.  This function subtracts the two counts.
*
* Parameters:  
*   bEPNumber: Endpoint Number
*******************************************************************************/
uint16 `@INSTANCE_NAME`_wGetEPCount(uint8 bEPNumber)
{
    uint8 ri = ((bEPNumber - 1) << 4);

    return ((CY_GET_REG8(&`$INSTANCE_NAME`_SIE_EP1_CNT0[ri]) <<8) | CY_GET_REG8(&`$INSTANCE_NAME`_SIE_EP1_CNT1[ri]) - 2);
}
/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_LoadEP
********************************************************************************
* Summary:  Load the endpoint buffer, set up the address pointers and go.
*
* Parameters:  
*   None
*******************************************************************************/
void   `@INSTANCE_NAME`_LoadEP(uint8 bEPNumber, uint8 *pData, uint16 wLength)
{
    uint8 i;
    uint8 ri = ((bEPNumber - 1) << 4);
    uint8 *p = &`@INSTANCE_NAME`_ARB_RW1_DR[ri];
    
    /* Write WAx */
    CY_SET_REG8(&`$INSTANCE_NAME`_ARB_RW1_WA[ri],        `$INSTANCE_NAME`_EP[bEPNumber].wBuffOffset & 0xFFu);
    CY_SET_REG8(&`$INSTANCE_NAME`_ARB_RW1_WA_MSB[ri],    (`$INSTANCE_NAME`_EP[bEPNumber].wBuffOffset >> 8));
    
    /* Copy the data using the arbiter data register */
    for (i = 0; i < wLength; i++)
    {
        CY_SET_REG8(p, *pData++);
    }
    /* Set the count and data toggle */
    CY_SET_REG8(&`$INSTANCE_NAME`_SIE_EP1_CNT0[ri], (wLength >> 8) | (`$INSTANCE_NAME`_EP[bEPNumber].bEPToggle));
    CY_SET_REG8(&`$INSTANCE_NAME`_SIE_EP1_CNT1[ri],  wLength & 0xFFu);
    /* Write the RAx */
    CY_SET_REG8(&`$INSTANCE_NAME`_ARB_RW1_RA[ri],        `$INSTANCE_NAME`_EP[bEPNumber].wBuffOffset & 0xFFu);
    CY_SET_REG8(&`$INSTANCE_NAME`_ARB_RW1_RA_MSB[ri],    (`$INSTANCE_NAME`_EP[bEPNumber].wBuffOffset >> 8));

    /* Mark the event pending */
    `$INSTANCE_NAME`_EP[bEPNumber].bAPIEPState = `$INSTANCE_NAME`_EVENT_PENDING;
    /* Write the Mode register */
    CY_SET_REG8(&`$INSTANCE_NAME`_SIE_EP1_CR0[ri], `$INSTANCE_NAME`_EP[bEPNumber].bEPMode);
}

/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_bReadOutEP
********************************************************************************
* Summary:
*   Read data from an endpoint.  The application must call @INSTANCE_NAME`_bGetEPState
*   to see if an event is pending.
*
* Parameters:  
*   bEPNumber   Endpoint Number
*   pData       Pointer to the destination buffer
*   wLength     Length of the destination buffer
*
* Returns:
*   Number of bytes received
*
*******************************************************************************/
uint16 `@INSTANCE_NAME`_ReadOutEP(uint8 bEPNumber, uint8 *pData, uint16 wLength)
{
    uint8 i;
    uint8 ri = ((bEPNumber - 1) << 4);
    uint8 *p = &`@INSTANCE_NAME`_ARB_RW1_DR[ri];
    
    /* Write the RAx */
    CY_SET_REG8(&`$INSTANCE_NAME`_ARB_RW1_RA[ri],        `$INSTANCE_NAME`_EP[bEPNumber].wBuffOffset & 0xFFu);
    CY_SET_REG8(&`$INSTANCE_NAME`_ARB_RW1_RA_MSB[ri],    (`$INSTANCE_NAME`_EP[bEPNumber].wBuffOffset >> 8));
    
    /* Copy the data using the arbiter data register */
    for (i = 0; i < wLength; i++)
    {
        *pData++ = CY_GET_REG8(p);
    }
    /* Write the WAx */
    CY_SET_REG8(&`$INSTANCE_NAME`_ARB_RW1_WA[ri],        `$INSTANCE_NAME`_EP[bEPNumber].wBuffOffset & 0xFFu);
    CY_SET_REG8(&`$INSTANCE_NAME`_ARB_RW1_WA_MSB[ri],    (`$INSTANCE_NAME`_EP[bEPNumber].wBuffOffset >> 8));

    return wLength;
}
/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_EnableOutEP
********************************************************************************
* Summary:
*
* Parameters:  
*   None
*******************************************************************************/
void `@INSTANCE_NAME`_EnableOutEP(uint8 bEPNumber)
{
    uint8 ri = ((bEPNumber - 1) << 4);
    /* Mark the event pending */
    `$INSTANCE_NAME`_EP[bEPNumber].bAPIEPState = `$INSTANCE_NAME`_NO_EVENT_PENDING;
    /* Write the Mode register */
    CY_SET_REG8(&`$INSTANCE_NAME`_SIE_EP1_CR0[ri], `$INSTANCE_NAME`_EP[bEPNumber].bEPMode);
}
/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_Force
********************************************************************************
* Summary:  Forces the bus state
*
* Parameters:  
*   bState 
*    `$INSTANCE_NAME`_FORCE_J 
*    `$INSTANCE_NAME`_FORCE_K 
*    `$INSTANCE_NAME`_FORCE_SE0 
*    `$INSTANCE_NAME`_FORCE_NONE
*
*******************************************************************************/
void `@INSTANCE_NAME`_Force(uint8 bState)
{
    CY_SET_REG8(`$INSTANCE_NAME`_USBIO_CR0, bState);
}
/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_bGetEPAckState
********************************************************************************
* Summary:  Returns the ACK of the CR0 Register (ACKD)
*
* Parameters:  
*   bEPNumber   Endpoint Number
*
* Returns
*   0 if nothing has been ACKD, non-=zero something has been ACKD
*******************************************************************************/
uint8 `@INSTANCE_NAME`_bGetEPAckState(uint8 bEPNumber)
{
    uint8 ri = ((bEPNumber - 1) << 4);
  
    return (CY_GET_REG8(&`$INSTANCE_NAME`_SIE_EP1_CR0[ri]) & `$INSTANCE_NAME`_MODE_ACKD );
}
/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_SetPowerStatus
********************************************************************************
* Summary:
*   Sets the device power status for reporting in the Get Device Status
*   request
*
* Parameters:  
*   bPowerStaus 0 = Bus Powered, 1 = Self Powered
*
*******************************************************************************/
void `@INSTANCE_NAME`_SetPowerStatus(uint8 bPowerStaus)
{
    if (bPowerStaus)
    {
        `$INSTANCE_NAME`_bDeviceStatus |=  `$INSTANCE_NAME`_DEVICE_STATUS_SELF_POWERED;
    }
    else
    {
        `$INSTANCE_NAME`_bDeviceStatus &=  ~`$INSTANCE_NAME`_DEVICE_STATUS_SELF_POWERED;
    }
}

/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_bVBusPresent
********************************************************************************
* Summary:
*   Determines VBUS presense for Self Powered Devices.  Returns 1 if VBUS
*   is present, otherwise 0.
*
* Parameters:  
*   None
*******************************************************************************/
#if (`$INSTANCE_NAME`_MON_VBUS == 1)
uint8 `@INSTANCE_NAME`_bVBusPresent()
{
    return ((CY_GET_REG8(`$INSTANCE_NAME`_VBUS_PS) & `$INSTANCE_NAME`_VBUS_MASK) ? 1 : 0);
}
#endif
/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_SetPriority
********************************************************************************
* Summary:  Set the priority for the endpoint interrupt
*
* Parameters:  
*   None
*******************************************************************************/
void `@INSTANCE_NAME`_SetPriority(uint8 bVector, uint8 bPriority)
{
    CY_SET_REG8(&`$INSTANCE_NAME`_USB_ISR_PRIOR[bVector], bPriority);
}

/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_SetVector
********************************************************************************
* Summary:  Set the address for the endpoint interrupt
*
* Parameters:  
*   None
*******************************************************************************/
void `@INSTANCE_NAME`_SetVector(uint8 bVector, uint16 wAddress)
{
    CY_SET_REG16(&`$INSTANCE_NAME`_USB_ISR_VECT[bVector], (uint16) wAddress);
}

/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_EnableInt
********************************************************************************
* Summary:  Enable an interrupt
*
* Parameters:  
*   None
*******************************************************************************/
void `@INSTANCE_NAME`_EnableInt(uint8 bVector, uint8 bMask)
{
    CY_SET_REG8(&`$INSTANCE_NAME`_USB_ISR_SET_EN[bVector / 8], bMask);
}

/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_DisableInt
********************************************************************************
* Summary:  Disable an interrupt
*
* Parameters:  
*   None
*******************************************************************************/
void `@INSTANCE_NAME`_DisableInt(uint8 bVector, uint8 bMask)
{
    CY_SET_REG8(&`$INSTANCE_NAME`_USB_ISR_CLR_EN[bVector / 8], bMask);
}