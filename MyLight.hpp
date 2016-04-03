/*
 * MyLight.hpp
 *
 *  Created on: Mar 25, 2016
 *      Author: Phan Vu Hoang
 */
#pragma once

#ifndef MYLIGHT_HPP_
#define MYLIGHT_HPP_

#include <mraa/aio.h>

class MyLight {
public:
	MyLight(int pin);
	int read();
	~MyLight();
private:
	mraa_aio_context myLight;
};

#endif /* MYLIGHT_HPP_ */
