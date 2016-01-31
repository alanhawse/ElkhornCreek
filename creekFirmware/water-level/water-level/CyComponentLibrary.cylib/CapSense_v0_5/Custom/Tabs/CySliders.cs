/*******************************************************************************
* Copyright 2008-2009, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/



using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace  CapSense_v0_5
{
    public partial class CySliders : M_ICyParamEditTemplate
    {
        public CySliders()
            : base()
        {
            InitializeComponent();
            this.colType.Items.Clear();
            this.colType.Items.AddRange(CyGeneralParams.strSliderType);
        }
    }
}

