/*******************************************************************************
* File Name: `$INSTANCE_NAME`.c
* Version `$CY_MAJOR_VERSION`.`$CY_MINOR_VERSION`
*
* Description:
*  This file provides the API source code for the Segment LCD component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2009, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/


#include "cytypes.h"
#include "`$INSTANCE_NAME`.h"
#include "CyLib.h"
#include <`$INSTANCE_NAME`_Chop_Clock.h>
#include <`$INSTANCE_NAME`_Int_Clock.h>

/* Look-up tables for different kinds of displays */

#ifdef `$INSTANCE_NAME`_7SEG

const uint8 `$INSTANCE_NAME`_7SegDigits[] =
    /*'0'  '1'  '2'  '3'  '4'  '5'  '6'  '7' */
    {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
       /*'8'  '9'  'A'  'B'  'C'  'D'  'E'  'F' null*/
        0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71,0x00};
#endif /* `$INSTANCE_NAME`_7SEG */

#ifdef ALPHANUMERIC

#ifdef `$INSTANCE_NAME`_14SEG
const uint16 `$INSTANCE_NAME`_14SegChars[] = {
/*----------------------------------------------------*/
/*                     Blank                          */
/*----------------------------------------------------*/
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
/*----------------------------------------------------*/
/*        !      "      #      $      %      &      ' */
/*----------------------------------------------------*/
0x0000,0x0006,0x0120,0x3fff,0x156d,0x2ee4,0x2a8d,0x0200,
/*----------------------------------------------------*/
/* (      )      *      +      ,      -      .      / */
/*----------------------------------------------------*/
0x0a00,0x2080,0x3fc0,0x1540,0x2000,0x0440,0x1058,0x2200,
/*----------------------------------------------------*/
/* 0      1      2      3      4      5      6      7 */
/*----------------------------------------------------*/
0x223f,0x0206,0x045b,0x040f,0x0466,0x0869,0x047d,0x1201,
/*----------------------------------------------------*/
/* 8      9      :      ;      <      =      >      ? */
/*----------------------------------------------------*/
0x047f,0x046f,0x2200,0x1100,0x2100,0x0a00,0x0448,0x2080,
/*----------------------------------------------------*/
/* @      A      B      C      D      E      F      G */
/*----------------------------------------------------*/
0x053b,0x0477,0x150f,0x0039,0x110F,0x0079,0x0071,0x043d,
/*----------------------------------------------------*/
/* H      I      J      K      L      M      N      O */
/*----------------------------------------------------*/
0x0476,0x1100,0x001e,0x0a70,0x0038,0x02b6,0x08b6,0x003f,
/*----------------------------------------------------*/
/* P      Q      R      S      T      U      V      W */
/*----------------------------------------------------*/
0x0473,0x083f,0x0C73,0x046d,0x1101,0x003e,0x2230,0x2836,
/*----------------------------------------------------*/
/* X      Y      Z      [      \      ]      ^      _ */
/*----------------------------------------------------*/
0x2a80,0x1280,0x2209,0x0039,0x0880,0x000f,0x2203,0x2008,
/*----------------------------------------------------*/
/* @      a      b      c      d      e      f      g */
/*----------------------------------------------------*/
0x0080,0x0477,0x150f,0x0039,0x110F,0x0079,0x0071,0x043d,
/*----------------------------------------------------*/
/* h      i      j      k      l      m      n      o */
/*----------------------------------------------------*/
0x0476,0x1100,0x001e,0x0a70,0x0038,0x02b6,0x08b6,0x003f,
/*----------------------------------------------------*/
/* p      q      r      s      t      u      v      w */
/*----------------------------------------------------*/
0x0473,0x083f,0x0C73,0x046d,0x1101,0x003e,0x2230,0x2836,
/*----------------------------------------------------*/
/* x      y      z      {      |      }      ~        */
/*----------------------------------------------------*/
0x2a80,0x1280,0x2209,0x0e00,0x1100,0x20C0,0x0452,0x003f};
#endif /* `$INSTANCE_NAME`_14SEG */

#ifdef `$INSTANCE_NAME`_16SEG
const uint16 `$INSTANCE_NAME`_16SegChars[] = {
/*----------------------------------------------------*/
/*                     Blank                          */
/*----------------------------------------------------*/
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
/*----------------------------------------------------*/
/*        !      "      #      $      %      &      ' */
/*----------------------------------------------------*/
0x0000,0x000c,0x0480,0xffff,0x55bb,0xdd99,0xaa3b,0x0800,
/*----------------------------------------------------*/
/* (      )      *      +      ,      -      .      / */
/*----------------------------------------------------*/
0x2800,0x8200,0xff00,0x5500,0x8000,0x1100,0x4160,0x8800,
/*----------------------------------------------------*/
/* 0      1      2      3      4      5      6      7 */
/*----------------------------------------------------*/
0x88ff,0x080c,0x1177,0x103f,0x118c,0x21b3,0x11fb,0x4803,
/*----------------------------------------------------*/
/* 8      9      :      ;      <      =      >      ? */
/*----------------------------------------------------*/
0x11ff,0x11bf,0x4400,0x8400,0x2800,0x1130,0x8200,0x5006,
/*----------------------------------------------------*/
/* @      A      B      C      D      E      F      G */
/*----------------------------------------------------*/
0x14f7,0x11cf,0x543f,0x00f3,0x443f,0x01f3,0x01c3,0x10fb,
/*----------------------------------------------------*/
/* H      I      J      K      L      M      N      O */
/*----------------------------------------------------*/
0x11cc,0x4400,0x007e,0x29c0,0x00f0,0x0acc,0x22cc,0x00ff,
/*----------------------------------------------------*/
/* P      Q      R      S      T      U      V      W */
/*----------------------------------------------------*/
0x11c7,0x20ff,0x31c7,0x11bb,0x4403,0x00fc,0x88c0,0xa0cc,
/*----------------------------------------------------*/
/* X      Y      Z      [      \      ]      ^      _ */
/*----------------------------------------------------*/
0xaa00,0x4A00,0x8833,0x4412,0x2200,0x4421,0x8806,0x0030,
/*----------------------------------------------------*/
/* @      a      b      c      d      e      f      g */
/*----------------------------------------------------*/
0x0200,0x11cf,0x543f,0x00f3,0x443f,0x01f3,0x01c3,0x10fb,
/*----------------------------------------------------*/
/* h      i      j      k      l      m      n      o */
/*----------------------------------------------------*/
0x11cc,0x4400,0x007e,0x29c0,0x00f0,0x0acc,0x22cc,0x00ff,
/*----------------------------------------------------*/
/* p      q      r      s      t      u      v      w */
/*----------------------------------------------------*/
0x11c7,0x20ff,0x31c7,0x11bb,0x4403,0x00fc,0x88c0,0xa0cc,
/*----------------------------------------------------*/
/* x      y      z      {      |      }      ~        */
/*----------------------------------------------------*/
0xaa00,0x4A00,0x8833,0x3800,0x4400,0x8300,0x1144,0x0000};
#endif /* `$INSTANCE_NAME`_16SEG */

#ifdef `$INSTANCE_NAME`_DOT_MATRIX
const uint8 `$INSTANCE_NAME`_charDotMatrix[][5] = {
{0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0x00, 0x00, 0x00}, {0x3e, 0x1c, 0x1c, 0x08, 0x08}, {0x08, 0x08, 0x1c, 0x1c, 0x3e},
{0x02, 0x06, 0x08, 0x10, 0x20}, {0x00, 0x4f, 0x00, 0x4f, 0x00}, {0x06, 0x0f, 0x7f, 0x01, 0x7f},
{0x48, 0x56, 0x55, 0x35, 0x09}, {0x0c, 0x0c, 0x0c, 0x0c, 0x0c}, {0x10, 0x38, 0x54, 0x10, 0x1f},
{0x04, 0x02, 0x7f, 0x02, 0x04}, {0x10, 0x20, 0x7f, 0x20, 0x10}, {0x7f, 0x3e, 0x1c, 0x08, 0x7f},
{0x7f, 0x08, 0x1c, 0x3e, 0x7f}, {0x7f, 0x08, 0x2a, 0x1c, 0x08}, {0x08, 0x1c, 0x2a, 0x08, 0x7f},
{0x02, 0x0e, 0x3e, 0x0e, 0x02}, {0x20, 0x38, 0x3e, 0x38, 0x20}, {0x00, 0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0x4f, 0x00, 0x00}, {0x00, 0x07, 0x00, 0x07, 0x00}, {0x14, 0x7f, 0x14, 0x7f, 0x14},
{0x24, 0x2a, 0x7f, 0x2a, 0x12}, {0x23, 0x13, 0x08, 0x64, 0x62}, {0x36, 0x49, 0x55, 0x22, 0x50},
{0x00, 0x05, 0x03, 0x00, 0x00}, {0x00, 0x1c, 0x22, 0x41, 0x00}, {0x00, 0x41, 0x22, 0x1c, 0x00},
{0x14, 0x08, 0x3e, 0x08, 0x14}, {0x08, 0x08, 0x3e, 0x08, 0x08}, {0x00, 0x50, 0x30, 0x00, 0x00},
{0x08, 0x08, 0x08, 0x08, 0x08}, {0x00, 0x60, 0x60, 0x00, 0x00}, {0x20, 0x10, 0x08, 0x04, 0x02},
{0x3e, 0x51, 0x49, 0x45, 0x3e}, {0x00, 0x42, 0x7f, 0x40, 0x00}, {0x42, 0x61, 0x51, 0x49, 0x46},
{0x21, 0x41, 0x45, 0x4B, 0x31}, {0x18, 0x14, 0x12, 0x7f, 0x10}, {0x27, 0x45, 0x45, 0x45, 0x39},
{0x3c, 0x4a, 0x49, 0x49, 0x30}, {0x01, 0x71, 0x09, 0x05, 0x03}, {0x36, 0x49, 0x49, 0x49, 0x36},
{0x06, 0x49, 0x49, 0x29, 0x1e}, {0x00, 0x36, 0x36, 0x00, 0x00}, {0x00, 0x56, 0x36, 0x00, 0x00},
{0x08, 0x14, 0x22, 0x41, 0x00}, {0x14, 0x14, 0x14, 0x14, 0x14}, {0x00, 0x41, 0x22, 0x14, 0x08},
{0x02, 0x01, 0x51, 0x09, 0x06}, {0x32, 0x49, 0x79, 0x41, 0x3e}, {0x7e, 0x11, 0x11, 0x11, 0x7e},
{0x7f, 0x49, 0x49, 0x49, 0x36}, {0x3e, 0x41, 0x41, 0x41, 0x22}, {0x7f, 0x41, 0x41, 0x22, 0x1c},
{0x7f, 0x49, 0x49, 0x49, 0x41}, {0x7f, 0x09, 0x09, 0x09, 0x01}, {0x3e, 0x41, 0x49, 0x49, 0x3a},
{0x7f, 0x08, 0x08, 0x08, 0x7f}, {0x00, 0x41, 0x7f, 0x41, 0x00}, {0x20, 0x40, 0x41, 0x3f, 0x01},
{0x7f, 0x08, 0x14, 0x22, 0x41}, {0x7f, 0x40, 0x40, 0x40, 0x40}, {0x7f, 0x02, 0x0c, 0x02, 0x7f},
{0x7f, 0x04, 0x08, 0x10, 0x7f}, {0x3e, 0x41, 0x41, 0x41, 0x3e}, {0x7f, 0x09, 0x09, 0x09, 0x06},
{0x3e, 0x41, 0x51, 0x21, 0x5e}, {0x7f, 0x09, 0x19, 0x29, 0x46}, {0x46, 0x49, 0x49, 0x49, 0x31},
{0x01, 0x01, 0x7f, 0x01, 0x01}, {0x3f, 0x40, 0x40, 0x40, 0x3f}, {0x1f, 0x20, 0x40, 0x20, 0x1f},
{0x3f, 0x40, 0x38, 0x40, 0x3f}, {0x63, 0x14, 0x08, 0x14, 0x63}, {0x07, 0x08, 0x70, 0x08, 0x07},
{0x61, 0x51, 0x49, 0x45, 0x43}, {0x00, 0x7f, 0x41, 0x41, 0x00}, {0x15, 0x16, 0x7c, 0x16, 0x15},
{0x00, 0x41, 0x41, 0x7f, 0x00}, {0x04, 0x02, 0x01, 0x02, 0x04}, {0x40, 0x40, 0x40, 0x40, 0x40},
{0x00, 0x01, 0x02, 0x04, 0x00}, {0x20, 0x54, 0x54, 0x54, 0x78}, {0x7f, 0x48, 0x44, 0x44, 0x38},
{0x38, 0x44, 0x44, 0x44, 0x40}, {0x38, 0x44, 0x44, 0x48, 0x7f}, {0x38, 0x54, 0x54, 0x54, 0x18},
{0x08, 0x7e, 0x09, 0x01, 0x02}, {0x0c, 0x52, 0x52, 0x52, 0x3e}, {0x7f, 0x08, 0x04, 0x04, 0x78},
{0x00, 0x44, 0x7d, 0x40, 0x00}, {0x20, 0x40, 0x40, 0x3d, 0x00}, {0x7f, 0x10, 0x28, 0x44, 0x00},
{0x00, 0x41, 0x7f, 0x40, 0x00}, {0x7c, 0x04, 0x18, 0x04, 0x78}, {0x7c, 0x08, 0x04, 0x04, 0x78},
{0x38, 0x44, 0x44, 0x44, 0x38}, {0x7c, 0x14, 0x14, 0x14, 0x08}, {0x08, 0x14, 0x14, 0x18, 0x7c},
{0x7c, 0x08, 0x04, 0x04, 0x08}, {0x48, 0x54, 0x54, 0x54, 0x20}, {0x04, 0x3f, 0x44, 0x40, 0x20},
{0x3c, 0x40, 0x40, 0x20, 0x7c}, {0x1c, 0x20, 0x40, 0x20, 0x1c}, {0x3c, 0x40, 0x30, 0x40, 0x3c},
{0x44, 0x28, 0x10, 0x28, 0x44}, {0x0C, 0x50, 0x50, 0x50, 0x3C}, {0x44, 0x64, 0x54, 0x4c, 0x44},
{0x00, 0x08, 0x36, 0x41, 0x00}, {0x00, 0x00, 0x7f, 0x00, 0x00}, {0x00, 0x41, 0x36, 0x08, 0x00},
{0x00, 0x00, 0x00, 0x00, 0x00}, {0x08, 0x08, 0x2a, 0x1c, 0x08}, {0x44, 0x44, 0x5f, 0x44, 0x44},
{0x22, 0x14, 0x08, 0x14, 0x22}, {0x1c, 0x3e, 0x3e, 0x3e, 0x1c}, {0x7f, 0x41, 0x41, 0x41, 0x7f},
{0x7f, 0x5b, 0x41, 0x5f, 0x7f}, {0x7f, 0x4d, 0x55, 0x59, 0x7f}, {0x1d, 0x15, 0x17, 0x00, 0x00},
{0x15, 0x15, 0x1f, 0x00, 0x00}, {0x17, 0x08, 0x74, 0x56, 0x5d}, {0x17, 0x08, 0x24, 0x32, 0x79},
{0x35, 0x1f, 0x28, 0x34, 0x7a}, {0x08, 0x14, 0x2a, 0x14, 0x22}, {0x22, 0x14, 0x2a, 0x14, 0x08},
{0x08, 0x04, 0x08, 0x10, 0x08}, {0x14, 0x0a, 0x14, 0x28, 0x14}, {0x2a, 0x55, 0x2a, 0x55, 0x2a},
{0x24, 0x3b, 0x2a, 0x7e, 0x2a}, {0x40, 0x3f, 0x15, 0x15, 0x7f}, {0x46, 0x20, 0x1f, 0x20, 0x46},
{0x24, 0x14, 0x7f, 0x18, 0x24}, {0x24, 0x14, 0x7f, 0x14, 0x24}, {0x44, 0x6a, 0x79, 0x6a, 0x44},
{0x40, 0x44, 0x7f, 0x44, 0x40}, {0x7f, 0x49, 0x49, 0x49, 0x7f}, {0x02, 0x4c, 0x30, 0x0c, 0x02},
{0x04, 0x04, 0x3c, 0x04, 0x44}, {0x49, 0x55, 0x7f, 0x55, 0x49}, {0x3a, 0x45, 0x45, 0x45, 0x39},
{0x40, 0x3e, 0x10, 0x10, 0x1e}, {0x08, 0x54, 0x3e, 0x15, 0x08}, {0x7f, 0x7f, 0x7f, 0x7f, 0x7f},
{0x55, 0x2a, 0x55, 0x2a, 0x55}, {0x00, 0x00, 0x00, 0x00, 0x00}, {0x70, 0x50, 0x70, 0x00, 0x00},
{0x00, 0x00, 0x0f, 0x01, 0x01}, {0x40, 0x40, 0x70, 0x00, 0x00}, {0x10, 0x20, 0x40, 0x00, 0x00},
{0x00, 0x18, 0x18, 0x00, 0x00}, {0x0a, 0x0a, 0x4a, 0x2a, 0x1e}, {0x04, 0x44, 0x34, 0x14, 0x0c},
{0x20, 0x10, 0x78, 0x04, 0x00}, {0x18, 0x08, 0x4c, 0x48, 0x38}, {0x48, 0x48, 0x78, 0x48, 0x48},
{0x48, 0x28, 0x18, 0x78, 0x08}, {0x08, 0x7c, 0x08, 0x28, 0x18}, {0x40, 0x48, 0x48, 0x78, 0x40},
{0x54, 0x54, 0x54, 0x7c, 0x00}, {0x18, 0x00, 0x58, 0x40, 0x38}, {0x08, 0x08, 0x08, 0x08, 0x08},
{0x01, 0x41, 0x3d, 0x09, 0x07}, {0x10, 0x08, 0x78, 0x02, 0x01}, {0x06, 0x02, 0x43, 0x22, 0x1e},
{0x42, 0x42, 0x7e, 0x42, 0x42}, {0x22, 0x12, 0x0a, 0x7f, 0x02}, {0x42, 0x3f, 0x02, 0x42, 0x3e},
{0x0a, 0x0a, 0x7f, 0x0a, 0x0a}, {0x08, 0x46, 0x42, 0x22, 0x1e}, {0x04, 0x03, 0x42, 0x3e, 0x02},
{0x42, 0x42, 0x42, 0x42, 0x7e}, {0x02, 0x4f, 0x22, 0x1f, 0x02}, {0x4a, 0x4a, 0x40, 0x20, 0x1c},
{0x42, 0x22, 0x12, 0x2a, 0x46}, {0x02, 0x3f, 0x42, 0x4a, 0x46}, {0x06, 0x48, 0x40, 0x20, 0x1e},
{0x08, 0x46, 0x4a, 0x32, 0x1e}, {0x0a, 0x4a, 0x3e, 0x09, 0x08}, {0x0e, 0x00, 0x4e, 0x20, 0x1e},
{0x04, 0x45, 0x3d, 0x05, 0x04}, {0x00, 0x7f, 0x08, 0x10, 0x00}, {0x44, 0x24, 0x1f, 0x04, 0x04},
{0x40, 0x42, 0x42, 0x42, 0x40}, {0x42, 0x2a, 0x12, 0x2a, 0x06}, {0x22, 0x12, 0x7a, 0x16, 0x22},
{0x00, 0x40, 0x20, 0x1f, 0x00}, {0x78, 0x00, 0x02, 0x04, 0x78}, {0x3f, 0x44, 0x44, 0x44, 0x44},
{0x02, 0x42, 0x42, 0x22, 0x1e}, {0x04, 0x02, 0x04, 0x08, 0x30}, {0x32, 0x02, 0x7f, 0x02, 0x32},
{0x02, 0x12, 0x22, 0x52, 0x0e}, {0x00, 0x2a, 0x2a, 0x2a, 0x40}, {0x38, 0x24, 0x22, 0x20, 0x1e},
{0x40, 0x28, 0x10, 0x28, 0x06}, {0x0a, 0x3e, 0x4a, 0x4a, 0x4a}, {0x04, 0x7f, 0x04, 0x14, 0x0c},
{0x40, 0x42, 0x42, 0x7e, 0x40}, {0x4a, 0x4a, 0x4a, 0x4a, 0x7e}, {0x04, 0x05, 0x45, 0x15, 0x1c},
{0x0f, 0x40, 0x20, 0x1f, 0x00}, {0x7c, 0x00, 0x7e, 0x40, 0x30}, {0x7e, 0x40, 0x20, 0x10, 0x08},
{0x7e, 0x7e, 0x7e, 0x7e, 0x7e}, {0x0e, 0x02, 0x42, 0x22, 0x1e}, {0x42, 0x42, 0x40, 0x20, 0x18},
{0x02, 0x04, 0x01, 0x02, 0x00}, {0x07, 0x05, 0x07, 0x00, 0x00}, {0x38, 0x44, 0x48, 0x30, 0x4c},
{0x20, 0x55, 0x55, 0x55, 0x38}, {0xfe, 0x15, 0x15, 0x15, 0x0a}, {0x28, 0x54, 0x54, 0x44, 0x20},
{0xff, 0x10, 0x10, 0x08, 0x1f}, {0x38, 0x44, 0x4c, 0x54, 0x24}, {0xfc, 0x12, 0x11, 0x11, 0x0e},
{0x0e, 0xa1, 0xa1, 0xa1, 0x7f}, {0x20, 0x40, 0x3c, 0x04, 0x04}, {0x04, 0x04, 0x00, 0x0e, 0x00},
{0x40, 0x80, 0x81, 0x7f, 0x00}, {0x0a, 0x04, 0x0a, 0x00, 0x00}, {0x18, 0x24, 0x7e, 0x24, 0x10},
{0x14, 0x7f, 0x54, 0x40, 0x40}, {0x7c, 0x0a, 0x05, 0x05, 0x78}, {0x38, 0x45, 0x45, 0x45, 0x38},
{0xff, 0x12, 0x11, 0x11, 0x0e}, {0x0e, 0x11, 0x11, 0x12, 0xff}, {0x3c, 0x4a, 0x4a, 0x4a, 0x3c},
{0x30, 0x28, 0x10, 0x28, 0x18}, {0x58, 0x64, 0x04, 0x64, 0x58}, {0x3c, 0x41, 0x40, 0x21, 0x7c},
{0x63, 0x55, 0x4a, 0x41, 0x41}, {0x44, 0x3c, 0x04, 0x7c, 0x44}, {0x45, 0x29, 0x11, 0x29, 0x45},
{0x0f, 0x90, 0x90, 0x90, 0x7f}, {0x14, 0x14, 0x7c, 0x14, 0x12}, {0x44, 0x3c, 0x14, 0x14, 0x74},
{0x7c, 0x14, 0x1c, 0x14, 0x7c}, {0x10, 0x10, 0x54, 0x10, 0x10}, {0x00, 0x00, 0x00, 0x00, 0x00},
{0xff, 0xff, 0xff, 0xff, 0xff}
};
#endif /* `$INSTANCE_NAME`_DOT_MATRIX */
#endif /* ALPHANUMERIC */

static uint8 `$INSTANCE_NAME`_initVar = 0;

/* Frame Buffer */
static uint8 `$INSTANCE_NAME`_buffer[`$INSTANCE_NAME`_BUFFER_LENGTH] ;

/* Array of TDs */
static uint8 `$INSTANCE_NAME`_td[`$INSTANCE_NAME`_COMM_NUM];

/* DMA channel dedicated for SegLCD  */
static uint8 `$INSTANCE_NAME`_channel;

uint8 `$INSTANCE_NAME`_TermOut = (`$INSTANCE_NAME`_LCD_Dma__TERMOUT0_EN ? TD_TERMOUT0_EN : 0) |
                                     (`$INSTANCE_NAME`_LCD_Dma__TERMOUT1_EN ? TD_TERMOUT1_EN : 0);


/******************************************/
/*** Start of customizer generated code ***/
/******************************************/

`$writerCVariables`

/******************************************/
/***  End of customizer generated code  ***/
/******************************************/


/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_Start
********************************************************************************
*
* Summary:
*  Starts the LCD component and enables any required
*  interrupts, DMA channels frame buffer and hardware. Does not
*  clear the frame buffer SRAM if previously defined.
*
* Parameters:
*  void:
*
* Return:
*  Status one of standard status for PSoC3 Component
*  CYRET_SUCCESS - Function completed successfully.
*  CYRET_LOCKED - The object was locked, already in use. Some of TDs or
*                 a channel already i use.
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
uint8 `$INSTANCE_NAME`_Start(void)
{
    uint8   status;
    uint8   errorCnt = 0;
    uint8   i = 0;
    uint32  fSrcAddr;
    uint32  addr;
    uint8   `$INSTANCE_NAME`_nextTd;

    fSrcAddr = `$INSTANCE_NAME`_DMA_ADDRESS_MASK & ((uint32) `$INSTANCE_NAME`_buffer);
    
    addr = (addr | 0xFFFFFFFF) & `$INSTANCE_NAME`_ALIASED_AREA_PTR;

    /* If not Initialized then initialize all required hardware and software */
    if(`$INSTANCE_NAME`_initVar == 0)
    {
        `$INSTANCE_NAME`_initVar = 1;

        /******************** Enable LCD *************************************/

        `$INSTANCE_NAME`_PWR_MGR |= `$INSTANCE_NAME`_LCD_EN;

        /******************** LCD Frame Buffer initialization ****************/

        /* Need to clear display to start normal work */
        `$INSTANCE_NAME`_ClearDisplay();

        /***************** LCD supporting hardware initialization ************/

        /* Select LCD DAC generated voltage as the source for LCD Driver *****/
        CY_SET_REG8(`$INSTANCE_NAME`_LCDDAC_SWITCH_REG0, `$INSTANCE_NAME`_LCDDAC_VOLTAGE_SEL);
        CY_SET_REG8(`$INSTANCE_NAME`_LCDDAC_SWITCH_REG1, `$INSTANCE_NAME`_LCDDAC_VOLTAGE_SEL);
        CY_SET_REG8(`$INSTANCE_NAME`_LCDDAC_SWITCH_REG2, `$INSTANCE_NAME`_LCDDAC_VOLTAGE_SEL);
        CY_SET_REG8(`$INSTANCE_NAME`_LCDDAC_SWITCH_REG3, `$INSTANCE_NAME`_LCDDAC_VOLTAGE_SEL);
        CY_SET_REG8(`$INSTANCE_NAME`_LCDDAC_SWITCH_REG4, `$INSTANCE_NAME`_LCDDAC_VOLTAGE_SEL);

        /* Turns on LCD DAC and set the bias type*/
        CY_SET_REG8(`$INSTANCE_NAME`_LCDDAC_CONTROL,
                (CY_GET_REG8(`$INSTANCE_NAME`_LCDDAC_CONTROL) & `$INSTANCE_NAME`_BIAS_TYPE_MASK)
                | `$INSTANCE_NAME`_BIAS_TYPE);

        /* Set the contrast level for LCD with value chosen in the GUI */
        `$INSTANCE_NAME`_SetBias(`$INSTANCE_NAME`_BIAS_VOLTAGE);

        /* Set LCD to active mode */
        `$INSTANCE_NAME`_SetAwakeMode();

        /* Set LO2 High current mode */
        #if(`$INSTANCE_NAME`_LOW_DRIVE_MODE == `$INSTANCE_NAME`_HI_RANGE)
            CY_SET_REG8(`$INSTANCE_NAME`_DRIVER_CONTROL, 0x02);
        #endif /*$INSTANCE_NAME`_LOW_DRIVE_MODE*/
    }

/******************************** LCD DMA initialization *********************/

    `$INSTANCE_NAME`_channel = `$INSTANCE_NAME``[LCD_Dma]`DmaInitialize(0, 0, HI16(fSrcAddr), HI16(addr));

    if(`$INSTANCE_NAME`_channel == DMA_INVALID_CHANNEL)
    {
        errorCnt++;
    }

    if( i > `$INSTANCE_NAME`_COMM_NUM)
        errorCnt++;
    else
    {

         /* Get first Transaction Descriptor. */
        `$INSTANCE_NAME`_td[0] = CyDmaTdAllocate();
        if(`$INSTANCE_NAME`_td[0] == DMA_INVALID_TD)
        {
            errorCnt++;
        }

        for(i = 1; i <= `$INSTANCE_NAME`_COMM_NUM; i++)
        {
            if(i < `$INSTANCE_NAME`_COMM_NUM)
            {
                `$INSTANCE_NAME`_td[i] = CyDmaTdAllocate();

                if(`$INSTANCE_NAME`_td[i] == DMA_INVALID_TD)
                {
                    errorCnt++;
                }
                   /* Setup a TD. */
               `$INSTANCE_NAME`_nextTd = `$INSTANCE_NAME`_td[i];
            }
            else
            `$INSTANCE_NAME`_nextTd = `$INSTANCE_NAME`_td[0];

            /* Configure TD as chained,  */
            CyDmaTdSetConfiguration(`$INSTANCE_NAME`_td[i-1],
                                    `$INSTANCE_NAME`_TD_SIZE,
                                    `$INSTANCE_NAME`_nextTd,
                                    /* no specific configuration */
                                    TD_INC_DST_ADR | TD_INC_SRC_ADR | `$INSTANCE_NAME`_TermOut);

            CyDmaTdSetAddress(`$INSTANCE_NAME`_td[i-1], LO16(fSrcAddr) + (i-1)*`$INSTANCE_NAME`_TD_SIZE, LO16(addr));

        }
        CyDmaChSetInitialTd(`$INSTANCE_NAME`_channel, `$INSTANCE_NAME`_td[0]);
    }

    CyDmaChEnable(`$INSTANCE_NAME`_channel, 1);

/********************** ISR initialization  ********************************/

        CyIntDisable(`$INSTANCE_NAME`_ISR_NUMBER);

        /* Set the ISR to point to the RTC_SUT_isr Interrupt. */
        CyIntSetVector(`$INSTANCE_NAME`_ISR_NUMBER, `$INSTANCE_NAME`_ISR);

        /* Set the priority. */
        CyIntSetPriority(`$INSTANCE_NAME`_ISR_NUMBER, `$INSTANCE_NAME`_ISR_PRIORITY);

    /* Starts Segment LCD */

    if(errorCnt == 0)
    {
        /* Enable required clocks */
        `$INSTANCE_NAME`_CNT_DELAY |= 0x07;
        `$INSTANCE_NAME`_EN_HI_DELAY = `$INSTANCE_NAME`_EN_HI_ACT_VAL;
        `$INSTANCE_NAME``[Int_Clock]`Enable();
        `$INSTANCE_NAME``[Chop_Clock]`Enable();
        `$INSTANCE_NAME`_CONTROL |= `$INSTANCE_NAME`_CLK_ENABLE;
        CyIntEnable(`$INSTANCE_NAME`_ISR_NUMBER);
        `$INSTANCE_NAME`_FRAME_CNT7_PERIOD |= `$INSTANCE_NAME`_CNTR7_ENABLE;

        #if(`$INSTANCE_NAME`_DRIVER_POWER_MODE == `$INSTANCE_NAME`_LOW_POWER)
            `$INSTANCE_NAME`_LOW_DRIVE_DELAY = `$INSTANCE_NAME`_LOW_POWER_DELAY_VAL;
        #endif /* `$INSTANCE_NAME`_DRIVER_POWER_MODE */

        `$INSTANCE_NAME`_CONTROL |= `$INSTANCE_NAME`_RESET;
        `$INSTANCE_NAME`_CNT_PERIOD = `$INSTANCE_NAME`_CNT_PERIOD_VAL;
        `$INSTANCE_NAME`_CONTROL |= `$INSTANCE_NAME`_POST_RESET;
        `$INSTANCE_NAME`_CONTROL &= ~`$INSTANCE_NAME`_RESET;
        `$INSTANCE_NAME`_CONTROL &= ~`$INSTANCE_NAME`_POST_RESET;
        status = CYRET_SUCCESS;
    }
    else
        status = CYRET_LOCKED;

    return(status);
}


/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_Stop
********************************************************************************
*
* Summary:
*   Disables the LCD component and disables any
*   required interrupts and DMA channels. Automatically blanks the
*   display to avoid damage from DC offsets. Does not clear the frame
*   buffer
*
* Parameters:
*  void
*
* Return:
*  void
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void `$INSTANCE_NAME`_Stop(void)
{
    uint8 i;

    /* Release all allocated TDs */
    for(i = 0; i < `$INSTANCE_NAME`_COMM_NUM; i++)
        CyDmaTdFree(`$INSTANCE_NAME`_td[i]);

    /* Release DMA handle */
    `$INSTANCE_NAME``[LCD_Dma]`DmaRelease();

    CyIntDisable(`$INSTANCE_NAME`_ISR_NUMBER);

    `$INSTANCE_NAME`_CONTROL &= ~`$INSTANCE_NAME`_CLK_ENABLE;
    `$INSTANCE_NAME``[Int_Clock]`Disable();
    `$INSTANCE_NAME``[Chop_Clock]`Disable();
}


/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_EnableInt
********************************************************************************
*
* Summary:
*  Description: Enables the LCD interrupt/s. Not required if `$INSTANCE_NAME`
*  _Start called
*
* Parameters:
*  void
*
* Return:
*  void
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void `$INSTANCE_NAME`_EnableInt(void)
{
    CyIntEnable(`$INSTANCE_NAME`_ISR_NUMBER);
}


/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_DisableInt
********************************************************************************
*
* Summary:
*  Description: Disables the LCD interrupt. Not required if `$INSTANCE_NAME`
*  _Stop called
*
* Parameters:
*  void
*
* Return:
*  void
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void `$INSTANCE_NAME`_DisableInt(void)
{
    CyIntDisable(`$INSTANCE_NAME`_ISR_NUMBER);
}


/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_SetBias
********************************************************************************
*
* Summary:
*  This function sets the bias level for the LCD glass to
*  one of up to 128 values. The actual number of values is limited by
*  the Analog supply voltage Vdda as the bias voltage can not exceed
*  Vdda. Changing the bias level affects the LCD contrast.
*
* Parameters:
*  biasLevel : bias level for the diplay
*
* Return:
*  Status: Defines the standard return values used PSoC content
*  CYRET_BAD_PARAM - Function completed successfully
*  CYRET_SUCCESS   - One or more parameters to the function were invalid.
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
uint8 `$INSTANCE_NAME`_SetBias(uint8 biasLevel)
{
    uint8 status;
    if(biasLevel < 128)
    {
        CY_SET_REG8(`$INSTANCE_NAME`_CONTRAST_CONTROL, biasLevel);
        status = CYRET_SUCCESS;
    }
    else
    {
        status = CYRET_BAD_PARAM;
    }
    return(status);
}


/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_WriteInvertState
********************************************************************************
*
* Summary:
*  This function inverts the display based on invertState.
*  The inversion occurs in hardware and no change is required to the
*  display RAM in the page buffer
*
* Parameters:
*  invertState = 0 (#LCD_NORMAL_STATE) for normal
*  non-inverted display and 1 (#LCD_INVERTED_STATE) for inverted
*  display.
*
* Return:
*  Status: Defines the standard return values used PSoC content
*  CYRET_BAD_PARAM - Function completed successfully
*  CYRET_SUCCESS   - One or more parameters to the function were invalid.
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
uint8 `$INSTANCE_NAME`_WriteInvertState(uint8 invertState)
{
    uint8 status;
    uint16 byteAddr, bitAddr, row, pixelNumber;
    uint8 mask,j,i;

    /* Return error when invertState is greater then 1 */
    if(invertState <= 1)
    {
       /* If parameter is valid then procced with driver control register write
           operation, we don't want to affect other bits then invert bit*/

        if(invertState == 0)
        {
            #ifdef `$INSTANCE_NAME`_GANG

            for(i=0; i<`$INSTANCE_NAME`_COMM_NUM; i++)
            {
                pixelNumber = `$INSTANCE_NAME`_gCommons[i];
                for(j=0; j<`$INSTANCE_NAME`_COMM_NUM; j++)
                {
                    bitAddr = (pixelNumber & `$INSTANCE_NAME`_BIT_MASK);
                    /* Extract byte position in the row*/
                    byteAddr = (pixelNumber & `$INSTANCE_NAME`_BYTE_MASK) >> 4;
                    /* Extract row position*/
                    row = j;

                    mask = ~(`$INSTANCE_NAME`_PIXEL_STATE_ON << bitAddr);
                    `$INSTANCE_NAME`_buffer[row * 16 + byteAddr] =
                    (`$INSTANCE_NAME`_buffer[row * 16 + byteAddr] & mask) |
                        (`$INSTANCE_NAME`_PIXEL_STATE_OFF << bitAddr);
                }
            }

            for(i=0; i<`$INSTANCE_NAME`_COMM_NUM; i++)
                `$INSTANCE_NAME`_WRITE_PIXEL(`$INSTANCE_NAME`_gCommons[i], `$INSTANCE_NAME`_PIXEL_STATE_ON);

            #endif /* `$INSTANCE_NAME`_GANG */

            for(i=0; i<`$INSTANCE_NAME`_COMM_NUM; i++)
            {
                pixelNumber = `$INSTANCE_NAME`_commons[i];
                for(j=0; j<`$INSTANCE_NAME`_COMM_NUM; j++)
                {
                    bitAddr = (pixelNumber & `$INSTANCE_NAME`_BIT_MASK);
                    /* Extract byte position in the row*/
                    byteAddr = (pixelNumber & `$INSTANCE_NAME`_BYTE_MASK) >> 4;
                    /* Extract row position*/
                    row = j;

                    mask = ~(`$INSTANCE_NAME`_PIXEL_STATE_ON << bitAddr);
                    `$INSTANCE_NAME`_buffer[row * 16 + byteAddr] = (`$INSTANCE_NAME`_buffer[row * 16 + byteAddr] & mask)
                        | (`$INSTANCE_NAME`_PIXEL_STATE_OFF << bitAddr);
                }
            }

            /* Reinitialize the commons */
            for(i=0; i<`$INSTANCE_NAME`_COMM_NUM; i++)
                `$INSTANCE_NAME`_WRITE_PIXEL(`$INSTANCE_NAME`_commons[i], `$INSTANCE_NAME`_PIXEL_STATE_ON);
        }
        else /* Initialization of Inverted display */
        {
        #ifdef `$INSTANCE_NAME`_GANG

        for(i=0; i<`$INSTANCE_NAME`_COMM_NUM; i++)
        {
            pixelNumber = `$INSTANCE_NAME`_gCommons[i];
            for(j=0; j<`$INSTANCE_NAME`_COMM_NUM; j++)
            {
                bitAddr = (pixelNumber & `$INSTANCE_NAME`_BIT_MASK);
                /* Extract byte position in the row*/
                byteAddr = (pixelNumber & `$INSTANCE_NAME`_BYTE_MASK) >> 4;
                /* Extract row position*/
                row = j;

                mask = ~(`$INSTANCE_NAME`_PIXEL_STATE_ON << bitAddr);
                `$INSTANCE_NAME`_buffer[row * 16 + byteAddr] =
                (`$INSTANCE_NAME`_buffer[row * 16 + byteAddr] & mask) | (`$INSTANCE_NAME`_PIXEL_STATE_ON << bitAddr);
            }
        }

        for(i=0; i<`$INSTANCE_NAME`_COMM_NUM; i++)
            `$INSTANCE_NAME`_WRITE_PIXEL(`$INSTANCE_NAME`_gCommons[i], `$INSTANCE_NAME`_PIXEL_STATE_OFF);

        #endif /* `$INSTANCE_NAME`_GANG */

        for(i=0; i<`$INSTANCE_NAME`_COMM_NUM; i++)
        {
            pixelNumber = `$INSTANCE_NAME`_commons[i];
            for(j=0; j<`$INSTANCE_NAME`_COMM_NUM; j++)
            {
                bitAddr = (pixelNumber & `$INSTANCE_NAME`_BIT_MASK);
                /* Extract byte position in the row*/
                byteAddr = (pixelNumber & `$INSTANCE_NAME`_BYTE_MASK) >> 4;
                /* Extract row position*/
                row = j;

                mask = ~(`$INSTANCE_NAME`_PIXEL_STATE_ON << bitAddr);
                `$INSTANCE_NAME`_buffer[row * 16 + byteAddr] =
                (`$INSTANCE_NAME`_buffer[row * 16 + byteAddr] & mask) | (`$INSTANCE_NAME`_PIXEL_STATE_ON << bitAddr);
            }
        }

        /* Reinitialize the commons */
        for(i=0; i<`$INSTANCE_NAME`_COMM_NUM; i++)
            `$INSTANCE_NAME`_WRITE_PIXEL(`$INSTANCE_NAME`_commons[i], `$INSTANCE_NAME`_PIXEL_STATE_OFF);

        }

        CY_SET_REG8(`$INSTANCE_NAME`_DRIVER_CONTROL,
            ((CY_GET_REG8(`$INSTANCE_NAME`_DRIVER_CONTROL) & `$INSTANCE_NAME`_STATE_MASK))
                | (invertState << 2));
        status = CYRET_SUCCESS;
    }
    else
        status = CYRET_BAD_PARAM;

    return(status);
}


/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_ReadInvertState
********************************************************************************
*
* Summary:
*  This function returns the current normal or inverted
*  state of the display
*
* Parameters:
*  void
*
* Return:
*  invertState = 0 (#LCD_NORMAL_STATE) for
*  normal non-inverted display and 1 (#LCD_INVERTED_STATE) for
*  inverted display.
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
uint8 `$INSTANCE_NAME`_ReadInvertState(void)
{
    /* Get only invert bit of Driver Control Register */
    return(((CY_GET_REG8(`$INSTANCE_NAME`_DRIVER_CONTROL)) & `$INSTANCE_NAME`_INVERT_BIT_MASK) >> 2);
}


/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_ClearDisplay
********************************************************************************
*
* Summary:
*  This function clears the display RAM of the frame buffer.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void `$INSTANCE_NAME`_ClearDisplay(void)
{
    uint16 i;
    uint8 dispState;

    /* Clear entire frame buffer to all zeroes */
    for(i=0; i<`$INSTANCE_NAME`_BUFFER_LENGTH; i++) `$INSTANCE_NAME`_buffer[i] = 0;

    #ifdef `$INSTANCE_NAME`_GANG
        for(i=0; i<`$INSTANCE_NAME`_COMM_NUM; i++)
            `$INSTANCE_NAME`_WRITE_PIXEL(`$INSTANCE_NAME`_gCommons[i], `$INSTANCE_NAME`_PIXEL_STATE_ON);
    #endif /* `$INSTANCE_NAME`_GANG */

    /* Reinitialize the commons */
    for(i=0; i<`$INSTANCE_NAME`_COMM_NUM; i++)
        `$INSTANCE_NAME`_WRITE_PIXEL(`$INSTANCE_NAME`_commons[i], `$INSTANCE_NAME`_PIXEL_STATE_ON);

    dispState = (CY_GET_REG8(`$INSTANCE_NAME`_DRIVER_CONTROL) & ~(`$INSTANCE_NAME`_STATE_MASK)) >> 2;

    if(dispState == 1)
        `$INSTANCE_NAME`_WriteinvertState(dispState);
}


/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_WritePixel
********************************************************************************
*
* Summary:
*  This function sets or clears a pixel based on pixelState
*  in a large frame buffer. The Pixel is addressed by a packed
*  number. User code can also directly write the frame buffer RAM
*  to create optimized interactions.
*
* Parameters:
*  pixelNumber: is the packed number that points to the pixels
*  location in the frame buffer. The lowest three bits in the LSB
*  low nibble are the bit position in the byte, the LSB upper
*  nibble (4 bits) is the byte address in the multiplex row and
*  the MSB low nibble (4 bits) is the multiplex row number.
*  pixelState : 0 for pixel off,1 for pixel on, 2 for pixel invert
*
* Return:
*  Status returns the standardized return value for pass
*  or fail on a range check of the byte address and multiplex row
*  number. No check is performed on bit position.
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
uint8 `$INSTANCE_NAME`_WritePixel(uint16 pixelNumber, uint8 pixelState)
{
    uint16 byteAddr, bitAddr, row;
    uint8 mask;
    uint8 status;

    /* Let the User know he is entered wrong parameter */
    if(pixelState > 2) status = CYRET_BAD_PARAM;
    else
    {
        /* Extract bit position in the byte*/
        bitAddr = (pixelNumber & `$INSTANCE_NAME`_BIT_MASK);
        /* Extract byte position in the row*/
        byteAddr = (pixelNumber & `$INSTANCE_NAME`_BYTE_MASK) >> 4;
        /* Extract row position*/
        row = (pixelNumber & `$INSTANCE_NAME`_ROW_MASK) >> 8;

        if(pixelState == 2)
        {
            /* Invert actual pixel state */
            pixelState = !(`$INSTANCE_NAME`_ReadPixel(pixelNumber));
        }

        mask = ~(`$INSTANCE_NAME`_PIXEL_STATE_ON << bitAddr);
        `$INSTANCE_NAME`_buffer[row * 16 + byteAddr] =
            (`$INSTANCE_NAME`_buffer[row * 16 + byteAddr] & mask) | (pixelState << bitAddr);
        status = CYRET_SUCCESS;
    }
    return(status);
}


/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_ReadPixel
********************************************************************************
*
* Summary:
*  This function reads a pixels state in a frame
*  buffer. The Pixel is addressed by a packed number. User code can also
*  directly read the frame buffer RAM to create optimized interactions.
*
* Parameters:
*  pixelNumber: is the packed number that points to the
*  pixels location in the frame buffer. The lowest three bits in the LSB
*  low nibble are the bit position in the byte, the LSB upper nibble (4
*  bits) is the byte address in the multiplex row and the MSB low
*  nibble (4 bits) is the multiplex row number.
*
* Return:
*  Pixel State: 0 for pixel off,1 for pixel on
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
uint8 `$INSTANCE_NAME`_ReadPixel(uint16 pixelNumber)
{
    uint8 byteAddr,bitAddr,row;
    uint8 pixelState;

    pixelState = 0;

    /* Extract all required information, to addres pixel, from pixelNumber */
    bitAddr = (pixelNumber & `$INSTANCE_NAME`_BIT_MASK);
    byteAddr = (pixelNumber & `$INSTANCE_NAME`_BYTE_MASK) >> 4;
    row = (pixelNumber & `$INSTANCE_NAME`_ROW_MASK) >> 8;

    pixelState |= (( `$INSTANCE_NAME`_buffer[row * 16 + byteAddr] >> bitAddr) & 1);
    return (pixelState);
}


/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_SetAwakeMode
********************************************************************************
*
* Summary:
*  This function is the default mode of the LCD
*  component and is automatically set by the `$INSTANCE_NAME`_Start()
*  fuction. This function must be called immediately after the device
*  transitions from one of the low power modes to active operation.
*
* Parameters:
*  void:
*
* Return:
*  void
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void `$INSTANCE_NAME`_SetAwakeMode(void)
{
    CY_SET_REG8(`$INSTANCE_NAME`_DRIVER_CONTROL,
        CY_GET_REG8(`$INSTANCE_NAME`_DRIVER_CONTROL) & (~`$INSTANCE_NAME`_SLEEP_ENABLE));
}


/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_SetSleepMode
********************************************************************************
*
* Summary:
*  This function must be called just prior to the device
*  entering a low power mode if LCD operation must continue in the
*  low power mode. This function insures that the LCD subframe clock
*  will wake the device as required to update the LCD display.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void `$INSTANCE_NAME`_SetSleepMode(void)
{
    /* This must bring LCD System to sleep mode. */
    CY_SET_REG8(`$INSTANCE_NAME`_DRIVER_CONTROL, `$INSTANCE_NAME`_SLEEP_ENABLE);
}


`$writerCFunctions`


/* [] END OF FILE */
