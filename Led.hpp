#ifndef LED_HPP_
#define LED_HPP_

#include <mraa/gpio.h>

/**
 * @brief API pour le Led Grove
 */
class Led {
public:

	/**
	 * Constructeur qui initialise un pin GPIO
	 *
	 * @param pin le pin GPIO correspond à la led
	 */
	Led(int pin);

	/**
	 * Allumer/Eteindre la led
	 *
	 * @param  state allumer la led si vrai et l'éteindre si faux
	 * @return void
	 */
	void ledOn(bool state);

	/**
	 * Destructeur
	 */
	~Led();
private:
	mraa_gpio_context myLed;
};

#endif /* LED_HPP_ */
