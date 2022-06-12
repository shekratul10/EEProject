float freq, period;
int ontime, offtime;

void setup() {
  pinMode(2, INPUT);
  Serial.begin(9600);

}

void loop() {
  CRadio();

}

void CRadio(){
  ontime = pulseIn(2, HIGH);
  offtime = pulseIn(2, LOW);
  period = offtime + ontime;
  freq = 1000000/period;
  if(ontime != 0){
    if(freq > 58000 && freq < 65000){
      // these are temporary values
      Serial.println("Radio carrier, 61 kHz");
    }
    else if(freq > 85000 && freq < 94000){
      // these are also temporary values
      Serial.println("Radio carrier, 89 kHz");
    }
  }
}
