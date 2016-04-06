#include "BuzzerAlarm.hpp"

BuzzerAlarm::BuzzerAlarm(int pin) {
	myAlarm = mraa_pwm_init(pin);
	mraa_pwm_enable(myAlarm, ENABLE);
}

void BuzzerAlarm::start(note tone, float vol, int delay) {
	mraa_pwm_period_us(myAlarm, tone);
	float volume;
	// éviter les valeurs impossibles
	if (vol > 1.0) volume = 1.0;
	else if (vol < 0.0) volume = 0.0;
	else volume = vol;
	// la volume correspond au rapport cyclique, 50% sera donc la volume max
	mraa_pwm_write(myAlarm, volume*0.5);
	usleep(delay*1000);
	BuzzerAlarm::stop();
}

void BuzzerAlarm::stop() {
	mraa_pwm_period_us(myAlarm, 1);
	mraa_pwm_write(myAlarm, 0);
}

BuzzerAlarm::~BuzzerAlarm() {
	mraa_pwm_enable(myAlarm, DISABLE);
	mraa_pwm_close(myAlarm);
}

