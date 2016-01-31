﻿//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     Runtime Version:2.0.50727.3625
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

namespace I2C_v3_10 {
    using System;
    
    
    /// <summary>
    ///   A strongly-typed resource class, for looking up localized strings, etc.
    /// </summary>
    // This class was auto-generated by the StronglyTypedResourceBuilder
    // class via a tool like ResGen or Visual Studio.
    // To add or remove a member, edit your .ResX file then rerun ResGen
    // with the /str option, or rebuild your VS project.
    [global::System.CodeDom.Compiler.GeneratedCodeAttribute("System.Resources.Tools.StronglyTypedResourceBuilder", "2.0.0.0")]
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
    [global::System.Runtime.CompilerServices.CompilerGeneratedAttribute()]
    internal class Resource {
        
        private static global::System.Resources.ResourceManager resourceMan;
        
        private static global::System.Globalization.CultureInfo resourceCulture;
        
        [global::System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1811:AvoidUncalledPrivateCode")]
        internal Resource() {
        }
        
        /// <summary>
        ///   Returns the cached ResourceManager instance used by this class.
        /// </summary>
        [global::System.ComponentModel.EditorBrowsableAttribute(global::System.ComponentModel.EditorBrowsableState.Advanced)]
        internal static global::System.Resources.ResourceManager ResourceManager {
            get {
                if (object.ReferenceEquals(resourceMan, null)) {
                    global::System.Resources.ResourceManager temp = new global::System.Resources.ResourceManager("I2C_v3_10.Resource", typeof(Resource).Assembly);
                    resourceMan = temp;
                }
                return resourceMan;
            }
        }
        
        /// <summary>
        ///   Overrides the current thread's CurrentUICulture property for all
        ///   resource lookups using this strongly typed resource class.
        /// </summary>
        [global::System.ComponentModel.EditorBrowsableAttribute(global::System.ComponentModel.EditorBrowsableState.Advanced)]
        internal static global::System.Globalization.CultureInfo Culture {
            get {
                return resourceCulture;
            }
            set {
                resourceCulture = value;
            }
        }
        
        /// <summary>
        ///   Looks up a localized string similar to Internal Clock can be used for UDB implementation only..
        /// </summary>
        internal static string ClockSourceValidator {
            get {
                return ResourceManager.GetString("ClockSourceValidator", resourceCulture);
            }
        }
        
        /// <summary>
        ///   Looks up a localized string similar to Fixed-Function implementation supports only standard data rates 50, 100 or 400 kbps for PSoC 5 devices..
        /// </summary>
        internal static string DRCDataRateInvalid {
            get {
                return ResourceManager.GetString("DRCDataRateInvalid", resourceCulture);
            }
        }
        
        /// <summary>
        ///   Looks up a localized string similar to The &quot;Enable wakeup from Sleep Mode&quot; option is not supported by the PSoC 5 devices..
        /// </summary>
        internal static string DRCRevisionErrorPSoC5A {
            get {
                return ResourceManager.GetString("DRCRevisionErrorPSoC5A", resourceCulture);
            }
        }
        
        /// <summary>
        ///   Looks up a localized string similar to Enable wakeup from Sleep Mode is valid only for Fixed Function Implementation when Slave Mode is chosen with Pins option setting in I2C0 or I2C1..
        /// </summary>
        internal static string EnableWakeupValidator {
            get {
                return ResourceManager.GetString("EnableWakeupValidator", resourceCulture);
            }
        }
        
        /// <summary>
        ///   Looks up a localized string similar to Fixed Placement is valid for Slave mode and UDB implementation only..
        /// </summary>
        internal static string FixedPlacementValidator {
            get {
                return ResourceManager.GetString("FixedPlacementValidator", resourceCulture);
            }
        }
        
        /// <summary>
        ///   Looks up a localized string similar to An I2C Data Rate must be between {0} and {1} kbps..
        /// </summary>
        internal static string I2CDataRateValidator {
            get {
                return ResourceManager.GetString("I2CDataRateValidator", resourceCulture);
            }
        }
        
        /// <summary>
        ///   Looks up a localized string similar to The I2C instance &apos;{0}&apos; is not configured as Slave or Multi-Master-Slave, but has been chosen as the bootloader IO component..
        /// </summary>
        internal static string I2CNotContainSlave {
            get {
                return ResourceManager.GetString("I2CNotContainSlave", resourceCulture);
            }
        }
        
        /// <summary>
        ///   Looks up a localized string similar to The I2C instance &apos;{0}&apos; is not configured as a Fixed Function I2C, but has been chosen as the bootloader IO component..
        /// </summary>
        internal static string I2CNotFixedFunction {
            get {
                return ResourceManager.GetString("I2CNotFixedFunction", resourceCulture);
            }
        }
        
        /// <summary>
        ///   Looks up a localized string similar to Slave address value must be between {0} and {1}..
        /// </summary>
        internal static string SlaveAddressValidator {
            get {
                return ResourceManager.GetString("SlaveAddressValidator", resourceCulture);
            }
        }
        
        /// <summary>
        ///   Looks up a localized string similar to Basic Configuration.
        /// </summary>
        internal static string TabBasicConfDisplayName {
            get {
                return ResourceManager.GetString("TabBasicConfDisplayName", resourceCulture);
            }
        }
        
        /// <summary>
        ///   Looks up a localized string similar to Built-in.
        /// </summary>
        internal static string TabBuiltInDisplayName {
            get {
                return ResourceManager.GetString("TabBuiltInDisplayName", resourceCulture);
            }
        }
        
        /// <summary>
        ///   Looks up a localized string similar to Tolerance value must be between {0}% and +{1}%..
        /// </summary>
        internal static string ToleranceValidator {
            get {
                return ResourceManager.GetString("ToleranceValidator", resourceCulture);
            }
        }
        
        /// <summary>
        ///   Looks up a localized string similar to UNKNOWN (Updated after &apos;Apply&apos;).
        /// </summary>
        internal static string UnknownActualDataRate {
            get {
                return ResourceManager.GetString("UnknownActualDataRate", resourceCulture);
            }
        }
    }
}
