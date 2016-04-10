#include "GpioEdge.hpp"


GpioEdge::GpioEdge(int pin) {
	GpioEdge::state = false;
	myTouch = mraa_gpio_init(pin);
	mraa_gpio_dir(myTouch, MRAA_GPIO_IN);
	mraa_gpio_isr(myTouch, MRAA_GPIO_EDGE_BOTH, &edgeDetect, (void*)this);
}

// self note: void* is a special pointer that can be pointed at an object of any type
void GpioEdge::edgeDetect(void *ctx) {
	std::cout << "Edge detected!" << std::endl;
	GpioEdge *thisObj = (GpioEdge*)ctx;
	if (thisObj->read() == 0) {
		thisObj->state = !thisObj->state;
	}
}

bool GpioEdge::getState() {
	return GpioEdge::state;
}

int GpioEdge::read() {
	return mraa_gpio_read(myTouch);
}

GpioEdge::~GpioEdge() {
	mraa_gpio_close(myTouch);
}

