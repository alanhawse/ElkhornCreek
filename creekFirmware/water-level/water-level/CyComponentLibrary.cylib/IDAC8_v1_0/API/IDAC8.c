
/*******************************************************************************
* File Name: `$INSTANCE_NAME`.c  
* Version `$CY_MAJOR_VERSION`.`$CY_MINOR_VERSION`
*
*  Description:
*    This file provides the source code to the API for the 8-bit Current 
*    DAC (IDAC8) User Module.
*
*   Note:
*     
*
*******************************************************************************
* Copyright 2008-2009, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/




#include "cytypes.h"
#include "`$INSTANCE_NAME`.h"   

uint8 `$INSTANCE_NAME`_initVar = 0;


/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_Start
********************************************************************************
* Summary:
*  Set power level then turn on IDAC8.
*
* Parameters:  
*  power:   Sets power level between off (0) and (3) high power
*
* Return: 
*  (void) 
*
* Theory: 
*
* Side Effects:
*
*******************************************************************************/
void `$INSTANCE_NAME`_Start(void) 
{
   /* Hardware initiazation only needs to occure the first time */
   if ( `$INSTANCE_NAME`_initVar == 0)  
   {     
      `$INSTANCE_NAME`_initVar = 1;
      `$INSTANCE_NAME`_CR0 = (`$INSTANCE_NAME`_MODE_I | `$INSTANCE_NAME`_DEFAULT_RANGE )  ;    

      /* Set default data source */
      if(`$INSTANCE_NAME`_DEFAULT_DATA_SRC != 0 )    
      {
          `$INSTANCE_NAME`_CR1 = (`$INSTANCE_NAME`_DEFAULT_CNTL | `$INSTANCE_NAME`_DACBUS_ENABLE | `$INSTANCE_NAME`_DEFAULT_POLARITY) ;   
      }
      else
      {
          `$INSTANCE_NAME`_CR1 = (`$INSTANCE_NAME`_DEFAULT_CNTL | `$INSTANCE_NAME`_DACBUS_DISABLE | `$INSTANCE_NAME`_DEFAULT_POLARITY) ;   
      } 

       /* Set default strobe mode */
      if(`$INSTANCE_NAME`_DEFAULT_STRB != 0)
      {
          `$INSTANCE_NAME`_Strobe |= `$INSTANCE_NAME`_STRB_EN ;
      }

      /* Set default speed */
      `$INSTANCE_NAME`_SetSpeed(`$INSTANCE_NAME`_DEFAULT_SPEED); 

      /* Enable power to DAC */
      `$INSTANCE_NAME`_PWRMGR |= `$INSTANCE_NAME`_ACT_PWR_EN;

      /* Set default value */
      `$INSTANCE_NAME`_SetValue(`$INSTANCE_NAME`_DEFAULT_DATA);
   }
   else
   {
      /* Enable power to DAC */
      `$INSTANCE_NAME`_PWRMGR |= `$INSTANCE_NAME`_ACT_PWR_EN;
   }
}


/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_Stop
********************************************************************************
* Summary:
*  Powers down IDAC8 to lowest power state.
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
void `$INSTANCE_NAME`_Stop(void)
{
   /* Disble power to DAC */
   `$INSTANCE_NAME`_PWRMGR &= ~`$INSTANCE_NAME`_ACT_PWR_EN;
}

/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_SetSpeed
********************************************************************************
* Summary:
*  Set DAC speed
*
* Parameters:  
*  power:   Sets speed value
*
* Return: 
*  (void) 
*
* Theory: 
*
* Side Effects:
*
*******************************************************************************/
void `$INSTANCE_NAME`_SetSpeed(uint8 speed) 
{
   /* Clear power mask then write in new value */
   `$INSTANCE_NAME`_CR0 &= ~`$INSTANCE_NAME`_HS_MASK ;    
   `$INSTANCE_NAME`_CR0 |=  ( speed & `$INSTANCE_NAME`_HS_MASK) ;    
}

/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_SetPolarity
********************************************************************************
* Summary:
*  Sets IDAC to Sink or Source current
*
* Parameters:  
*  Polarity: Sets the IDAC to Sink or Source
*             0 = sink, 1 = source
*
* Return: 
*  (void) 
*
* Theory: 
*
* Side Effects:
*
*******************************************************************************/
void `$INSTANCE_NAME`_SetPolarity(uint8 polarity)
{
   
   `$INSTANCE_NAME`_CR1 &= ~`$INSTANCE_NAME`_IDIR_MASK ;   
   if(polarity == 0)     /* Sink Current */
      {
      `$INSTANCE_NAME`_CR1 &= ~`$INSTANCE_NAME`_IDIR_SINK ;   
      }
   else               /* Source Current */
      {
      `$INSTANCE_NAME`_CR1 |= `$INSTANCE_NAME`_IDIR_SRC ;   
      }
}

/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_SetRange
********************************************************************************
* Summary:
*  Set current range
*
* Parameters:  
*  Range:  Sets on of four valid ranges.
*
* Return: 
*  (void) 
*
* Theory: 
*
* Side Effects:
*
*******************************************************************************/
void `$INSTANCE_NAME`_SetRange(uint8 range)
{
   `$INSTANCE_NAME`_CR0 &= ~`$INSTANCE_NAME`_RANGE_MASK ;       /* Clear existing mode */
   `$INSTANCE_NAME`_CR0 |= ( range & `$INSTANCE_NAME`_RANGE_MASK );  /*  Set Range  */
}


/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_SetValue
********************************************************************************
* Summary:
*  Set DAC value
*
* Parameters:  
*  value:  Sets DAC value between 0 and 255.
*
* Return: 
*  (void) 
*
* Theory: 
*
* Side Effects:
*
*******************************************************************************/
void `$INSTANCE_NAME`_SetValue(uint8 value)
{
   `$INSTANCE_NAME`_Data = value;         /*  Set Value  */
   
   #if defined(`$INSTANCE_NAME`_FIRST_SILICON)
   `$INSTANCE_NAME`_Data = value;                             /*  TODO: Need for first version of silicon */
   #endif
}



/* [] END OF FILE */

