/*
 *  Copyright 2003 by Texas Instruments Incorporated.
 *  All rights reserved. Property of Texas Instruments Incorporated.
 *  Restricted rights to use, duplicate or disclose this code are
 *  granted through contract.
 *  
 */
/* "@(#) DDK 1.10.00.23 07-02-03 (ddk-b12)" */
/* "@(#) Driver Patch number 1.00.01" */
#ifndef _VPORT_H
#define _VPORT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <std.h>
#include <csl.h>
#include <iom.h>
#include <edc.h>     

/* common for both capture and display drivers */                     
/* maximum number of video frame buffers */
#define VPORT_MAX_NUM_FRMBUFS           10

/* VPORT field operation mode */   
#define    VPORT_FLDOP_FLD1              0x1  /* field 1 cap/dis only */
#define    VPORT_FLDOP_FLD2              0x2  /* field 2 cap/dis only */
#define    VPORT_FLDOP_FRAME             0x4  /* frame cap/dis        */
#define    VPORT_FLDOP_PROGRESSIVE       0x5  /* progressive cap/dis  */

/* VPORT video port operation mode */
#define    VPORT_MODE_BT656_8BIT  0x0
#define    VPORT_MODE_BT656_10BIT 0x1
#define    VPORT_MODE_RAW_8BIT    0x2
#define    VPORT_MODE_RAW_10BIT   0x3
#define    VPORT_MODE_YCBCR_8BIT  0x4
#define    VPORT_MODE_YCBCR_10BIT 0x5
#define    VPORT_MODE_RAW_16BIT   0x6
#define    VPORT_MODE_RAW_20BIT   0x7

/* VPORT external PIN POLARITY */
#define   VPORT_POLARITY_ACTIVE_HIGH  0x0
#define   VPORT_POLARITY_ACTIVE_LOW   0x11
                
/* video port HORIZONTAL scaling mode control */
/* 1/2 for capture, 2x for display */
#define   VPORT_SCALING_DISABLE       0x0
#define   VPORT_SCALING_ENABLE        0x1

/* video port HORIZONTAL chroma resampling mode control */
/* capture : 4:2:2 => 4:2:0    display: 4:2:0 => 4:2:2  */
#define   VPORT_RESMPL_DISABLE        0x0
#define   VPORT_RESMPL_ENABLE         0x1          
                                           
                                           
#define VPORT_FLDS_SEPARATED    0
#define VPORT_FLDS_MERGED       1

/* Video mini-driver control command */
/* The following commands are common for both capture and display operation */
#define VPORT_CMD_RESET         0x10000001  /* video port reset command     */
#define VPORT_CMD_CONFIG_PORT   0x10000002  /* configure video port         */
#define VPORT_CMD_CONFIG_CHAN   0x10000003  /* configure video channel      */
#define VPORT_CMD_START         0x10000004  /* start video port operation   */
#define VPORT_CMD_STOP          0x10000005  /* stop video port operation    */
#define VPORT_CMD_SET_VINTCB    0x10000006  /* set video channel error      */
                                            /* call-back function           */
#define VPORT_CMD_DUND_RECOVER  0x10000007  /* force the recovery of        */
                                            /* display under-run            */
#define VPORT_CMD_COVR_RECOVER  0x10000007  /* force the recovery of        */
                                            /* capture over-run             */
/* base of control commands for external device */
/* that is stack under the video drivers        */
/* external device control command base */
#define VPORT_CMD_EDC_BASE      0x80000000  

/************************************************
 * Error call-back function prototype           *
 ************************************************/
/* Only one video port global interrupt call-back   */
/* function can be defined for each channel/device  */
/* pair. Multiple calls to setup the call-back      */
/* function overwrite the previous setup.           */

typedef void (*VPORT_IntCallBack)(Arg id, Arg mask);

/* video port interrupt masks */
#define VPORT_INT_COVR     0x0002  /* capture fifo over-run interrupt   */
#define VPORT_INT_CCMP     0x0004  /* capture complete interrupt        */
#define VPORT_INT_SERR     0x0008  /* synchronization error interrupt   */
#define VPORT_INT_VINT1    0x0010  /* field 1 vertical interrupt        */
#define VPORT_INT_VINT2    0x0020  /* field 2 vertical interrupt        */
#define VPORT_INT_SFD      0x0040  /* short field detected interrupt    */
#define VPORT_INT_LFD      0x0080  /* long field detected interrupt     */
#define VPORT_INT_STC      0x0400  /* system time clock interrupt       */
#define VPORT_INT_TICK     0x0800  /* clock tick interrupt              */
#define VPORT_INT_DUND     0x1000  /* display fifo under-run            */
#define VPORT_INT_DCMP     0x2000  /* display complete                  */
#define VPORT_INT_DCNA     0x4000  /* display complete not ackowledeged */

                                           
/* parameter structure to setup video port call-back functions */
typedef struct VPORT_VIntCbParams{
    Int cbArg;                   /* call-back argument is for the            */
                                 /* application to identify which channel or */
                                 /* device causes the interrupt              */
    VPORT_IntCallBack vIntCbFxn; /* pointer to the video port interrupt      */
                                 /* call-back function                       */
    Uint16 vIntMask;             /* interrupt mask, All masks OR together    */
                                 /* to indicate errors that are handled by   */
                                 /* by the call-back                         */
    Uint16 vIntLine;             /* line number where vertical interrupt     */
                                 /* occurs, don't care otherwise.            */
    Int irqId;                                   
    
} VPORT_VIntCbParams;

/******************************************************************************
 * Binding of external device control function tables to the video port       *
 * is done when _mdBindDev() is called at system initialization time.         *
 * A statically defined EDC function table is passed to the _mdBindDev()      *
 * function via the "devParam" argument. This argument must point to a        *
 * type of data structure that is defined below                               *
 *****************************************************************************/
typedef struct VPORT_PortParams{
    Bool             dualChanEnable;       /* dual channel mode enable        */
    Uns              vc1Polarity;    /* vport control pin 1 polarity    */
    Uns              vc2Polarity;    /* vport control pin 2 polarity    */
    Uns              vc3Polarity;    /* vport control pin 3 polarity    */
    EDC_Fxns*        edcTbl[2];      /* function tables for edc modules */
    Arg              edcCtrlHandle;
} VPORT_PortParams;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* _VPORT_H */
