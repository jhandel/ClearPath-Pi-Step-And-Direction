#ifndef _BCM_2835_DRV_
#define _BCM_2835_DRV_

#include <bcm2835.h>
#include <stdint.h>
#include <stdio.h>

/**
 * data
**/
#define UBYTE   uint8_t
#define UWORD   uint16_t
#define UDOUBLE uint32_t

/**
 * GPIO config
**/
#define DEV_ENABLE_PIN     23
#define DEV_INPUT_A_PIN     24
#define DEV_INPUT_B_PIN     25
#define DEV_pin_config(_pin, _use) bcm2835_gpio_fsel(_pin, _use) 

/**
 * GPIO read and write
**/
#define DEV_Digital_Write(_pin, _value) bcm2835_gpio_write(_pin, _value)
#define DEV_Digital_Read(_pin) bcm2835_gpio_lev(_pin)

/**
 * SPI
**/
#define DEV_SPI_WriteByte(__value) bcm2835_spi_transfer(__value)
#define DEV_SPI_ReadByte() bcm2835_spi_transfer(0xff)
/**
 * delay x ms
**/
#define DEV_Delay_ms(__xms) bcm2835_delay(__xms)
#define DEV_Delay_us(__xms) bcm2835_delayMicroseconds(__xms)

#define DEV_ModuleInit() bcm2835_init();
#define DEV_ModuleExit() bcm2835_close();

/*------------------------------------------------------------------------------------------------------*/

#endif