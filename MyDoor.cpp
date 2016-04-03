/*
 * MyDoor.cpp
 *
 *  Created on: Mar 25, 2016
 *      Author: Phan Vu Hoang
 */

#include <iostream>
#include <unistd.h>
#include "MyDoor.hpp"

MyDoor::MyDoor(int pin) {
	myDoor = mraa_pwm_init(pin);
	MyDoor::open();
}

void MyDoor::open() {
	if (!isOpen) {
		MyDoor::setAngle(120);
		isOpen = true;
	}
}

void MyDoor::close() {
	if (isOpen) {
		MyDoor::setAngle(30);
		isOpen = false;
	}
}

mraa_result_t MyDoor::enable(int en) {
	return mraa_pwm_enable(myDoor, en);
}

void MyDoor::setAngle(int ang) {
	int ang2us;
	MyDoor::enable(HIGH);
	mraa_pwm_period_us(myDoor, PERIOD);
	if (ang > 180) {
		ang2us = MAX_PULSE_WIDTH;
	} else if (ang < 0) {
		ang2us = MIN_PULSE_WIDTH;
	} else {
		ang2us = (int)((float)MIN_PULSE_WIDTH + ((float)ang / 180) * ((float)MAX_PULSE_WIDTH - (float)MIN_PULSE_WIDTH));
	}
	mraa_pwm_pulsewidth_us(myDoor, ang2us);
	sleep(1);
	MyDoor::enable(LOW);
}

MyDoor::~MyDoor() {
	MyDoor::enable(LOW);
	mraa_pwm_close(myDoor);
}

