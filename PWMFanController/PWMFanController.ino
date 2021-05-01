/*
 Name:		PWMFanController.ino
 Created:	5/1/2021 3:40:43 PM
 Author:	MagicALCN
*/

// the setup function runs once when you press reset or power the board

int inputRPM;
const int fanPIN = PA1;

int outputRPM() {
	return (inputRPM) / 2400 * 65535;
}

void setup() {
	Serial.begin(9600);
	pinMode(fanPIN, OUTPUT);

}

// the loop function runs over and over again until power down or reset
void loop() {
	if (Serial) {
		inputRPM = Serial.read();
		pwmWrite(fanPIN, outputRPM());
	}
}
