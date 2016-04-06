/*
 Name:		Alarm_Btl_DistLib.h
 Created:	4/4/2016 9:56:37 AM
 Author:	Phan Vu Hoang
 Editor:	http://www.visualmicro.com
*/

#ifndef _Alarm_Btl_DistLib_h
#define _Alarm_Btl_DistLib_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

// constance pour convertir us => cm
#define US_2_CM	(1/58.2)

/** 
	@brief API pour le capteur de distance, référence HC-SR04
*/
class CaptDist {
public:
	/**
		Constructeur qui initialise les deux pins trigger et echo du capteur

		@param trigPin output pin pour déclancher le capteur
		@param echoPin input pin pour recevoir la réponse
	*/
	CaptDist(int trigPin, int echoPin);

	/**
		Recupérer la valeur brute en microseconde

		@param  aucun
		@return la durée en microseconde du pulse reçu par l'echo pin 
	*/
	long getRaw();

	/**
	Recupérer la distance capturée en cm

	@param  aucun
	@return la distance en cm
	*/
	long getCm();
	/**
		Déstructeur
	*/
	~CaptDist();
private:
	int trig;
	int echo;
};

#endif

