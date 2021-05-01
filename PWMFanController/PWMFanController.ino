/*
 Name:		PWMFanController.ino
 Created:	5/1/2021 3:40:43 PM
 Author:	MagicALCN
*/

// the setup function runs once when you press reset or power the board

const int PWMPIN = PA0;
const int SENSEPIN = PA1;
const int VOLTAGEPIN = PA2;

void setup() {
	Serial.begin(9600);
	pinMode(PWMPIN, OUTPUT);
	pinMode(SENSEPIN, INPUT);
	pinMode(VOLTAGEPIN, INPUT_ANALOG);
}

// the loop function runs over and over again until power down or reset
void loop() {
	if (Serial) {
		pwmWrite(PWMPIN, Serial.read() / 2400 * 65535);
		Serial.write(digitalRead(SENSEPIN));
	}
	else
		pwmWrite(PWMPIN, analogRead(VOLTAGEPIN) * 16);
}
