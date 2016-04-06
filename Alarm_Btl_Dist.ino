/*
 Name:		Alarm_Btl_Dist.ino
 Created:	4/4/2016 9:56:37 AM
 Author:	Phan Vu Hoang
 Editor:	http://www.visualmicro.com
*/

#include <SoftwareSerial.h>
#include "Alarm_Btl_DistLib.h"

//====d�finir les pins � utiliser====// 

// bluetooth module tx, rx pins
#define TX_PIN		7			 
#define RX_PIN		8

// capteur de distance trigger et echo pins
#define TRIG_PIN	6
#define ECHO_PIN	9

// communication pins avec la carte Galileo
#define ALARM_PIN	5
#define DIST_PIN	4

//===================================//

// distance max � d�clancher l'alarme
#define MAX_DIST    20.0

// d�finir le mot de passe pour d�sactiver l'alarme
const String password = "1234";
const int passwordLen = 4;

// initialiser la communication s�riale et le capteur de distance 
SoftwareSerial bltSerial(RX_PIN, TX_PIN);
CaptDist capDist(TRIG_PIN, ECHO_PIN);

// variables pour la communication
char recv;
String data = "";
bool pwCorrect = false;

/**
	Initialiser les pins et la communication s�riale

	@param  aucun
	@return void
*/
void setup() {
	Serial.begin(9600);
	pinMode(ALARM_PIN, OUTPUT);
	digitalWrite(ALARM_PIN, LOW);
	pinMode(DIST_PIN, OUTPUT);
	pinMode(RX_PIN, INPUT);
	pinMode(TX_PIN, OUTPUT);
	bltSerial.begin(9600);
	bltSerial.flush();
}

/**
    Envoyer une pulse de 100ms sur un pin

	@param  aucun
	@return void
*/
void sendPulse(int pin) {
	digitalWrite(pin, HIGH);
	delay(100);
	digitalWrite(pin, LOW);
	Serial.println("Pulse sent");
}

/**
    V�rifier le mot de passe re�u par le module bluetooth
	Le mot de passe ne contient que <passwordLen> carat�res
	La v�rification sera fait quand le module re�oit le caract�re 'Z' <=> bouton <Submit>

	@param  aucun
	@return void
*/
void checkPw() {
	if (bltSerial.available()) {
		recv = bltSerial.read();
		if (recv == 'Z') {
			Serial.println("Submit");
			pwCorrect = (data == password);
			if (pwCorrect) sendPulse(ALARM_PIN);
			pwCorrect ? Serial.println("Password correct!") : Serial.println("Password incorrect");
			data = "";
		}
		else {
			if (data.length() >= passwordLen) data = "";
			data += recv;
			Serial.println(data);
		}
	}
}

/**
	Boucle infinie, on va v�rifier la distance captur�e et le mot de passe r�guli�rement
	Si le mot de passe est correct, une pulse de 100ms sera envoyer vers la carte Galileo pour d�activer l'alarme
	Si la distance est sup�rieur au MAX_DIST, le pin DIST_PIN est activ� en HIGH et donc d�clanche l'alarme

	@param  aucun
	@return void
*/
void loop() {
	(capDist.getCm() > MAX_DIST) ? digitalWrite(DIST_PIN, HIGH) : digitalWrite(DIST_PIN, LOW);
	checkPw();
}
