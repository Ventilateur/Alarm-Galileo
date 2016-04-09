#pragma once

#ifndef SECURITY_SYSTEM_HPP_
#define SECURITY_SYSTEM_HPP_

#include "BuzzerAlarm.hpp"
#include "ServoDoor.hpp"
#include "LightSensor.hpp"
#include "Lcd.hpp"
#include "GpioEdge.hpp"
#include "Led.hpp"

// d�finir les pins � utiliser
#define LED_PIN			4
#define SERVO_PIN		5
#define BUZZER_PIN		3
#define LIGHT_PIN		3
#define BUTTON_PIN		2
#define ARDUINO_PIN_5	1
#define ARDUINO_PIN_4	0

// d�finir les constances � utiliser
#define VOLUME			0.5
#define BUZZER_DELAY_MS	10
#define LIGHT_THRESHOLD	100

/**
 * D�clancher l'alarme
 * Afficher message sur l'afficheur LCD et activer le buzzer
 *
 * @param  aucun
 * @return void
 */
void triggerAlarm();

/**
 * D�sactiver l'alarme
 * Par d�fault, l'afficheur et le buzzer sont �teints
 *
 * @param  aucun
 * @return void
 */
void setDefault();

/**
 * Initialiser le syst�me
 * Mettre l'alarme dans l'�tat par d�fault et initialiser le mraa
 *
 * @param  aucun
 * @return void
 */
void setup();

/**
 * Mettre en oeuvre l'alarme
 * L'alarme et activ�e/d�sactiv�e selon l'�tat de l'objet <isActive> qui communique avec l'Arduino
 * Si l'alarme est activ�e, les capteurs (lumi�re et distance) vont d�tecter
 * s'il y a une intrusion et d�clancher l'alarme, l'ouverture de la porte sera donc impossible
 * Si l'alarme est d�sactiv�e, on pourra utiliser le bouton poussoir pour ouvrir/fermer la porte
 * sans d�clancher l'alarme
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

