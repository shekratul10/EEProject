void setup() {
  pinMode(4, INPUT);
  // assign digital pin 4 to be an input pin for our signal
  Serial.begin(9600);

}

void loop() {
  int D4 = digitalRead(4);
  // stores the digital input from pin 4 in this variable each cycle
  Serial.println(D4);
  // outputs the value of the digital input from pin 4
  // the signal can be analysed by using the serial plotter tool

}
