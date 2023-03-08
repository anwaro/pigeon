
#define PUMP_PIN 6

void setupPump() {
    pinMode(PUMP_PIN, OUTPUT);
}

bool updatePump(bool state) {
    if(state){
      digitalWrite(PUMP_PIN, HIGH);
    } else {
      digitalWrite(PUMP_PIN, LOW);
    }
}
 