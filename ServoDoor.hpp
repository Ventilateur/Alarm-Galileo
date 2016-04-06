#pragma once

#ifndef SERVODOOR_HPP_
#define SERVODOOR_HPP_

#include <mraa/pwm.h>
#include <mraa/common.h>

#define MIN_PULSE_WIDTH             600
#define MAX_PULSE_WIDTH             2500
#define PERIOD                      5000

#define HIGH                        1
#define LOW                         0

class ServoDoor {
public:
	ServoDoor(int pin);
	void open();
	void close();
	mraa_result_t enable(int en);
	void setAngle(int ang);
	~ServoDoor();
private:
	mraa_pwm_context myDoor;
	bool isOpen;
};

#endif /* SERVODOOR_HPP_ */
