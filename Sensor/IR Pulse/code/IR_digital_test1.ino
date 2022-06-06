float freq, period;
int ontime, offtime;

void setup() {
  pinMode(4, INPUT);
  /*
  use a digital pin for testing our circuit and analysis of the signal
  any digital pin could be used to analyse the signal - we don't know how many pins will be used
  for the final rover
  */
  Serial.begin(9600);
}

void loop() {
  ontime = pulseIn(4, HIGH);
  // measures the time that the digital signal is high/on
  offtime = pulseIn(4, LOW);
  // measures the time that the digital signal is low/off
  period = ontime + offtime;
  // the period of a digital pulse signal is equal to the time the signal is high and low across one cycle
  freq = 1000000/period;
  // frequency is the reciprocal of period. 1000000 is used instead of 1 because the period measurements are in mircoseconds so it is converted to obtain Hertz

  if(ontime != 0) {
    /*  
      The code will not run unless a pulse is detected (when the signal is high)
      Currently the code reports the frequency of a pulse that is measured from the circuit in Hertz
      It reports all frequencies and not specific to frequencies we are required to detect (353 and 571 Hz)
    */
    Serial.print("IR detected! Freq = ");
    Serial.print(freq);
    Serial.println("Hz");
  }

}
