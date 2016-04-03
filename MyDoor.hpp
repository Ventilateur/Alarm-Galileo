/*
 * MyDoor.hpp
 *
 *  Created on: Mar 25, 2016
 *      Author: Phan Vu Hoang
 */
#pragma once

#ifndef MYDOOR_HPP_
#define MYDOOR_HPP_

#include <mraa/pwm.h>
#include <mraa/common.h>

#define MIN_PULSE_WIDTH             600
#define MAX_PULSE_WIDTH             2500
#define PERIOD                      5000

#define HIGH                        1
#define LOW                         0

class MyDoor {
public:
	MyDoor(int pin);
	void open();
	void close();
	mraa_result_t enable(int en);
	void setAngle(int ang);
	~MyDoor();
private:
	mraa_pwm_context myDoor;
	bool isOpen;
};

#endif /* MYDOOR_HPP_ */
