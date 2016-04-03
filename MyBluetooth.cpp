/*
 * MyBluetooth.cpp
 *
 *  Created on: Apr 1, 2016
 *      Author: Phan Vu Hoang
 */

#include "MyBluetooth.hpp"

MyBluetooth::MyBluetooth(int pinTx, int pinRx) {
	myTx = mraa_uart_init(pinTx);
	myRx = mraa_uart_init(pinRx);
	 mraa_uart_set_baudrate(myTx, BAUD_RATE);
	 mraa_uart_set_baudrate(myRx, BAUD_RATE);
	 mraa_uart_set_mode(myTx, BYTESIZE, MRAA_UART_PARITY_NONE, STOP_BITS);
	 mraa_uart_set_mode(myRx, BYTESIZE, MRAA_UART_PARITY_NONE, STOP_BITS);
	 mraa_uart_flush(myTx);
	 mraa_uart_flush(myRx);
}

std::string MyBluetooth::read(int length) {
	char* data = (char*)malloc(sizeof(char)* length);
	int v = mraa_uart_read(myRx, data, (size_t)length);
	std::string ret(data, v);
	free(data);
	return ret;
}

MyBluetooth::~MyBluetooth() {
	mraa_uart_stop(myTx);
	mraa_uart_stop(myRx);
}

