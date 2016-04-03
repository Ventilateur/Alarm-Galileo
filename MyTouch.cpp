/*
 * MyTouch.cpp
 *
 *  Created on: Mar 29, 2016
 *      Author: Phan Vu Hoang
 */

#include "MyTouch.hpp"


MyTouch::MyTouch(int pin) {
	MyTouch::state = false;
	myTouch = mraa_gpio_init(pin);
	mraa_gpio_dir(myTouch, MRAA_GPIO_IN);
	mraa_gpio_isr(myTouch, MRAA_GPIO_EDGE_BOTH, &edgeDetect, (void*)this);
}

// void* is a special pointer that can be pointed at an object of any type
void MyTouch::edgeDetect(void *ctx) {
	MyTouch *thisObj = (MyTouch*)ctx;
	if (thisObj->read() == 0) {
		thisObj->state = !thisObj->state;
	}
}

bool MyTouch::getState() {
	return MyTouch::state;
}

int MyTouch::read() {
	return mraa_gpio_read(myTouch);
}

MyTouch::~MyTouch() {
	mraa_gpio_close(myTouch);
}

