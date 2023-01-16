#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

int pos1 = 0;
int pos2 = 0;
int pos3 = 0;
int pos4 = 0;

const int buttonPin = 7;
int buttonState = 0;
int x;

int cannon = 0;

void setup() {
  x = 0; 
  pinMode(buttonPin, INPUT_PULLUP);
  servo1.attach(5);
//  servo2.attach(2);
//  servo3.attach(3);
  servo4.attach(4);
  Serial.begin(9600);
  servo1.write(70);
//  servo2.write(70);
//  servo3.write(70); // janky
  servo4.write(70); //janky
  
}

void moveServos() {
  for (int i = 70; i < 130; i++) {
    
    servo1.write(i);
    servo4.write(i);
    delay(16);

  }
  
}

void moveServos2() {
for (int f = 130; f >= 70; f--) {
    servo1.write(f);
    servo4.write((f));
    delay(16); 
  }
}

void loop() {
  
  if (Serial.available() > 0) {
    int c = Serial.read();
    if (c == 'm') {
      cannon = 1;
    }
    if (c == 'e') {
      cannon = 0;
  }
}

  buttonState = digitalRead(buttonPin);
  if (cannon == 0) {
  
  
  if(buttonState == 1){ 
    Serial.println(x); 
    if (x == 0){
      Serial.println("Going up");
      x = 1;
      moveServos();
      //Serial.print(x);
      delay(30);
    } 
    
    else if (x == 1) {
      Serial.println("Going down");
      //Serial.print('Hello');
      x = 0;
      moveServos2();
      //Serial.print(x);
      delay(30);
    } 
    Serial.println(x); 
  }
  

}
else if (cannon == 1) {
  if(buttonState == 1){ 
    Serial.println(x); 
    if (x == 0){
      x = 1;
      servo1.write(130);
      servo4.write(130);
      
      delay(300);
    } 
    
    else if (x == 1) {
      x = 0;
      servo1.write(70);
      servo4.write(70);
      
      delay(300);
    }   
}
}
}