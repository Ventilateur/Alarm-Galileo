#include "LightSensor.hpp"

LightSensor::LightSensor(int pin) {
	myLight = mraa_aio_init(pin);
}

int LightSensor::read() {
	return mraa_aio_read(myLight);
}

LightSensor::~LightSensor() {
	mraa_aio_close(myLight);
}

