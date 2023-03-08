bool active = false;


void setup() {
  Serial.begin(57600);
  setupDetector();
  setupPump();
  setupServo();
}

void loop() {
  active = checkIsActive();
  updateServo(active);
  updatePump(active);
  delay(15);   
}