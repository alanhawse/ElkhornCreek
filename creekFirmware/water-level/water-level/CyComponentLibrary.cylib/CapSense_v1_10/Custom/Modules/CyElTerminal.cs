/*******************************************************************************
* Copyright 2008-2009, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/



using System;
using System.Collections.Generic;
using System.Text;
using System.Drawing;
using System.Xml.Serialization;


namespace  CapSense_v1_10
{
    #region Terminals Classes
    [Serializable()]
    public class CyElTerminal
    {

        [XmlAttribute("Name")]
        public string m_Name;
        [XmlAttribute("Nameindex")]
        public int m_Nameindex = -1;
        [XmlAttribute("Method")]
        public E_CAPSENSE_MODE m_method = E_CAPSENSE_MODE.CSD;
        [XmlAttribute("Enable")]
        public bool m_Enable = false;

        [XmlAttribute("IsLeft")]
        public E_EL_SIDE m_haveSide = E_EL_SIDE.None;

        [XmlAttribute("Type")]
        public E_SENSOR_TYPE m_type;

        Color m_color = CyGeneralParams.m_ColorLeft;

        public Color Color
        {
            get
            {
                switch (m_haveSide)
                {
                    case E_EL_SIDE.None:
                        return Color.White;

                    case E_EL_SIDE.Left:
                        return CyGeneralParams.m_ColorLeft;

                    case E_EL_SIDE.Right:
                        return CyGeneralParams.m_ColorRight;

                    default:
                        return Color.White;
                }
            }

        }


        public CyElTerminal()
        {
            this.m_haveSide = E_EL_SIDE.None;
        }
        public CyElTerminal(E_EL_SIDE haveSide)
        {
            this.m_haveSide = haveSide;
        }
        public CyElTerminal(string Name, E_SENSOR_TYPE type)
        {
            this.m_Name = Name;
            this.m_type = type;
            this.m_Enable = true;
            m_Nameindex = -1;
        }
        public CyElTerminal(string Name, E_SENSOR_TYPE type, int Nameindex)
        {
            this.m_Name = Name;
            this.m_type = type;
            this.m_Enable = true;
            this.m_Nameindex = Nameindex;
        }
        public CyElTerminal(string Name, bool Enable, E_EL_SIDE haveSide)
        {
            this.m_Name = Name;
            this.m_Enable = Enable;
            this.m_haveSide = haveSide;
        }

        public string GetPref()
        {
            string res = "";
            if (m_haveSide == E_EL_SIDE.Right) res = "R_";
            else if (m_haveSide == E_EL_SIDE.Left) res = "L_";
            return res;
        }

        public override string ToString()
        {
            return GetName();
        }
        public bool IsSameW(CyElTerminal term,bool subTypeInclude)
        {
            if (m_Name != term.m_Name) return false;
            if (m_type != term.m_type) return false;
            if (subTypeInclude)
            {

            }
            return true;
        }
        public bool IsSameFull(CyElTerminal term)
        {
            if (m_Name != term.m_Name) return false;
            if (m_type != term.m_type) return false;
            if (m_Nameindex != term.m_Nameindex) return false;
            if (ToString() != term.ToString()) return false;

            return true;
        }
        public string GetName()
        {
            string res = "";
            switch (m_type)
            {
                case E_SENSOR_TYPE.Button: res = "BTN_" + m_Name; break;

                case E_SENSOR_TYPE.Linear_Slider: res = "LS_" + m_Name + "_e" + m_Nameindex; break;


                case E_SENSOR_TYPE.Radial_Slider: res = "RS_" + m_Name + "_e" + m_Nameindex; break;

                case E_SENSOR_TYPE.Touchpad_Col: res = "TP_" + m_Name + "_Col" + "_" + m_Nameindex; break;

                case E_SENSOR_TYPE.Touchpad_Row: res = "TP_" + m_Name + "_Row" + "_" + m_Nameindex; break;

                case E_SENSOR_TYPE.Matrix_Buttons_Col: res = "MB_" + m_Name + "_Col" + "_" + m_Nameindex; break;

                case E_SENSOR_TYPE.Matrix_Buttons_Row: res = "MB_" + m_Name + "_Row" + "_" + m_Nameindex; break;

                case E_SENSOR_TYPE.Proximity: res = "PROX_" + m_Name +"_"+ m_Nameindex; break;

                case E_SENSOR_TYPE.Generic: res = "GEN_" + m_Name + "_" + m_Nameindex; break;

                default:
                    break;
            }

            //For Custom Proximity and Generic case
            if (m_Nameindex == -1)
            {
                switch (m_type)
                {
                    case E_SENSOR_TYPE.Proximity: res = "PROX_" + m_Name; break;

                    case E_SENSOR_TYPE.Generic: res = "GEN_" + m_Name ; break;
                }
            }
            return res;

        }
    }
    #endregion
}
