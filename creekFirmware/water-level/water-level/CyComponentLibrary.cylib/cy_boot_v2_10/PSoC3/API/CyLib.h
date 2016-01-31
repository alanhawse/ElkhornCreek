/******************************************************************************
* File Name: CyLib.h
* Version `$CY_MAJOR_VERSION`.`$CY_MINOR_VERSION`
*
*  Description:
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

#if !defined(__CYLIB_H__)
#define __CYLIB_H__

#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <cytypes.h>
#include <cyfitter.h>
#include <cydevice_trm.h>
#include <cyPm.h>

#if defined(__C51__)
#include <PSoC3_8051.h>
#endif

#if !defined(NULL)
#define NULL                    ((void *)0)
#endif

/***************************************
* Conditional Compilation Parameters
***************************************/

/* PSoC3 ES2 or early */
#define CYLIB_PSOC3_ES2    ((CYDEV_CHIP_MEMBER_USED == CYDEV_CHIP_MEMBER_3A) && \
                            (CYDEV_CHIP_REVISION_USED <= CYDEV_CHIP_REVISION_3A_ES2))
/* PSoC5 ES1 */
#define CYLIB_PSOC5_ES1    ((CYDEV_CHIP_MEMBER_USED == CYDEV_CHIP_MEMBER_5A) && \
                            (CYDEV_CHIP_REVISION_USED <= CYDEV_CHIP_REVISION_5A_ES1))
/* PSoC3 ES3 or later */
#define CYLIB_PSOC3_ES3    ((CYDEV_CHIP_MEMBER_USED == CYDEV_CHIP_MEMBER_3A) && \
                            (CYDEV_CHIP_REVISION_USED > CYDEV_CHIP_REVISION_3A_ES2))
/* PSoC5 ES2 or later */
#define CYLIB_PSOC5_ES2    ((CYDEV_CHIP_MEMBER_USED == CYDEV_CHIP_MEMBER_5A) && \
                            (CYDEV_CHIP_REVISION_USED > CYDEV_CHIP_REVISION_5A_ES1))

/* CYLIB CLOCK macros/funcs begin*/

/***************************************
*    Function Prototypes
***************************************/
cystatus CyPLL_OUT_Start(uint8 wait) `=ReentrantKeil("CyPLL_OUT_Start")`;
void  CyPLL_OUT_Stop(void) `=ReentrantKeil("CyPLL_OUT_Stop")`;
void  CyPLL_OUT_SetPQ(uint8 P, uint8 Q, uint8 current) `=ReentrantKeil("CyPLL_OUT_SetPQ")`;
void  CyPLL_OUT_SetSource(uint8 source) `=ReentrantKeil("CyPLL_OUT_SetSource")`;

void  CyIMO_Start(uint8 wait) `=ReentrantKeil("CyIMO_Start")`;
void  CyIMO_Stop(void) `=ReentrantKeil("CyIMO_Stop")`;
void  CyIMO_SetFreq(uint8 freq) `=ReentrantKeil("CyIMO_SetFreq")`;
void  CyIMO_SetSource(uint8 source) `=ReentrantKeil("CyIMO_SetSource")`;
void  CyIMO_EnableDoubler(void) `=ReentrantKeil("CyIMO_EnableDoubler")`;
void  CyIMO_DisableDoubler(void) `=ReentrantKeil("CyIMO_DisableDoubler")`;

void  CyMasterClk_SetSource(uint8 source) `=ReentrantKeil("CyMasterClk_SetSource")`;
void  CyMasterClk_SetDivider(uint8 divider) `=ReentrantKeil("CyMasterClk_SetDivider")`;
void  CyBusClk_SetDivider(uint16 divider) `=ReentrantKeil("CyBusClk_SetDivider")`;
void  CyCpuClk_SetDivider(uint8 divider) `=ReentrantKeil("CyCpuClk_SetDivider")`;
void  CyUsbClk_SetSource(uint8 source) `=ReentrantKeil("CyUsbClk_SetSource")`;

void  CyILO_Start1K(void) `=ReentrantKeil("CyILO_Start1K")`;
void  CyILO_Stop1K(void) `=ReentrantKeil("CyILO_Stop1K")`;
void  CyILO_Start100K(void) `=ReentrantKeil("CyILO_Start100K")`;
void  CyILO_Stop100K(void) `=ReentrantKeil("CyILO_Stop100K")`;
void  CyILO_Enable33K(void) `=ReentrantKeil("CyILO_Enable33K")`;
void  CyILO_Disable33K(void) `=ReentrantKeil("CyILO_Disable33K")`;
void  CyILO_SetSource(uint8 source) `=ReentrantKeil("CyILO_SetSource")`;
uint8 CyILO_SetPowerMode(uint8 mode) `=ReentrantKeil("CyILO_SetPowerMode")`;

uint8 CyXTAL_32KHZ_ReadStatus(void) `=ReentrantKeil("CyXTAL_32KHZ_ReadStatus")`;
uint8 CyXTAL_32KHZ_SetPowerMode(uint8 mode) `=ReentrantKeil("CyXTAL_32KHZ_SetPowerMode")`;
void  CyXTAL_32KHZ_Start(void) `=ReentrantKeil("CyXTAL_32KHZ_Start")`;
void  CyXTAL_32KHZ_Stop(void) `=ReentrantKeil("CyXTAL_32KHZ_Stop")`;

cystatus CyXTAL_Start(uint8 wait) `=ReentrantKeil("CyXTAL_Start")`;
void  CyXTAL_Stop(void) `=ReentrantKeil("CyXTAL_Stop")`;
void  CyXTAL_EnableErrStatus(void) `=ReentrantKeil("CyXTAL_EnableErrStatus")`;
void  CyXTAL_DisableErrStatus(void) `=ReentrantKeil("CyXTAL_DisableErrStatus")`;
uint8 CyXTAL_ReadStatus(void) `=ReentrantKeil("CyXTAL_ReadStatus")`;
void  CyXTAL_EnableFaultRecovery(void) `=ReentrantKeil("CyXTAL_EnableFaultRecovery")`;
void  CyXTAL_DisableFaultRecovery(void) `=ReentrantKeil("CyXTAL_DisableFaultRecovery")`;
void  CyXTAL_SetStartup(uint8 setting) `=ReentrantKeil("CyXTAL_SetStartup")`;

#if CYLIB_PSOC3_ES3
void CyXTAL_SetFbVoltage(uint8 setting) `=ReentrantKeil("CyXTAL_SetFbVoltage")`;
void CyXTAL_SetWdVoltage(uint8 setting) `=ReentrantKeil("CyXTAL_SetWdVoltage")`;
#endif 

/***************************************
*    API Constants
***************************************/
#define PLL_CONTROL_ENABLE             (1 << 0) /* Enables the PLL. */
#define PLL_STATUS_LOCK             (1 << 0) /* Lock Status. */
#define PLL_STATUS_ENABLED             (1 << 0) /* Enabled Status. */
#define IMO_PM_ENABLE                  (1 << 4) /* Enable IMO clock source. */
#define XMHZ_CONTROL_ENABLE            (1 << 0) /* Enables the 4 - 33 MHz crystal oscillator circuit when set high. */

#define X32_CONTROL_ANA_STAT           (1 << 5) /* Indicates oscillator status, using internal analog measurement. */
#define X32_CONTROL_DIG_STAT           (1 << 4) /* Indicates oscillator status, using test against a reference clock. The ILO's CLK33K must be enabled for this function to operate. */
#define X32_CONTROL_LPM                (1 << 1) /* Power setting for 32K crystal oscillator.
                                                This setting only takes effect in sleep modes.
                                                During active modes, the oscillator always runs in high power mode. */
#define X32_CONTROL_LPM_POSITION    1           /* Power setting bits position*/
#define X32_CONTROL_X32EN              (1 << 0) /* 32K Crystal Oscillator Enable. */
#if (CYLIB_PSOC3_ES3 || CYLIB_PSOC5_ES2)
#define X32_CONTROL_PDBEN          (1 << 2)      /* Power switch enable (active-low powerdown) for 32K crystal oscillator. */
#endif
#define X32_TR_CLEAR                0x00     /* X32_TR Trim value*/
#define X32_TST_SETALL                 0xF1     /* Test bits, high for normal operation*/
#define X32_CFG_LOWPOWERMODE        (1 << 7) /* Low power oscillator mode configuration. */
#define X32_CONTROL_XERR_DIS           (1 << 2) /* xfb_dis bit in FASTCLK_XMHZ_CSR*/
#define X32_CONTROL_XERR_MASK        (1 << 7) /* High output indicates oscillator failure. */
#define X32_CONTROL_XERR_POSITION    7            /* XERR bits position. */
#define X32_CONTROL_FAULT_RECOVER    (1 << 6) /*      Enable External Crystal Oscillator (XMHZ) fault recovery circuitry*/
#define ILO_CONTROL_PD_MODE            (1 << 4) /* Power down mode for ILO. */

#define CY_XTAL32K_DIG_STAT             (1 << 4)
#define CY_XTAL32K_DIG_STAT_UNSTABLE     0
#define CY_XTAL32K_ANA_STAT             (1 << 5)
#define CY_XTAL32K_ANA_STAT_UNSTABLE     0
#define CY_XTAL32K_STAT_FIELDS             0x30u

#define CY_ILO_SOURCE_100K             0
#define CY_ILO_SOURCE_33K             1
#define CY_ILO_SOURCE_1K             2

#define CY_ILO_SOURCE_BITS_CLEAR    0xF3u     /*3:2 bits       ILO_OUT[1:0], 2'h0*/
#define CY_ILO_SOURCE_1K_SET           0x08u   /*3:2 bits       ILO_OUT[1:0], 2'h2 */
#define CY_ILO_SOURCE_33K_SET          0x04u     /*3:2 bits       ILO_OUT[1:0], 2'h1*/
#define CY_ILO_SOURCE_100K_SET         0x00u     /*3:2 bits       ILO_OUT[1:0], 2'h0*/

#define MASTER_CLK_SRC_CLEAR           0xFC /* Clear 0:1 bits. */
#define MASTERCLK_DIVIDER_VALUE        7     /* Master clock divider value*/

#define CY_MASTER_SOURCE_IMO        0 /* IMO as the source. */
#define CY_MASTER_SOURCE_PLL        1 /* PLL as the source. */
#define CY_MASTER_SOURCE_XTAL        2 /* XTAL as the source. */
#define CY_MASTER_SOURCE_DSI        3 /* DSI as the source. */

#define BUS_AMASK_CLEAR                0xF0u
#define BUS_DMASK_CLEAR                0x00u

#define CLKDIST_WRK0_MASK_SET        (1 << 7) /*7th bit         MASK     Mask bit to enable shadow loads*/
#define CLKDIST_LD_LOAD_SET            0x01u
#define CLKDIST_BCFG2_SSS_SET        (1 << 6) /*1'b1  6th bit      Sync source is same frequency*/

#define CY_IMO_SOURCE_IMO            0
#define CY_IMO_SOURCE_XTAL            1
#define CY_IMO_SOURCE_DSI            2

#define CLOCK_IMO_RANGE_CLEAR       0XF8    /* IMO frequency bits set to zero*/
#define CLOCK_IMO_3MHZ_VALUE           0X03    /* IMO frequency 3MHz bit to set*/
#define CLOCK_IMO_6MHZ_VALUE           0X01    /* IMO frequency 6MHz bit to set*/
#define CLOCK_IMO_12MHZ_VALUE          0X00    /* IMO frequency 12MHz bit to set*/
#define CLOCK_IMO_24MHZ_VALUE          0X02    /* IMO frequency 24MHz bit to set*/
#define CLOCK_IMO_48MHZ_VALUE          0X04    /* IMO frequency 48MHz bit to set*/
#define CLOCK_IMO_62MHZ_VALUE          0X05    /* IMO frequency 62MHz bit to set*/
#define CLOCK_IMO_74MHZ_VALUE        0x06    /* IMO frequency 74MHz bit to set*/

#define CY_IMO_FREQ_3MHZ             0      /*3 MHz*/
#define CY_IMO_FREQ_6MHZ            1     /*6 MHz*/
#define CY_IMO_FREQ_12MHZ            2   /*12 MHz*/
#define CY_IMO_FREQ_24MHZ            3    /*24 MHz*/
#define CY_IMO_FREQ_48MHZ            4    /*48 MHz*/
#define CY_IMO_FREQ_62MHZ            5    /*62.6 MHz*/
#define CY_IMO_FREQ_74MHZ            6    /*74.7 MHz (PSoC 5)*/
#define CY_IMO_FREQ_USB                8    /*24 MHz (Trimmed for USB operation)*/

#define SFR_USER_CPUCLK_DIV_MASK    0x0Fu
#define CLKDIST_DIV_POSITION        4         /*Clock divider bits position*/
#define CLKDIST_MSTR1_DIV_CLEAR     0x0Fu     /**/
#define IMO_DOUBLER_ENABLE          (1 << 4) /* Enables the IMO Doubler. */
#define CLOCK_USB_ENABLE            (1 << 1) /*turn on the automatic frequency locking of the 
                                                internal oscillator to USB traffic.*/                    
#define CLOCK_IMO_IMO                 (1 << 5) 
#define CLOCK_IMO2X_XTAL             (1 << 6)
#define CLOCK_IMO_OUT_X2            (1 << 4)
#define CLOCK_IMO_OUT_X1            ~CLOCK_IMO_OUT_X2
#define CY_PLL_SOURCE_IMO           0
#define CY_PLL_SOURCE_XTAL          1
#define CY_PLL_SOURCE_DSI           2
#define PLL_VCO_GAIN_2                2
#define PLL_CURRENT_POSITION        4
#define CLOCK_CONTROL_DIST_MASK     0xFCu    /*Clear the clock distribution fields. Bit 1:0*/
#define MAX_FASTCLK_PLL_Q_VALUE     16
#define MIN_FASTCLK_PLL_Q_VALUE     1
#define MIN_FASTCLK_PLL_P_VALUE     4
#define MIN_FASTCLK_PLL_CUR_VALUE   1
#define MAX_FASTCLK_PLL_CUR_VALUE   7

#define CLOCK_IMO2X_ECO             ~CLOCK_IMO2X_DSI
#define FASTCLK_XMHZ_GAINMASK       0x1Fu    /* Gain bits 4:0 bits */
#define FASTCLK_XMHZ_VREFMASK       0x0Fu    /* VREF 3:0 bits*/
#define FASTCLK_XMHZ_VREF_WD_MASK   0x70u    /* WD 6:4 bits */

#define ILO_CONTROL_PD_MODE         (1 << 4) /* Power down mode for ILO. */
#define ILO_CONTROL_PD_POSITION     4          /* Power down mode bit position. */
#define ILO_CONTROL_1KHZ_ON         (1 << 1) /* ILO 1KHz clock on. */
#define ILO_CONTROL_100KHZ_ON       (1 << 2) /* ILO 100KHz clock on. */
#define ILO_CONTROL_33KHZ_ON        (1 << 5) /* ILO 33KHz (100/3) clock on.*/

#define USB_CLKDIST_CONFIG_MASK           0X03
#define USB_CLK_IMO2X                     0x00
#define USB_CLK_IMO                       0x01
#define USB_CLK_PLL                       0x02
#define USB_CLK_DSI                       0x03
#define USB_CLK_DIV2_ON                  (1 << 2) /* Turn divide by 2 on.*/
#define USB_CLK_STOP_FLAG                 0x00
#define USB_CLK_START_FLAG                0x01

#define FTW_CLEAR_ALL_BITS                0x00u /*To clear all bits of PM_TW_CFG2*/
#define FTW_CLEAR_FTW_BITS                0xFCu /*To clear FTW bits of PM_TW_CFG2*/
#define FTW_ENABLE                        0x01u /*To enable FTW, no interrupt*/

/***************************************
* Registers
***************************************/
#define FASTCLK_PLL_CFG0_PTR           ( (reg8 *) CYREG_FASTCLK_PLL_CFG0)
#define FASTCLK_PLL_CFG0            (*(reg8 *) CYREG_FASTCLK_PLL_CFG0) 
#define FASTCLK_PLL_SR_PTR          ( (reg8 *) CYREG_FASTCLK_PLL_SR)
#define FASTCLK_PLL_SR              (*(reg8 *) CYREG_FASTCLK_PLL_SR)
#define PM_ACT_CFG0_PTR             ( (reg8 *) CYREG_PM_ACT_CFG0)
#define PM_ACT_CFG0                 (*(reg8 *) CYREG_PM_ACT_CFG0)
#define PM_STBY_CFG0_PTR               ( (reg8 *) CYREG_PM_STBY_CFG0)
#define PM_STBY_CFG0                 (*(reg8 *) CYREG_PM_STBY_CFG0)
#define PM_AVAIL_CR2_PTR             ( (reg8 *) CYREG_PM_AVAIL_CR2)
#define PM_AVAIL_CR2                 (*(reg8 *) CYREG_PM_AVAIL_CR2)
#define FASTCLK_XMHZ_CSR_PTR           ( (reg8 *) CYREG_FASTCLK_XMHZ_CSR)
#define FASTCLK_XMHZ_CSR               (*(reg8 *) CYREG_FASTCLK_XMHZ_CSR)
#define SLOWCLK_X32_CR_PTR            ( (reg8 *) CYREG_SLOWCLK_X32_CR)
#define SLOWCLK_X32_CR                (*(reg8 *) CYREG_SLOWCLK_X32_CR)
#define MFGCFG_X32_TR_PTR            ( (reg8 *) CYDEV_MFGCFG_X32_TR)
#define MFGCFG_X32_TR                (*(reg8 *) CYDEV_MFGCFG_X32_TR)
#define SLOWCLK_X32_TST_PTR            ( (reg8 *) CYDEV_SLOWCLK_X32_TST)
#define SLOWCLK_X32_TST                (*(reg8 *) CYDEV_SLOWCLK_X32_TST)
#define SLOWCLK_X32_CFG_PTR            ( (reg8 *) CYDEV_SLOWCLK_X32_CFG)
#define SLOWCLK_X32_CFG                (*(reg8 *) CYDEV_SLOWCLK_X32_CFG)
#define SLOWCLK_ILO_CR0_PTR            ( (reg8 *) CYREG_SLOWCLK_ILO_CR0)
#define SLOWCLK_ILO_CR0                (*(reg8 *) CYREG_SLOWCLK_ILO_CR0)
#define CLKDIST_UCFG_PTR            ( (reg8 *) CYREG_CLKDIST_UCFG)
#define CLKDIST_UCFG                (*(reg8 *) CYREG_CLKDIST_UCFG)
#define SLOWCLK_X32_CR_PTR            ( (reg8 *) CYREG_SLOWCLK_X32_CR)
#define SLOWCLK_X32_CR                (*(reg8 *) CYREG_SLOWCLK_X32_CR)

#define PM_TW_CFG0_PTR                ( (reg8 *) CYREG_PM_TW_CFG0)
#define PM_TW_CFG0                    (*(reg8 *) CYREG_PM_TW_CFG0)

#define PM_TW_CFG2_PTR                ( (reg8 *) CYREG_PM_TW_CFG2)
#define PM_TW_CFG2                    (*(reg8 *) CYREG_PM_TW_CFG2)

#define CLKDIST_MSTR1_PTR           ( (reg8 *) CYREG_CLKDIST_MSTR1)
#define CLKDIST_MSTR1               (*(reg8 *) CYREG_CLKDIST_MSTR1)
#define CLKDIST_MSTR0_PTR           ( (reg8 *) CYREG_CLKDIST_MSTR0)
#define CLKDIST_MSTR0               (*(reg8 *) CYREG_CLKDIST_MSTR0)

#define CLKDIST_AMASK_PTR            ( (reg8 *) CYREG_CLKDIST_AMASK)
#define CLKDIST_AMASK                (*(reg8 *) CYREG_CLKDIST_AMASK)
#define CLKDIST_DMASK_PTR            ( (reg8 *) CYREG_CLKDIST_DMASK)
#define CLKDIST_DMASK                (*(reg8 *) CYREG_CLKDIST_DMASK)
#define CLKDIST_WRK0_PTR            ( (reg8 *) CYREG_CLKDIST_WRK0)
#define CLKDIST_WRK0                 (*(reg8 *) CYREG_CLKDIST_WRK0)
#define CLKDIST_LD_PTR                ( (reg8 *) CYREG_CLKDIST_LD)
#define CLKDIST_LD                    (*(reg8 *) CYREG_CLKDIST_LD)
#define CLKDIST_BCFG0_PTR            ( (reg8 *) CYREG_CLKDIST_BCFG0)
#define CLKDIST_BCFG0                (*(reg8 *) CYREG_CLKDIST_BCFG0)
#define CLKDIST_BCFG2_PTR            ( (reg8 *) CYREG_CLKDIST_BCFG2)
#define CLKDIST_BCFG2                (*(reg8 *) CYREG_CLKDIST_BCFG2)
#define SFR_USER_CPUCLK_DIV_PTR        ((void far *) CYREG_SFR_USER_CPUCLK_DIV)

#define FASTCLK_IMO_CR_PTR             ( (reg8 *) CYREG_FASTCLK_IMO_CR)
#define FASTCLK_IMO_CR                 (*(reg8 *) CYREG_FASTCLK_IMO_CR)
#define CLOCK_CONTROL               ((reg8 *) CYREG_CLKDIST_CR)
#define IMO_TR1_PTR                    ( (reg8 *) CYREG_IMO_TR1)
#define IMO_TR1                        (*(reg8 *) CYREG_IMO_TR1)
#define CY_USB_CR1_PTR                ( (reg8 *) CYREG_USB_CR1 )
#define CY_USB_CR1                    (*(reg8 *) CYREG_USB_CR1 )

#if (CYLIB_PSOC3_ES2 || CYLIB_PSOC3_ES3)
#define FLSHID_CUST_TABLES_IMO_3MHZ_PTR         ((void far *) CYDEV_FLSHID_CUST_TABLES_IMO_3MHZ)
#define FLSHID_CUST_TABLES_IMO_6MHZ_PTR            ((void far *) CYDEV_FLSHID_CUST_TABLES_IMO_6MHZ)
#define FLSHID_CUST_TABLES_IMO_12MHZ_PTR        ((void far *) CYDEV_FLSHID_CUST_TABLES_IMO_12MHZ)
#define FLSHID_CUST_TABLES_IMO_24MHZ_PTR        ((void far *) CYDEV_FLSHID_CUST_TABLES_IMO_24MHZ)
#define FLSHID_MFG_CFG_IMO_TR1_PTR                ((void far *) CYDEV_FLSHID_MFG_CFG_IMO_TR1)
#define FLSHID_CUST_TABLES_IMO_67MHZ_PTR        ((void far *) CYDEV_FLSHID_CUST_TABLES_IMO_67MHZ)
#define FLSHID_CUST_TABLES_IMO_80MHZ_PTR        ((void far *) CYDEV_FLSHID_CUST_TABLES_IMO_80MHZ)
#define FLSHID_CUST_TABLES_IMO_USB_PTR            ((void far *) CYDEV_FLSHID_CUST_TABLES_IMO_USB)
#else
#define FLSHID_CUST_TABLES_IMO_3MHZ_PTR         ((reg8 *) CYDEV_FLSHID_CUST_TABLES_IMO_3MHZ)
#define FLSHID_CUST_TABLES_IMO_6MHZ_PTR            ((reg8 *) CYDEV_FLSHID_CUST_TABLES_IMO_6MHZ)
#define FLSHID_CUST_TABLES_IMO_12MHZ_PTR        ((reg8 *) CYDEV_FLSHID_CUST_TABLES_IMO_12MHZ)
#define FLSHID_CUST_TABLES_IMO_24MHZ_PTR        ((reg8 *) CYDEV_FLSHID_CUST_TABLES_IMO_24MHZ)
#define FLSHID_MFG_CFG_IMO_TR1_PTR                ((reg8 *) CYDEV_FLSHID_MFG_CFG_IMO_TR1)
#define FLSHID_CUST_TABLES_IMO_67MHZ_PTR        ((reg8 *) CYDEV_FLSHID_CUST_TABLES_IMO_67MHZ)
#define FLSHID_CUST_TABLES_IMO_80MHZ_PTR        ((reg8 *) CYDEV_FLSHID_CUST_TABLES_IMO_80MHZ)
#define FLSHID_CUST_TABLES_IMO_USB_PTR            ((reg8 *) CYDEV_FLSHID_CUST_TABLES_IMO_USB)
#endif

#define CLKDIST_CR_PTR                ( (reg8 *) CYREG_CLKDIST_CR)
#define CLKDIST_CR                    (*(reg8 *) CYREG_CLKDIST_CR)
#define FASTCLK_PLL_Q_PTR           ( (reg8 *) CYREG_FASTCLK_PLL_Q)
#define FASTCLK_PLL_Q                   (*(reg8 *) CYREG_FASTCLK_PLL_Q)
#define FASTCLK_PLL_P_PTR             ( (reg8 *) CYREG_FASTCLK_PLL_P)
#define FASTCLK_PLL_P                 (*(reg8 *) CYREG_FASTCLK_PLL_P)
#define FASTCLK_PLL_CFG1_PTR        ( (reg8 *) CYREG_FASTCLK_PLL_CFG1)
#define FASTCLK_PLL_CFG1            (*(reg8 *) CYREG_FASTCLK_PLL_CFG1)
#define FASTCLK_XMHZ_CFG0_PTR       ( (reg8 *) CYREG_FASTCLK_XMHZ_CFG0)
#define FASTCLK_XMHZ_CFG0           (*(reg8 *) CYREG_FASTCLK_XMHZ_CFG0)
#define FASTCLK_XMHZ_CFG1_PTR       ( (reg8 *) CYREG_FASTCLK_XMHZ_CFG1)
#define FASTCLK_XMHZ_CFG1           (*(reg8 *) CYREG_FASTCLK_XMHZ_CFG1)
#define USB_CLKDIST_CONFIG_PTR        ( (reg8 *) CYREG_CLKDIST_UCFG)
#define USB_CLKDIST_CONFIG               (*(reg8 *) CYREG_CLKDIST_UCFG)
/* CYLIB CLOCK macros/funcs end */


/* CYLIB SYSTEM macros/funcs begin*/
void CyHalt(uint8 reason);

#if !defined(NDEBUG)

/*******************************************************************************
* Macro Name: CyAssert
********************************************************************************
* Summary:
*   Macro that evaluates the expression and if it is false (evaluates to 0) 
*   then the processor is halted.
*   
*   This macro is evaluated unless NDEBUG is defined.  
*   If NDEBUG is defined, then no code is generated for this macro.  
*   NDEBUG is defined by default for a Release build setting and not defined for 
*    a Debug build setting.
*
*
* Parameters:
*   expr: Logical expression.  Asserts if false.
*
*
* Return:
*   void.
*
*******************************************************************************/
#define CYASSERT(x)             {if(!(x)) CyHalt((uint32) (x));}

#else /* NDEBUG */

#define CYASSERT(x)

#endif /* NDEBUG */

/* CYLIB SYSTEM macros/funcs end */

/* CYLIB STRING macros/funcs begin */

/* cymemset and cymemcpy are defined for compatibility and are not recommended for use in new code. */
#define cymemset(s,c,n) memset(s,c,n)
#define cymemcpy(d,s,n) memcpy(d,s,n)

/* CYLIB STRING macros/funcs end */


/* Watchdog timer registers. */
#define CYWDT_CFG                   ((reg8 *) CYREG_PM_WDT_CFG)
#define CYWDT_CR                    ((reg8 *) CYREG_PM_WDT_CR)

#define CYWDT_LPMODE_SHIFT          5          /* shift the lpmode value*/
#define CYWDT_TICKS_MASK            0x3        /*wdt_interval[1:0] 0:1 bits of PM_WDT_CFG*/
#define CYWDT_LPMODE_MASK           (0x3 << CYWDT_LPMODE_SHIFT) /*wdt_lpmode[1:0] 5:6 bits of PM_WDT_CFG*/
#define CYWDT_RESET                 0x80       /*ctw_reset is 7th bit of PM_WDT_CFG*/
#define CYWDT_ENABLE_BIT            (0x1 << 4) /*ctw_en is 4th bit of PM_WDT_CFG*/

/* Valid tick counts. */
#define CYWDT_2_TICKS               0x0 /* 2 CTW ticks ==> 4ms - 6ms. */
#define CYWDT_16_TICKS              0x1 /* 16 CTW ticks ==> 32ms - 48ms. */
#define CYWDT_128_TICKS             0x2 /* 128 CTW ticks ==> 256ms - 384ms. */
#define CYWDT_1024_TICKS            0x3 /* 1024 CTW ticks ==> 2.048s - 3.072s. */

/* Valid low power Mode. */
#define CYWDT_LPMODE_NOCHANGE       0x0 /* No Change. */
#define CYWDT_LPMODE_MAXINTER       0x1 /* Switch to longest timer mode during sleep/hibernate. */
#define CYWDT_LPMODE_DISABLED       0x3 /* Disable WDT during sleep/hibernate. */

/* Enables the watchdog timer, also clears the central time wheel. */
#define CYWDT_ENABLE                {*CYWDT_CFG = 0x90 | *CYWDT_CFG;}

/* Set the number of ticks before the watchdog expires. 
   NOTE: Recommended to use the CyWdtStart() function instead of this macro*/
#define CYWDT_TICKS(Ticks)          {*CYWDT_CFG = (Ticks & 0x3) | (*CYWDT_CFG & ~0x3);}

/* Clears the Watchdog timer. 
   NOTE: Recommended to use the CyWdtClear() function instead of this macro.*/
#if ((CYDEV_CHIP_MEMBER_USED == CYDEV_CHIP_MEMBER_3A) && (CYDEV_CHIP_REVISION_USED == CYDEV_CHIP_REVISION_3A_ES2))
   /*ES2 watchdog time clear requires workaround*/
#define CYWDT_CLEAR                 {uint8 wdt_cfg_value = *CYWDT_CFG; *CYWDT_CR = 1; *CYWDT_CFG = 0; *CYWDT_CFG = wdt_cfg_value;}
#else
#define CYWDT_CLEAR                 {*CYWDT_CR = 1;}
#endif 

/* Watch dog functions. */
void CyWdtStart(uint8 ticks, uint8 lpMode);
void CyWdtClear(void);


/* The system does not automatically change the interval or feed the WDT when entering sleep. */
/* This can only be set before the WDT is enabled. */
#define CYWDT_DISABLE_AUTO_FEED     {*CYWDT_CFG = 0x20 | *CYWDT_CFG;}

/*Interrrupt Controller Configuration and Status Register*/
#if ((CYDEV_CHIP_MEMBER_USED == CYDEV_CHIP_MEMBER_3A) && (CYDEV_CHIP_REVISION_USED == CYDEV_CHIP_REVISION_3A_ES3))
#define INTERRUPT_CSR               ((reg8 *) CYREG_INTC_CSR_EN)
#define DISABLE_IRQ_SET             (0x01u << 1)                             /*DISABLE_IRQ bit in INTC_CSR_EN*/
#define INTERRUPT_DISABLE_IRQ       {*INTERRUPT_CSR |= DISABLE_IRQ_SET;}
#define INTERRUPT_ENABLE_IRQ        {*INTERRUPT_CSR &= ~DISABLE_IRQ_SET;}
#endif

/*CYGlobalIntEnable and CYGlobalIntDisable are obsolete. Defined for backward compatibilty.*/
#define CYGlobalIntEnable           CyGlobalIntEnable
#define CYGlobalIntDisable          CyGlobalIntDisable

#if defined(__ARMCC_VERSION)
#define CyGlobalIntEnable           {__enable_irq();}
#define CyGlobalIntDisable          {__disable_irq();}
#elif defined(__GNUC__)
#define CyGlobalIntEnable           {__asm("CPSIE   i");}
#define CyGlobalIntDisable          {__asm("CPSID   i");}
#elif defined(__C51__)

#if ((CYDEV_CHIP_MEMBER_USED == CYDEV_CHIP_MEMBER_3A) && (CYDEV_CHIP_REVISION_USED == CYDEV_CHIP_REVISION_3A_ES3))
#define CyGlobalIntEnable           {EA = 1; INTERRUPT_ENABLE_IRQ}
#define CyGlobalIntDisable          {INTERRUPT_DISABLE_IRQ; CY_NOP; EA = 0;}
#else
#define CyGlobalIntEnable           {EA = 1;}
#define CyGlobalIntDisable          {EA = 0;}
#endif /*CYDEV_CHIP_REVISION_3A_ES3*/

#endif

#ifdef CYREG_MLOGIC_CPU_SCR_CPU_SCR
#define CYDEV_HALT_CPU              CY_SET_REG8(CYREG_MLOGIC_CPU_SCR_CPU_SCR, 0x01)
#else
#define CYDEV_HALT_CPU              CY_SET_REG8(CYREG_MLOGIC_CPU_SCR, 0x01)
#endif

#ifdef CYREG_MLOGIC_REV_ID_REV_ID
#define CYDEV_CHIP_REV_ACTUAL       (CY_GET_REG8(CYREG_MLOGIC_REV_ID_REV_ID))
#else
#define CYDEV_CHIP_REV_ACTUAL       (CY_GET_REG8(CYREG_MLOGIC_REV_ID))
#endif


/***************************************
*    System Function Prototypes
***************************************/
void CyDelay(uint32 milliseconds) CYREENTRANT;
void CyDelayUs(uint16 microseconds);
void CyDelayFreq(uint32 freq) CYREENTRANT;
void CyDelayCycles(uint32 cycles);

uint32 CyDisableInts(void) `=ReentrantKeil("CyDisableInts")`;
void CyEnableInts(uint32 mask) `=ReentrantKeil("CyEnableInts")`;
void CySoftwareReset(void);

uint8 CyEnterCriticalSection(void);
void CyExitCriticalSection(uint8 savedIntrStatus);

/***************************************
*    Interrupt API Constants
***************************************/
#define RESET_CR2           ((reg8 *) CYREG_RESET_CR2)
#if CYDEV_CHIP_MEMBER_USED == CYDEV_CHIP_MEMBER_5A
#define CYINT_IRQ_BASE    16
#define CYINT_VECT_TABLE    ((cyisraddress **) CYREG_NVIC_VECT_OFFSET)
#define CYINT_PRIORITY      ((reg8 *) CYREG_NVIC_PRI_0)
#define CYINT_ENABLE        ((reg32 *) CYREG_NVIC_SETENA0)
#define CYINT_CLEAR         ((reg32 *) CYREG_NVIC_CLRENA0)
#define CYINT_SET_PEND      ((reg32 *) CYREG_NVIC_SETPEND0)
#define CYINT_CLR_PEND      ((reg32 *) CYREG_NVIC_CLRPEND0)
#define CACHE_CC_CTL        ((reg16 *) CYREG_CACHE_CC_CTL)
#elif CYDEV_CHIP_MEMBER_USED == CYDEV_CHIP_MEMBER_3A
#define CYINT_IRQ_BASE    0
#define CYINT_VECT_TABLE    ((cyisraddress CYXDATA *) CYREG_INTC_VECT_MBASE)
#define CYINT_PRIORITY      ((reg8 *) CYREG_INTC_PRIOR0)
#define CYINT_ENABLE        ((reg8 *) CYREG_INTC_SET_EN0)
#define CYINT_CLEAR         ((reg8 *) CYREG_INTC_CLR_EN0)
#define CYINT_SET_PEND      ((reg8 *) CYREG_INTC_SET_PD0)
#define CYINT_CLR_PEND      ((reg8 *) CYREG_INTC_CLR_PD0)
#endif


/***************************************
*    Interrupt Function Prototypes
***************************************/
cyisraddress CyIntSetVector(uint8 number, cyisraddress address) `=ReentrantKeil("CyIntSetVector")`;
cyisraddress CyIntGetVector(uint8 number) `=ReentrantKeil("CyIntGetVector")`;

void CyIntSetPriority(uint8 number, uint8 priority) `=ReentrantKeil("CyIntSetPriority")`;
uint8 CyIntGetPriority(uint8 number) `=ReentrantKeil("CyIntGetPriority")`;

void CyIntEnable(uint8 number) `=ReentrantKeil("CyIntEnable")`;
uint8 CyIntGetState(uint8 number) `=ReentrantKeil("CyIntGetState")`;
void CyIntDisable(uint8 number) `=ReentrantKeil("CyIntDisable")`;

void CyIntSetPending(uint8 number) `=ReentrantKeil("CyIntSetPending")`;
void CyIntClearPending(uint8 number) `=ReentrantKeil("CyIntClearPending")`;

/* __CYLIB_H__ */
#endif
