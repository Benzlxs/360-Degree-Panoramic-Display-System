
/* "@(#) DDK 1.10.00.23 07-02-03 (ddk-b12)" */
/* "@(#) Driver Patch number 1.00.01" */
/********************************************************************************/
/* tvp51xx.h file */
/********************************************************************************/
#ifndef _TVP51XX_H
#define _TVP51XX_H

#include <csl_i2c.h>
#include <std.h>
#include <csl_stdinc.h>

typedef enum TVP51XX_AnalogFormat {
    TVP51XX_AFMT_COMPOSITE,
    TVP51XX_AFMT_SVIDEO,
    TVP51XX_AFMT_RGB,
    TVP51XX_AFMT_YPBPR

} TVP51XX_AnalogFormat;

typedef enum TVP51XX_Mode {
    TVP51XX_MODE_NTSC601,
    TVP51XX_MODE_NTSCSqp,
    TVP51XX_MODE_PAL601,
    TVP51XX_MODE_PALSqp,
    TVP51XX_MODE_USER
}TVP51XX_Mode;


typedef unsigned int TVP51XX_Cmd;

#define TVP51XX_POWERDOWN           EDC_USER+1
#define TVP51XX_POWERUP             EDC_USER+2      
#define TVP51XX_SET_AMUXMODE        EDC_USER+3

#define TVP51XX_NTSCM     			0x81
#define TVP51XX_PALBGHIN    		0x83
#define TVP51XX_PALM				0x85
#define TVP51XX_COMBINATION-N 		0x87
#define TVP51XX_NTSC443         	0x89 


typedef struct {
    TVP51XX_Mode videoMode;
    TVP51XX_AnalogFormat aFmt;
    Bool enableBT656Sync;
    int inputPort;
    I2C_Handle hI2C;
} TVP51XX_ConfParams;

#endif 

