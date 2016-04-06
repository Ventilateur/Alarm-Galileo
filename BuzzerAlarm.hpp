#pragma once

#ifndef BUZZERALARM_HPP_
#define BUZZERALARM_HPP_

#include <mraa/pwm.h>
#include <unistd.h>
#include <iostream>

// d�finir les �tats du PWM et les notes correspondantes � des p�riodes du PWM
#define ENABLE	1
#define DISABLE	0

enum note{DO = 3300, RE = 2930, MI = 2600, FA = 2460, SOL = 2190, LA = 1960, SI = 1750};

/**
 * @brief API du buzzer Grove
 */
class BuzzerAlarm {
public:
	/**
	 * Constructeur qui initialise le PWM sur un pin
	 * La fonctionnement du PWM n'est disponible que sur les pins 3, 5, 6, 9, 10 et 11
	 *
	 * @param pin le pin qui envoie le PWM
	 */
	BuzzerAlarm(int pin);

	/**
	 * Activer le buzzer
	 *
	 * @param  tone la note � jouer (de DO � SI)
	 * @param  vol la volume (valeur valide entre 0.0 et 1.0)
	 * @param  delay la dur�e de la note
	 * @return void
	 */
	void start(note tone, float vol, int delay);

	/**
	 * D�sactiver le buzzer
	 *
	 * @param  aucun
	 * @return void
	 */
	void stop();

	/**
	 * D�structeur
	 */
	~BuzzerAlarm();
protected:
	mraa_pwm_context myAlarm;
};

#endif /* BUZZERALARM_HPP_ */
