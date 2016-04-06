#pragma once

#ifndef LCD_HPP_
#define LCD_HPP_

#include <mraa/i2c.h>
#include <unistd.h>
#include <iostream>
#include <string>

#define DEFAULT_I2C_BUS			0

#define LCD_CTRL_ADR			0x3E
#define RGB_CTRL_ADR			0x62

#define LCD_CLEARDISPLAY 		0x01
#define LCD_ENTRYMODESET 		0x04
#define LCD_FUNCTIONSET 		0x20
#define LCD_DATA 				0x40
#define LCD_CMD 				0x80
#define LCD_DISPLAYCONTROL 		0x08
#define LCD_DISPLAYON 			0x04

#define LCD_ENTRYLEFT 			0x02
#define LCD_ENTRYSHIFTDECREMENT 0x00

#define LCD_2LINE 				0x08

class Lcd {
public:
	Lcd();
	~Lcd();
	void writeMsg(std::string msg);
	void setColor(int r, int g, int b);
	void setPos(int row, int col);
	void display(bool val);
private:
	mraa_i2c_context myLcd;
	mraa_i2c_context myRgb;
	void writeCmd(mraa_i2c_context ctx, uint8_t val);
	void writeData(mraa_i2c_context ctx, uint8_t val);
	void writeReg(mraa_i2c_context ctx, int devAdr, uint8_t adr, uint8_t val);
};

#endif /* LCD_HPP_ */
