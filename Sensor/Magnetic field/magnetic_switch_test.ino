void setup() {
  // put your setup code here, to run once:
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  Serial.begin(1200);
}

void loop() {
  // put your main code here, to run repeatedly:
  int D8 = digitalRead(8);
  int D9 = digitalRead(9);

  if(D8 == HIGH){
    Serial.println("Magnetic field detected");
    if(D9 == HIGH){
      Serial.println("Magnetic field is up");
    }
    else{
      Serial.println("Magnetic field is down");
    }
  }
  
  else {
    Serial.println("No magnetic field");
  }
  delay(10);

}
