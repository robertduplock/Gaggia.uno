// The brew time in milliseconds.
// E.g. 30000 equals 30 seconds.
const long brewTime = 30000; 

const int relayPin = 3;
const int brewSwitchPin = 10;
int relayState = LOW; 

unsigned long initTime = 0;

bool isFirstStart = true;

void setup() {
  pinMode(relayPin, OUTPUT);
  pinMode(brewSwitchPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void setRelayOn() {
  digitalWrite(relayPin, LOW);
}

void setRelayOff() {
  digitalWrite(relayPin, HIGH);
}

bool isBrewSwitchOn() {
  return digitalRead(brewSwitchPin) == LOW;
}

void loop() {
  if (initTime == 0) {
    initTime = millis();
    setRelayOff();
  }

  if (isBrewSwitchOn()) {
    if ((millis() - initTime) < brewTime) {
      setRelayOn();
    }
    else {
      setRelayOff();
    }    
  }

  if (!isBrewSwitchOn()) {
    setRelayOff();
    initTime = 0;
  }

  delay(100);
}
