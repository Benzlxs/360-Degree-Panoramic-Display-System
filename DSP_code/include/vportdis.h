#include <csl_vp.h>
#include <csl_edma.h>
#include <csl_irq.h>
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
/* robin,¡­etc. */
/*................................................................ */
void configVPDispEDMAChannel( EDMA_Handle *edmaHandle,
							  Int32 eventId, Int32 *tccNum,
							  Uint32 srcAddr, Uint32 dstAddr,
							  Uint32 frameCount, Uint32 elementCount);
/*................................................................ */
/* Function : setupVPDispEDMA */
/* Input(s) : portNumber, video port number i.e. 0,1 or 2. */
/* Description : Sets up DMA channels for Y, U, V events for VP */
/* display. */
/*................................................................ */
void setupVPDispEDMA(Int32 portNumber);
/*................................................................ */
/* Function : VPDispIsr */
/* Description : This display ISR clears FRMD to continue display */
/* in this non.continuous mode and also clears other */
/* status bits. */
/*................................................................ */
interrupt void VPDispIsr(void);
/*................................................................ */
/* Function : bt656_display_start */
/* Input(s) : VP_Handle*/
/* Description : Configures given video port for 8.bit BT.656 non. */
/* continuous frame display. */
/*................................................................ */
void bt656_display_start(VP_Handle videohandle);
/*................................................................ */
/* Function : bt656_8bit_ncfd */
/* Input(s) : portNumber, video port number i.e. 0, 1 or 2. */
/* Description : Configures given video port for 8.bit BT.656 non. */
/* continuous frame display. */
/*................................................................ */
VP_Handle bt656_8bit_ncfd(int portNumber);

