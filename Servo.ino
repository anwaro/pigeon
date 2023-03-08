#include <Servo.h>

Servo myservo;  // create servo object to control a servo
int minAngle = 0;
int maxAngle = 100;
int initialAngle = 50;
int currentAngle = 0;
int dAngle = 1;


void setupServo() {
  // pass
}

void updateServo(bool active) {
  if(active){
    if(currentAngle + dAngle < minAngle || currentAngle + dAngle > maxAngle){
      dAngle *= -1;
    }
    currentAngle += dAngle;
    moveServo();
  } else if(currentAngle != initialAngle){
    currentAngle = initialAngle;
    moveServo();
  } 
}
 

void moveServo() {
  myservo.write(currentAngle);  
}
 