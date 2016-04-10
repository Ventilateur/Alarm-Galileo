#include "Lcd.hpp"

Lcd::Lcd() {

	myLcd = mraa_i2c_init(DEFAULT_I2C_BUS);
	mraa_i2c_address(myLcd, LCD_CTRL_ADR);

	myRgb = mraa_i2c_init(DEFAULT_I2C_BUS);
	mraa_i2c_address(myRgb, RGB_CTRL_ADR);

	usleep(50000);
	writeCmd(myLcd, LCD_FUNCTIONSET | LCD_2LINE);
    usleep(4500);
	writeCmd(myLcd, LCD_FUNCTIONSET | LCD_2LINE);
    usleep(4500);
	writeCmd(myLcd, LCD_FUNCTIONSET | LCD_2LINE);
    usleep(4500);
	writeCmd(myLcd, LCD_FUNCTIONSET | LCD_2LINE);
	Lcd::display(false);
	writeCmd(myLcd, LCD_CLEARDISPLAY);
	usleep(4500);
	writeCmd(myLcd, LCD_ENTRYMODESET | LCD_ENTRYLEFT | LCD_ENTRYSHIFTDECREMENT);

	Lcd::setColor(255, 255, 255);

}

void Lcd::writeMsg(std::string msg) {
	for (std::string::size_type i = 0; i < msg.size(); ++i) {
		Lcd::writeData(myLcd, msg[i]);
	}
}

void Lcd::setPos(int row, int col) {
	int row_addr[] = { 0x80, 0xc0, 0x14, 0x54};
	uint8_t offset = ((col % 16) + row_addr[row]);
	writeCmd(myLcd, offset);
}

void Lcd::setColor(int r, int g, int b) {
	writeReg(myRgb, RGB_CTRL_ADR, 0x00, 0x00);
	writeReg(myRgb, RGB_CTRL_ADR, 0x01, 0x00);
	writeReg(myRgb, RGB_CTRL_ADR, 0x08, 0xAA);

	writeReg(myRgb, RGB_CTRL_ADR, 0x04, r);
	writeReg(myRgb, RGB_CTRL_ADR, 0x03, g);
	writeReg(myRgb, RGB_CTRL_ADR, 0x02, b);
}

void Lcd::writeData(mraa_i2c_context ctx, uint8_t val) {
	uint8_t data[2] = {LCD_DATA, val};
	mraa_i2c_address(ctx, LCD_CTRL_ADR);
	mraa_i2c_write(ctx, data, 2);
}

void Lcd::display(bool val) {
	int mask = 0x00;
	if (val) {
		mask |=  LCD_DISPLAYON;
		writeCmd(myLcd, LCD_DISPLAYCONTROL | mask);
	} else {
		mask &= ~LCD_DISPLAYON;
		writeCmd(myLcd, LCD_DISPLAYCONTROL | mask);
	}
}

void Lcd::writeCmd(mraa_i2c_context ctx, uint8_t val) {
	uint8_t data[2] = {LCD_CMD, val};
	mraa_i2c_address(ctx, LCD_CTRL_ADR);
	mraa_i2c_write(ctx, data, 2);
}

void Lcd::writeReg(mraa_i2c_context ctx, int devAdr, uint8_t adr, uint8_t val) {
	uint8_t data[2] = {adr, val};
	mraa_i2c_address (ctx, devAdr);
	mraa_i2c_write (ctx, data, 2);
}

Lcd::~Lcd() {
	mraa_i2c_stop(myLcd);
	mraa_i2c_stop(myRgb);
}

