/*
 * MyAlarm.cpp
 *
 *  Created on: Mar 25, 2016
 *      Author: Phan Vu Hoang
 */

#include "MyAlarm.hpp"

MyAlarm::MyAlarm(int pin) {
	myAlarm = mraa_pwm_init(pin);
	mraa_pwm_enable(myAlarm, ENABLE);
}

void MyAlarm::start(note tone, float vol, int delay) {
	mraa_pwm_period_us(myAlarm, tone);
	float volume;
	if (vol > 1.0) {
		volume = 1.0;
	} else if (vol < 0.0) {
		volume = 0.0;
	} else {
		volume = vol;
	}
	mraa_pwm_write(myAlarm, volume*0.5);
	usleep(delay*1000);
}

void MyAlarm::stop() {
	mraa_pwm_period_us(myAlarm, 1);
	mraa_pwm_write(myAlarm, 0);
}

MyAlarm::~MyAlarm() {
	mraa_pwm_enable(myAlarm, DISABLE);
	mraa_pwm_close(myAlarm);
}

