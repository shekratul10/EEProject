/*//Test the EEEBug motors by generating two PWM signals
//The speed of each motor should rise and fall over a period of 2 seconds
unsigned int i = 0;
unsigned long  prevMillis = 0;
unsigned long  interval = 3000;
const unsigned int increment = 16;
 
void setup() {
  // put your setup code here, to run once:
  pinMode(6,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(LED_BUILTIN,OUTPUT);
  
}

void loop() {
    ///forwards
    digitalWrite(8,HIGH);
    analogWrite(9, 100);
    analogWrite(11,100);
    delay(2000);
    //turn right
    digitalWrite(8,HIGH);
    digitalWrite(6,HIGH);
    analogWrite(9,100);
    analogWrite(11,100);
    delay(2000);
    //turn left
    digitalWrite(8,LOW);
    digitalWrite(6,LOW);
    analogWrite(9,100);
    analogWrite(11,100);
    delay(2000);
    //reverse
    digitalWrite(8,LOW);
    digitalWrite(6,HIGH);
    analogWrite(9,100);
    analogWrite(11,100);
    delay(2000); ***
    unsigned long currMillis = millis();
 
  if(currMillis - prevMillis > interval) {
    analogWrite(9,100);
    prevMillis = currMillis;   
    
  }
  
    
   
}***/
//Test the EEEBug motors by generating two PWM signals
//The speed of each motor should rise and fall over a period of 2 seconds

unsigned int i=0;
unsigned long nextTime = 0;
const unsigned long time1 = 1000;
const unsigned long time2 = 3000;
const unsigned int STEP = 16;

void setup() {
  // put your setup code here, to run once:
  pinMode(6,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(LED_BUILTIN,OUTPUT);
  
}
void forward(){
  digitalWrite(8,HIGH);
  digitalWrite(6,LOW);
  if (millis()>nextTime){ //Is it time to update the output?
    nextTime += time1;  //Calculate next update time
    i += STEP;                //Increment output counter
  
    if (i&256){        
      analogWrite(9,i&127); 
      analogWrite(11,i&127);
      }
      
    else {
      analogWrite(9,127-(i&127));   
      analogWrite(11,127-(i&127));
      } 
    }

    digitalWrite(LED_BUILTIN,i&0x80); //Flash the LED
  }
void reverse(){
  digitalWrite(8,LOW);
  digitalWrite(6,HIGH);
  if(millis()>nextTime){
    nextTime += time2;
    i += STEP;
    
    if(i&256){
     analogWrite(9,i&127); 
     analogWrite(11,i&127);
      }
      
    else {
      digitalWrite(8,HIGH);
      digitalWrite(6,LOW);
      analogWrite(9,127-(i&127));   
      analogWrite(11,127-(i&127));
      } 
  }
}
void right(){
  digitalWrite(8,LOW);
  digitalWrite(6,LOW);
  if(millis()>nextTime){
    nextTime += time1;
    i += STEP;
    
    if(i&256){
     analogWrite(9,i&127); 
     analogWrite(11,i&127);
      }
      
    else {
      digitalWrite(8,HIGH);
      digitalWrite(6,HIGH);
      analogWrite(9,127-(i&127));   
      analogWrite(11,127-(i&127));
      } 
  }
}
void left(){
  digitalWrite(8,HIGH);
  digitalWrite(6,HIGH);
  if(millis()>nextTime){
    nextTime += time2;
    i += STEP;
    
    if(i&256){
     analogWrite(9,i&127); 
     analogWrite(11,i&127);
      }
      
    else {
      digitalWrite(8,LOW);
      digitalWrite(6,LOW);
      analogWrite(9,127-(i&127));   
      analogWrite(11,127-(i&127));
      } 
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  
  
  
   
}
