#pragma once

#ifndef LIGHTSENSOR_HPP_
#define LIGHTSENSOR_HPP_

#include <mraa/aio.h>

class LightSensor {
public:
	LightSensor(int pin);
	int read();
	~LightSensor();
private:
	mraa_aio_context myLight;
};

#endif /* LIGHTSENSOR_HPP_ */
