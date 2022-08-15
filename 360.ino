#include <HCSR04.h>
#include <Servo.h>

UltraSonicDistanceSensor distanceSensor(6, 7);         
UltraSonicDistanceSensor distanceSensor2(5, 4);      
Servo servoMotor;          

int delayTime = 5;   
long d;                 
long d2;             

void setup() {
  Serial.begin(9600);          

  servoMotor.attach(2);     
  servoMotor.write(0);      
  delay(1000);              

}

void loop() {
  for (int i = 1; i < 180; i++) {
    readSensors();           
    displayData(i,d,d2);
    servoMotor.write(i);       
    delay(delayTime);        
  }
  for (int i = 180; i > 1; i--) {  
    readSensors();            
    displayData(i,d,d2);
    servoMotor.write(i);     
    delay(delayTime);        
  }
}

void readSensors() {
  d = distanceSensor.measureDistanceCm();
  d2 = distanceSensor2.measureDistanceCm();
}

void displayData(int i , int d , int d2) {
    Serial.print("servo angle = "); 
    Serial.print(i);          
    Serial.print(" :: sensor 1 = ");          
    Serial.print(d);          
    Serial.print(" :: sensor 2 = ");        
    Serial.println(d2); 
}
