/*!
   \file i2c.h
   \brief I2C Serial comunication library
   \author Varius Unknown authors
	 \author Davide Bortolami
	 \copyright Unknown authors
	 \copyright (c) 2017 - Fermium LABS srl
*/

#ifndef FRM_I2C_H
#define	FRM_I2C_H

#define I2C_READ 0x01
#define I2C_WRITE 0x00

#include <avr/io.h>
#include <util/twi.h>


#define F_SCL 100000UL /*!< SCL frequency */

#define Prescaler 1
#define TWBR_val ((((F_CPU / F_SCL) / Prescaler) - 16 ) / 2) /*!< the TWBR registers sets the speed of TWI comunication */

void i2c_init(void);

uint8_t i2c_start(uint8_t address);

uint8_t i2c_write(uint8_t data);

uint8_t i2c_read_ack(void);

uint8_t i2c_read_nack(void);

uint8_t i2c_transmit(uint8_t address, uint8_t* data, uint16_t length);

uint8_t i2c_receive(uint8_t address, uint8_t* data, uint16_t length);

uint8_t i2c_writeReg(uint8_t devaddr, uint8_t regaddr, uint8_t* data, uint16_t length);

uint8_t i2c_readReg(uint8_t devaddr, uint8_t regaddr, uint8_t* data, uint16_t length);

void i2c_stop(void);

#endif
