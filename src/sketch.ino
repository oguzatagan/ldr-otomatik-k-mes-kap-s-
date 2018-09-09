#include <SimpleTimer.h>

int lightSensorPin = 1;
int motorDown = 2;
int motorUp = 3;
int lightSensor;
int lightState;
boolean doorstate = 0; //kapı açıksa 1, kapalıysa 0

SimpleTimer chickenCoopTimer;

void setup(){
  pinMode(lightSensorPin, INPUT);
  pinMode(motorDown, OUTPUT);
  pinMode(motorUp, OUTPUT);
  Serial.begin(9600);
  chickenCoopTimer.setInterval(6000, howIsLight);      // read the lightSensor every
}

void loop(){
  chickenCoopTimer.run();
  //howIsLight();
  if(lightState == 1){
    Serial.println("motor goes up!");
    digitalWrite(motorDown, LOW);
    motorGoUp();
    doorstate = 1;
    Serial.println("motor is up!");
  } else {
    Serial.println("motor goes down!");
    digitalWrite(motorUp, LOW);
    motorGoDown();
    doorstate = 0;
    Serial.println("motor is down!");
  }
}

void motorGoUp(){
  if (doorstate == 1) {
    digitalWrite(motorUp, LOW);
    Serial.println("Motor is up !");
    delay(100);
  } else {
    digitalWrite(motorUp, HIGH);
    Serial.println("Motor go up!");
    delay(100);
  }
}

void motorGoDown(){
  if (doorstate == 0) {
    digitalWrite(motorDown, LOW);
    Serial.println("Motor is down !");
    delay(100);
  } else {
    digitalWrite(motorDown, HIGH);
    Serial.println("Motor go down!");
    delay(100);
  }
}

void howIsLight(){
  lightSensor = analogRead(lightSensorPin);
  if(lightSensor >= 100){
    lightState = 1;
  } else {
    lightState = 0;
  }
  Serial.print("lighState is ");
  Serial.println(lightState);
}
