#include <Arduino.h>

// I Sanjay Kumar, 000811237 certify that the given work is my own work.
// I have not provided my work to someone else or not used anyone else
void setup() {
  // put your setup code here, to run once:

  //configure the USB serial monitor
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:

  int iVal;
  
  // read digitized value from the D1 Mini's A/D convertor

  iVal = analogRead(A0);

  float analogValve = (iVal*3.3)/1024; // Stores the analog value calculated from digital value

  float temprature = (50/3.3)*analogValve;

  // Variable that store the value of water condition Cold, Cool, Perfect, Hot, Too Hot
  String waterCondition = "";

  if(temprature < 10){
    waterCondition = "Cold!";
  }
  else if( temprature>=10 and temprature<15){
    waterCondition = "Cool";
  }
  else if( temprature >= 15 and temprature <25){
    waterCondition = "Perfect";
  }
  else if(temprature >=25 and temprature < 30){
    waterCondition = "Warm";
  }
  else if (temprature >= 30 and temprature <35){
    waterCondition = "Hot";
  }
  else{
    waterCondition = "Too Hot!";
  }

  // print value to the USB port
  Serial.println("Digitized Value = "+ String(iVal)+" is equivalent to a temprature input of "+String(temprature)+" deg. C, which is "+waterCondition);

  //wait 2 seconds(2000ms)
  delay(2000);
}