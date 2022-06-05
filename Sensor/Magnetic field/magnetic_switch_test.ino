void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  // analogue for BHS
  pinMode(8, INPUT);
  // digital for UHS
  Serial.begin(1200);
}

void loop() {
  // put your main code here, to run repeatedly:
  int VA0 = analogRead(A0);
  int D8 = digitalRead(8);

  if(VA0 > 0.7 && VA0 < 1.5){
    // not exact parameters - need to determine the correct ADC values when the voltage across the resistor are equal to these values
    Serial.println("No field detected");
    // If the reported adc (analogue to digital) value is between this range, do not detect a field
  }
  else{
    // if adc is outside of range, a field is detected with the BHS
    if(D8 == HIGH){
      // with UHS, if the signal is high then output is 1 and south detected
      Serial.println("South detected!");
    }
    else{
      Serial.println("North detected!");
    }
  }

}
