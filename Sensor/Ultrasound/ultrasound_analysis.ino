float freq, period;
int ontime, offtime;

void setup() {
  pinMode(4, INPUT);
  // assign digital pin 4 to be an input pin for our signal but this can be any digital pin
  Serial.begin(9600);
}

void loop() {
  ontime = pulseIn(4, HIGH);
  // see explanations for IR pulse circuits
  offtime = pulseIn(4, LOW);
  period = offtime + ontime;
  freq = 1000000/period;
  if(freq > 37037.03 && freq < 38461.54){
    Serial.println("Acoustic signal detected!");
  }
}
