#include <iostream>
#include <unistd.h>
#include "ServoDoor.hpp"

ServoDoor::ServoDoor(int pin) {
	myDoor = mraa_pwm_init(pin);
	ServoDoor::open();
}

void ServoDoor::open() {
	// ouvrir seulement si la porte est fermée, sinon le servo vibra
	if (!isOpen) {
		ServoDoor::setAngle(120);
		isOpen = true;
	}
}

void ServoDoor::close() {
	// fermer seulement si la porte est ouverte, sinon le servo vibra
	if (isOpen) {
		ServoDoor::setAngle(30);
		isOpen = false;
	}
}

mraa_result_t ServoDoor::enable(int en) {
	return mraa_pwm_enable(myDoor, en);
}

void ServoDoor::setAngle(int ang) {
	int ang2us;
	ServoDoor::enable(HIGH);
	mraa_pwm_period_us(myDoor, PERIOD);
	// on évite les angles impossibles
	if (ang > 180) {
		ang2us = MAX_PULSE_WIDTH;
	} else if (ang < 0) {
		ang2us = MIN_PULSE_WIDTH;
	} else {
		// la formule qui transforme l'angle à la durée du pulse correspondante
		ang2us = (int)((float)MIN_PULSE_WIDTH + ((float)ang / 180) * ((float)MAX_PULSE_WIDTH - (float)MIN_PULSE_WIDTH));
	}
	mraa_pwm_pulsewidth_us(myDoor, ang2us);
	// on attend pour assurer que le servo puisse atteindre l'angle avant d'éteindre le servo, sinon il vibra
	sleep(1);
	ServoDoor::enable(LOW);
}

ServoDoor::~ServoDoor() {
	ServoDoor::enable(LOW);
	mraa_pwm_close(myDoor);
}

