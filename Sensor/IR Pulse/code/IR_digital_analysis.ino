float freq, period;
int ontime, offtime;

void setup() {
  pinMode(4,INPUT);
  Serial.begin(9600);

}

void loop() {
  ontime = pulseIn(4,HIGH);
  offtime = pulseIn(4,LOW);
  period = ontime+offtime;
  freq = 1000000.0/period;
  
  if(ontime != 0) {
    if(freq > 340.91 && freq < 366.78) {
      /*
       * These values are limits for the measured frequency; a reported frequency within this range will cause the
       * code to report a pulse of 353 Hz IR has been detected. The values were determined from using the code from
       * IR_digital_test1 to obtain many (1000+) frequency readings, which were then imported to excel. The 10th and 90th 
       * percentiles were calculated and used as the limits for this if statement. The same process was repeated for the 571 Hz
       * IR pulses. 
       * 
       * The code will only output a message when an IR pulse of 353 or 571 Hz has been detected. The code inside the if
       * statements will be changed so that the message can be received by the web interface.
       */
      Serial.println("IR Pulse of 353 Hz detected!");
      
    }
    else if(freq > 564.97 && freq < 585.28) {
       Serial.println("IR Pulse of 571 Hz detected!");
    }    
  }

  
  

}
