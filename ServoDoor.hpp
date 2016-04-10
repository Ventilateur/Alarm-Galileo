#pragma once

#ifndef SERVODOOR_HPP_
#define SERVODOOR_HPP_

#include <mraa/pwm.h>
#include <mraa/common.h>

// définir les coefficients du servo, obtenus par le fabriquant
#define MIN_PULSE_WIDTH             600
#define MAX_PULSE_WIDTH             2500
#define PERIOD                      5000

// définir les états du PWM
#define HIGH                        1
#define LOW                         0

/**
 * @brief API pour le servo moteur
 * Fonctionnements : faire tourner le servo à une angle donnée,
 * éteindre/allumer le PWM (donc le servo)
 * open() correspond à une angle de 120 degré
 * close() correspond à une angle de 30 degré
 */
class ServoDoor {
public:
	/**
	 * Constructeur qui initialise le PWM sur un pin
	 *
	 * @param pin le pin qui envoie le PWM
	 */
	ServoDoor(int pin);

	/**
	 * Ouvrir la porte, correspondre donc à fixer le servo à 120 degré
	 *
	 * @param  aucun
	 * @return void
	 */
	void open();

	/**
	 * Fermer la porte, correspondre donc à fixer le servo à 30 degré
	 *
	 * @param  aucun
	 * @return void
	 */
	void close();

	/**
	 * Activer/Désactiver le PWM
	 *
	 * @param  en éteindre si 0 et allumer si 1 (à utiliser les macros HIGH et LOW)
	 * @return une valeur de type mraa_result_t, voir la documentation de la lib mraa
	 */
	mraa_result_t enable(int en);

	/**
	 * Fixer le servo à une angle
	 *
	 * @param  ang l'angle donnée, possible entre 0 et 180
	 * @return void
	 */
	void setAngle(int ang);

	/**
	 * Destructeur
	 */
	~ServoDoor();
private:
	mraa_pwm_context myDoor;

	// variable d'état pour éviter que le servo vibre
	bool isOpen;
};

#endif /* SERVODOOR_HPP_ */
