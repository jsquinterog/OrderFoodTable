#include <Servo.h> 

Servo servo1;  
Servo servo2; 
Servo servo3;
Servo servo4;
char a;
String readString; 
void setup() {
  pinMode(13,OUTPUT);
  servo1.attach(3); 
  servo2.attach(5); 
  servo3.attach(6);  
  servo4.attach(9); 
  Serial.begin(9600); 
  servo1.write(8);
  servo2.write(100);
  servo3.write(164);
  servo4.write(90);
  delay(10);
}

void loop() {
 if (Serial.available()) {  
    a = Serial.read();
    
    if(a=='A'){ //BASE
      motor1();
      delay(80);
    }
    
    if(a=='B'){ //SUPERIORBASE
      motor2();
      delay(80);
    }
    
    if(a=='C'){ //MOTORSEGUNDO_ESLABON
      motor3();
      delay(80);
    }
     if(a=='D'){ //EFECTOR_FINAL
      motor4();
      delay(80);
    }
    
  }
}  
  
void motor1(){
        delay(10);   
        while (Serial.available()) { 
                           
          char b = Serial.read();  
          readString += b;        
        }
        if (readString.length() >0) {   
          Serial.println(readString.toInt());  
          servo1.write(readString.toInt());
          readString=""; // Clear string
          delay(100);
        }
}

void motor2(){
        delay(10); 
        while (Serial.available()) {                  
          char b = Serial.read();  
          readString += b;         
        }
        if (readString.length() >0) { 
          Serial.println(readString.toInt());  
          servo2.write(readString.toInt());
          readString="";
          delay(100); 
        } 
}

void motor3(){
        delay(10); 
        while (Serial.available()) {                 
          char b = Serial.read();  
          readString += b;        
        }
        if (readString.length() >0) { 
          Serial.println(readString.toInt());  
          servo3.write(readString.toInt());
          readString="";
          delay(100); 
        } 
}
void motor4(){
        delay(10); 
        while (Serial.available()) {                  
          char b = Serial.read();  
          readString += b;        
        }
        if (readString.length() >0) { 
          Serial.println(readString.toInt());  
          servo4.write(readString.toInt());
          readString=""; 
          delay(100);
        } 
}
