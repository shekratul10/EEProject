const unsigned long interval = 3000;
unsigned long startTime = 0;
unsigned long endTime = 3000;
unsigned long currTime = millis();

void setup() {
  // put your setup code here, to run once:
 pinMode(12,OUTPUT);
 pinMode(13,OUTPUT);
 pinMode(8,OUTPUT);
 pinMode(9,OUTPUT);
 Serial.begin(9600);
 
}

void stull() {
  while(startTime <= currTime && currTime <= endTime){// 3000ms < t < 6000ms
    Serial.println("STOP!!");
    analogWrite(12,0);
    analogWrite(8,0);
    currTime = millis();
  }
  startTime += interval;
  endTime += interval;
  return;

}

void forward() {
  digitalWrite(13,HIGH);
  digitalWrite(9,LOW);
  while(startTime <= currTime && currTime <= endTime){//0ms < t < 3000ms,
    Serial.println("forwards");
    analogWrite(12,127);
    analogWrite(8,127);
    currTime = millis();
  }
  startTime += interval;
  endTime += interval;
  return;
}

void left(){
  digitalWrite(13,HIGH);
  digitalWrite(9,HIGH);
  while(startTime <= currTime && currTime <= endTime){
    Serial.println("turning left");
    analogWrite(12,77);
    analogWrite(8,77);
    currTime = millis();
  }
  startTime += interval;
  endTime += interval;
  return;
}

void right(){
  digitalWrite(13,LOW);
  digitalWrite(9,LOW);
  while(startTime <= currTime && currTime <= endTime){
    Serial.println("turning right");
    analogWrite(12,77);
    analogWrite(8,77);
    currTime = millis();
  }
  startTime += interval;
  endTime += interval;
  return;
}

void reverse(){
  digitalWrite(13,LOW);
  digitalWrite(9,HIGH);
  while(startTime <= currTime && currTime <= endTime){
    Serial.println("reversing");
    analogWrite(12,127);
    analogWrite(8,127);
    currTime = millis();
  }
  startTime += interval;
  endTime += interval;
  return;
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("entering loop");
  left();
  stull();
  right();
  stull();
  forward();
  stull();
  reverse();
  stull(); 
  
  
  
    
}
