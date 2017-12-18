
/********************************************************************/
/* _TVP51XX.c file                                                      */
/********************************************************************/

#include <csl_i2c.h>
#include  <csl_gpio.h>
#include "iic.h"
#include "_tvp51xx.h"

extern GPIO_Handle hGpio;
extern I2C_Handle dm642i2c; 
_TVP51XX_Regs _TVP51XX_settingsDef[2]=
{
{
/* addr 00h - 07h */
	0,0,0,0,0,
	1,1,1,
	0,0,0,0,0,0,0,
	1,0,0,1,0,1,1,0,
	0,0,0,0,0,0,
	0,0,
	0x10,0,0,
	0,0,1,0,0,
/* addr 08h - 0fh */
	0,0,0,0,0,
	0x80,
	0x80,
	0,
	0x80,
	7,0,0,1,0,
	0,0,
	0,0,0,1,0,0,0,0,
	/* addr 10h - 17h */
	0,
	0,
	0,0,0,
	0,
	0,0,
	1,0,1,0,0,0,
	0x80,
	0,
	/* addr 18h - 1fh */
	0,
	0,
	0,1,1,0,0,
	0,1,0,1,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,
	0,
	/* addr 20h - 27h */
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	/* addr 28h - 2fh */
	0,0,
	0,
	0,
	0,
	0,
	0,
	0x15,
	0x01,
	/* addr 30h - 7fh */
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	/* addr 80h - 87h */
	0x51,
	0x50,
	0x03,
	0x21,
	0,0,
	0,
	0,
	0,
	/* addr 88h - ffh */
		0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0
},
{
/* addr 00h - 07h */
	0,0,0,0,0,
	1,1,1,
	0,0,0,0,0,0,0,
	1,0,0,1,0,1,1,0,
	0,0,0,0,0,0,
	0,0,
	0x10,0,0,
	0,0,1,0,0,
/* addr 08h - 0fh */
	0,0,0,0,0,
	0x80,
	0x80,
	0,
	0x80,
	7,0,0,1,0,
	0,0,
	0,0,0,1,0,0,0,0,
	/* addr 10h - 17h */
	0,
	0,
	0,0,0,
	0,
	0,0,
	1,0,1,0,0,0,
	0x80,
	0,
	/* addr 18h - 1fh */
	0,
	0,
	0,1,1,0,0,
	0,1,0,1,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,
	0,
	/* addr 20h - 27h */
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	/* addr 28h - 2fh */
	0,0,
	0,
	0,
	0,
	0,
	0,
	0x15,
	0x01,
	/* addr 30h - 7fh */
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	/* addr 80h - 87h */
	0x51,
	0x50,
	0x03,
	0x21,
	0,0,
	0,
	0,
	0,
	/* addr 88h - ffh */
		0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0
}

};

void TVP51XX_Set(Uint8 Chanel)
{
   Uint8 addrI2C;
   switch(Chanel)
  {
   case 1:  GPIO_pinWrite(hGpio,GPIO_PIN1,0);
            addrI2C=0xBA>>1;
            _IIC_write(dm642i2c, addrI2C,0x00, 00);
            _IIC_write(dm642i2c, addrI2C,0x03, 0x6f);
            _IIC_write(dm642i2c, addrI2C,0x06, 0x6f); //6f
            _IIC_write(dm642i2c, addrI2C,0x07, 0x67);
            _IIC_write(dm642i2c, addrI2C,0x08, 0x4f);
            _IIC_write(dm642i2c, addrI2C,0x09, 0x64);
            _IIC_write(dm642i2c, addrI2C,0x0a, 0x64);
            _IIC_write(dm642i2c, addrI2C,0x0c, 0x80);
            _IIC_write(dm642i2c, addrI2C,0x0D, 71);
            _IIC_write(dm642i2c, addrI2C,0x1B, 20);
            break;
   case 2:  GPIO_pinWrite(hGpio,GPIO_PIN1,0);
            addrI2C=0xB8>>1;
			_IIC_write(dm642i2c, addrI2C,0x00, 00);
            _IIC_write(dm642i2c, addrI2C,0x03, 0x6f);
            _IIC_write(dm642i2c, addrI2C,0x06, 0x6f); //6f
            _IIC_write(dm642i2c, addrI2C,0x07, 0x67);
            _IIC_write(dm642i2c, addrI2C,0x08, 0x4f);
            _IIC_write(dm642i2c, addrI2C,0x09, 0x64);
            _IIC_write(dm642i2c, addrI2C,0x0a, 0x64);
            _IIC_write(dm642i2c, addrI2C,0x0c, 0x80);
            _IIC_write(dm642i2c, addrI2C,0x0D, 71);
            _IIC_write(dm642i2c, addrI2C,0x1B, 20);
			break;
   case 3:  GPIO_pinWrite(hGpio,GPIO_PIN1,1);
            addrI2C=0xBA>>1;
			_IIC_write(dm642i2c, addrI2C,0x00, 00);
            _IIC_write(dm642i2c, addrI2C,0x03, 0x6f);
            _IIC_write(dm642i2c, addrI2C,0x06, 0x6f); //6f
            _IIC_write(dm642i2c, addrI2C,0x07, 0x67);
            _IIC_write(dm642i2c, addrI2C,0x08, 0x4f);
            _IIC_write(dm642i2c, addrI2C,0x09, 0x64);
            _IIC_write(dm642i2c, addrI2C,0x0a, 0x64);
            _IIC_write(dm642i2c, addrI2C,0x0c, 0x80);
            _IIC_write(dm642i2c, addrI2C,0x0D, 71);
            _IIC_write(dm642i2c, addrI2C,0x1B, 20);
            break;
   case 4:  GPIO_pinWrite(hGpio,GPIO_PIN1,1);
            addrI2C=0xB8>>1;
			_IIC_write(dm642i2c, addrI2C,0x00, 00);
            _IIC_write(dm642i2c, addrI2C,0x03, 0x6f);
            _IIC_write(dm642i2c, addrI2C,0x06, 0x6f); //6f
            _IIC_write(dm642i2c, addrI2C,0x07, 0x67);
            _IIC_write(dm642i2c, addrI2C,0x08, 0x4f);
            _IIC_write(dm642i2c, addrI2C,0x09, 0x64);
            _IIC_write(dm642i2c, addrI2C,0x0a, 0x64);
            _IIC_write(dm642i2c, addrI2C,0x0c, 0x80);
            _IIC_write(dm642i2c, addrI2C,0x0D, 71);
            _IIC_write(dm642i2c, addrI2C,0x1B, 20);
            break;
   default: break;
  }
}


/********************************************************************/
/* end of file                                                      */
/********************************************************************/

