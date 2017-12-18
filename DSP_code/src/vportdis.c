/**********************************************************/
/* Display parameter definitions based on 625/50 format */
/**********************************************************/
/* ................. */
/* Define frame size */
/* ................. */
/* no of pixels per frame line including horizontal blanking*/
/*����ÿ�е�������������������*/
#define VD_FRM_WIDTH 864 
/*����ÿ֡������������������*/
#define VD_FRM_HEIGHT 625 /* total noof lines per frame */
/*����ÿ֡�Ĵ�С*/
#define VD_FRM_SIZE (VD_FRM_WIDTH * VD_FRM_HEIGHT)
/* ................... */
/* Horizontal blanking */
/* ................... */
/*���������ֵ�����λ��*/
#define VD_HBLNK_START 720 /* starting location of EAV */
/*����������������λ��*/
#define VD_HBLNK_STOP 862 /* starting location of SAV */
/*������������*/
#define VD_HBLNK_SIZE (VD_HBLNK_STOP - VD_HBLNK_START +2/*EAV*/) /* (138) EAV, SAV inclusive */
/* ............................ */
/* Vertical blanking for field1 */
/* ............................ */
/*�泡�ĳ���������*/
#define VD_VBLNK_XSTART1 720 /* pixel on which VBLNK active */
/* edge occurs for field1 */
#define VD_VBLNK_YSTART1 642 /* line on which VBLNK active */
/* edge occurs for field1 */
#define VD_VBLNK_XSTOP1 720 /* pixel on which VBLNK inactive */
/* edge occurs for field1 */
#define VD_VBLNK_YSTOP1 23 /* line on which VBLNK inactive */
/* edge occurs for field1 */
/* ............................ */
/* Vertical blanking for field2 */
/* ............................ */
/*ż���ĳ���������*/
#define VD_VBLNK_XSTART2 360 /* pixel on which VBLNK active */
/* edge occurs for field2 */
#define VD_VBLNK_YSTART2 311 /* line on which VBLNK active */
/* edge occurs for field2 */
#define VD_VBLNK_XSTOP2 360 /* pixel on which VBLNK inactive */
/* edge occurs for field2 */
#define VD_VBLNK_YSTOP2 336 /* line on which VBLNK inactive */
/* edge occurs for field2 */
/* ................................................. */
/* Define vertical blanking bit(VD_VBITn) reg values */
/* ................................................. */
/*��һ����ֱ������������������ڵ�����*/
/* first line with an EAV with V=1 indicating the start of Field1 vertical blanking */
#define VD_VBIT_SET1 1 
/* first line with an EAV with V=0 indicating the start of Field1 active display*/
#define VD_VBIT_CLR1 23
#define VD_VBLNK1_SIZE (VD_VBIT_CLR1 - VD_VBIT_SET1) /* 19 lines */
/*�ڶ�����ֱ������������������ڵ�����*/
/* first line with an EAV with V=1 indicating the start of Field2 vertical blanking*/
#define VD_VBIT_SET2 311 
/* first line with an EAV with V=0 indicating the start of Field2 active display*/
#define VD_VBIT_CLR2 336 
#define VD_VBLNK2_SIZE (VD_VBIT_CLR2 - VD_VBIT_SET2) /* 19 lines */
/* ............ */
/* Field timing */
/* ............ */
/* pixel on the first line of Field1 on which FLD ouput is de-asserted*/
#define VD_FIELD1_XSTART 720 
/* line on which FLD is de-asserted */
#define VD_FIELD1_YSTART 1 
/* pixel on the first line of Field1 on which FLD ouput is asserted */
#define VD_FIELD2_XSTART 360
/* line on which FLD is asserted */
#define VD_FIELD2_YSTART 313 
/* .................................... */
/* Define field bit(VD_FBIT) reg values */
/* .................................... */
#define VD_FBIT_CLR 1 /* first line with an EAV with F=0 indicating Field 1 display*/
#define VD_FBIT_SET 313 /* first line with an EAV with F=1 indicating Field 2 display*/

/* ................................ */
/* Define horzontal synchronization */
/* ................................ */
#define VD_HSYNC_START 752
#define VD_HSYNC_STOP 782
/* .......................................... */
/* Define vertical synchronization for field1 */
/* .......................................... */
#define VD_VSYNC_XSTART1 752
#define VD_VSYNC_YSTART1 1
#define VD_VSYNC_XSTOP1 752
#define VD_VSYNC_YSTOP1 3
/* .......................................... */
/* Define vertical synchronization for field2 */
/* .......................................... */
#define VD_VSYNC_XSTART2 320
#define VD_VSYNC_YSTART2 313
#define VD_VSYNC_XSTOP2 320
#define VD_VSYNC_YSTOP2 316
/* ........................................ */
/* Define image offsets for both the fields */
/* which are zero in this example */
/* ........................................ */
#define VD_IMG_HOFF1 0
#define VD_IMG_VOFF1 0
#define VD_IMG_HOFF2 0
#define VD_IMG_VOFF2 0
/* ................................................. */
/* Define image active vertical and horizontal sizes */
/* ................................................. */
#define VD_IMG_HSIZE1 720 /* field1 horizontal image size */
#define VD_IMG_VSIZE1 288 /* field1 vertical image size */
#define VD_IMG_HSIZE2 720 /* field2 horizontal image size */
#define VD_IMG_VSIZE2 288 /* field2 vertical image size */
/* Manipulate field1 and field2 image sizes */
#define VD_IMAGE_SIZE1 (VD_IMG_HSIZE1 * VD_IMG_VSIZE1)
#define VD_IMAGE_SIZE2 (VD_IMG_HSIZE2 * VD_IMG_VSIZE2)
/* Define threshold values in double-words. Both fields should */
/* have same threshold value */
#define VD_VDTHRLD1 (VD_IMG_HSIZE1/8) /* line length in */
#define VD_VDTHRLD2 VD_VDTHRLD1 /* double-words */
/* Define number of events to be generated for field1 and field2 */
#define VD_DISPEVT1 (VD_IMAGE_SIZE1 / (VD_VDTHRLD1 * 8))
#define VD_DISPEVT2 (VD_IMAGE_SIZE2 / (VD_VDTHRLD2 * 8))
#define DISPLAY_FRAME_COUNT 1 /* in this example */
/* ............................................ */
/* EDMA parameters for display Y event that are */
/* specific to this example. */
/* ............................................ */
/* VD_VDTHRLDn is in double-words and 32-bit element size */
#define VD_Y_EDMA_ELECNT (VD_VDTHRLD1 * 2) 
#define VD_Y_EDMA_FRMCNT ((VD_DISPEVT1 + VD_DISPEVT2) * DISPLAY_FRAME_COUNT)
/******************************************************************/
/* Description : 8.bit BT.656 non.continuous frame display */
/* */
/* Some important field descriptions: */
/* */
/* DMODE = 000, 8.bit BT.656 mode */
/* CON = 0 */
/* FRAME = 1, display frame */
/* DF2 = 0 */
/* DF1 = 0, (8.bit non.continuous frame display) */
/* SCALE = 0, no scaling */
/* RESMPL = 0, no resampling */
/* DPK = X, not used in 8.bit display */
/* RSYNC = X, used in Raw mode(Enable second synchronized raw */
/* data channel) */
/* RGBX = X, used in Raw mode(RGB extract enable. Perform */
/* 3/4 FIFO unpacking) */
/* VCTL1S = 00, output HSYNC */
/* VCTL2S = 00, output VSYNC */
/* VCTL3S = 0, output CBLNK */
/* HXS = 0, VCTL1 is an output */
/* VXS = 0, VCTL2 is an output */
/* FXS = 0, VCTL3 is an output */
/* PVPSYN = 0, no previous port synchronization */
/******************************************************************/
#include <vportdis.h>
#include "vportcap.h"
/*................................................................ */
/* global variable declarations */
/* ............................................................... */

//	Uint32 disChaAYSpace  = 0x80000000;
//	Uint32 disChaACbSpace = 0x800675c0; 
//	Uint32 disChaACrSpace = 0x8009b0a0;

	#pragma DATA_SECTION(disChaAYSpace, ".disChaAYSpace") 
	/* buffer to store captured Y-data */
	Uint8 disChaAYSpace[720*588]; 
	#pragma DATA_SECTION(disChaACbSpace, ".disChaACbSpace")
	/* buffer to store captured Cb-data */
	Uint8 disChaACbSpace[360*588]; 
	#pragma DATA_SECTION(disChaACrSpace, ".disChaACrSpace")
	/* buffer to store captured Cr-data */
	Uint8 disChaACrSpace[360*588];
	
	/* handle of vp that to be configured */
	VP_Handle vpDisplayHandle; 
	EDMA_Handle hEdmaVPDispY;
	EDMA_Handle hEdmaVPDispCb;
	EDMA_Handle hEdmaVPDispCr;
	Int32 edmaDispYTccNum = 0; /* EDMA tcc for Y channel */
	Int32 edmaDispCbTccNum = 0; /* EDMA tcc for Cb channel */
	Int32 edmaDispCrTccNum = 0; /* EDMA tcc for Cb channel */
	volatile Uint32 displayFrameCount = 0; /* no of frames that are */
	/* displayed */
	volatile Uint32 dispUnderrun = 0; /* underrun error flag */
	volatile Uint32 disNewFrame =0;
/*................................................................ */
/* Function : bt656_8bit_ncfd */
/* Input(s) : portNumber, video port number i.e. 0, 1 or 2. */
/* Description : Configures given video port for 8.bit BT.656 non. */
/* continuous frame display. */
/*................................................................ */
VP_Handle bt656_8bit_ncfd(int portNumber)
{
	/* Open video port for display ����һ����Ƶ��*/
	vpDisplayHandle = VP_open(portNumber, VP_OPEN_RESET);
	if(vpDisplayHandle == INV)
	{
		return (VP_Handle)0xFFFF;
	}
	/*ʹ����Ƶ��*/
	/* Enable video port functionality in VP Peripheral Control Reg(PCR)*/
	VP_FSETH(vpDisplayHandle , PCR, PEREN, VP_PCR_PEREN_ENABLE);
	/* Set this port to display mode�����˿���Ϊ��ʾģʽ */
	VP_FSETH(vpDisplayHandle , VPCTL, DISP, VP_VPCTL_DISP_DISPLAY);
	/* ..................... */
	/* Enable all interrupts */
	/* ..................... */
	/*ʹ����Ӧ���ж�Դ*/
	/* enable display complete interrupt */
	VP_FSETH(vpDisplayHandle , VPIE, DCMP, VP_VPIE_DCMP_ENABLE);
	/* enable display underrun interrupt */
	VP_FSETH(vpDisplayHandle , VPIE, DUND, VP_VPIE_DUND_ENABLE);
	/* enable video port global interrupt enable */
	VP_FSETH(vpDisplayHandle , VPIE, VIE, VP_VPIE_VIE_ENABLE);
	/* .................... */
	/* Set all other fields */
	/* .................... */
	/* set frame size ��������ʾ֡�Ĵ�С*/
	VP_RSETH(vpDisplayHandle , VDFRMSZ,VP_VDFRMSZ_RMK(VD_FRM_HEIGHT, VD_FRM_WIDTH));
	/*�����ź�VBLNK��ʱ��*/
	/* set horizontal blanking������ˮƽ��������ʼλ����ֹͣλ��720��856 */
	VP_RSETH(vpDisplayHandle , VDHBLNK,VP_VDHBLNK_RMK(VD_HBLNK_STOP, 
													  VP_VDHBLNK_HBDLA_NONE,
													  VD_HBLNK_START));
	
	/* set vertical blanking start for field1�����õ�һ���Ĵ�ֱ������λ�� */
	VP_RSETH(vpDisplayHandle , VDVBLKS1,VP_VDVBLKS1_RMK(VD_VBLNK_YSTART1,
														VD_VBLNK_XSTART1));
	/* set vertical blanking end for field1 */
	VP_RSETH(vpDisplayHandle , VDVBLKE1,VP_VDVBLKE1_RMK(VD_VBLNK_YSTOP1, 
													    VD_VBLNK_XSTOP1));
	/* set vertical blanking start for field2 �����õڶ����Ĵ�ֱ������λ��*/
	VP_RSETH(vpDisplayHandle , VDVBLKS2,VP_VDVBLKS2_RMK(VD_VBLNK_YSTART2, 
													    VD_VBLNK_XSTART2));
	/* set vertical blanking end for field2 */
	VP_RSETH(vpDisplayHandle , VDVBLKE2,VP_VDVBLKE2_RMK(VD_VBLNK_YSTOP2, 
														VD_VBLNK_XSTOP2));
	/*����EAV��SAV�е�Vλ��ֵ*/
	/* set vertical blanking bit register for field 1(VD_VBIT1) */
	/*���õ�һ��������������*/
	VP_RSETH(vpDisplayHandle , VDVBIT1,VP_VDVBIT1_RMK(VD_VBIT_CLR1, 
											    	  VD_VBIT_SET1));
	/* set vertical blanking bit register for field 2(VD_VBIT2) */
	/*���õڶ���������������*/
	VP_RSETH(vpDisplayHandle , VDVBIT2,VP_VDVBIT2_RMK(VD_VBIT_CLR2, 
													  VD_VBIT_SET2));
	/* No image offsets in this example */
	/* set image size for field1,ÿһ������ͼ��Ĵ�С */
	VP_RSETH(vpDisplayHandle , VDIMGSZ1,VP_VDIMGSZ1_RMK(VD_IMG_VSIZE1, 
														VD_IMG_HSIZE1));
	/* set image size for field2�����õڶ���ͼ��Ĵ�С */
	VP_RSETH(vpDisplayHandle , VDIMGSZ2,VP_VDIMGSZ1_RMK(VD_IMG_VSIZE2, 
														VD_IMG_HSIZE2));
	/*����FLD�źŵ��߼�*/
	/* set field1 timing �����õ�һ������ʼ��*/
	VP_RSETH(vpDisplayHandle , VDFLDT1,VP_VDFLDT1_RMK(VD_FIELD1_YSTART, VD_FIELD1_XSTART));
	/* set field2 timing �����õڶ�������ʼ��*/
	VP_RSETH(vpDisplayHandle , VDFLDT2,VP_VDFLDT2_RMK(VD_FIELD2_YSTART, VD_FIELD2_XSTART));
	/*����EAV��SAV�е�Fλ��ֵ*/
	/* set display field bit register(VD_FBIT) */
	VP_RSETH(vpDisplayHandle , VDFBIT,VP_VDFBIT_RMK(VD_FBIT_SET, VD_FBIT_CLR));
	
	/* set horizontal sync control (VCTL1S) ������ˮƽͬ���ź�����Ŀ���*/
	VP_RSETH(vpDisplayHandle , VDHSYNC,VP_VDHSYNC_RMK(VD_HSYNC_STOP, VD_HSYNC_START));
	/*������ֱͬ���ź�����Ŀ���*/
	/* set vertical sync start for field1 (VCTL1S) */
	VP_RSETH(vpDisplayHandle , VDVSYNS1,VP_VDVSYNS1_RMK(VD_VSYNC_YSTART1,VD_VSYNC_XSTART1));
	/* set vertical sync end for field1 (VCTL1S) */
	VP_RSETH(vpDisplayHandle , VDVSYNE1,VP_VDVSYNE1_RMK(VD_VSYNC_YSTOP1, VD_VSYNC_XSTOP1));
	/* set vertical sync start for field2 (VCTL2S) */
	VP_RSETH(vpDisplayHandle , VDVSYNS2,VP_VDVSYNS2_RMK(VD_VSYNC_YSTART2,VD_VSYNC_XSTART2));
	/* set vertical sync end for field2 (VCTL2S) */
	VP_RSETH(vpDisplayHandle , VDVSYNE2,VP_VDVSYNE2_RMK(VD_VSYNC_YSTOP2, VD_VSYNC_XSTOP2));
	/* Let clipping values to be their defaults (VD_CLIP) No need to set DEF_VAL and VD_RELOAD in this example*/
	/*�����ж��¼�*/
	/* set event register */
	VP_RSETH(vpDisplayHandle , VDDISPEVT,VP_VDDISPEVT_RMK(VD_DISPEVT2, VD_DISPEVT1));
	/* Vertical interrupts are not used in this example (VD_VINT) */
	/* set threshold value for DMA events */
	VP_RSETH(vpDisplayHandle, VDTHRLD,VP_VDTHRLD_RMK(VD_VDTHRLD2,
													 VP_VDTHRLD_INCPIX_DEFAULT, 
													 VD_VDTHRLD1));
	/* ............................... */
	/* Set display control reg(VD_CTL) */
	/* ............................... */
	/* set display mode(DMODE) to 8-bit BT.656 */
	VP_FSETH(vpDisplayHandle , VDCTL, DMODE, VP_VDCTL_DMODE_BT656B);
	/* set non-continuous frame display */
	VP_FSETH(vpDisplayHandle , VDCTL, CON, VP_VDCTL_CON_DISABLE);
	VP_FSETH(vpDisplayHandle , VDCTL, FRAME, VP_VDCTL_FRAME_FRMDIS);
	VP_FSETH(vpDisplayHandle , VDCTL, DF2, VP_VDCTL_DF2_NONE);
	VP_FSETH(vpDisplayHandle , VDCTL, DF1, VP_VDCTL_DF1_NONE);
	/* let control outputs(VCTL1S, VCTL2S, VCTL3S, HXS, VXS, FXS) */
	/* be their defaults i.e. VCTLxS are output control signals */
	/* no scaling and no resampling in this example */
	/* no need to bother about 10.bit unpacking mode(DPK bit) */
	/* in this 8.bit example */
	/* Set up Y, Cb and Cr EDMA channels */
	setupVPDispEDMA(portNumber);
	IRQ_enable(vpDisplayHandle ->eventId);
	/* clear VPHLT in VP_CTL to make video port function */
	VP_FSETH(vpDisplayHandle , VPCTL, VPHLT, VP_VPCTL_VPHLT_CLEAR);
	
	return vpDisplayHandle;	
	
}
/*................................................................ */
/* Function : bt656_display_start */
/* Input(s) : VP_Handle*/
/* Description : Configures given video port for 8.bit BT.656 non. */
/* continuous frame display. */
/*................................................................ */
void bt656_display_start(VP_Handle vpDisplayHandle)
{
	/* .............. */
	/* enable display */
	/* .............. */
	/* set VDEN to enable display for loop-back */
	VP_FSETH(vpDisplayHandle, VDCTL, VDEN, VP_VDCTL_VDEN_ENABLE);
	/* clear BLKDIS in VD_CTL to enable display DMA events */
	VP_FSETH(vpDisplayHandle, VDCTL, BLKDIS, VP_VDCTL_BLKDIS_CLEAR);

}
/*................................................................ */
/* Function : VPDispIsr */
/* Description : This display ISR clears FRMD to continue display */
/* in this non.continuous mode and also clears other */
/* status bits. */
/*................................................................ */
interrupt void VPDispIsr(void)
{
	Uint32 vpis = 0;
	vpis = VP_RGETH(vpDisplayHandle , VPIS);
	if(vpis & _VP_VPIS_DCMP_MASK) /* frame display complete */
	{
		/* Clear frame complete bit FRMD to continue display */
		VP_FSETH(vpDisplayHandle , VDSTAT, FRMD,
		VP_VDSTAT_FRMD_CLEAR);
		/* clear DCMPA to enable next frame complete interrupts */
		VP_FSETH(vpDisplayHandle , VPIS, DCMP, VP_VPIS_DCMP_CLEAR);
		displayFrameCount++; /* increment displayed frame count */
		disNewFrame = 1;
	}
	if(vpis & _VP_VPIS_DUND_MASK) /* underrun error */
	{
		dispUnderrun++;
		/* clear DUND to enable next underrun interrupts */
		VP_FSETH(vpDisplayHandle , VPIS, DUND, VP_VPIS_DUND_CLEAR);
	}
}
/*................................................................ */
/* Function : setupVPDispEDMA */
/* Input(s) : portNumber, video port number i.e. 0,1 or 2. */
/* Description : Sets up DMA channels for Y, U, V events for VP */
/* display. */
/*................................................................ */
void setupVPDispEDMA(Int32 portNumber)
{
	Int32 YEvent, UEvent, VEvent;
	/* get Y, U, V EDMA event numbers */
	switch(portNumber)
	{
		case VP_DEV0: 
			YEvent = EDMA_CHA_VP0EVTYA;
			UEvent = EDMA_CHA_VP0EVTUA;
			VEvent = EDMA_CHA_VP0EVTVA;
			break;
		case VP_DEV1: 
			YEvent = EDMA_CHA_VP1EVTYA;
			UEvent = EDMA_CHA_VP1EVTUA;
			VEvent = EDMA_CHA_VP1EVTVA;
			break;
		case VP_DEV2: 
			YEvent = EDMA_CHA_VP2EVTYA;
			UEvent = EDMA_CHA_VP2EVTUA;
			VEvent = EDMA_CHA_VP2EVTVA;
			break;
	}
	/* Configure Y EDMA channel to move data from */
	/* Y-data buffer, dispYSpace to YDSTA (FIFO) */
	configVPDispEDMAChannel(&hEdmaVPDispY, YEvent,
							&edmaDispYTccNum,
							(Uint32)disChaAYSpace,
							vpDisplayHandle ->ydstaAddr,
							VD_Y_EDMA_FRMCNT,
							VD_Y_EDMA_ELECNT);
	/* Configure Cb EDMA channel to move data from */
	/* Cb-data buffer, dispCbSpace to CbDSTA (FIFO) */
	configVPDispEDMAChannel(&hEdmaVPDispCb, UEvent,
							&edmaDispCbTccNum,
							(Uint32)disChaACbSpace,
							vpDisplayHandle ->cbdstAddr,
							VD_Y_EDMA_FRMCNT,
							VD_Y_EDMA_ELECNT/2); /* (1/2) of Y */
	/* Configure Cr EDMA channel to move data from */
	/* Cr-data buffer, dispCrSpace to CrDSTA (FIFO) */
	configVPDispEDMAChannel(&hEdmaVPDispCr, VEvent,
							&edmaDispCrTccNum,
							(Uint32)disChaACrSpace,
							vpDisplayHandle ->crdstAddr,
							VD_Y_EDMA_FRMCNT,
							VD_Y_EDMA_ELECNT/2);
	/* enable three EDMA channels */
	EDMA_enableChannel(hEdmaVPDispY);
	EDMA_enableChannel(hEdmaVPDispCb);
	EDMA_enableChannel(hEdmaVPDispCr);
}
/*................................................................ */
/* Function : configVPDispEDMAChannel */
/* */
/* Input(s) : edmaHandle . pointer to EDMA handle. */
/* eventId . EDMA eventId. */
/* tccNum . pointer to transfer complete number. */
/* srcAddr . source address for EDMA transfer. */
/* dstAddr . destination address for EDMA transfer */
/* frameCount . frame count. */
/* elementCount . element count(32.bit element size). */
/* */
/* Output(s): edmaHandle . edma Handle of the given event. */
/* tccNum . transfer complete code for the given */
/* event. */
/* */
/* Description : Configures the given VP display EDMA channel. */
/* The destination address update is fixed because */
/* the displayed data is write to the FIFO. */
/* In this example, the source address mode is */
/* auto.increment. But, in real.time applications */
/* there is lot of flexibility in the way display */
/* buffers can be managed like ping.pong and round */
/* robin,��etc. */
/*................................................................ */
void configVPDispEDMAChannel( EDMA_Handle *edmaHandle,
							  Int32 eventId, 
							  Int32 *tccNum,
							  Uint32 srcAddr, 
							  Uint32 dstAddr,
							  Uint32 frameCount, 
							  Uint32 elementCount)
{
	Int32 tcc = 0;
	EDMA_Handle hEdmaTable;
	/* Open Y event EDMA channel */
	*edmaHandle = EDMA_open(eventId, EDMA_OPEN_RESET);
	if(*edmaHandle == EDMA_HINV)
	{
		for(;;){}
	}
	/* allocate TCC for Y event */
	if((tcc = EDMA_intAlloc(.1)) == .1)
	{
		for(;;){}
	}
	/*��һ���µ�EDMA����*/
	hEdmaTable = EDMA_allocTable(-1);
	/* Configure EDMA parameters */
	EDMA_configArgs(
		*edmaHandle,
		EDMA_OPT_RMK(
			EDMA_OPT_PRI_MEDIUM, /* medium priority */
			EDMA_OPT_ESIZE_32BIT, /* Element size 32 bits */
			EDMA_OPT_2DS_YES, /* 2-dimensional source */
			EDMA_OPT_SUM_INC, /* source address auto increment */
			EDMA_OPT_2DD_NO, /* 1-dimensional destination(FIFO) */
			EDMA_OPT_DUM_NONE, /* fixed dest address mode(FIFO) */
			EDMA_OPT_TCINT_YES, /* Enable transfer complete indication*/
			EDMA_OPT_TCC_OF(tcc & 0xF),
			EDMA_OPT_TCCM_OF(((tcc & 0x30) >> 4)),
			EDMA_OPT_ATCINT_NO, /* Disable Alternate Transfer Complete Interrupt */
			EDMA_OPT_ATCC_OF(0),
			EDMA_OPT_PDTS_DISABLE, /* disable PDT(peripheral device  transfer) mode for source*/
			EDMA_OPT_PDTD_DISABLE, /* disable PDT mode for dest */
			EDMA_OPT_LINK_YES, /* Disable linking */
			EDMA_OPT_FS_NO /* Array synchronization */
		),
		EDMA_SRC_RMK(srcAddr),
		EDMA_CNT_RMK(EDMA_CNT_FRMCNT_OF((frameCount-1)),
					 EDMA_CNT_ELECNT_OF(elementCount)),
		EDMA_DST_RMK(dstAddr),
		EDMA_IDX_RMK(EDMA_IDX_FRMIDX_OF((elementCount * 4)),
		EDMA_IDX_ELEIDX_OF(0)), /* note: 32-bit element size */
		/* no RLD in 2D and no linking */
		EDMA_RLD_RMK(EDMA_RLD_ELERLD_OF(0), EDMA_RLD_LINK_OF(0))
		);
	EDMA_configArgs(
		hEdmaTable,/*���ñ�ľ��*/
		EDMA_OPT_RMK(
			EDMA_OPT_PRI_MEDIUM, /* medium priority */
			EDMA_OPT_ESIZE_32BIT, /* Element size 32 bits */
			EDMA_OPT_2DS_YES, /* 2-dimensional source */
			EDMA_OPT_SUM_INC, /* source address auto increment */
			EDMA_OPT_2DD_NO, /* 1-dimensional destination(FIFO) */
			EDMA_OPT_DUM_NONE, /* fixed dest address mode(FIFO) */
			EDMA_OPT_TCINT_YES, /* Enable transfer complete indication*/
			EDMA_OPT_TCC_OF(tcc & 0xF),
			EDMA_OPT_TCCM_OF(((tcc & 0x30) >> 4)),
			EDMA_OPT_ATCINT_NO, /* Disable Alternate Transfer Complete Interrupt*/
			EDMA_OPT_ATCC_OF(0),
			EDMA_OPT_PDTS_DISABLE, /* disable PDT(peripheral devicetransfer) mode for source */
			EDMA_OPT_PDTD_DISABLE, /* disable PDT mode for dest */
			EDMA_OPT_LINK_YES, /* Enable linking */
			EDMA_OPT_FS_NO /* Array synchronization */
		),
		EDMA_SRC_RMK(srcAddr),
		EDMA_CNT_RMK(EDMA_CNT_FRMCNT_OF((frameCount-1)),
					 EDMA_CNT_ELECNT_OF(elementCount)),
		EDMA_DST_RMK(dstAddr),
		EDMA_IDX_RMK(EDMA_IDX_FRMIDX_OF((elementCount * 4)),
										 EDMA_IDX_ELEIDX_OF(0)), /* note: 32.bit element size */
		/* no RLD in 2D and no linking */
		EDMA_RLD_RMK(EDMA_RLD_ELERLD_OF(0), EDMA_RLD_LINK_OF(0))
	);
	/*��������DMA*/
	EDMA_link(*edmaHandle,hEdmaTable);
	/*ʹEDMAѭ������*/
	EDMA_link(hEdmaTable,hEdmaTable);
	*tccNum = tcc;
}
