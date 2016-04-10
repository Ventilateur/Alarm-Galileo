#pragma once

#ifndef LIGHTSENSOR_HPP_
#define LIGHTSENSOR_HPP_

#include <mraa/aio.h>

/**
 * @brief API pour le capteur de lumière
 */
class LightSensor {
public:

	/**
	 * Constructeur qui initialise un pin en mode input analogique
	 *
	 * @param pin le pin correspondant au capteur
	 */
	LightSensor(int pin);

	/**
	 * Lire la valeur capturée par le capteur
	 *
	 * @param  aucun
	 * @return une valeur lue entre 0 et 1023
	 */
	int read();

	/**
	 * Destructeur
	 */
	~LightSensor();
private:
	mraa_aio_context myLight;
};

#endif /* LIGHTSENSOR_HPP_ */
