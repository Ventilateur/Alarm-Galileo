#include <iostream>
#include "Security_system.hpp"

ServoDoor 	door(SERVO_PIN);
BuzzerAlarm buzzer(BUZZER_PIN);
LightSensor sensor(LIGHT_PIN);
GpioEdge 	button(BUTTON_PIN);
GpioEdge 	isActive(ARDUINO_PIN);
Lcd 		lcd;

bool thief;

void triggerAlarm() {
	// Afficher message sur l'afficheur LCD
	lcd.display(true);
	lcd.setColor(255, 0, 0);
	lcd.setPos(2, 1);
	lcd.writeMsg("Alert!!!");
	// Activer le buzzer (quelques notes pour qu'il ne soit pas monotone)
	buzzer.start(MI,  VOLUME, BUZZER_DELAY_MS);
	buzzer.start(FA,  VOLUME, BUZZER_DELAY_MS);
	buzzer.start(SOL, VOLUME, BUZZER_DELAY_MS);
	buzzer.start(LA,  VOLUME, BUZZER_DELAY_MS);
	buzzer.start(SOL, VOLUME, BUZZER_DELAY_MS);
	buzzer.start(FA,  VOLUME, BUZZER_DELAY_MS);
}

void setDefault() {
	buzzer.stop();
	lcd.setColor(0, 0, 0);
	lcd.display(false);
	thief = false;
}

void setup() {
	mraa_init();
	setDefault();
}

void runAlarm() {
	if (isActive.getState()) {
		std::cout << "Activated!" << std::endl;
		door.close();
		if (sensor.read() < LIGHT_THRESHOLD) thief = true;
		if (thief) triggerAlarm();
	} else {
		std::cout << "Deactivated!" << std::endl;
		setDefault();
		(button.getState()) ? door.open() : door.close();
	}
}


int main() {

	setup();
	for (;;) {
		runAlarm();
	}
	return 0;

}
