#include <SoftwareSerial.h>

char data=0;

void setup(){
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}

void loop(){
   while(Serial.available()==0);
   data = Serial.read();
   digitalWrite(13,HIGH);
   delay(50);
   digitalWrite(13,LOW);
   
   if(Serial){
       data++;
       Serial.println(data);
   }
}

