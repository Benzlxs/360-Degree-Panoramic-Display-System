
/*NTSC*/
//#define VCB_HBLNK_SIZE 138 /* (858-720),horizontal blanking */
//#define VCB_IMG_VSIZE1 244 /* (263-20+1), fld1 vertical image size */
//#define VCB_IMG_VSIZE2 243 /* (525-283+1), fld2 vertical image size */

/*PAL*/
#define VCB_HBLNK_SIZE 144 /* (864-720),horizontal blanking */
/*确定第一场图像的重直像素为288*/
#define VCB_IMG_VSIZE1 288 /* (311-24+1), fld1 vertical image size */
/*确定第一场图像的重直像素为288*/
#define VCB_IMG_VSIZE2 288 /* (625-338+1), fld2 vertical image size */

/*确定第一场图像的水平像素为720*/
#define VCB_IMG_HSIZE1 720 /* field1 horizontal image size */
/*确定第二场图像的水平像素为720*/
#define VCB_IMG_HSIZE2 720 /* field2 horizontal image size */

/* 确定一场像素的大小为720×288 */
#define VCB_IMAGE_SIZE1 (VCB_IMG_HSIZE1 * VCB_IMG_VSIZE1)
/* 确定二场像素的大小为720×288 */
#define VCB_IMAGE_SIZE2 (VCB_IMG_HSIZE2 * VCB_IMG_VSIZE2)
/* Define threshold values in double.words. Both fields should have same threshold value*/
/* 确定FIFO的事件的门槛，为一行的长度，因为DM642为64位DMA，所以长度/8 */
#define VCB_VDTHRLD1 (VCB_IMG_HSIZE1/8) /* line length in */
#define VCB_VDTHRLD2 VCB_VDTHRLD1 /* double.words */
/* ....................................................... */
/* Define channel A capture window co-ordinates for Field1 */
/* ....................................................... */
/*设置图像的采集框*/
/* HRST = 0, start of horizontal blanking，HCOUNT在EAV后复位
   即一行是从EAV之后开始 ，那行消隐在前，图像在后*/
#define VCB_XSTART1 (VCB_HBLNK_SIZE-2)/*EAV*/
#define VCB_XSTOP1 (VCB_XSTART1 + VCB_IMG_HSIZE1-1)
/* VRST = 1, end of vertical blanking */
#define VCB_YSTART1 1
#define VCB_YSTOP1 (VCB_YSTART1 + VCB_IMG_VSIZE1-1)

/* ....................................................... */
/* Define channel A capture window co-ordinates for Field2 */
/* ....................................................... */
/* HRST = 0, start of horizontal blanking */
#define VCB_XSTART2 (VCB_HBLNK_SIZE-2/*EAV*/)
#define VCB_XSTOP2 (VCB_XSTART2 + VCB_IMG_HSIZE2-1)
/* VRST = 1, end of vertical blanking */
#define VCB_YSTART2 1
#define VCB_YSTOP2 (VCB_YSTART2 + VCB_IMG_VSIZE2-1)

/* Define threshold values in double-words. Both fields should same threshold value */
/* 确定FIFO触发的长度*/
#define VCB_THRLD_FIELD1 (VCB_IMG_HSIZE1/8) /* line length in */
#define VCB_THRLD_FIELD2 VCB_THRLD_FIELD1 /* double-words */

/* Define number of events to be generated for field1 and field2 
   定义奇场（244）与偶场的行数（243）*/
#define VCB_CAPEVT1 (VCB_IMAGE_SIZE1 / (VCB_VDTHRLD1 * 8))
#define VCB_CAPEVT2 (VCB_IMAGE_SIZE2 / (VCB_VDTHRLD2 * 8))
/* in this example 定义采1帧  */
#define CAPCHA_FRAME_COUNT 1 
/* ............................................ */
/* EDMA parameters for capture Y event that are */
/* specific to this example. */
/* ............................................ */

/* because VCB_THRLD_FIELDn is in double-words and element size is 32-bit */
#define VCB_Y_EDMA_ELECNT (VCB_THRLD_FIELD1 * 2) 

#define VCB_Y_EDMA_FRMCNT ((VCB_CAPEVT1 + VCB_CAPEVT2) * CAPCHA_FRAME_COUNT)
/******************************************************************/
/* Description : 8.bit BT.656 non.continuous frame capture 		  */
/* 																  */
/* Some important field descriptions:                             */
/*                                                                */
/* CMODE = 000, 8.bit BT.656 mode                                 */
/* CON = 0                                                        */
/* FRAME = 1, capture frame                                       */
/* CF2 = 0                                                        */
/* CF1 = 0, (8-bit non.continuous frame capture)                  */
/* SCALE = 0, no scaling                                          */
/* RESMPL= 0, no resampling                                       */
/* 10BPK = X, not used in 8-bit capture                           */
/* EXC = 0, use EAV/SAV codes                                     */
/* VRST = 1, end of vertical blanking                             */
/* HRST = 0, start of horizontal blanking                         */
/* FLDD = 0, 1st line EAV or FID input                            */
/* FINV = 0, no field invert                                      */
/* RDFE = X, used in Raw mode only(Enable field identification)   */
/* SSE = X, used in Raw mode only(Startup synch enable)           */
/******************************************************************/
#include <vportcap.h>
/*................................................................ */
/* global variable declarations 								   */
/* ............................................................... */
	#pragma DATA_SECTION(capChaAYSpace1, ".capChaAYSpace1") 
	/* buffer to store captured Y-data */
	Uint8 capChaAYSpace1[720*588]; 
	#pragma DATA_SECTION(capChaACbSpace1, ".capChaACbSpace1")
	/* buffer to store captured Cb-data */
	Uint8 capChaACbSpace1[360*588]; 
	#pragma DATA_SECTION(capChaACrSpace1, ".capChaACrSpace1")
	/* buffer to store captured Cr-data */
	Uint8 capChaACrSpace1[360*588];

	#pragma DATA_SECTION(capChaAYSpace2, ".capChaAYSpace2") 
	/* buffer to store captured Y-data */
	Uint8 capChaAYSpace2[720*588]; 
	#pragma DATA_SECTION(capChaACbSpace2, ".capChaACbSpace2")
	/* buffer to store captured Cb-data */
	Uint8 capChaACbSpace2[360*588]; 
	#pragma DATA_SECTION(capChaACrSpace2, ".capChaACrSpace2")
	/* buffer to store captured Cr-data */
	Uint8 capChaACrSpace2[360*588];

	#pragma DATA_SECTION(capChaAYSpace3, ".capChaAYSpace3") 
	/* buffer to store captured Y-data */
	Uint8 capChaAYSpace3[720*588]; 
	#pragma DATA_SECTION(capChaACbSpace3, ".capChaACbSpace3")
	/* buffer to store captured Cb-data */
	Uint8 capChaACbSpace3[360*588]; 
	#pragma DATA_SECTION(capChaACrSpace3, ".capChaACrSpace3")
	/* buffer to store captured Cr-data */
	Uint8 capChaACrSpace3[360*588];

	#pragma DATA_SECTION(capChaAYSpace4, ".capChaAYSpace4") 
	/* buffer to store captured Y-data */
	Uint8 capChaAYSpace4[720*588]; 
	#pragma DATA_SECTION(capChaACbSpace4, ".capChaACbSpace4")
	/* buffer to store captured Cb-data */
	Uint8 capChaACbSpace4[360*588]; 
	#pragma DATA_SECTION(capChaACrSpace4, ".capChaACrSpace4")
	/* buffer to store captured Cr-data */
	Uint8 capChaACrSpace4[360*588];
	
	/* handle of vp that to be configured */
	VP_Handle vpCaptureHandle0;
	VP_Handle vpCaptureHandle2; 
	/*设置Y、Cb、Cr的EDMA通路的句柄*/ 
	EDMA_Handle hEdmaVPCapCha2AY;
	EDMA_Handle hEdmaVPCapCha2ACb;
	EDMA_Handle hEdmaVPCapCha2ACr;

	EDMA_Handle hEdmaVPCapCha2BY;
	EDMA_Handle hEdmaVPCapCha2BCb;
	EDMA_Handle hEdmaVPCapCha2BCr;

	EDMA_Handle hEdmaVPCapCha0AY;
	EDMA_Handle hEdmaVPCapCha0ACb;
	EDMA_Handle hEdmaVPCapCha0ACr;

	EDMA_Handle hEdmaVPCapCha0BY;
	EDMA_Handle hEdmaVPCapCha0BCb;
	EDMA_Handle hEdmaVPCapCha0BCr;
	
	
	/* no of frames captured */ 
	volatile Uint32 capChaAFrameCount2A = 0;
	volatile Uint32 capChaAFrameCount2B = 0; 

	volatile Uint32 capChaAFrameCount0A = 0;
	volatile Uint32 capChaAFrameCount0B = 0;
	
	/* Error flags */
	volatile Uint32 capChaAOverrun2B = 0;
	volatile Uint32 capChaASyncError2B = 0;
	volatile Uint32 capChaAShortFieldDetect2B = 0;
	volatile Uint32 capChaALongFieldDetect2B = 0;

	volatile Uint32 capChaAOverrun2A = 0;
	volatile Uint32 capChaASyncError2A = 0;
	volatile Uint32 capChaAShortFieldDetect2A = 0;
	volatile Uint32 capChaALongFieldDetect2A = 0;

	volatile Uint32 capChaAOverrun0A = 0;
	volatile Uint32 capChaASyncError0A = 0;
	volatile Uint32 capChaAShortFieldDetect0A = 0;
	volatile Uint32 capChaALongFieldDetect0A = 0;

	volatile Uint32 capChaAOverrun0B = 0;
	volatile Uint32 capChaASyncError0B = 0;
	volatile Uint32 capChaAShortFieldDetect0B = 0;
	volatile Uint32 capChaALongFieldDetect0B = 0;

	volatile Uint32 capNewFrame2A = 0;
	volatile Uint32 capNewFrame2B = 0;
	volatile Uint32 capNewFrame0A = 0;
	volatile Uint32 capNewFrame0B = 0;
/*******************************************************************/
/* Function : bt656_8bit_ncfc 									   */
/* Input(s) : portNumber, video port number i.e. 0, 1 or 2.        */
/* Description : Configures given video port for 8.bit BT.656 non. */
/* continuos frame capture on channel A.                           */
/*******************************************************************/
void bt656_8bit_ncfc2( int portNumber)
{	 
	/* Open video port for capture ,打开一个视频端口*/
	VP_Handle vpCaptureHandle = VP_open(portNumber, VP_OPEN_RESET);
	if(vpCaptureHandle == INV)
	{
		return ;
	}
	/*将VP2设置为双通路*/
	VP_FSETH(vpCaptureHandle,VPCTL,DCHNL,VP_VPCTL_DCHNL_OF(1));
	/* Enable video port functionality in VP Peripheral Control Reg(PCR)，使能视频端口*/
	VP_FSETH(vpCaptureHandle, PCR, PEREN, VP_PCR_PEREN_ENABLE);
	/* ..................... */
	/* Enable all interrupts */
	/* ..................... */
	/*便能VCB的中断源*/
	/* Enable capture overrun interrupt(COVRA) for VP channel B */
	VP_FSETH(vpCaptureHandle, VPIE, COVRB, VP_VPIE_COVRB_ENABLE);
	/* Enable capture complete interrupt(CCMPA) for VP channel B */
	VP_FSETH(vpCaptureHandle, VPIE, CCMPB, VP_VPIE_CCMPB_ENABLE);
	/* Enable channel synchronization error interrupt(SERRA) for VP channel B */
	VP_FSETH(vpCaptureHandle, VPIE, SERRB, VP_VPIE_SERRB_ENABLE);
	/* Enable short field detect interrupt(SFDA) for VP channel B */
	VP_FSETH(vpCaptureHandle, VPIE, SFDB, VP_VPIE_SFDB_ENABLE);
	/* Enable video port global interrupt enable */

	VP_FSETH(vpCaptureHandle, VPIE, COVRA, VP_VPIE_COVRA_ENABLE);
	/* Enable capture complete interrupt(CCMPA) for VP channel A */
	VP_FSETH(vpCaptureHandle, VPIE, CCMPA, VP_VPIE_CCMPA_ENABLE);
	/* Enable channel synchronization error interrupt(SERRA) for */
	/* VP channel A */
	VP_FSETH(vpCaptureHandle, VPIE, SERRA, VP_VPIE_SERRA_ENABLE);
	/* Enable short field detect interrupt(SFDA) for VP channel A */
	VP_FSETH(vpCaptureHandle, VPIE, SFDA, VP_VPIE_SFDA_ENABLE);

	VP_FSETH(vpCaptureHandle, VPIE, VIE, VP_VPIE_VIE_ENABLE);
	/* ...................... */
	/* Setup all other fields */
	/* ...................... */
	

	VP_FSETH(vpCaptureHandle, VCACTL, SFDE, VP_VCACTL_SFDE_ENABLE);
	/* Set last pixel to be captured in Field1 (VCA_STOP1 reg) */
	/*设置第一场的最后一个像素的Y轴与X轴的坐标*/
	VP_RSETH(vpCaptureHandle, VCASTOP1,VP_VCASTOP1_RMK(VCB_YSTOP1, VCB_XSTOP1));
	/* Set last pixel to be captured in Field2 (VCA_STOP2 reg) */
	/*设置第二场的最后一个像素的Y轴与X轴的坐标*/
	VP_RSETH(vpCaptureHandle, VCASTOP2,VP_VCASTOP2_RMK(VCB_YSTOP2, VCB_XSTOP2));
	/* Set first pixel to be captured in Field1 (VCA_STRT1 reg) */
	/*设置第一场的第一个像素的Y轴与X轴的坐标*/
	VP_RSETH(vpCaptureHandle, VCASTRT1, VP_VCASTRT1_RMK(VCB_YSTART1,VP_VCASTRT1_SSE_ENABLE, VCB_XSTART1));
	/* Set first pixel to be captured in Field2 (VCA_STRT2 reg) */
	/*设置第二场的第一个像素的Y轴与X轴的坐标*/
	VP_RSETH(vpCaptureHandle, VCASTRT2,VP_VCASTRT2_RMK(VCB_YSTART2, VCB_XSTART2));
	/* Set threshold values ，设置EDMA启动的门限*/
	VP_RSETH(vpCaptureHandle, VCATHRLD,VP_VCATHRLD_RMK(VCB_THRLD_FIELD2, VCB_THRLD_FIELD1));
	/* Set capture event.register values，设置一场的需要的EDMA的次数 */
	VP_RSETH(vpCaptureHandle, VCAEVTCT,VP_VCAEVTCT_RMK(VCB_CAPEVT2,VCB_CAPEVT1));
	/* Vertical interrupts (VCA_INT) are not enabled in this example. */
	/* Set CMODE to 8.bit BT.656，采用BT656格式的数据流 */
	VP_FSETH(vpCaptureHandle, VCACTL, CMODE, VP_VCACTL_CMODE_BT656B);


	/* Enable short field detect，使能缺场探测*/
	VP_FSETH(vpCaptureHandle, VCBCTL, SFDE, VP_VCBCTL_SFDE_ENABLE);
	/* Set last pixel to be captured in Field1 (VCB_STOP1 reg) */
	/*设置第一场的最后一个像素的Y轴与X轴的坐标*/
	VP_RSETH(vpCaptureHandle, VCBSTOP1,VP_VCBSTOP1_RMK(VCB_YSTOP1, VCB_XSTOP1));
	/* Set last pixel to be captured in Field2 (VCB_STOP2 reg) */
	/*设置第二场的最后一个像素的Y轴与X轴的坐标*/
	VP_RSETH(vpCaptureHandle, VCBSTOP2,VP_VCBSTOP2_RMK(VCB_YSTOP2, VCB_XSTOP2));
	/* Set first pixel to be captured in Field1 (VCB_STRT1 reg) */
	/*设置第一场的第一个像素的Y轴与X轴的坐标*/
	VP_RSETH(vpCaptureHandle, VCBSTRT1, VP_VCBSTRT1_RMK(VCB_YSTART1,VP_VCBSTRT1_SSE_ENABLE, VCB_XSTART1));
	/* Set first pixel to be captured in Field2 (VCB_STRT2 reg) */
	/*设置第二场的第一个像素的Y轴与X轴的坐标*/
	VP_RSETH(vpCaptureHandle, VCBSTRT2,VP_VCBSTRT2_RMK(VCB_YSTART2, VCB_XSTART2));
	/* Set threshold values ，设置EDMA启动的门限*/
	VP_RSETH(vpCaptureHandle, VCBTHRLD,VP_VCBTHRLD_RMK(VCB_THRLD_FIELD2, VCB_THRLD_FIELD1));
	/* Set capture event.register values，设置一场的需要的EDMA的次数 */
	VP_RSETH(vpCaptureHandle, VCBEVTCT,VP_VCBEVTCT_RMK(VCB_CAPEVT2,VCB_CAPEVT1));
	/* Vertical interrupts (VCB_INT) are not enabled in this example. */
	/* Set CMODE to 8.bit BT.656，采用BT656格式的数据流 */
	VP_FSETH(vpCaptureHandle, VCBCTL, CMODE, VP_VCBCTL_CMODE_BT656B);
	/* Set non.continuous frame capture，设置为电视显示格式的采集，即不连续的采集，
	   CON/FRAME/CF2/CF1的值为0100 */

	VP_FSETH(vpCaptureHandle, VCACTL, CON, VP_VCACTL_CON_DISABLE);
	VP_FSETH(vpCaptureHandle, VCACTL, FRAME, VP_VCACTL_FRAME_FRMCAP);
	VP_FSETH(vpCaptureHandle, VCACTL, CF2, VP_VCACTL_CF2_NONE);
	VP_FSETH(vpCaptureHandle, VCACTL, CF1, VP_VCACTL_CF1_NONE);

	VP_FSETH(vpCaptureHandle, VCBCTL, CON, VP_VCBCTL_CON_DISABLE);
	VP_FSETH(vpCaptureHandle, VCBCTL, FRAME, VP_VCBCTL_FRAME_FRMCAP);
	VP_FSETH(vpCaptureHandle, VCBCTL, CF2, VP_VCBCTL_CF2_NONE);
	VP_FSETH(vpCaptureHandle, VCBCTL, CF1, VP_VCBCTL_CF1_NONE);
	/* Let FLDD and FINV to be their defaults */

	VP_FSETH(vpCaptureHandle, VCACTL, VRST, VP_VCACTL_VRST_V0EAV);
	/* Set HRST to start of horizontal blanking，行计数复位在EAV之后 */
	VP_FSETH(vpCaptureHandle, VCACTL, HRST, VP_VCACTL_HRST_OF(0));
	/* Set VRST to end of vertical blanking,VCOUNT复位在场消隐之后 */
	VP_FSETH(vpCaptureHandle, VCBCTL, VRST, VP_VCBCTL_VRST_V0EAV);
	/* Set HRST to start of horizontal blanking，行计数复位在EAV之后 */
	VP_FSETH(vpCaptureHandle, VCBCTL, HRST, VP_VCBCTL_HRST_OF(0));
	/* 10.bit pack mode(10BPK bit) in this 8.bit example */
	/* No (1/2) scaling and no chroma re.sampling in this example */
	/*初始化EDMA通路*/
	
	if(portNumber==2){
		IRQ_enable(IRQ_EVT_VINT2);
		/* Enable video port interrupts */
		IRQ_enable(vpCaptureHandle->eventId);
		setupVPCapChaAEDMA(hEdmaVPCapCha2BY,hEdmaVPCapCha2BCb,hEdmaVPCapCha2BCr,portNumber,CHANNELB,vpCaptureHandle,(Uint32)capChaAYSpace3,(Uint32)capChaACbSpace3,(Uint32)capChaACrSpace3);
		setupVPCapChaAEDMA(hEdmaVPCapCha2AY,hEdmaVPCapCha2ACb,hEdmaVPCapCha2ACr,portNumber,CHANNELA,vpCaptureHandle,(Uint32)capChaAYSpace4,(Uint32)capChaACbSpace4,(Uint32)capChaACrSpace4);
		vpCaptureHandle2=vpCaptureHandle;
	}else if(portNumber==0){
		IRQ_enable(IRQ_EVT_VINT0);
		/* Enable video port interrupts */
		IRQ_enable(vpCaptureHandle->eventId);
		setupVPCapChaAEDMA(hEdmaVPCapCha0BY,hEdmaVPCapCha0BCb,hEdmaVPCapCha0BCr,portNumber,CHANNELB,vpCaptureHandle,(Uint32)capChaAYSpace1,(Uint32)capChaACbSpace1,(Uint32)capChaACrSpace1);
		setupVPCapChaAEDMA(hEdmaVPCapCha0AY,hEdmaVPCapCha0ACb,hEdmaVPCapCha0ACr,portNumber,CHANNELA,vpCaptureHandle,(Uint32)capChaAYSpace2,(Uint32)capChaACbSpace2,(Uint32)capChaACrSpace2);
		vpCaptureHandle0=vpCaptureHandle;
	}
	/* Clear VPHLT in VP_CTL to make video port function，清除VPHLT位?
	   使能其它位 */
	VP_FSETH(vpCaptureHandle, VPCTL, VPHLT, VP_VPCTL_VPHLT_CLEAR);
	/* .............. */
	/* enable capture */
	/* .............. */
	VP_FSETH(vpCaptureHandle, VCACTL, VCEN, VP_VCACTL_VCEN_ENABLE);
	/* clear BLKCAP in VCA_CTL to enable capture DMA events */
	VP_FSETH(vpCaptureHandle, VCACTL, BLKCAP,VP_VCACTL_BLKCAP_CLEAR);

	/* set VCEN bit to enable capture，使能VCB口 */
	VP_FSETH(vpCaptureHandle, VCBCTL, VCEN, VP_VCBCTL_VCEN_ENABLE);
	/* clear BLKCAP in VCB_CTL to enable capture DMA events */
	VP_FSETH(vpCaptureHandle, VCBCTL, BLKCAP,VP_VCBCTL_BLKCAP_CLEAR);
	
}
/*******************************************************************/
/* Function : bt656_capture_start    							   */
/* Input(s) : VP_handle									           */
/* Description : Configures given video port for 8.bit BT.656 non. */
/* continuos frame capture on channel A.                           */
/*******************************************************************/
void bt656_capture_start2()
{
    volatile Uint32 *p;  

    /*set VCTL1=1,VCTL0=1  enable  VP2_A and VP2_B Capture */
    p=(Uint32 *)0x01c48020;
    *p=0x00300000;
    p=(Uint32 *)0x01c48024;
    *p=0x00300000;
    p=(Uint32 *)0x01c4802c;
    *p=0x00300000;

}
void bt656_capture_start0()
{
    volatile Uint32 *p;  

    p=(Uint32 *)0x01c40020;//PFUNC
    *p=0x00300000;
    p=(Uint32 *)0x01c40024;//PDIR
    *p=0x00300000;
    p=(Uint32 *)0x01c4002c;//PDOUT
    *p=0x00300000;
	
}
/*................................................................ */
/* Function : VPCapChaAIsr */
/* Description : This capture ISR clears FRMC to continue capture */
/* in this non.continuous mode and also clears other */
/* status bits. */
/*................................................................ */
interrupt void VPCapChaAIsr0(void)
{
	Uint32 vpis = 0;
	/* Get video port status register value */
	vpis = VP_RGETH(vpCaptureHandle0, VPIS);
	if(vpis & _VP_VPIS_CCMPA_MASK) /* capture complete */
	{
		/* Clear frame complete bit in VCX_CTL to continue capture in non-continuous mode*/
		VP_FSETH(vpCaptureHandle0, VCASTAT, FRMC,VP_VCASTAT_FRMC_CLEAR);
		/* Clear CCMPA to enable next frame complete interrupts*/
		VP_FSETH(vpCaptureHandle0, VPIS, CCMPA,VP_VPIS_CCMPA_CLEAR);
		capChaAFrameCount0A++; /* increment captured frame count */
		capNewFrame0A = 1;
	}
	if(vpis & _VP_VPIS_COVRA_MASK) /* overrun error */
	{
		capChaAOverrun0A++;
		VP_FSETH(vpCaptureHandle0, VPIS, COVRA,VP_VPIS_COVRA_CLEAR);
	}
	if(vpis & _VP_VPIS_SERRA_MASK) /* synchronization error */
	{
		capChaASyncError0A++;
		VP_FSETH(vpCaptureHandle0, VPIS, SERRA,VP_VPIS_SERRA_CLEAR);
	}
	if(vpis & _VP_VPIS_SFDA_MASK) /* short field detect */
	{
		capChaAShortFieldDetect0A++;
		VP_FSETH(vpCaptureHandle0, VPIS, SFDA, VP_VPIS_SFDA_CLEAR);
	}
	if(vpis & _VP_VPIS_LFDA_MASK) /* long field detect */
	{
		capChaALongFieldDetect0A++;
		VP_FSETH(vpCaptureHandle0, VPIS, LFDA, VP_VPIS_LFDA_CLEAR);
	}
	
	if(vpis & _VP_VPIS_CCMPB_MASK) /* capture complete */
	{
		/* Clear frame complete bit in VCX_CTL to continue capture in non-continuous mode*/
		VP_FSETH(vpCaptureHandle0, VCBSTAT, FRMC,VP_VCBSTAT_FRMC_CLEAR);
		/* Clear CCMPA to enable next frame complete interrupts*/
		VP_FSETH(vpCaptureHandle0, VPIS, CCMPB,VP_VPIS_CCMPB_CLEAR);
		capChaAFrameCount0B++; /* increment captured frame count */
		capNewFrame0B = 1;
	}
	if(vpis & _VP_VPIS_COVRB_MASK) /* overrun error */
	{
		capChaAOverrun0B++;
		VP_FSETH(vpCaptureHandle0, VPIS, COVRB,VP_VPIS_COVRB_CLEAR);
	}
	if(vpis & _VP_VPIS_SERRB_MASK) /* synchronization error */
	{
		capChaASyncError0B++;
		VP_FSETH(vpCaptureHandle0, VPIS, SERRB,VP_VPIS_SERRB_CLEAR);
	}
	if(vpis & _VP_VPIS_SFDB_MASK) /* short field detect */
	{
		capChaAShortFieldDetect0B++;
		VP_FSETH(vpCaptureHandle0, VPIS, SFDB, VP_VPIS_SFDB_CLEAR);
	}
	if(vpis & _VP_VPIS_LFDB_MASK) /* long field detect */
	{
		capChaALongFieldDetect0B++;
		VP_FSETH(vpCaptureHandle0, VPIS, LFDB, VP_VPIS_LFDB_CLEAR);
	}

}
interrupt void VPCapChaAIsr2(void)
{
	Uint32 vpis = 0;
	/* Get video port status register value */
	vpis = VP_RGETH(vpCaptureHandle2, VPIS);
	if(vpis & _VP_VPIS_CCMPB_MASK) /* capture complete */
	{
		/* Clear frame complete bit in VCX_CTL to continue capture in non-continuous mode*/
		VP_FSETH(vpCaptureHandle2, VCBSTAT, FRMC,VP_VCBSTAT_FRMC_CLEAR);
		/* Clear CCMPA to enable next frame complete interrupts*/
		VP_FSETH(vpCaptureHandle2, VPIS, CCMPB,VP_VPIS_CCMPB_CLEAR);
		capChaAFrameCount2B++; /* increment captured frame count */
		capNewFrame2B = 1;
	}
	if(vpis & _VP_VPIS_COVRB_MASK) /* overrun error */
	{
		capChaAOverrun2B++;
		VP_FSETH(vpCaptureHandle2, VPIS, COVRB,VP_VPIS_COVRB_CLEAR);
	}
	if(vpis & _VP_VPIS_SERRB_MASK) /* synchronization error */
	{
		capChaASyncError2B++;
		VP_FSETH(vpCaptureHandle2, VPIS, SERRB,VP_VPIS_SERRB_CLEAR);
	}
	if(vpis & _VP_VPIS_SFDB_MASK) /* short field detect */
	{
		capChaAShortFieldDetect2B++;
		VP_FSETH(vpCaptureHandle2, VPIS, SFDB, VP_VPIS_SFDB_CLEAR);
	}
	if(vpis & _VP_VPIS_LFDB_MASK) /* long field detect */
	{
		capChaALongFieldDetect2B++;
		VP_FSETH(vpCaptureHandle2, VPIS, LFDB, VP_VPIS_LFDB_CLEAR);
	}


	if(vpis & _VP_VPIS_CCMPA_MASK) /* capture complete */
	{
		/* Clear frame complete bit in VCX_CTL to continue capture in non-continuous mode*/
		VP_FSETH(vpCaptureHandle2, VCASTAT, FRMC,VP_VCASTAT_FRMC_CLEAR);
		/* Clear CCMPA to enable next frame complete interrupts*/
		VP_FSETH(vpCaptureHandle2, VPIS, CCMPA,VP_VPIS_CCMPA_CLEAR);
		capChaAFrameCount2A++; /* increment captured frame count */
		capNewFrame2A = 1;
	}
	if(vpis & _VP_VPIS_COVRA_MASK) /* overrun error */
	{
		capChaAOverrun2A++;
		VP_FSETH(vpCaptureHandle2, VPIS, COVRA,VP_VPIS_COVRA_CLEAR);
	}
	if(vpis & _VP_VPIS_SERRA_MASK) /* synchronization error */
	{
		capChaASyncError2A++;
		VP_FSETH(vpCaptureHandle2, VPIS, SERRA,VP_VPIS_SERRA_CLEAR);
	}
	if(vpis & _VP_VPIS_SFDA_MASK) /* short field detect */
	{
		capChaAShortFieldDetect2A++;
		VP_FSETH(vpCaptureHandle2, VPIS, SFDA, VP_VPIS_SFDA_CLEAR);
	}
	if(vpis & _VP_VPIS_LFDA_MASK) /* long field detect */
	{
		capChaALongFieldDetect2A++;
		VP_FSETH(vpCaptureHandle2, VPIS, LFDA, VP_VPIS_LFDA_CLEAR);
	}
}
/*................................................................ */
/* Function : setupVPCapChaAEDMA(Int32 portNumber) */
/* Input(s) : portNumber, video port number i.e. 0, 1 or 2. */
/* Description : Sets up EDMA channels for Y, U, V events for */
/* channel A capture. */
/*功能描述：将为Y，U，V建立EDMA的通路*/
/*................................................................ */
void setupVPCapChaAEDMA(EDMA_Handle hEdmaVPCapChaY,EDMA_Handle hEdmaVPCapChaCb,EDMA_Handle hEdmaVPCapChaCr,int portNumber,int channelNumber,VP_Handle vpCaptureHandle,Uint32 capPlaceY,Uint32 capPlaceCb,Uint32 capPlaceCr)
{
	Int32 YEvent, UEvent, VEvent;
	/* get channelA Y, U, V EDMA event numbers，选择触发事件 */
	if(channelNumber==CHANNELB){
		switch(portNumber)
		{
			/*确定相应的DMA通路*/
			case VP_DEV0: 
				YEvent = EDMA_CHA_VP0EVTYB;
				UEvent = EDMA_CHA_VP0EVTUB;
				VEvent = EDMA_CHA_VP0EVTVB;
				break;
			case VP_DEV1: 
				YEvent = EDMA_CHA_VP1EVTYB;
				UEvent = EDMA_CHA_VP1EVTUB;
				VEvent = EDMA_CHA_VP1EVTVB;
				break;
			case VP_DEV2: 
				YEvent = EDMA_CHA_VP2EVTYB;
				UEvent = EDMA_CHA_VP2EVTUB;
				VEvent = EDMA_CHA_VP2EVTVB;
				break;
		}
		configVPCapEDMAChannel( &hEdmaVPCapChaY, YEvent,
							
							vpCaptureHandle->ysrcbAddr,
							capPlaceY,
							VCB_Y_EDMA_FRMCNT,
							VCB_Y_EDMA_ELECNT);

		configVPCapEDMAChannel( &hEdmaVPCapChaCb, UEvent,
								
								vpCaptureHandle->cbsrcbAddr,
								capPlaceCb,
								VCB_Y_EDMA_FRMCNT,
								VCB_Y_EDMA_ELECNT/2); 

		configVPCapEDMAChannel( &hEdmaVPCapChaCr, VEvent,
								
								vpCaptureHandle->crsrcbAddr,
								capPlaceCr,
								VCB_Y_EDMA_FRMCNT,
								VCB_Y_EDMA_ELECNT/2);
	}else if(channelNumber==CHANNELA){
		switch(portNumber)
		{
			/*确定相应的DMA通路*/
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
		configVPCapEDMAChannel( &hEdmaVPCapChaY, YEvent,
							
							vpCaptureHandle->ysrcaAddr,
							capPlaceY,
							VCB_Y_EDMA_FRMCNT,
							VCB_Y_EDMA_ELECNT);

		configVPCapEDMAChannel( &hEdmaVPCapChaCb, UEvent,
								
								vpCaptureHandle->cbsrcaAddr,
								capPlaceCb,
								VCB_Y_EDMA_FRMCNT,
								VCB_Y_EDMA_ELECNT/2); 

		configVPCapEDMAChannel( &hEdmaVPCapChaCr, VEvent,
								
								vpCaptureHandle->crsrcaAddr,
								capPlaceCr,
								VCB_Y_EDMA_FRMCNT,
								VCB_Y_EDMA_ELECNT/2);

	}

	 
	/* Enable three EDMA channels */
	EDMA_enableChannel(hEdmaVPCapChaY);
	EDMA_enableChannel(hEdmaVPCapChaCb);
	EDMA_enableChannel(hEdmaVPCapChaCr);
}
void configVPCapEDMAChannel(EDMA_Handle *edmaHandle, 
							Int32 eventId,
							Uint32 srcAddr,
							Uint32 dstAddr, 
							Uint32 frameCount,
							Uint32 elementCount)
{
	Int32 tcc = 0;
	EDMA_Handle hEdmaTable;
	/* Open Y EVT EDMA channel */
	*edmaHandle = EDMA_open(eventId, EDMA_OPEN_RESET);
	if(*edmaHandle == EDMA_HINV)
	{
		for(;;){}
	}	
	/* allocate TCC for Y event */
	if((tcc = EDMA_intAlloc(-1)) == -1)
	{
		for(;;){}
	}
	/*打开一个新的EDMA链接*/
	hEdmaTable = EDMA_allocTable(-1);
	/* Configure EDMA parameters */
	EDMA_configArgs(
		*edmaHandle,
		EDMA_OPT_RMK(EDMA_OPT_PRI_MEDIUM, /* medium priority 设置优先级为中*/
					 EDMA_OPT_ESIZE_32BIT, /* Element size 32 bits 元素的长度为4个Byte*/
					 EDMA_OPT_2DS_NO, /* 1.dimensional source(FIFO) 源采用固定的方试*/
					 EDMA_OPT_SUM_NONE, /* fixed src address mode(FIFO) 源地址不变*/
					 EDMA_OPT_2DD_YES, /* 2.dimensional destination 目的采用2维空间的组成*/
					 EDMA_OPT_DUM_INC, /* destination increment 目的采用增长的方式*/
					 EDMA_OPT_TCINT_YES, /* Enable transfer complete indication，使能传送结束指示*/
					 EDMA_OPT_TCC_OF(tcc & 0xF),/*设置完成标志CIP0的低位*/
					 EDMA_OPT_TCCM_OF(((tcc & 0x30) >> 4)),/*设置完成标志CIP0的高位*/
					 EDMA_OPT_ATCINT_NO, /* Disable Alternate Transfers 禁止交替传送 */
					 EDMA_OPT_ATCC_OF(0),/* Complete Interrupt 未使用交替完标志 */
					 EDMA_OPT_PDTS_DISABLE, /* disable PDT(peripheral device transfer) mode for source */
					 EDMA_OPT_PDTD_DISABLE, /* disable PDT mode for dest */
					 EDMA_OPT_LINK_YES, /* Disable linking */
					 EDMA_OPT_FS_NO), /* Array synchronization 阵列同步*/
		EDMA_SRC_RMK(srcAddr),
		EDMA_CNT_RMK(EDMA_CNT_FRMCNT_OF((frameCount-1)),
					 EDMA_CNT_ELECNT_OF(elementCount)),
		EDMA_DST_RMK(dstAddr),
		EDMA_IDX_RMK(EDMA_IDX_FRMIDX_OF((elementCount * 4)),
		         	 EDMA_IDX_ELEIDX_OF(0)), 
		
		EDMA_RLD_RMK(EDMA_RLD_ELERLD_OF(0), EDMA_RLD_LINK_OF(0))
	);
	EDMA_configArgs(
		hEdmaTable,
		EDMA_OPT_RMK(EDMA_OPT_PRI_MEDIUM, 
					 EDMA_OPT_ESIZE_32BIT, 
					 EDMA_OPT_2DS_NO, 
					 EDMA_OPT_SUM_NONE, 
					 EDMA_OPT_2DD_YES, 
					 EDMA_OPT_DUM_INC, 
					 EDMA_OPT_TCINT_YES,
					 EDMA_OPT_TCC_OF(tcc & 0xF),
					 EDMA_OPT_TCCM_OF(((tcc & 0x30) >> 4)),
					 EDMA_OPT_ATCINT_NO, 
					 EDMA_OPT_ATCC_OF(0),
					 EDMA_OPT_PDTS_DISABLE, 
					 EDMA_OPT_PDTD_DISABLE, 
					 EDMA_OPT_LINK_YES, 
					 EDMA_OPT_FS_NO), 
		EDMA_SRC_RMK(srcAddr),
		EDMA_CNT_RMK(EDMA_CNT_FRMCNT_OF((frameCount-1)),
					 EDMA_CNT_ELECNT_OF(elementCount)),
		EDMA_DST_RMK(dstAddr),
		EDMA_IDX_RMK(EDMA_IDX_FRMIDX_OF((elementCount * 4)),
		         	 EDMA_IDX_ELEIDX_OF(0)),
		EDMA_RLD_RMK(EDMA_RLD_ELERLD_OF(0), EDMA_RLD_LINK_OF(0))
	);

	EDMA_link(*edmaHandle,hEdmaTable);

	EDMA_link(hEdmaTable,hEdmaTable);
}
