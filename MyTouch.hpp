/*
 * MyTouch.hpp
 *
 *  Created on: Mar 29, 2016
 *      Author: Phan Vu Hoang
 */

#ifndef MYTOUCH_HPP_
#define MYTOUCH_HPP_

#include <mraa/gpio.h>
#include <unistd.h>


class MyTouch {
public:
	MyTouch(int pin);
	bool getState();
	int read();
	~MyTouch();
private:
	mraa_gpio_context myTouch;
	static void edgeDetect(void* ctx);
	bool state;
};

#endif /* MYTOUCH_HPP_ */
