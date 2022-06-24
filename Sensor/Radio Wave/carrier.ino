int val1 = 0; // variable to store the value read
void setup() {
  Serial.begin(9600);           //  setup serial
  pinMode(A0, INPUT);
}

void loop() {
  val1 = analogRead(A0);  // read the input pin

  float volt1 = val1 * (5000 / 1024);
  if(volt1 > 500 ){ // If the voltage input at this pin is greater than a certain threshold then an 89 kHz signal is detected
    // the amplitudes of 61 kHz and 89 kHz radio waves are different to each other in the amplitude modulation part, allowing differentiation between the two
    // only the 89 kHz method is shown here since this is the resonant circuit that has been implemented. 
  Serial.println("89kHz carrier frequency signal are detected");
 } 

}
