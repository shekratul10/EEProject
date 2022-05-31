float freq, period;
int ontime, offtime;

void setup() {
  pinMode(4,INPUT);
  // Here I have used pin 4 on Adafruit but this can be any non-PWM digital pin of your choosing
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
       * This region of values were chosen as 10th and 90th percentiles respectively
       * Values were determined by taking a large number of readings (around 700 readings of frequency)
       * and used the percentile function in excel to obtain these values from the gathered data
       */
      Serial.println("IR Pulse of 353 Hz detected!");
      // You can change this line to [make a boolean variable corresponding to IR 353Hz true or something creative]
    }
    else if(freq > 564.97 && freq < 585.28) {
      /*
       * Same as above but using a sample of 2000+ readings
       */
       Serial.println("IR Pulse of 571 Hz detected!");
    }    
  }

  
  

}
