/*
 * MyBluetooth.hpp
 *
 *  Created on: Apr 1, 2016
 *      Author: Phan Vu Hoang
 */

#ifndef MYBLUETOOTH_HPP_
#define MYBLUETOOTH_HPP_

#include <mraa/uart.h>
#include <string>
#include <stdlib.h>

#define BAUD_RATE	9600
#define BYTESIZE	8
#define STOP_BITS	1

class MyBluetooth {
public:
	MyBluetooth(int pinTx, int pinRx);
	std::string read(int length);
	void write(std::string data);
	~MyBluetooth();
private:
	mraa_uart_context myTx;
	mraa_uart_context myRx;
};

#endif /* MYBLUETOOTH_HPP_ */
