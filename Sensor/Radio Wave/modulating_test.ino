float freq, period;
int ontime, offtime, count151 = 0, count239 = 0;

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
    if(freq < 154.18 && freq > 147.11){
      //Serial.println("151");
      count151++;
    }
    else if(freq < 254.84 && freq > 242.07){
      //Serial.println("239");
      count239++;
    }

    if((!count151 == 0 && count239 == 0) || (count151 == 0 && !count239 == 0)){
       //Serial.println("0");
      if(count151 == 2 && count239 == 0){
        Serial.println("151 nodulating are detected");
      }
      else if(count151 == 0 && count239 == 2){
        Serial.println("239 modulating are detected");
      }
    }
    else if (!count151 == 0 && !count239 == 0){
      count151 = count239 = 0;
    }
  }
}
