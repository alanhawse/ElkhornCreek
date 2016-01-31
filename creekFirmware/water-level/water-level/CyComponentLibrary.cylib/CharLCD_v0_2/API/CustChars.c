/*******************************************************************************
* File Name: `$INSTANCE_NAME`_CustChars.c
* Version `$CY_MAJOR_VERSION`.`$CY_MINOR_VERSION`
*
* Description:
*  This file provides the source code for the Character LCD custom character 
*  API.
*
* Note:
* 
*******************************************************************************
* Copyright 2008-2009, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/



#include "cytypes.h"
#include "`$INSTANCE_NAME`.h"

const uint8 `$INSTANCE_NAME`_customFonts[] = 
{
    /* Character `$INSTANCE_NAME`_CUSTOM_0   */
 `$CUST_CHAR0`,
    /* Character `$INSTANCE_NAME`_CUSTOM_1   */
 `$CUST_CHAR1`,
    /* Character `$INSTANCE_NAME`_CUSTOM_2   */
 `$CUST_CHAR2`,
    /* Character `$INSTANCE_NAME`_CUSTOM_3   */
 `$CUST_CHAR3`,
    /* Character `$INSTANCE_NAME`_CUSTOM_4   */
 `$CUST_CHAR4`,
    /* Character `$INSTANCE_NAME`_CUSTOM_5   */
 `$CUST_CHAR5`,
    /* Character `$INSTANCE_NAME`_CUSTOM_6   */
 `$CUST_CHAR6`,
    /* Character `$INSTANCE_NAME`_CUSTOM_7   */
 `$CUST_CHAR7`
 };
  
  
/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_LoadCustomFonts
********************************************************************************
* Summary:
*  Loads 8 custom font characters into the LCD Module for use.  Cannot use 
*  characters from two different font sets at once, but font sets can be 
*  switched out during runtime.
*
* Parameters:  
*  customData: pointer to a constant array of 64 bytes representing 8 custom 
*              font characters.  
* Return: 
*  void 
*******************************************************************************/
void `$INSTANCE_NAME`_LoadCustomFonts(const uint8* customData)
{
    uint8 index_u8; 

    `$INSTANCE_NAME`_IsReady();
    /* Set starting address in the LCD Module */
    /* Optionally: Read the current address to restore at a later time */
    `$INSTANCE_NAME`_WriteControl(`$INSTANCE_NAME`_CGRAM_0);

    /* Load in the 64 bytes of CustomChar Data */
    for(index_u8 = 0; index_u8 < 64; index_u8++)
    {
        `$INSTANCE_NAME`_WriteData(customData[index_u8]);
    }

    `$INSTANCE_NAME`_IsReady();
    `$INSTANCE_NAME`_WriteControl(`$INSTANCE_NAME`_DDRAM_0);
}