#include "Led.hpp"

Led::Led(int pin) {
	myLed = mraa_gpio_init(pin);
	mraa_gpio_dir(myLed, MRAA_GPIO_OUT);
}

void Led::ledOn(bool state) {
	(state) ? mraa_gpio_write(myLed, 1) : mraa_gpio_write(myLed, 0);
}

Led::~Led() {
	mraa_gpio_close(myLed);
}

