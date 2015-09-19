int potPin1 = 3;    // select the input pin for the potentiometer
int potPin2 = 4;
int potPin3 = 5;
float val1 = 0;       // variable to store the value coming from the sensor
float val2 = 0;
float val3 = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  val1 = ((analogRead(potPin1))/256 + 36.5);    //BODY TEMPERATURE
  val2 = ((analogRead(potPin2))/10 + 50);    //HEART RATE
  val3 = ((analogRead(potPin3))/2);    //PM 2.5
  Serial.print(val1);
  Serial.print(" , ");
  Serial.print(val2);
  Serial.print(" , ");
  Serial.println(val3);
  
  if(val1 == 0 && val2 == 0 && val3 == 0){
    Serial.println("NO DATA!");
  }

}


