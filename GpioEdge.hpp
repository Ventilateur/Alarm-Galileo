#ifndef GPIOEDGE_HPP_
#define GPIOEDGE_HPP_

#include <mraa/gpio.h>
#include <unistd.h>
#include <iostream>

/**
 * @brief API pour le GPIO en mode input
 */
class GpioEdge {
public:

	/**
	 * Initialiser le GPIO
	 * Mode: input,
	 */
	GpioEdge(int pin);
	bool getState();
	int read();
	~GpioEdge();
private:
	mraa_gpio_context myTouch;
	static void edgeDetect(void* ctx);
	bool state;
};

#endif /* GPIOEDGE_HPP_ */
