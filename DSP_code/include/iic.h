
#ifndef _IIC_H  
#define _IIC_H

#include <std.h>
#include <csl_stdinc.h>
#include <csl_i2c.h>

#ifdef __cplusplus
extern "C" {
#endif

void _IIC_write(I2C_Handle hI2C,
              Uint8   devAddress,
              Uint32  subAddress,
              Uint8   data
              );
/*
 * ======== _IIC_read ========
 * This function performs read from operation via I2C bus.
 */

void _IIC_read(I2C_Handle hI2C,
              Uint8 devAddress,
              Uint32  subAddress,
              Uint8 *data
              );


#ifdef __cplusplus
}
#endif

#endif

