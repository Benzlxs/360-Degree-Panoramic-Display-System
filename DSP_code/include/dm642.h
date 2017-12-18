

/*
 *  ======== dm642.h ========
 *
 *  This file contains DM642 board initialization functions.
 *
 *  DM642 BSL Version 1.00 - 08/02/2005
 *
 */

#ifndef DM642_
#define DM642_

#ifdef __cplusplus
extern "C" {
#endif

#include <csl.h>
#include <csl_i2c.h>
#include <csl_gpio.h>

/*
 *  Note:  Bit definitions for each register field
 *         needs to be supplied here for the CPLD
 *	       and other board periperals.
 */

/* Compatability definitions */
#define NULL                 0


/* I2C handle */
extern I2C_Handle DM642_I2C_hI2C;


/* Spin in a delay loop for delay iterations */
void DM642_wait(Uint32 delay);

/* Spin in a delay loop for delay microseconds */
void DM642_waitusec(Uint32 delay);

void DPM642_init();


#ifdef __cplusplus
}
#endif

#endif
