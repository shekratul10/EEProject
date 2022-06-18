int analogPin1 = A0; // potentiometer wiper (middle terminal) connected to analog pin 3
                    // outside leads to ground and +5V
int val1 = 0; // variable to store the value read
int a;
void setup() {
  Serial.begin(9600);           //  setup serial
}

void loop() {
  val1 = analogRead(analogPin1);  // read the input pin

  float volt1 = val1 * (5000 / 1024);
  if(volt1 > 500 ){
  Serial.println("89kHz carrier frequency signal are detected");
 } 

}
