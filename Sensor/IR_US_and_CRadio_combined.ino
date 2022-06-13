float freq, period;
int ontime, offtime;

void setup() {
  // once again any digital pin can be used except for pins 5, 7 & 10 (since they are for the wifi shield functionality
  pinMode(2, INPUT); // Radio carrier frequency
  pinMode(3, INPUT); // IR
  pinMode(4, INPUT); // US
  Serial.begin(9600);

}

void loop() {
  IR();
  US();
  CRadio();

}

// perform calls to sensing functions in a loop, provides very consistent results.

void IR() {
  // the code for the following functions are the same as their individual .ino files (except for the configured pins)
  ontime = pulseIn(3, HIGH);
  offtime = pulseIn(3, LOW);
  period = offtime + ontime;
  freq = 1000000/period;
  if(ontime != 0) {
    if(freq > 340.91 && freq < 366.78) {
      // Serial.println("IR Pulse, 353 Hz");
      // 353 Hz IR pulse detected
    }
    else if(freq > 564.97 && freq < 585.28) {
      // Serial.println("IR Pulse, 571 Hz");
      // 571 Hz IR pulse detected
    }
  }
  else {
    // No IR pulse detected
}

void US(){
  ontime = pulseIn(4, HIGH);
  offtime = pulseIn(4, LOW);
  period = offtime + ontime;
  freq = 1000000/period;
  if(freq > 37037.03 && 38461.54) {
    // Serial.println("Acoustic signal, 40 kHz");
    // Acoustic signal detected
  }
  else {
    // no acoustic signal detected - make the equivalent for web interface
  }
}
  
void CRadio(){
  // this function mostly works without filters, but they may be necessary since these signals have very high frequencies. 
  ontime = pulseIn(2, HIGH);
  offtime = pulseIn(2, LOW);
  period = offtime + ontime;
  freq = 1000000/period;
  if(ontime != 0){
    if(freq > 55555.55 && freq < 58823.53){
      Serial.println("Radio carrier, 61 kHz");
    }
    else if(freq > 83333.34 && freq < 90909.1){
      Serial.println("Radio carrier, 89 kHz");
    }
  }
}
  
