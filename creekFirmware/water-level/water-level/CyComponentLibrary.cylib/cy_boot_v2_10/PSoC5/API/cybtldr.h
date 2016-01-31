/*******************************************************************************
* File Name: cybldr.h  
* Version `$CY_MAJOR_VERSION`.`$CY_MINOR_VERSION`
*
*  Description:
*   Provides an API for the Bootloader. The API includes functions for starting
*   boot loading operations, validating the application and jumping to the 
*   application.
*
*  Note: 
*   Documentation of the API's in this file is located in the
*   System Reference Guide provided with PSoC Creator.
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/


#if !defined(__CYBTLDR_H__)
#define __CYBTLDR_H__
#include <device.h>

/*******************************************************************************
* Metadata Offsets--Metadata is inserted by the cyhextool
********************************************************************************/
#define CY_META_DATA_SIZE           64
#define CY_APP_CHECKSUM_OFFSET      0

#if (defined(__C51__))
#define CYAPPADDRESS                uint16
/* offset by 2 from 32 bit start because only need 16 bits */
#define CY_APP_ADDR_OFFSET          3   /* 2 bytes */
#define CY_APP_BL_LAST_ROW_OFFSET   7   /* 4 bytes */
#define CY_APP_BYTE_LEN             11  /* 4 bytes */
#define CY_APP_RUN_TYPE				15  /* 1 byte  */
#define CY_GETCODEDATA(idx)         *((uint8 CYCODE *)idx)
#define CY_GETCODEWORD(idx)         *((uint32 CYCODE *)idx)

#elif (defined(__GNUC__) || defined(__ARMCC_VERSION))
#define CYAPPADDRESS                uint32
#define CY_APP_ADDR_OFFSET          1   /* 2 bytes */
#define CY_APP_BL_LAST_ROW_OFFSET   5   /* 4 bytes */
#define CY_APP_BYTE_LEN             9   /* 4 bytes */
#define CY_APP_RUN_TYPE				13  /* 1 byte  */
#define CY_GETCODEDATA(idx)         *((uint8 *)(CYDEV_FLASH_BASE + (idx)))
#define CY_GETCODEWORD(idx)         *((uint32 *)(CYDEV_FLASH_BASE + (idx)))
#endif /* __GNUC__ || __ARMCC_VERSION */

/*******************************************************************************
* Metadata addresses and pointer defines
********************************************************************************/
#define CY_BTLDR_MD_BASE (CYDEV_FLASH_BASE + (CYDEV_FLASH_SIZE - CY_META_DATA_SIZE))

#define CY_BTLDR_MD_CHECKSUM_ADDR           (CY_BTLDR_MD_BASE   +   CY_APP_CHECKSUM_OFFSET)
#define CY_BTLDR_MD_APP_ENTRY_POINT_ADDR    (CY_BTLDR_MD_BASE   +   CY_APP_ADDR_OFFSET)
#define CY_BTLDR_MD_LAST_BLDR_ROW_ADDR      (CY_BTLDR_MD_BASE   +   CY_APP_BL_LAST_ROW_OFFSET)
#define CY_BTLDR_MD_APP_BYTE_LEN            (CY_BTLDR_MD_BASE   +   CY_APP_BYTE_LEN)
#define CY_BTLDR_MD_APP_RUN_ADDR            (CY_BTLDR_MD_BASE   +   CY_APP_RUN_TYPE)

/* Pointers to the Bootloader metadata items */
#define CY_BTLDR_P_CHECKSUM                 ((uint8  CYCODE *) CY_BTLDR_MD_CHECKSUM_ADDR)
#define CY_BTLDR_P_APP_ENTRY_POINT          ((CYAPPADDRESS CYCODE *) CY_BTLDR_MD_APP_ENTRY_POINT_ADDR)
#define CY_BTLDR_P_LAST_BLDR_ROW            ((uint16 CYCODE *) CY_BTLDR_MD_LAST_BLDR_ROW_ADDR)
#define CY_BTLDR_P_APP_BYTE_LEN             ((CYAPPADDRESS CYCODE *) CY_BTLDR_MD_APP_BYTE_LEN)
#define CY_BTLDR_P_APP_RUN_ADDR             ((uint8 CYCODE *) CY_BTLDR_MD_APP_RUN_ADDR)

/*******************************************************************************
* Function Name: CyBtldr_Start
********************************************************************************
* Summary:
*   Runs the bootloading algorithm, determining if a bootload is necessary and
*	launching the application if it is not.
*
* Parameters:
*   void:
*   
* Return:
*   This method will never return. It will either load a new application and reset
*	the device or it will jump directly to the existing application.
*
* Remark:
*	If this method determines that the bootloader appliation itself is corrupt,
*	this method will not return, instead it will simply hang the application.
*
*******************************************************************************/
extern void CyBtldr_Start(void);

/*******************************************************************************
* Function Name: CyBtldr_ValidateApp
********************************************************************************
* Summary:
*   This routine computes the checksum, zero check, 0xFF check of the
*   application area.
*
* Parameters:  
*   None
*******************************************************************************/
extern cystatus CyBtldr_ValidateApp(void);

/*******************************************************************************
* Function Name: CyBtldr_LaunchApplication
********************************************************************************
* Summary:
*   Jumps the PC to the start address of the user application in flash.
*
* Parameters:
*   void:
*   
* Return:
*   This method will never return if it succesfully goes to the user application.
*
*******************************************************************************/
extern void CyBtldr_LaunchApplication(void);

/* __CYBTLDR_H__ */
#endif

