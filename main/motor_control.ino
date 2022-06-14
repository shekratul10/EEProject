const unsigned long interval = 2000;
unsigned long startTime = 0;
unsigned long endTime = 2000;
unsigned long currTime = millis();

void setup() {
  // put your setup code here, to run once:
 pinMode(12,OUTPUT);
 pinMode(13,OUTPUT);
 pinMode(8,OUTPUT);
 pinMode(9,OUTPUT);
 Serial.begin(9600);
 
}

void still() {
  while(startTime <= currTime && currTime <= endTime){
    analogWrite(12,0);
    analogWrite(8,0);//analogWrite(pin,255,0)
    currTime = millis();
    Serial.println("still");
  }
  startTime += interval;
  endTime += interval;
  return;
}

void forward() {
  digitalWrite(13,HIGH);
  digitalWrite(9,LOW);
  while(startTime <= currTime && currTime <= endTime){
    analogWrite(12,200);
    analogWrite(8,200);
    currTime = millis();
  }
  startTime += interval;
  endTime += interval;
  return;
}

void left(){
  digitalWrite(13,HIGH);
  digitalWrite(9,HIGH);
  while(startTime <= currTime && currTime <= (endTime-1000)){
    analogWrite(12,150);
    analogWrite(8,150);
    currTime = millis();
    Serial.println("in whileloop");
  }
  while(startTime <= currTime && currTime <= endTime){
    analogWrite(12,0);
    analogWrite(8,0);
    currTime = millis();
    Serial.println("in whileloop2");
  }
  startTime += interval;
  endTime += interval;
  return;
}

void right(){
  digitalWrite(13,LOW);
  digitalWrite(9,LOW);
  while(startTime <= currTime && currTime <= (endTime-1000)){
    analogWrite(12,150);
    analogWrite(8,150);
    currTime = millis();
    Serial.println("in whileloop");
  }
  while(startTime <= currTime && currTime <= endTime){
    analogWrite(12,0);
    analogWrite(8,0);
    currTime = millis();
    Serial.println("in whileloop2");
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
    analogWrite(12,200);
    analogWrite(8,200);
    currTime = millis();
  }
  startTime += interval;
  endTime += interval;
  return;
}
void fwdright(){
  digitalWrite(13,LOW);
  digitalWrite(9,LOW);
  while(startTime <= currTime && currTime <= (endTime - 1500)){
    analogWrite(12,150);
    analogWrite(8,150);
    currTime = millis();
    }
  digitalWrite(13,HIGH);
  digitalWrite(9,LOW);
  while(startTime <= currTime && currTime <= endTime){
    analogWrite(12,200);
    analogWrite(8,200);
    currTime = millis();
    }
  startTime += interval;
  endTime += interval;
  return;
}
void fwdleft(){
  digitalWrite(13,HIGH);
  digitalWrite(9,HIGH);
  while(startTime <= currTime && currTime <= (endTime - 1500)){
    analogWrite(12,150);
    analogWrite(8,150);
    currTime = millis();
    }
  digitalWrite(13,HIGH);
  digitalWrite(9,LOW);
  while(startTime <= currTime && currTime <= endTime){
    analogWrite(12,200);
    analogWrite(8,200);
    currTime = millis();
    }
  startTime += interval;
  endTime += interval;
  return;
}
void revright(){
  digitalWrite(13,HIGH);
  digitalWrite(9,HIGH);
  while(startTime <= currTime && currTime <= (endTime - 1500)){
    analogWrite(12,150);
    analogWrite(8,150);
    currTime = millis();
    }
  digitalWrite(13,LOW);
  digitalWrite(9,HIGH);
  while(startTime <= currTime && currTime <= endTime){
    analogWrite(12,200);
    analogWrite(8,200);
    currTime = millis();
    }
  startTime += interval;
  endTime += interval;
  return;
}
void revleft(){
  digitalWrite(13,LOW);
  digitalWrite(9,LOW);
  while(startTime <= currTime && currTime <= (endTime - 1500)){
    analogWrite(12,150);
    analogWrite(8,150);
    currTime = millis();
    }
  digitalWrite(13,LOW);
  digitalWrite(9,HIGH);
  while(startTime <= currTime && currTime <= endTime){
    analogWrite(12,200);
    analogWrite(8,200);
    currTime = millis();
    }
  startTime += interval;
  endTime += interval;
  return;
}


void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("entering loop");
  forward();
  reverse();
  left();
  right();
  fwdright();
  fwdleft();
  revright();
  revleft();
  still();
  
    
}
