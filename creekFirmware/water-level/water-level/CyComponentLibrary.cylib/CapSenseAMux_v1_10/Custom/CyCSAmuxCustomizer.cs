/*******************************************************************************
* Copyright 2008-2009, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/



using System;
using System.Collections.Generic;
using System.Text;
using System.Windows.Forms;
using CyDesigner.Extensions.Common;
using CapSenseAMux_v1_10.LogicGateCustomizer;
using System.Diagnostics;
using System.Drawing;
using CyDesigner.Extensions.Gde;

namespace CyCustomizer.CapSenseAMux_v1_10
{
    [CyCompDevCustomizer()]
    public partial class CyCustomizer :
        ICyVerilogCustomize_v1        
    {
        const string OUTPUT_A_TERM_BASE_NAME = "AoutTerm";
        const string OUTPUT_B_TERM_BASE_NAME = "BoutTerm";
        const string GENERATED_SHAPE = "SymbolShape";
        const string INPUT_A_TERM_BASE_NAME = "AinTerm";
        const string INPUT_B_TERM_BASE_NAME = "BinTerm";
        const string AMUX_PRIM_NAME = "cy_psoc3_amux_v1_0";

        const uint SINGLE_MUX = 1;
        const uint DIFFERENTIAL_MUX = 2;

        #region ICyVerilogCustomize_v1 Members

        public CyCustErr CustomizeVerilog(
            ICyInstQuery_v1 instQuery,
            ICyTerminalQuery_v1 termQuery,
            out string codeSnippet)
        {
            string outASigSegName = string.Empty;
            string outBSigSegName = string.Empty;

            Debug.Assert(instQuery != null);

            if (instQuery == null)
            {
                codeSnippet = string.Empty;
                return new CyCustErr("Invalid instance query parameter");
            }

            // Get parameters
            CyCompDevParam numTerminals_param = instQuery.GetCommittedParam("Channels");
            uint numTerminals = uint.Parse(numTerminals_param.Value);

            CyCompDevParam ChannelWidth_param = instQuery.GetCommittedParam("MuxType");
            uint ChannelWidth = uint.Parse(ChannelWidth_param.Value);

            string mux_A_suffix = string.Empty;
            string mux_B_suffix = string.Empty;

            if (ChannelWidth == DIFFERENTIAL_MUX)
            {
                mux_A_suffix = "_CYAMUXSIDE_A";
                mux_B_suffix = "_CYAMUXSIDE_B";
            }

            // Collect the signal segment names for each of the instance terminals
            List<string> inASigSegNames = new List<string>();
            List<string> inBSigSegNames = new List<string>();

            // Note: This works because the term names are generated by us in
            inASigSegNames = GetTermNames(instQuery, termQuery, ref numTerminals);

            outASigSegName = termQuery.GetTermSigSegScalarName(OUTPUT_A_TERM_BASE_NAME);

            string instanceName = instQuery.InstanceName;

            CyVerilogBuilder vBuilder = new CyVerilogBuilder();
            vBuilder.AddComment("-- AMux " + instanceName + " start -- ***");

            // Build first Mux A verilog code
            vBuilder.AddComment("-- Mux A --");
            vBuilder.WriteLine("");
            vBuilder.WriteLine(AMUX_PRIM_NAME + " " + instanceName + mux_A_suffix + "(");
            vBuilder.IncreaseIndent();
            vBuilder.WriteLine(".muxin({");
            vBuilder.IncreaseIndent();
            // Add the signal names for the muxin input
            for (int i = (inASigSegNames.Count - 1); i >= 0; i--)
            {
                if (i > 0)
                {
                    vBuilder.WriteLine(inASigSegNames[i] + ",");
                }
                else
                {
                    vBuilder.WriteLine(inASigSegNames[i]);
                }
            }
            vBuilder.WriteLine("}),");
            vBuilder.DecreaseIndent();
            vBuilder.WriteLine(".vout(" + outASigSegName + ")");
            vBuilder.WriteLine(");");
            vBuilder.DecreaseIndent();
            vBuilder.WriteLine("");

            vBuilder.DefineParam(instanceName + mux_A_suffix, "muxin_width", numTerminals.ToString());
            vBuilder.DefineParam(instanceName + mux_A_suffix, "init_mux_sel", numTerminals.ToString() + "'h0");
            vBuilder.WriteLine("");

            if (ChannelWidth == DIFFERENTIAL_MUX)
            {
                // Build  Mux B verilog code
                vBuilder.WriteLine("");
                vBuilder.AddComment("-- Mux B --");
                vBuilder.WriteLine("");
                vBuilder.WriteLine(AMUX_PRIM_NAME + " " + instanceName + mux_B_suffix + "(");
                vBuilder.IncreaseIndent();
                vBuilder.WriteLine(".muxin({");
                vBuilder.IncreaseIndent();
                // Add the signal names for the muxin input
                for (int i = (inBSigSegNames.Count - 1); i >= 0; i--)
                {
                    if (i > 0)
                    {
                        vBuilder.WriteLine(inBSigSegNames[i] + ",");
                    }
                    else
                    {
                        vBuilder.WriteLine(inBSigSegNames[i]);
                    }
                }
                vBuilder.WriteLine("}),");
                vBuilder.DecreaseIndent();
                vBuilder.WriteLine(".vout(" + outBSigSegName + ")");
                vBuilder.WriteLine(");");
                vBuilder.DecreaseIndent();
                vBuilder.WriteLine("");

                vBuilder.DefineParam(instanceName + mux_B_suffix, "muxin_width", numTerminals.ToString());
                vBuilder.DefineParam(instanceName + mux_B_suffix, "init_mux_sel", numTerminals.ToString() + "'h0");
                vBuilder.WriteLine("");

            }
            vBuilder.AddComment("-- AMux " + instanceName + " end --");
            codeSnippet = vBuilder.VerilogString;

            return CyCustErr.OK;
        }

        private IEnumerable<string> GetOrderedTermNames(ICyTerminalQuery_v1 termQuery)
        {
            List<string> termNames = new List<string>();
            foreach (string termName in termQuery.GetTerminalNames())
            {
                termNames.Add(termName);
            }
            termNames.Sort();
            return termNames;
        }

        #endregion

     }
}
