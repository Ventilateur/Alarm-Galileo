#pragma once

#ifndef SECURITY_SYSTEM_HPP_
#define SECURITY_SYSTEM_HPP_

#include "BuzzerAlarm.hpp"
#include "ServoDoor.hpp"
#include "LightSensor.hpp"
#include "Lcd.hpp"
#include "GpioEdge.hpp"
#include "Led.hpp"

// définir les pins à utiliser
#define LED_PIN			4
#define SERVO_PIN		5
#define BUZZER_PIN		3
#define LIGHT_PIN		3
#define BUTTON_PIN		2
#define ARDUINO_PIN_5	1
#define ARDUINO_PIN_4	0

// définir les constances à utiliser
#define VOLUME			0.5
#define BUZZER_DELAY_MS	10
#define LIGHT_THRESHOLD	100

/**
 * Déclancher l'alarme
 * Afficher message sur l'afficheur LCD et activer le buzzer
 *
 * @param  aucun
 * @return void
 */
void triggerAlarm();

/**
 * Désactiver l'alarme
 * Par défault, l'afficheur et le buzzer sont éteints
 *
 * @param  aucun
 * @return void
 */
void setDefault();

/**
 * Initialiser le système
 * Mettre l'alarme dans l'état par défault et initialiser le mraa
 *
 * @param  aucun
 * @return void
 */
void setup();

/**
 * Mettre en oeuvre l'alarme
 * L'alarme et activée/désactivée selon l'état de l'objet <isActive> qui communique avec l'Arduino
 * Si l'alarme est activée, les capteurs (lumière et distance) vont détecter
 * s'il y a une intrusion et déclancher l'alarme, l'ouverture de la porte sera donc impossible
 * Si l'alarme est désactivée, on pourra utiliser le bouton poussoir pour ouvrir/fermer la porte
 * sans déclancher l'alarme
 *
 * @param  aucun
 * @return void
 */
void runAlarm();

/**
 * Fonction principale
 */
int main();

#endif /* SECURITY_SYSTEM_HPP_ */

