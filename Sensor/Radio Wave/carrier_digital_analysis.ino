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
    if(freq > 55555.55 && freq < 58823.53){
      Serial.println("Radio carrier, 61 kHz");
    }
    else if(freq > 83333.34 && freq < 90909.1){
      Serial.println("Radio carrier, 89 kHz");
    }
  }
}
