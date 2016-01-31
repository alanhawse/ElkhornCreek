/*******************************************************************************
* File Name: `$INSTANCE_NAME`.c  
* Version `$CY_MAJOR_VERSION`.`$CY_MINOR_VERSION`
*
*  Description:
*    This file provides the source code to the API for the Delta-Sigma ADC
*    User Module.
*
*   Note:
*
*******************************************************************************
* Copyright 2008-2009, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/




#include "cytypes.h"
#include "`$INSTANCE_NAME`.h"
#include "`$INSTANCE_NAME`_IRQ.h" 
#if(`$INSTANCE_NAME`_DEFAULT_INTERNAL_CLK)
    #include "`$INSTANCE_NAME`_theACLK.h"
#endif


#if(`$INSTANCE_NAME`_PSOC3_ES3 || `$INSTANCE_NAME`_PSOC5_ES1)
    #error "This version of the ADC is not supported with the current silicon, please update the component\
    using component update tool"
#endif

uint8 `$INSTANCE_NAME`_initVar = 0;
uint8 `$INSTANCE_NAME`_Resolution = `$INSTANCE_NAME`_DEFAULT_RESOLUTION;
/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_Start
********************************************************************************
* Summary:
*  The start function initializes the Delta Sigma Modulator with the default values, 
*  and sets the power to the given level.  A power level of 0, is the same as executing
*  the stop function.
*
* Parameters:  
*  None
*
* Return: 
*  (void) 
*
* Theory: 
*
* Side Effects:
*
*******************************************************************************/
void `$INSTANCE_NAME`_Start() 
{
  
    if(`$INSTANCE_NAME`_initVar == 0)
    {
        `$INSTANCE_NAME`_initVar = 1;
        `$INSTANCE_NAME`_InitRegisters();

        /* This is only valid if there is an internal clock */
        #if(`$INSTANCE_NAME`_DEFAULT_INTERNAL_CLK)
            `$INSTANCE_NAME`_theACLK_SetMode(CYCLK_DUTY);
        #endif

        /* Start and set interrupt vector */
        `$INSTANCE_NAME`_IRQ_SetPriority(`$INSTANCE_NAME`_IRQ_INTC_PRIOR_NUMBER);
        `$INSTANCE_NAME`_IRQ_SetVector( `$INSTANCE_NAME`_ISR );
    }

    /* Enable power for ADC */
    `$INSTANCE_NAME`_PWRMGR_DEC |= `$INSTANCE_NAME`_ACT_PWR_DEC_EN;
    `$INSTANCE_NAME`_PWRMGR_DSM |= `$INSTANCE_NAME`_ACT_PWR_DSM_EN;

    /* Enable negative pumps for DSM  */
    `$INSTANCE_NAME`_PUMP_CR1  |= ( `$INSTANCE_NAME`_PUMP_CR1_CLKSEL | `$INSTANCE_NAME`_PUMP_CR1_FORCE );


    /* This is only valid if there is an internal clock */
    #if(`$INSTANCE_NAME`_DEFAULT_INTERNAL_CLK)
        `$INSTANCE_NAME`_PWRMGR_CLK |= `$INSTANCE_NAME`_ACT_PWR_CLK_EN;
        `$INSTANCE_NAME`_theACLK_Enable();
    #endif
}


/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_Stop
********************************************************************************
* Summary:
*  Stops and powers down ADC to lowest power state.
*
* Parameters:  
*  (void) 
*
* Return: 
*  (void) 
*
* Theory: 
*
* Side Effects:
*
*******************************************************************************/
void `$INSTANCE_NAME`_Stop(void)
{
    /* Stop conversions */
    `$INSTANCE_NAME`_DEC_CR &= ~`$INSTANCE_NAME`_DEC_START_CONV;
    `$INSTANCE_NAME`_DEC_SR |=  `$INSTANCE_NAME`_DEC_INTR_CLEAR;

    /* Disable power to the ADC */
    `$INSTANCE_NAME`_PWRMGR_DSM &= ~`$INSTANCE_NAME`_ACT_PWR_DSM_EN;
    `$INSTANCE_NAME`_PWRMGR_DEC &= ~`$INSTANCE_NAME`_ACT_PWR_DEC_EN;

	/* Disable negative pumps for DSM  */
    `$INSTANCE_NAME`_PUMP_CR1 &= ~(`$INSTANCE_NAME`_PUMP_CR1_CLKSEL | `$INSTANCE_NAME`_PUMP_CR1_FORCE );

    /* This is only valid if there is an internal clock */
    #if(`$INSTANCE_NAME`_DEFAULT_INTERNAL_CLK)
        `$INSTANCE_NAME`_PWRMGR_CLK &= ~`$INSTANCE_NAME`_ACT_PWR_CLK_EN;
        `$INSTANCE_NAME`_theACLK_Disable();
    #endif
}


/*******************************************************************************
* Function Name: ADC_SetBufferGain
********************************************************************************
* Summary:
*  Set input buffer range.
*
* Parameters:  
*  gain:  Two bit value to select a gain of 1, 2, 4, or 8.
*
* Return: 
*  (void) 
*
* Theory: 
*
* Side Effects:
*
*******************************************************************************/
void `$INSTANCE_NAME`_SetBufferGain(uint8 gain)
{
    uint8 tmpReg;
    tmpReg = `$INSTANCE_NAME`_DSM_BUF1 & ~`$INSTANCE_NAME`_DSM_GAIN_MASK;
    tmpReg |= (gain << 2);
    `$INSTANCE_NAME`_DSM_BUF1 = tmpReg;
}



/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_SetBufferChop
********************************************************************************
* Summary:
*  Sets the Delta Sigma Modulator Buffer chopper mode.
*
* Parameters:  
*  chopen:   If non-zero set the chopper mode.
*  chopFreq: Chop frequency value.
*
* Return: 
*  (void) 
*
* Theory: 
*
* Side Effects:
*
*******************************************************************************/
void `$INSTANCE_NAME`_SetBufferChop(uint8 chopen, uint8 chopFreq)
{
    if(chopen != 0)
    {
        `$INSTANCE_NAME`_DSM_BUF2 = (`$INSTANCE_NAME`_DSM_BUF_FCHOP_MASK & chopFreq) | `$INSTANCE_NAME`_DSM_BUF_CHOP_EN;
    }
    else
    {
        `$INSTANCE_NAME`_DSM_BUF2 = 0x00;
    }
}





/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_SetPower
********************************************************************************
* Summary:
*  Sets power mode of ADC
*
* Parameters:  
*  power:  Power setting for ADC
*
* Return: 
*  (void) 
*
* Theory: 
*
* Side Effects:
*
*******************************************************************************/
void `$INSTANCE_NAME`_SetPower(uint8 power)
{
    uint8 tmpReg;

    /* mask off invalid power settings */
    power &= `$INSTANCE_NAME`_POWER_MASK;

    /* Set Power1 parameter  */
    tmpReg = `$INSTANCE_NAME`_DSM_CR14 & ~`$INSTANCE_NAME`_DSM_POWER1_MASK;
    `$INSTANCE_NAME`_DSM_CR14 = tmpReg | power;


    /* Set Power2_3 parameter  */
    /* `$INSTANCE_NAME`_DSM_CR15 = `$INSTANCE_NAME`_DSM_POWER2_3_HIGH | `$INSTANCE_NAME`_DSM_POWER_12MHZ ; */

    /* Set Power_sum parameter  */
    /* `$INSTANCE_NAME`_DSM_CR16 = `$INSTANCE_NAME`_DSM_CP_PWRCTL_DEFAULT | `$INSTANCE_NAME`_DSM_POWER_SUM_HIGH ; */
}


/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_StartConvert
********************************************************************************
* Summary:
*  Starts ADC conversion using the given mode.
*
* Parameters:  
*  (void)
*
* Return: 
*  (void) 
*
* Theory: 
*
* Side Effects:
*
*******************************************************************************/
void `$INSTANCE_NAME`_StartConvert(void)
{
    /* Start the conversion */
    `$INSTANCE_NAME`_DEC_CR |= `$INSTANCE_NAME`_DEC_START_CONV;  
}

/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_StopConvert
********************************************************************************
* Summary:
*  Starts ADC conversion using the given mode.
*
* Parameters:  
*  (void)
*
* Return: 
*  (void) 
*
* Theory: 
*
* Side Effects:
*
*******************************************************************************/
void `$INSTANCE_NAME`_StopConvert(void)
{
    /* Stop all conversions */
    `$INSTANCE_NAME`_DEC_CR &= ~`$INSTANCE_NAME`_DEC_START_CONV;  
}

/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_IsEndConversion
********************************************************************************
* Summary:
*  Queries the ADC to see if conversion is complete
*
* Parameters:  
*  wMode:  Wait mode, 0 if return with answer imediately.
*                     1 if wait until conversion is complete, then return.
*
* Return: 
*  (uint8)  0 =>  Conversion not complete.
*           1 =>  Conversion complete.
*
* Theory: 
*
* Side Effects:
*
*******************************************************************************/
uint8 `$INSTANCE_NAME`_IsEndConversion(uint8 wMode)
{
    uint8 status;

    do 
    {
        status = `$INSTANCE_NAME`_DEC_SR & `$INSTANCE_NAME`_DEC_CONV_DONE;
    } while((status != `$INSTANCE_NAME`_DEC_CONV_DONE) && (wMode == `$INSTANCE_NAME`_WAIT_FOR_RESULT));

    return(status);
}

/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_GetResult8
********************************************************************************
* Summary:
*  Returns an 8-bit result or the LSB of the last conversion.
*
* Parameters:  
*  (void) 
*
* Return: 
*  (int8) ADC result.
*
* Theory: 
*
* Side Effects:
*
*******************************************************************************/
int8 `$INSTANCE_NAME`_GetResult8( void )
{
    return( `$INSTANCE_NAME`_DEC_SAMP );
}


/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_GetResult16
********************************************************************************
* Summary:
*  Returns a 16-bit result from the last ADC conversion.
*
* Parameters:  
*   (void)
*
* Return: 
*  (int16) ADC result.
*
* Theory: 
*
* Side Effects:
*
*******************************************************************************/
int16 `$INSTANCE_NAME`_GetResult16(void)
{
    uint16 result;
    result = `$INSTANCE_NAME`_DEC_SAMPM ;
    result = (result << 8 ) | `$INSTANCE_NAME`_DEC_SAMP;
    return( result );
}

/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_GetResult32
********************************************************************************
* Summary:
*  Returns an 32-bit result from ADC
*
* Parameters:  
*   (void)
*
* Return: 
*  (int32) ADC result.
*
* Theory: 
*
* Side Effects:
*
*******************************************************************************/
int32 `$INSTANCE_NAME`_GetResult32(void)
{
    uint32 result;

    result = (int8) `$INSTANCE_NAME`_DEC_SAMPH;
    result = (result << 8) | `$INSTANCE_NAME`_DEC_SAMPM;
    result = (result << 8) | `$INSTANCE_NAME`_DEC_SAMP;
    return( result );
}




/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_InitRegisters(void)
********************************************************************************
* Summary:
*  Initializes all registers based on customizer settings
*
* Parameters:  
*   (void)
*
* Return: 
*  (void)
*
* Theory: 
*
* Side Effects:
*
*******************************************************************************/
void `$INSTANCE_NAME`_InitRegisters(void)
{

    `$INSTANCE_NAME`_DEC_CR     = `$INSTANCE_NAME`_DFLT_DEC_CR;      
    `$INSTANCE_NAME`_DEC_SR     = `$INSTANCE_NAME`_DFLT_DEC_SR;      
    `$INSTANCE_NAME`_DEC_SHIFT1 = `$INSTANCE_NAME`_DFLT_DEC_SHIFT1;  
    `$INSTANCE_NAME`_DEC_SHIFT2 = `$INSTANCE_NAME`_DFLT_DEC_SHIFT2;  
    `$INSTANCE_NAME`_DEC_DR2    = `$INSTANCE_NAME`_DFLT_DEC_DR2;     
    `$INSTANCE_NAME`_DEC_DR2H   = `$INSTANCE_NAME`_DFLT_DEC_DR2H;    
    `$INSTANCE_NAME`_DEC_DR1    = `$INSTANCE_NAME`_DFLT_DEC_DR1;     
    `$INSTANCE_NAME`_DEC_OCOR   = `$INSTANCE_NAME`_DFLT_DEC_OCOR;    
    `$INSTANCE_NAME`_DEC_OCORM  = `$INSTANCE_NAME`_DFLT_DEC_OCORM;   
    `$INSTANCE_NAME`_DEC_OCORH  = `$INSTANCE_NAME`_DFLT_DEC_OCORH;   
    `$INSTANCE_NAME`_DEC_GVAL   = `$INSTANCE_NAME`_DFLT_DEC_GVAL;    
    `$INSTANCE_NAME`_DEC_GCOR   = `$INSTANCE_NAME`_DFLT_DEC_GCOR;    
    `$INSTANCE_NAME`_DEC_GCORH  = `$INSTANCE_NAME`_DFLT_DEC_GCORH;   
    `$INSTANCE_NAME`_DEC_COHER  = `$INSTANCE_NAME`_DFLT_DEC_COHER;   

    `$INSTANCE_NAME`_DSM_CR0  = `$INSTANCE_NAME`_DFLT_DSM_CR0;     
    `$INSTANCE_NAME`_DSM_CR1  = `$INSTANCE_NAME`_DFLT_DSM_CR1;     
    `$INSTANCE_NAME`_DSM_CR2  = `$INSTANCE_NAME`_DFLT_DSM_CR2;     
    `$INSTANCE_NAME`_DSM_CR3  = `$INSTANCE_NAME`_DFLT_DSM_CR3;     
    `$INSTANCE_NAME`_DSM_CR4  = `$INSTANCE_NAME`_DFLT_DSM_CR4;     
    `$INSTANCE_NAME`_DSM_CR5  = `$INSTANCE_NAME`_DFLT_DSM_CR5;     
    `$INSTANCE_NAME`_DSM_CR6  = `$INSTANCE_NAME`_DFLT_DSM_CR6;     
    `$INSTANCE_NAME`_DSM_CR7  = `$INSTANCE_NAME`_DFLT_DSM_CR7;     
    `$INSTANCE_NAME`_DSM_CR8  = `$INSTANCE_NAME`_DFLT_DSM_CR8;     
    `$INSTANCE_NAME`_DSM_CR9  = `$INSTANCE_NAME`_DFLT_DSM_CR9;     
    `$INSTANCE_NAME`_DSM_CR10 = `$INSTANCE_NAME`_DFLT_DSM_CR10;    
    `$INSTANCE_NAME`_DSM_CR11 = `$INSTANCE_NAME`_DFLT_DSM_CR11;    
    `$INSTANCE_NAME`_DSM_CR12 = `$INSTANCE_NAME`_DFLT_DSM_CR12;    
    `$INSTANCE_NAME`_DSM_CR13 = `$INSTANCE_NAME`_DFLT_DSM_CR13;    
    `$INSTANCE_NAME`_DSM_CR14 = `$INSTANCE_NAME`_DFLT_DSM_CR14;    
    `$INSTANCE_NAME`_DSM_CR15 = `$INSTANCE_NAME`_DFLT_DSM_CR15;    
    `$INSTANCE_NAME`_DSM_CR16 = `$INSTANCE_NAME`_DFLT_DSM_CR16;    
    `$INSTANCE_NAME`_DSM_CR17 = `$INSTANCE_NAME`_DFLT_DSM_CR17;    
    `$INSTANCE_NAME`_DSM_REF0 = `$INSTANCE_NAME`_DFLT_DSM_REF0;    
    `$INSTANCE_NAME`_DSM_REF1 = `$INSTANCE_NAME`_DFLT_DSM_REF1;    
    `$INSTANCE_NAME`_DSM_REF2 = `$INSTANCE_NAME`_DFLT_DSM_REF2;    
    `$INSTANCE_NAME`_DSM_REF3 = `$INSTANCE_NAME`_DFLT_DSM_REF3;    

    `$INSTANCE_NAME`_DSM_DEM0 = `$INSTANCE_NAME`_DFLT_DSM_DEM0;    
    `$INSTANCE_NAME`_DSM_DEM1 = `$INSTANCE_NAME`_DFLT_DSM_DEM1;    
    `$INSTANCE_NAME`_DSM_MISC = `$INSTANCE_NAME`_DFLT_DSM_MISC;    
    `$INSTANCE_NAME`_DSM_CLK  = `$INSTANCE_NAME`_DFLT_DSM_CLK;     

    `$INSTANCE_NAME`_DSM_BUF0 = `$INSTANCE_NAME`_DFLT_DSM_BUF0;    
    `$INSTANCE_NAME`_DSM_BUF1 = `$INSTANCE_NAME`_DFLT_DSM_BUF1;    
    `$INSTANCE_NAME`_DSM_BUF2 = `$INSTANCE_NAME`_DFLT_DSM_BUF2;    
    `$INSTANCE_NAME`_DSM_BUF3 = `$INSTANCE_NAME`_DFLT_DSM_BUF3;    
    `$INSTANCE_NAME`_DSM_OUT0 = `$INSTANCE_NAME`_DFLT_DSM_OUT0;    
    `$INSTANCE_NAME`_DSM_OUT1 = `$INSTANCE_NAME`_DFLT_DSM_OUT1;    

    `$INSTANCE_NAME`_DSM_SW3 &= ~`$INSTANCE_NAME`_DSM_VN_REF_MASK;
    `$INSTANCE_NAME`_DSM_SW3 |= `$INSTANCE_NAME`_DFLT_DSM_SW3;
}
/* [] END OF FILE */


