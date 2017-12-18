/*
 *  Copyright 2003 by Texas Instruments Incorporated.
 *  All rights reserved. Property of Texas Instruments Incorporated.
 *  Restricted rights to use, duplicate or disclose this code are
 *  granted through contract.
 *  
 */
/* "@(#) DDK 1.10.00.23 07-02-03 (ddk-b12)" */
/* "@(#) Driver Patch number 1.00.01" */
/********************************************************************************/
/* _tvp51xx.h file */
/********************************************************************************/
#ifndef __TVP51XX_H
#define __TVP51XX_H

#ifdef __cplusplus
extern "C" {
#endif

#include <tvp51xx.h>

#define _TVP5150_IIC_ADDR       (0xB8>>1) 
#define _TVP5146_IIC_ADDR       (0xBA>>1)

Uint8	NTSC601_EXEC[8][2], NTSCSGP_EXEC[8][2], PAL601_EXEC[8][2], PALSGP_EXEC[8][2];


typedef struct _TVP51XX_Generics
{
/* Video Input Source Selection #1 (0x00) */
    Uns svideo_sel : 1;
    Uns channel1_sel : 1;
    Uns	source_sel_rsv1 : 1;
    Uns black_output : 1;
    Uns source_sel_rsv2: 4;
/* Analog Channel Controls (0x01)         */
    Uns automatic_gain_ctrl : 2;
    Uns automatic_offset_ctrl : 2;
    Uns analog_channel_ctrl_rsv : 4;
/* Operation Mode Controls (0x02)         */
    Uns power_down_mode : 1;
    Uns luma_peak_disable : 1;
    Uns color_subcarrier_pll_frozen : 1;
    Uns white_peak_disable : 1;
    Uns tv_vcr_mode : 2;
    Uns color_burst_ref_disable : 1;
    Uns operation_mode_ctrl_rsv : 1;
/* Miscellaneous Control (0x03)           */
    Uns clock_output_enable : 1;
    Uns vertical_blanking_onoff : 1;
    Uns hsync_vsync_output_enable : 1;
    Uns ycrcb_output_enable : 1;
    Uns lock_status : 1;
    Uns gpcl_io_mode_sel : 1;
    Uns gpcl : 1;
    Uns vbko : 1;
/* Autoswitch Mask (0x04)                 */
    Uns autoswitch_mask_rsv1 : 2;
    Uns palm_off : 1;
    Uns paln_off : 1;
    Uns n443_off : 1;
    Uns sec_off : 1;
    Uns autoswitch_mask_rsv2 : 2;
/* Software Reset (0x05)                  */
    Uns reset : 1;
    Uns software_reset_rsv : 7;
/* Color Killer Threshold Control (0x06)  */
    Uns color_killer_shreshold : 5;
    Uns automatic_color_killer : 2;
    Uns color_killer_shreshold_rsv: 1;
/* Luminance Processing Control #1 (0x07) */
    Uns luminance_signal_delay : 4;
    Uns luma_bypass : 1;
    Uns disable_raw_header : 1;
    Uns pedestal_not_present: 1;
    Uns luma_bypass_mode : 1;
/* Luminance Processing Control #2 (0x08) */
    Uns mac_agc_ctrl : 2;
    Uns peaking_gain : 2;
    Uns luminance_processing_ctrl_rsv1 : 2;
    Uns luminance_filter_sel : 1;
    Uns luminance_processing_ctrl_rsv2 : 1;
/* Brightness Control (0x09)              */
    Uint8 brightness_ctrl;
/* Saturation Control (0x0A)              */
    Uint8 saturation_ctrl;
/* Hue Control (0x0B)                     */
    Uint8 hue_ctrl;
/* Contrast Control (0x0C)                */
    Uint8 contrast_ctrl;
/* Outputs and Data Select (0x0D)         */
    Uns ycrcb_output_format : 3;
    Uns ycrcb_data_path_bypass : 2;
    Uns cbcr_code_format : 1;
    Uns ycbcr_output_code_range : 1;
    Uns outputs_data_sel_rsv : 1;
/* Luminance Processing Control #3 (0x0E) */
    Uns luminance_trap_filter_sel : 2;
    Uns luminance_processing_ctrl_rsv3 : 6;
/* Configuration Shared Pins (0x0F)       */
    Uns sclk_pclk : 1;
    Uns intreq_gpcl_vblk : 1;
    Uns vsync_pali : 1;
    Uns fid_glco : 1;
    Uns lock24b : 1;
    Uns lock24a : 1;
    Uns lock23 : 1;
    Uns config_shared_pins_rsv : 1;
/* Reserved (0x10)                        */
    Uint8 rsv1;
/* Active Video Cropping Start Pixel MSB (0x11) */
    Uint8 avid_start_pixel_msb;
/* Active Video Cropping Start Pixel LSB (0x12) */
    Uns avid_start_pixel_lsb : 2;
    Uns avid_active : 1;
    Uns active_video_cropping_start_pixel_lsb_rsv : 5;
/* Active Video Cropping Stop Pixel MSB (0x13) */
    Uint8 avid_stop_pixel_msb;
/* Active Video Cropping Stop Pixel LSB (0x14) */
    Uns avid_stop_pixel_lsb : 2;
    Uns active_video_cropping_stop_pixel_lsb_rsv : 6;
/* Genlock and RTC (0x15)                 */
    Uns glco_rtc : 1;
    Uns genlock_rtc_rsv1 : 1;
    Uns cdto_sw : 1;
    Uns genlock_rtc_rsv2 : 1;
    Uns fv_bit_ctrl : 2;
    Uns genlock_rtc_rsv3 : 2;
/* Horizontal Sync (HSYNC) Start (0x16)   */
    Uint8 hsync_start;
/* Reserved (0x17)                        */
    Uint8 rsv2;
/* Vertical Blanking Start (0x18)         */
    Uint8 vertical_blanking_start;
/* Vertical Blanking Stop (0x19)          */
    Uint8 vertical_blanking_stop;
/* Chrominance Control #1 (0x1A)          */
    Uns automatic_color_gain_ctrl : 2;
    Uns chrominance_comb_filter_enable : 1;
    Uns chrominance_adaptive_comb_filter_enable : 1;
    Uns color_pll_reset : 1;
    Uns chrominance_control_rsv1 : 3;
/* Chrominance Control #2 (0x1B)          */
    Uns chrominance_filter_select : 2;
    Uns wcf : 1;
    Uns chrominance_control_rsv2 : 1;
    Uns chrominance_comb_filter_mode : 4;
/* Interrupt Reset (0x1C)                 */
    Uns tv_vcr_changed_reset : 1;
    Uns hv_lock_changed_reset : 1;
    Uns color_lock_changed_reset : 1;
    Uns line_alternation_changed_reset : 1;
    Uns field_rate_changed_reset : 1;
    Uns command_ready_reset : 1;
    Uns macrovision_detect_changed_reset : 1;
    Uns software_initialization_reset : 1;
/* Interrupt Enable (0x1D)                */
    Uns tv_vcr_changed : 1;
    Uns hv_lock_changed : 1;
    Uns color_lock_changed : 1;
    Uns line_alternation_changed : 1;
    Uns field_rate_changed : 1;
    Uns command_ready : 1;
    Uns macrovision_detect_changed : 1;
    Uns software_initialization_occurred_enable : 1;
/* Interrupt Configuration (0x1E)         */
    Uns interrupt_polarity_b : 1;
    Uns interrupt_config_rsv : 7;
/* Reserved (0x1F) - (0x27)               */
    Uint8 rsv3[9];
/* Video Standard (0x28)                  */
    Uns video_standard : 4;
    Uns video_standard_rsv : 4;
/* Reserved (0x29) - (0x2B)               */
    Uint8 rsv4[3];
/* Cb Gain Factor (0x2C)                  */
    Uint8 cb_gain_factor;
/* Cr Gain Factor (0x2D)                  */
    Uint8 cr_gain_factor;
/* Macrovision On Counter (0x2E)          */
    Uint8 macrovision_on_counter;
/* Macrovision Off Counter (0x2F)         */
    Uint8 macrovision_off_counter;
/* Reserved (0x30) - (0x7F)               */
    Uint8 rsv5[80];
/* MSB of Device ID (0x80)                */
    Uint8 msb_of_device_id;
/* LSB of Device ID (0x81)                */
    Uint8 lsb_of_device_id;
/* ROM Version (0x82)                     */
    Uint8 rom_version;
/* RAM Patch Code Version (0x83)          */
    Uint8 ram_patch_code_version;
/* Vertical Line Count MSB (0x84)         */
    Uns vertical_line_count_msb : 2;
    Uns vertical_line_count_msb_rsv : 6;
/* Vertical Line Count LSB (0x85)         */
    Uint8 vertical_line_count_lsb;
/* Interrupt Status (0x86)                */
    Uint8 rsv6[122];

    
}_TVP51XX_Generics;

typedef struct _TVP51XX_Regs
{
    _TVP51XX_Generics generics;
}_TVP51XX_Regs;                        

extern _TVP51XX_Regs _TVP51XX_settingsDef[2];




#ifdef __cplusplus
}
#endif


#endif /*#ifndef __TVP51XX_H*/

/********************************************************************************/
/* end of file */
/********************************************************************************/



