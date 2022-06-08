void setup() {
  pinMode(A0, INPUT);
  /*
   * We use an analogue pin to measure the output voltage from the bipolar HS (detects if there is a magnetic field)
   * Using analogue because the component output characteristic is linear depending on the distance from the sensor to the magnetic
   * When no field is detected the output voltage is around value Vq, usually 1.012 V
   * On github, there is a range of voltages that will result in no field being detected (0.7 < v < 1.5) - see the truth table corresponding to the magnetic section
   */
   pinMode(4, INPUT);
   // Digital pin used to for unipolar HS (detects the direction of the magnetic field)
  Serial.begin(9600);

}

void loop() {
  int VA0 = analogRead(A0);
  int D4 = digitalRead(4);

  if(!(VA0 > 146 && VA0 < 310)){
    if(D4 == HIGH){
      Serial.println("South pole detected!");
    }
    else{
      Serial.println("North pole detected!");
    }
  }
  else{
    Serial.println("No pole detected");
  }

  

}

// 1.5V = 310 as int
// 0.7V = 146 as int
