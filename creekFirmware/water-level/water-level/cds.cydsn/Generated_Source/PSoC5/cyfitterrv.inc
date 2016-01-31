    IF :LNOT::DEF:INCLUDED_CYFITTERRV_INC
INCLUDED_CYFITTERRV_INC EQU 1
    GET cydevicerv.inc
    GET cydevicerv_trm.inc

; adc_Ext_CP_Clk
adc_Ext_CP_Clk__CFG0 EQU CYREG_CLKDIST_DCFG0_CFG0
adc_Ext_CP_Clk__CFG1 EQU CYREG_CLKDIST_DCFG0_CFG1
adc_Ext_CP_Clk__CFG2 EQU CYREG_CLKDIST_DCFG0_CFG2
adc_Ext_CP_Clk__CFG2_SRC_SEL_MASK EQU 0x07
adc_Ext_CP_Clk__INDEX EQU 0x00
adc_Ext_CP_Clk__PM_ACT_CFG EQU CYREG_PM_ACT_CFG2
adc_Ext_CP_Clk__PM_ACT_MSK EQU 0x01
adc_Ext_CP_Clk__PM_STBY_CFG EQU CYREG_PM_STBY_CFG2
adc_Ext_CP_Clk__PM_STBY_MSK EQU 0x01

; i2c_I2C_Prim
i2c_I2C_Prim__ADR EQU CYREG_I2C_ADR
i2c_I2C_Prim__CFG EQU CYREG_I2C_CFG
i2c_I2C_Prim__CLK_DIV EQU CYREG_I2C_CLK_DIV
i2c_I2C_Prim__CSR EQU CYREG_I2C_CSR
i2c_I2C_Prim__D EQU CYREG_I2C_D
i2c_I2C_Prim__MCSR EQU CYREG_I2C_MCSR
i2c_I2C_Prim__PM_ACT_CFG EQU CYREG_PM_ACT_CFG5
i2c_I2C_Prim__PM_ACT_MSK EQU 0x04
i2c_I2C_Prim__PM_STBY_CFG EQU CYREG_PM_STBY_CFG5
i2c_I2C_Prim__PM_STBY_MSK EQU 0x04
i2c_I2C_Prim__XCFG EQU CYREG_I2C_XCFG

; adc_theACLK
adc_theACLK__CFG0 EQU CYREG_CLKDIST_ACFG0_CFG0
adc_theACLK__CFG1 EQU CYREG_CLKDIST_ACFG0_CFG1
adc_theACLK__CFG2 EQU CYREG_CLKDIST_ACFG0_CFG2
adc_theACLK__CFG2_SRC_SEL_MASK EQU 0x07
adc_theACLK__CFG3 EQU CYREG_CLKDIST_ACFG0_CFG3
adc_theACLK__CFG3_PHASE_DLY_MASK EQU 0x0F
adc_theACLK__INDEX EQU 0x00
adc_theACLK__PM_ACT_CFG EQU CYREG_PM_ACT_CFG1
adc_theACLK__PM_ACT_MSK EQU 0x01
adc_theACLK__PM_STBY_CFG EQU CYREG_PM_STBY_CFG1
adc_theACLK__PM_STBY_MSK EQU 0x01

; lcd_LCDPort
lcd_LCDPort__0__MASK EQU 0x01
lcd_LCDPort__0__PC EQU CYREG_PRT2_PC0
lcd_LCDPort__0__PORT EQU 2
lcd_LCDPort__0__SHIFT EQU 0
lcd_LCDPort__1__MASK EQU 0x02
lcd_LCDPort__1__PC EQU CYREG_PRT2_PC1
lcd_LCDPort__1__PORT EQU 2
lcd_LCDPort__1__SHIFT EQU 1
lcd_LCDPort__2__MASK EQU 0x04
lcd_LCDPort__2__PC EQU CYREG_PRT2_PC2
lcd_LCDPort__2__PORT EQU 2
lcd_LCDPort__2__SHIFT EQU 2
lcd_LCDPort__3__MASK EQU 0x08
lcd_LCDPort__3__PC EQU CYREG_PRT2_PC3
lcd_LCDPort__3__PORT EQU 2
lcd_LCDPort__3__SHIFT EQU 3
lcd_LCDPort__4__MASK EQU 0x10
lcd_LCDPort__4__PC EQU CYREG_PRT2_PC4
lcd_LCDPort__4__PORT EQU 2
lcd_LCDPort__4__SHIFT EQU 4
lcd_LCDPort__5__MASK EQU 0x20
lcd_LCDPort__5__PC EQU CYREG_PRT2_PC5
lcd_LCDPort__5__PORT EQU 2
lcd_LCDPort__5__SHIFT EQU 5
lcd_LCDPort__6__MASK EQU 0x40
lcd_LCDPort__6__PC EQU CYREG_PRT2_PC6
lcd_LCDPort__6__PORT EQU 2
lcd_LCDPort__6__SHIFT EQU 6
lcd_LCDPort__AG EQU CYREG_PRT2_AG
lcd_LCDPort__AMUX EQU CYREG_PRT2_AMUX
lcd_LCDPort__BIE EQU CYREG_PRT2_BIE
lcd_LCDPort__BIT_MASK EQU CYREG_PRT2_BIT_MASK
lcd_LCDPort__BYP EQU CYREG_PRT2_BYP
lcd_LCDPort__CTL EQU CYREG_PRT2_CTL
lcd_LCDPort__DM0 EQU CYREG_PRT2_DM0
lcd_LCDPort__DM1 EQU CYREG_PRT2_DM1
lcd_LCDPort__DM2 EQU CYREG_PRT2_DM2
lcd_LCDPort__DR EQU CYREG_PRT2_DR
lcd_LCDPort__INP_DIS EQU CYREG_PRT2_INP_DIS
lcd_LCDPort__LCD_COM_SEG EQU CYREG_PRT2_LCD_COM_SEG
lcd_LCDPort__LCD_EN EQU CYREG_PRT2_LCD_EN
lcd_LCDPort__MASK EQU 0x7F
lcd_LCDPort__PORT EQU 2
lcd_LCDPort__PRT EQU CYREG_PRT2_PRT
lcd_LCDPort__PRTDSI__CAPS_SEL EQU CYREG_PRT2_CAPS_SEL
lcd_LCDPort__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT2_DBL_SYNC_IN
lcd_LCDPort__PRTDSI__OE_SEL0 EQU CYREG_PRT2_OE_SEL0
lcd_LCDPort__PRTDSI__OE_SEL1 EQU CYREG_PRT2_OE_SEL1
lcd_LCDPort__PRTDSI__OUT_SEL0 EQU CYREG_PRT2_OUT_SEL0
lcd_LCDPort__PRTDSI__OUT_SEL1 EQU CYREG_PRT2_OUT_SEL1
lcd_LCDPort__PRTDSI__SYNC_OUT EQU CYREG_PRT2_SYNC_OUT
lcd_LCDPort__PS EQU CYREG_PRT2_PS
lcd_LCDPort__SHIFT EQU 0
lcd_LCDPort__SLW EQU CYREG_PRT2_SLW

; adc_DSM2
adc_DSM2__BUF0 EQU CYREG_DSM0_BUF0
adc_DSM2__BUF1 EQU CYREG_DSM0_BUF1
adc_DSM2__BUF2 EQU CYREG_DSM0_BUF2
adc_DSM2__BUF3 EQU CYREG_DSM0_BUF3
adc_DSM2__CLK EQU CYREG_DSM0_CLK
adc_DSM2__CR0 EQU CYREG_DSM0_CR0
adc_DSM2__CR1 EQU CYREG_DSM0_CR1
adc_DSM2__CR10 EQU CYREG_DSM0_CR10
adc_DSM2__CR11 EQU CYREG_DSM0_CR11
adc_DSM2__CR12 EQU CYREG_DSM0_CR12
adc_DSM2__CR13 EQU CYREG_DSM0_CR13
adc_DSM2__CR14 EQU CYREG_DSM0_CR14
adc_DSM2__CR15 EQU CYREG_DSM0_CR15
adc_DSM2__CR16 EQU CYREG_DSM0_CR16
adc_DSM2__CR17 EQU CYREG_DSM0_CR17
adc_DSM2__CR2 EQU CYREG_DSM0_CR2
adc_DSM2__CR3 EQU CYREG_DSM0_CR3
adc_DSM2__CR4 EQU CYREG_DSM0_CR4
adc_DSM2__CR5 EQU CYREG_DSM0_CR5
adc_DSM2__CR6 EQU CYREG_DSM0_CR6
adc_DSM2__CR7 EQU CYREG_DSM0_CR7
adc_DSM2__CR8 EQU CYREG_DSM0_CR8
adc_DSM2__CR9 EQU CYREG_DSM0_CR9
adc_DSM2__DEM0 EQU CYREG_DSM0_DEM0
adc_DSM2__DEM1 EQU CYREG_DSM0_DEM1
adc_DSM2__MISC EQU CYREG_DSM0_MISC
adc_DSM2__OUT0 EQU CYREG_DSM0_OUT0
adc_DSM2__OUT1 EQU CYREG_DSM0_OUT1
adc_DSM2__REF0 EQU CYREG_DSM0_REF0
adc_DSM2__REF1 EQU CYREG_DSM0_REF1
adc_DSM2__REF2 EQU CYREG_DSM0_REF2
adc_DSM2__REF3 EQU CYREG_DSM0_REF3
adc_DSM2__RSVD1 EQU CYREG_DSM0_RSVD1
adc_DSM2__SW0 EQU CYREG_DSM0_SW0
adc_DSM2__SW2 EQU CYREG_DSM0_SW2
adc_DSM2__SW3 EQU CYREG_DSM0_SW3
adc_DSM2__SW4 EQU CYREG_DSM0_SW4
adc_DSM2__SW6 EQU CYREG_DSM0_SW6
adc_DSM2__TR0 EQU CYREG_NPUMP_DSM_TR0
adc_DSM2__TST0 EQU CYREG_DSM0_TST0
adc_DSM2__TST1 EQU CYREG_DSM0_TST1

; adc_DEC
adc_DEC__COHER EQU CYREG_DEC_COHER
adc_DEC__CR EQU CYREG_DEC_CR
adc_DEC__DR1 EQU CYREG_DEC_DR1
adc_DEC__DR2 EQU CYREG_DEC_DR2
adc_DEC__DR2H EQU CYREG_DEC_DR2H
adc_DEC__GCOR EQU CYREG_DEC_GCOR
adc_DEC__GCORH EQU CYREG_DEC_GCORH
adc_DEC__GVAL EQU CYREG_DEC_GVAL
adc_DEC__OCOR EQU CYREG_DEC_OCOR
adc_DEC__OCORH EQU CYREG_DEC_OCORH
adc_DEC__OCORM EQU CYREG_DEC_OCORM
adc_DEC__OUTSAMP EQU CYREG_DEC_OUTSAMP
adc_DEC__OUTSAMPH EQU CYREG_DEC_OUTSAMPH
adc_DEC__OUTSAMPM EQU CYREG_DEC_OUTSAMPM
adc_DEC__OUTSAMPS EQU CYREG_DEC_OUTSAMPS
adc_DEC__PM_ACT_CFG EQU CYREG_PM_ACT_CFG10
adc_DEC__PM_ACT_MSK EQU 0x01
adc_DEC__PM_STBY_CFG EQU CYREG_PM_STBY_CFG10
adc_DEC__PM_STBY_MSK EQU 0x01
adc_DEC__SHIFT1 EQU CYREG_DEC_SHIFT1
adc_DEC__SHIFT2 EQU CYREG_DEC_SHIFT2
adc_DEC__SR EQU CYREG_DEC_SR
adc_DEC__TRIM__16H EQU CYREG_FLSHID_CUST_TABLES_DEC_16H
adc_DEC__TRIM__16L EQU CYREG_FLSHID_CUST_TABLES_DEC_16L
adc_DEC__TRIM__1H EQU CYREG_FLSHID_CUST_TABLES_DEC_1H
adc_DEC__TRIM__1L EQU CYREG_FLSHID_CUST_TABLES_DEC_1L
adc_DEC__TRIM__4H EQU CYREG_FLSHID_CUST_TABLES_DEC_4H
adc_DEC__TRIM__4L EQU CYREG_FLSHID_CUST_TABLES_DEC_4L
adc_DEC__TRIM__P25H EQU CYREG_FLSHID_CUST_TABLES_DEC_P25H
adc_DEC__TRIM__P25L EQU CYREG_FLSHID_CUST_TABLES_DEC_P25L

; adc_IRQ
adc_IRQ__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
adc_IRQ__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
adc_IRQ__INTC_MASK EQU 0x20000000
adc_IRQ__INTC_NUMBER EQU 29
adc_IRQ__INTC_PRIOR_NUM EQU 7
adc_IRQ__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_29
adc_IRQ__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
adc_IRQ__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

; i2c_isr
i2c_isr__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
i2c_isr__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
i2c_isr__INTC_MASK EQU 0x01
i2c_isr__INTC_NUMBER EQU 0
i2c_isr__INTC_PRIOR_NUM EQU 7
i2c_isr__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_0
i2c_isr__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
i2c_isr__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

; ledhb
ledhb__0__MASK EQU 0x80
ledhb__0__PC EQU CYREG_PRT2_PC7
ledhb__0__PORT EQU 2
ledhb__0__SHIFT EQU 7
ledhb__AG EQU CYREG_PRT2_AG
ledhb__AMUX EQU CYREG_PRT2_AMUX
ledhb__BIE EQU CYREG_PRT2_BIE
ledhb__BIT_MASK EQU CYREG_PRT2_BIT_MASK
ledhb__BYP EQU CYREG_PRT2_BYP
ledhb__CTL EQU CYREG_PRT2_CTL
ledhb__DM0 EQU CYREG_PRT2_DM0
ledhb__DM1 EQU CYREG_PRT2_DM1
ledhb__DM2 EQU CYREG_PRT2_DM2
ledhb__DR EQU CYREG_PRT2_DR
ledhb__INP_DIS EQU CYREG_PRT2_INP_DIS
ledhb__LCD_COM_SEG EQU CYREG_PRT2_LCD_COM_SEG
ledhb__LCD_EN EQU CYREG_PRT2_LCD_EN
ledhb__MASK EQU 0x80
ledhb__PORT EQU 2
ledhb__PRT EQU CYREG_PRT2_PRT
ledhb__PRTDSI__CAPS_SEL EQU CYREG_PRT2_CAPS_SEL
ledhb__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT2_DBL_SYNC_IN
ledhb__PRTDSI__OE_SEL0 EQU CYREG_PRT2_OE_SEL0
ledhb__PRTDSI__OE_SEL1 EQU CYREG_PRT2_OE_SEL1
ledhb__PRTDSI__OUT_SEL0 EQU CYREG_PRT2_OUT_SEL0
ledhb__PRTDSI__OUT_SEL1 EQU CYREG_PRT2_OUT_SEL1
ledhb__PRTDSI__SYNC_OUT EQU CYREG_PRT2_SYNC_OUT
ledhb__PS EQU CYREG_PRT2_PS
ledhb__SHIFT EQU 7
ledhb__SLW EQU CYREG_PRT2_SLW

; Pin_1
Pin_1__0__MASK EQU 0x01
Pin_1__0__PC EQU CYREG_PRT0_PC0
Pin_1__0__PORT EQU 0
Pin_1__0__SHIFT EQU 0
Pin_1__AG EQU CYREG_PRT0_AG
Pin_1__AMUX EQU CYREG_PRT0_AMUX
Pin_1__BIE EQU CYREG_PRT0_BIE
Pin_1__BIT_MASK EQU CYREG_PRT0_BIT_MASK
Pin_1__BYP EQU CYREG_PRT0_BYP
Pin_1__CTL EQU CYREG_PRT0_CTL
Pin_1__DM0 EQU CYREG_PRT0_DM0
Pin_1__DM1 EQU CYREG_PRT0_DM1
Pin_1__DM2 EQU CYREG_PRT0_DM2
Pin_1__DR EQU CYREG_PRT0_DR
Pin_1__INP_DIS EQU CYREG_PRT0_INP_DIS
Pin_1__LCD_COM_SEG EQU CYREG_PRT0_LCD_COM_SEG
Pin_1__LCD_EN EQU CYREG_PRT0_LCD_EN
Pin_1__MASK EQU 0x01
Pin_1__PORT EQU 0
Pin_1__PRT EQU CYREG_PRT0_PRT
Pin_1__PRTDSI__CAPS_SEL EQU CYREG_PRT0_CAPS_SEL
Pin_1__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT0_DBL_SYNC_IN
Pin_1__PRTDSI__OE_SEL0 EQU CYREG_PRT0_OE_SEL0
Pin_1__PRTDSI__OE_SEL1 EQU CYREG_PRT0_OE_SEL1
Pin_1__PRTDSI__OUT_SEL0 EQU CYREG_PRT0_OUT_SEL0
Pin_1__PRTDSI__OUT_SEL1 EQU CYREG_PRT0_OUT_SEL1
Pin_1__PRTDSI__SYNC_OUT EQU CYREG_PRT0_SYNC_OUT
Pin_1__PS EQU CYREG_PRT0_PS
Pin_1__SHIFT EQU 0
Pin_1__SLW EQU CYREG_PRT0_SLW

; Pin_2
Pin_2__0__MASK EQU 0x02
Pin_2__0__PC EQU CYREG_PRT0_PC1
Pin_2__0__PORT EQU 0
Pin_2__0__SHIFT EQU 1
Pin_2__AG EQU CYREG_PRT0_AG
Pin_2__AMUX EQU CYREG_PRT0_AMUX
Pin_2__BIE EQU CYREG_PRT0_BIE
Pin_2__BIT_MASK EQU CYREG_PRT0_BIT_MASK
Pin_2__BYP EQU CYREG_PRT0_BYP
Pin_2__CTL EQU CYREG_PRT0_CTL
Pin_2__DM0 EQU CYREG_PRT0_DM0
Pin_2__DM1 EQU CYREG_PRT0_DM1
Pin_2__DM2 EQU CYREG_PRT0_DM2
Pin_2__DR EQU CYREG_PRT0_DR
Pin_2__INP_DIS EQU CYREG_PRT0_INP_DIS
Pin_2__LCD_COM_SEG EQU CYREG_PRT0_LCD_COM_SEG
Pin_2__LCD_EN EQU CYREG_PRT0_LCD_EN
Pin_2__MASK EQU 0x02
Pin_2__PORT EQU 0
Pin_2__PRT EQU CYREG_PRT0_PRT
Pin_2__PRTDSI__CAPS_SEL EQU CYREG_PRT0_CAPS_SEL
Pin_2__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT0_DBL_SYNC_IN
Pin_2__PRTDSI__OE_SEL0 EQU CYREG_PRT0_OE_SEL0
Pin_2__PRTDSI__OE_SEL1 EQU CYREG_PRT0_OE_SEL1
Pin_2__PRTDSI__OUT_SEL0 EQU CYREG_PRT0_OUT_SEL0
Pin_2__PRTDSI__OUT_SEL1 EQU CYREG_PRT0_OUT_SEL1
Pin_2__PRTDSI__SYNC_OUT EQU CYREG_PRT0_SYNC_OUT
Pin_2__PS EQU CYREG_PRT0_PS
Pin_2__SHIFT EQU 1
Pin_2__SLW EQU CYREG_PRT0_SLW

; Pin_3
Pin_3__0__MASK EQU 0x01
Pin_3__0__PC EQU CYREG_PRT12_PC0
Pin_3__0__PORT EQU 12
Pin_3__0__SHIFT EQU 0
Pin_3__1__MASK EQU 0x02
Pin_3__1__PC EQU CYREG_PRT12_PC1
Pin_3__1__PORT EQU 12
Pin_3__1__SHIFT EQU 1
Pin_3__AG EQU CYREG_PRT12_AG
Pin_3__BIE EQU CYREG_PRT12_BIE
Pin_3__BIT_MASK EQU CYREG_PRT12_BIT_MASK
Pin_3__BYP EQU CYREG_PRT12_BYP
Pin_3__DM0 EQU CYREG_PRT12_DM0
Pin_3__DM1 EQU CYREG_PRT12_DM1
Pin_3__DM2 EQU CYREG_PRT12_DM2
Pin_3__DR EQU CYREG_PRT12_DR
Pin_3__INP_DIS EQU CYREG_PRT12_INP_DIS
Pin_3__MASK EQU 0x03
Pin_3__PORT EQU 12
Pin_3__PRT EQU CYREG_PRT12_PRT
Pin_3__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT12_DBL_SYNC_IN
Pin_3__PRTDSI__OE_SEL0 EQU CYREG_PRT12_OE_SEL0
Pin_3__PRTDSI__OE_SEL1 EQU CYREG_PRT12_OE_SEL1
Pin_3__PRTDSI__OUT_SEL0 EQU CYREG_PRT12_OUT_SEL0
Pin_3__PRTDSI__OUT_SEL1 EQU CYREG_PRT12_OUT_SEL1
Pin_3__PRTDSI__SYNC_OUT EQU CYREG_PRT12_SYNC_OUT
Pin_3__PS EQU CYREG_PRT12_PS
Pin_3__SHIFT EQU 0
Pin_3__SIO_CFG EQU CYREG_PRT12_SIO_CFG
Pin_3__SIO_DIFF EQU CYREG_PRT12_SIO_DIFF
Pin_3__SIO_HYST_EN EQU CYREG_PRT12_SIO_HYST_EN
Pin_3__SIO_REG_HIFREQ EQU CYREG_PRT12_SIO_REG_HIFREQ
Pin_3__SLW EQU CYREG_PRT12_SLW
Pin_3__scl__MASK EQU 0x01
Pin_3__scl__PC EQU CYREG_PRT12_PC0
Pin_3__scl__PORT EQU 12
Pin_3__scl__SHIFT EQU 0
Pin_3__sda__MASK EQU 0x02
Pin_3__sda__PC EQU CYREG_PRT12_PC1
Pin_3__sda__PORT EQU 12
Pin_3__sda__SHIFT EQU 1

; led
led__0__MASK EQU 0x80
led__0__PC EQU CYREG_PRT1_PC7
led__0__PORT EQU 1
led__0__SHIFT EQU 7
led__AG EQU CYREG_PRT1_AG
led__AMUX EQU CYREG_PRT1_AMUX
led__BIE EQU CYREG_PRT1_BIE
led__BIT_MASK EQU CYREG_PRT1_BIT_MASK
led__BYP EQU CYREG_PRT1_BYP
led__CTL EQU CYREG_PRT1_CTL
led__DM0 EQU CYREG_PRT1_DM0
led__DM1 EQU CYREG_PRT1_DM1
led__DM2 EQU CYREG_PRT1_DM2
led__DR EQU CYREG_PRT1_DR
led__INP_DIS EQU CYREG_PRT1_INP_DIS
led__LCD_COM_SEG EQU CYREG_PRT1_LCD_COM_SEG
led__LCD_EN EQU CYREG_PRT1_LCD_EN
led__MASK EQU 0x80
led__PORT EQU 1
led__PRT EQU CYREG_PRT1_PRT
led__PRTDSI__CAPS_SEL EQU CYREG_PRT1_CAPS_SEL
led__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT1_DBL_SYNC_IN
led__PRTDSI__OE_SEL0 EQU CYREG_PRT1_OE_SEL0
led__PRTDSI__OE_SEL1 EQU CYREG_PRT1_OE_SEL1
led__PRTDSI__OUT_SEL0 EQU CYREG_PRT1_OUT_SEL0
led__PRTDSI__OUT_SEL1 EQU CYREG_PRT1_OUT_SEL1
led__PRTDSI__SYNC_OUT EQU CYREG_PRT1_SYNC_OUT
led__PS EQU CYREG_PRT1_PS
led__SHIFT EQU 7
led__SLW EQU CYREG_PRT1_SLW

; Miscellaneous
; -- WARNING: define names containing LEOPARD or PANTHER are deprecated and will be removed in a future release
CYDEV_DEBUGGING_DPS_SWD_SWV EQU 6
CYDEV_CONFIG_UNUSED_IO_AllowButWarn EQU 0
CYDEV_CONFIGURATION_MODE_COMPRESSED EQU 0
CYDEV_CONFIG_FASTBOOT_ENABLED EQU 0
CYDEV_CHIP_REV_PANTHER_PRODUCTION EQU 1
CYDEV_CHIP_REVISION_5A_PRODUCTION EQU 1
CYDEV_CHIP_MEMBER_5A EQU 2
CYDEV_CHIP_FAMILY_PSOC5 EQU 3
CYDEV_CHIP_DIE_PANTHER EQU 2
CYDEV_CHIP_DIE_EXPECT EQU CYDEV_CHIP_DIE_PANTHER
BCLK__BUS_CLK__HZ EQU 24000000
BCLK__BUS_CLK__KHZ EQU 24000
BCLK__BUS_CLK__MHZ EQU 24
CYDEV_CHIP_DIE_ACTUAL EQU CYDEV_CHIP_DIE_EXPECT
CYDEV_CHIP_DIE_LEOPARD EQU 1
CYDEV_CHIP_DIE_PSOC5LP EQU 3
CYDEV_CHIP_DIE_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_PSOC3 EQU 1
CYDEV_CHIP_FAMILY_PSOC4 EQU 2
CYDEV_CHIP_FAMILY_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_USED EQU CYDEV_CHIP_FAMILY_PSOC5
CYDEV_CHIP_JTAG_ID EQU 0x0E13C069
CYDEV_CHIP_MEMBER_3A EQU 1
CYDEV_CHIP_MEMBER_5B EQU 3
CYDEV_CHIP_MEMBER_UNKNOWN EQU 0
CYDEV_CHIP_MEMBER_USED EQU CYDEV_CHIP_MEMBER_5A
CYDEV_CHIP_REVISION_3A_ES1 EQU 0
CYDEV_CHIP_REVISION_3A_ES2 EQU 1
CYDEV_CHIP_REVISION_3A_ES3 EQU 3
CYDEV_CHIP_REVISION_3A_PRODUCTION EQU 3
CYDEV_CHIP_REVISION_5A_ES0 EQU 0
CYDEV_CHIP_REVISION_5A_ES1 EQU 1
CYDEV_CHIP_REVISION_5B_ES EQU 0
CYDEV_CHIP_REVISION_5B_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_USED EQU CYDEV_CHIP_REVISION_5A_PRODUCTION
CYDEV_CHIP_REV_EXPECT EQU CYDEV_CHIP_REV_PANTHER_PRODUCTION
CYDEV_CHIP_REV_LEOPARD_ES1 EQU 0
CYDEV_CHIP_REV_LEOPARD_ES2 EQU 1
CYDEV_CHIP_REV_LEOPARD_ES3 EQU 3
CYDEV_CHIP_REV_LEOPARD_PRODUCTION EQU 3
CYDEV_CHIP_REV_PANTHER_ES0 EQU 0
CYDEV_CHIP_REV_PANTHER_ES1 EQU 1
CYDEV_CHIP_REV_PSOC5LP_ES EQU 0
CYDEV_CHIP_REV_PSOC5LP_PRODUCTION EQU 0
CYDEV_CONFIGURATION_COMPRESSED EQU 1
CYDEV_CONFIGURATION_DMA EQU 0
CYDEV_CONFIGURATION_ECC EQU 1
CYDEV_CONFIGURATION_IMOENABLED EQU CYDEV_CONFIG_FASTBOOT_ENABLED
CYDEV_CONFIGURATION_MODE EQU CYDEV_CONFIGURATION_MODE_COMPRESSED
CYDEV_CONFIGURATION_MODE_DMA EQU 2
CYDEV_CONFIGURATION_MODE_UNCOMPRESSED EQU 1
CYDEV_CONFIG_UNUSED_IO EQU CYDEV_CONFIG_UNUSED_IO_AllowButWarn
CYDEV_CONFIG_UNUSED_IO_AllowWithInfo EQU 1
CYDEV_CONFIG_UNUSED_IO_Disallowed EQU 2
CYDEV_DATA_CACHE_ENABLED EQU 0
CYDEV_DEBUGGING_DPS EQU CYDEV_DEBUGGING_DPS_SWD_SWV
CYDEV_DEBUGGING_DPS_Disable EQU 3
CYDEV_DEBUGGING_DPS_JTAG_4 EQU 1
CYDEV_DEBUGGING_DPS_JTAG_5 EQU 0
CYDEV_DEBUGGING_DPS_SWD EQU 2
CYDEV_DEBUGGING_ENABLE EQU 1
CYDEV_DEBUGGING_REQXRES EQU 1
CYDEV_DEBUGGING_XRES EQU 0
CYDEV_DEBUG_ENABLE_MASK EQU 0x01
CYDEV_DEBUG_ENABLE_REGISTER EQU CYREG_MLOGIC_DBG_DBE
CYDEV_DMA_CHANNELS_AVAILABLE EQU 24
CYDEV_ECC_ENABLE EQU 0
CYDEV_HEAP_SIZE EQU 0x1000
CYDEV_INSTRUCT_CACHE_ENABLED EQU 1
CYDEV_PROJ_TYPE EQU 0
CYDEV_PROJ_TYPE_BOOTLOADER EQU 1
CYDEV_PROJ_TYPE_LOADABLE EQU 2
CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER EQU 3
CYDEV_PROJ_TYPE_STANDARD EQU 0
CYDEV_PROTECTION_ENABLE EQU 0
CYDEV_STACK_SIZE EQU 0x4000
CYDEV_VDDA_MV EQU 5000
CYDEV_VDDD_MV EQU 5000
CYDEV_VDDIO0_MV EQU 5000
CYDEV_VDDIO1_MV EQU 5000
CYDEV_VDDIO2_MV EQU 5000
CYDEV_VDDIO3_MV EQU 5000
CYDEV_VIO0 EQU 5
CYDEV_VIO0_MV EQU 5000
CYDEV_VIO1 EQU 5
CYDEV_VIO1_MV EQU 5000
CYDEV_VIO2 EQU 5
CYDEV_VIO2_MV EQU 5000
CYDEV_VIO3 EQU 5
CYDEV_VIO3_MV EQU 5000
DMA_CHANNELS_USED__MASK0 EQU 0x00000000
CYDEV_BOOTLOADER_ENABLE EQU 0
    ENDIF
    END