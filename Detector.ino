
#define DETECTOR_TRIG_PIN  12
#define DETECTOR_ECHO_PIN  11

int startTime = 0;
int endTime = 0;
int activeDuration = 10 * 1000; // 10 seconds
int now = 0;
int initialDistance = 0;
int offsetDistance = 10;
bool currentState = false;


void setupDetector() {
  pinMode(DETECTOR_TRIG_PIN, OUTPUT);
  pinMode(DETECTOR_ECHO_PIN, INPUT);
  initialDistance = getDistance();
}

long getDistance() {
  long signalTime, distance;
 
  digitalWrite(DETECTOR_TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(DETECTOR_TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(DETECTOR_TRIG_PIN, LOW);
 
  signalTime = pulseIn(DETECTOR_ECHO_PIN, HIGH);
  distance = signalTime / 58;
  return distance;
}

bool getDetectorState() {
  long distance = getDistance();
  
  return distance > initialDistance + offsetDistance 
    || distance < initialDistance - offsetDistance;
}

bool checkIsActive() {
  currentState = getDetectorState();
  now = millis();
  if(now < endTime){
    return true;
  }
  if(currentState){
    startTime = now;
    endTime = now + activeDuration;
    return true;
  }
  return false;
}