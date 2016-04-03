/*
 * MyAlarm.hpp
 *
 *  Created on: Mar 25, 2016
 *      Author: Phan Vu Hoang
 */
#pragma once

#ifndef MYALARM_HPP_
#define MYALARM_HPP_

#include <mraa/pwm.h>
#include <unistd.h>
#include <iostream>

#define ENABLE	1
#define DISABLE	0

enum note{DO = 3300, RE = 2930, MI = 2600, FA = 2460, SOL = 2190, LA = 1960, SI = 1750};

class MyAlarm {
public:
	MyAlarm(int pin);
	void start(note tone, float vol, int delay);
	void stop();
	~MyAlarm();
protected:
	mraa_pwm_context myAlarm;
};

#endif /* MYALARM_HPP_ */
