/*******************************************************************************
* Copyright 2008-2009, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/



using System;
using System.Collections.Generic;
using System.Windows.Forms;

namespace SegLCD_v1_20
{
    public partial class CyBasicConfiguration : UserControl
    {
        public CyLCDParameters m_Parameters;
        public bool m_ParametersChanged;

        public CyBasicConfiguration()
        {
            InitializeComponent();

            this.m_Parameters = new CyLCDParameters();

            InitComboBoxes();
            SetBiasType();

            m_Parameters.NumCommonLines = (byte)numUpDownNumCommonLines.Value;
            m_Parameters.NumSegmentLines = (byte)numUpDownNumSegmentLines.Value;
        }


        public CyBasicConfiguration(CyLCDParameters parameters)
        {
            InitializeComponent();

            this.m_Parameters = parameters;

            InitComboBoxes();
            SetBiasType();

            LoadValuesFromParameters();
        }

        private void LoadValuesFromParameters()
        {
            numUpDownNumCommonLines.Value = m_Parameters.NumCommonLines;
            numUpDownNumSegmentLines.Value = m_Parameters.NumSegmentLines;
            comboBoxWaveformType.SelectedIndex = m_Parameters.WaveformType;
            comboBoxFrameRate.Text = m_Parameters.FrameRate.ToString();
            comboBoxBiasVoltage.SelectedIndex = m_Parameters.BiasVoltage;
            checkBoxGang.Checked = m_Parameters.Gang;
            checkBoxDebugMode.Checked = m_Parameters.DebugMode;
        }

        private void InitComboBoxes()
        {
            comboBoxFrameRate.Items.Clear();
            for (int i = 10; i <= 150; i += 10)
                comboBoxFrameRate.Items.Add(i);

            comboBoxBiasVoltage.Items.Clear();
            for (double i = 2.0; i < 5.21; i += 0.05)
                comboBoxBiasVoltage.Items.Add(i.ToString("f2"));
        }

        private void numUpDownNumCommonLines_ValueChanged(object sender, EventArgs e)
        {
            if ((m_Parameters.m_HelpersConfig.Count > 1) && 
                (numUpDownNumCommonLines.Value != m_Parameters.NumCommonLines))
            {
                MessageBox.Show("Please, remove helper functions first.", "Information",
                                MessageBoxButtons.OK, MessageBoxIcon.Information);
                numUpDownNumCommonLines.Value = m_Parameters.NumCommonLines;
                return;
            }
            numUpDownNumSegmentLines.Maximum = 64 - (int)numUpDownNumCommonLines.Value;
            SetBiasType();

            bool updateEmptyHelper = numUpDownNumCommonLines.Value != m_Parameters.NumCommonLines;

            if (m_Parameters.NumCommonLines != (byte)numUpDownNumCommonLines.Value)
                m_Parameters.NumCommonLines = (byte)numUpDownNumCommonLines.Value;

            UpdateDisabledCommons();
            SetClockFrequency();

            //Update Empty helper
            if (updateEmptyHelper)
            {
                HelperInfo.UpdateEmptyHelper(m_Parameters);
            }


            m_ParametersChanged = true;
        }

        private void SetBiasType()
        {
            int value = (int)numUpDownNumCommonLines.Value;
            if (value == 1)
            {
                editBiasType.Text = "Direct";
                m_Parameters.BiasType = 0;
            }
            else if ((value >= 2) && (value <= 6))
            {
                editBiasType.Text = "1/3";
                m_Parameters.BiasType = 0;
            }
            else if ((value >= 7) && (value <= 11))
            {
                editBiasType.Text = "1/4";
                m_Parameters.BiasType = 1;
            }
            else // 12-16
            {
                editBiasType.Text = "1/5";
                m_Parameters.BiasType = 2;
            }
        }

        private void SetClockFrequency()
        {
            if (m_Parameters.WaveformType == 0)
                m_Parameters.ClockFrequency =
                   Convert.ToUInt32((m_Parameters.NumCommonLines - m_Parameters.DisabledCommons.Count)*
                                 m_Parameters.FrameRate*512);
            else
                m_Parameters.ClockFrequency =
                   Convert.ToUInt32((m_Parameters.NumCommonLines - m_Parameters.DisabledCommons.Count) *
                                 m_Parameters.FrameRate * 256);

        }

        private void UpdateDisabledCommons()
        {
            foreach (int val in m_Parameters.DisabledCommons)
            {
                if (val >= m_Parameters.NumCommonLines)
                {
                    List<int> DisabledCommons = new List<int>(m_Parameters.DisabledCommons);
                    DisabledCommons.Remove(val);
                    m_Parameters.DisabledCommons = DisabledCommons;
                }
            }
        }

        private void numUpDownNumSegmentLines_ValueChanged(object sender, EventArgs e)
        {
            if ((m_Parameters.m_HelpersConfig.Count > 1) && 
                (numUpDownNumSegmentLines.Value != m_Parameters.NumSegmentLines))
            {
                MessageBox.Show("Please, remove helper functions first.", "Information",
                                MessageBoxButtons.OK, MessageBoxIcon.Information);
                numUpDownNumSegmentLines.Value = m_Parameters.NumSegmentLines;
                return;
            }

            bool updateEmptyHelper = numUpDownNumSegmentLines.Value != m_Parameters.NumSegmentLines;

            if (m_Parameters.NumSegmentLines != (byte)numUpDownNumSegmentLines.Value)
                m_Parameters.NumSegmentLines = (byte)numUpDownNumSegmentLines.Value;

            //Update Empty helper
            if (updateEmptyHelper)
            {
                HelperInfo.UpdateEmptyHelper(m_Parameters);
            }

            m_ParametersChanged = true;
        }

        private void comboBoxWaveformType_SelectedIndexChanged(object sender, EventArgs e)
        {
            m_Parameters.WaveformType = (byte)comboBoxWaveformType.SelectedIndex;
            SetClockFrequency();
        }

        private void comboBoxFrameRate_SelectedIndexChanged(object sender, EventArgs e)
        {
            m_Parameters.FrameRate = Convert.ToByte(comboBoxFrameRate.Text);
            SetClockFrequency();
        }

        private void comboBoxBiasVoltage_SelectedIndexChanged(object sender, EventArgs e)
        {
            m_Parameters.BiasVoltage = (byte)comboBoxBiasVoltage.SelectedIndex;
        }

        private void checkBoxGang_CheckedChanged(object sender, EventArgs e)
        {
            m_Parameters.Gang = checkBoxGang.Checked;
        }

        private void checkBoxDebugMode_CheckedChanged(object sender, EventArgs e)
        {
            m_Parameters.DebugMode = checkBoxDebugMode.Checked;
        }

        private void CyBasicConfiguration_Leave(object sender, EventArgs e)
        {
            // Save changes
            if (m_ParametersChanged)
                m_Parameters.SerializedHelpers = HelperInfo.SerializeHelpers(m_Parameters.m_HelpersConfig);
            m_ParametersChanged = false;
        }
    }
}

