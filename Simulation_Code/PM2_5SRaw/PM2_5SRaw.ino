//RAW DATA BETWEEN 800-1100 IS NORMAL; MORE TESTING IS NEEDED

const int gasPin = A0; //GAS sensor output pin to Arduino analog A0 pin


void setup()
{
	Serial.begin(9600); //Initialize serial port - 9600 bps
}

void loop()
{
	Serial.println(analogRead(gasPin));
	delay(1000); // Print value every 1 sec.
}

