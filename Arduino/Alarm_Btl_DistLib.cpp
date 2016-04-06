/*
 Name:		Alarm_Btl_DistLib.cpp
 Created:	4/4/2016 9:56:37 AM
 Author:	Phan Vu Hoang
 Editor:	http://www.visualmicro.com
*/

#include "Alarm_Btl_DistLib.h"

CaptDist::CaptDist(int trigPin, int echoPin) {
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
	trig = trigPin;
	echo = echoPin;
}

long CaptDist::getRaw() {
	// envoyer un pulse de 15us pour déclancher la mesure
	digitalWrite(trig, LOW);
	delayMicroseconds(5);
	digitalWrite(trig, HIGH);
	delayMicroseconds(15);
	digitalWrite(trig, LOW);
	// mesurer la durée du pulse reçu
	long duration = pulseIn(echo, HIGH);
	delay(100);
	return duration;
}

long CaptDist::getCm() {
	// la durée du pulse est proportionnel à la distance
	return US_2_CM * CaptDist::getRaw();
}

CaptDist::~CaptDist() {
}

