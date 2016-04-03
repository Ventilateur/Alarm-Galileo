#include <iostream>

#include "Components.hpp"

MyDoor door(SERVO_PIN);
MyAlarm buzzer(BUZZER_PIN);
MyLight sensor(LIGHT_PIN);
MyTouch touch(TOUCH_PIN);
MyLcd lcd;
// MyBluetooth bthModule(TX_PIN, RX_PIN);

bool thief;

void triggerAlarm() {
	// Display on LCD
	lcd.display(true);
	lcd.setColor(255, 0, 0);
	lcd.setPos(2, 1);
	lcd.writeMsg("Voleurrrr!!!");
	// Close the door
	door.close();
	// Trigger the alarm
	buzzer.start(MI, VOLUME, BUZZER_DELAY_MS);
}

void setDefault() {
	door.open();
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
	if (touch.getState()) {
		if (sensor.read() < THRESHOLD) {
			thief = true;
		}
		if (thief) {
			triggerAlarm();
		}
	} else {
		setDefault();
	}
}

//void test() {
//	std::cout << "Received: " << bthModule.read(8) << std::endl;
//}

int main() {

	setup();
	for (;;) {
		runAlarm();
	}
	return 0;

}
