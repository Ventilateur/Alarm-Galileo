/*
 * MyLight.cpp
 *
 *  Created on: Mar 25, 2016
 *      Author: Phan Vu Hoang
 */

#include "MyLight.hpp"

MyLight::MyLight(int pin) {
	myLight = mraa_aio_init(pin);
}

int MyLight::read() {
	return mraa_aio_read(myLight);
}

MyLight::~MyLight() {
	mraa_aio_close(myLight);
}

