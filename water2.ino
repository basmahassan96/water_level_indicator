
#include <SoftwareSerial.h>
byte sensorPin[] = {3,4,5,6};
byte ledPin[] = {11, 12, 13}; // number of leds = numbers of sensors
const byte sensors = 4;
int level = -1; 
int m1 = 22;
int m2 = 23;
int flag=0;
char value;
void setup() {
  /*for(int i = 0; i < sensors; i++) {
     pinMode(sensorPin[i], INPUT); 
     pinMode(ledPin[i], OUTPUT);
  }*/
  pinMode(sensorPin[0], INPUT); 
  pinMode(sensorPin[1], INPUT); 
  pinMode(sensorPin[2], INPUT); 
  pinMode(sensorPin[3], INPUT); 
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
 Serial.begin(9600);
}

void loop() {
  level = -1; 
  for(int i = 0; i < sensors; i++) {
    delay(50);
     if(digitalRead(sensorPin[i]) == LOW) {
        //igitalWrite(ledPin[i], HIGH);
        level = sensors - i;
     } else {
        //level = -1;
       //digitalWrite(ledPin[i], LOW);       
     }    
  }
    
  switch(level) {
     case 1:
      Serial.println("4");
       flag=0;
      break;
     case 2:
      Serial.println("3");
     
      break;
     case 3:
       Serial.println("2");
       
       break;
     case 4:
       Serial.println("1");
      
       break;
     default:
      Serial.println("0"); 
        
      break;
  }
  delay(50);  
   if(Serial.available())
  { 
    value = Serial.read();
    Serial.println(value);
    if(value =='F')
      flag=0;
    if(value =='N')
      flag=1; 
       Serial.println(flag);
  }
 
    if (flag == 1)
      {
        digitalWrite(m1,HIGH);
        digitalWrite(m2,LOW);
         
      }
     else if(flag == 0 )
      {
        digitalWrite(m1,LOW);
        digitalWrite(m2,LOW);
      }
 }
