#pragma once

#ifndef SERVODOOR_HPP_
#define SERVODOOR_HPP_

#include <mraa/pwm.h>
#include <mraa/common.h>

// d�finir les coefficients du servo, obtenus par le fabriquant
#define MIN_PULSE_WIDTH             600
#define MAX_PULSE_WIDTH             2500
#define PERIOD                      5000

// d�finir les �tats du PWM
#define HIGH                        1
#define LOW                         0

/**
 * @brief API pour le servo moteur
 * Fonctionnements : faire tourner le servo � une angle donn�e,
 * �teindre/allumer le PWM (donc le servo)
 * open() correspond � une angle de 120 degr�
 * close() correspond � une angle de 30 degr�
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
	 * Ouvrir la porte, correspondre donc � fixer le servo � 120 degr�
	 *
	 * @param  aucun
	 * @return void
	 */
	void open();

	/**
	 * Fermer la porte, correspondre donc � fixer le servo � 30 degr�
	 *
	 * @param  aucun
	 * @return void
	 */
	void close();

	/**
	 * Activer/D�sactiver le PWM
	 *
	 * @param  en �teindre si 0 et allumer si 1 (� utiliser les macros HIGH et LOW)
	 * @return une valeur de type mraa_result_t, voir la documentation de la lib mraa
	 */
	mraa_result_t enable(int en);

	/**
	 * Fixer le servo � une angle
	 *
	 * @param  ang l'angle donn�e, possible entre 0 et 180
	 * @return void
	 */
	void setAngle(int ang);

	/**
	 * Destructeur
	 */
	~ServoDoor();
private:
	mraa_pwm_context myDoor;

	// variable d'�tat pour �viter que le servo vibre
	bool isOpen;
};

#endif /* SERVODOOR_HPP_ */
