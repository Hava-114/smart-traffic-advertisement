// Sender Arduino - Controls traffic lights and sends state to receiver
const int greenLed = 2;
const int orangeLed = 3;
const int redLed = 4;
const int stateOutputPin = 5;  // Connected to Receiver's pin 4

int currentState = 0;  // 0: green, 1: orange, 2: red
unsigned long lastStateChange = 0;
unsigned long stateDurations[] = {5000, 2000, 7000};  // green, orange, red durations
bool adsChanged = false;

void setup() {
  Serial.begin(9600);
  Serial.println("Sender Arduino - Traffic Light Controller Started");
  
  pinMode(greenLed, OUTPUT);
  pinMode(orangeLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(stateOutputPin, OUTPUT);
  
  // Start with green light
  setLights(0);
  lastStateChange = millis();
  
  // Initialize state output
  digitalWrite(stateOutputPin, LOW);  // Start with NOT RED signal
}

void loop() {
  unsigned long currentTime = millis();
  
  // Check if it's time to change state
  if (currentTime - lastStateChange >= stateDurations[currentState]) {
    changeState();
  }
  
  // Send state to receiver
  sendStateToReceiver();
  
  // Small delay to prevent flickering
  delay(100);
}

void changeState() {
  currentState = (currentState + 1) % 3;
  setLights(currentState);
  lastStateChange = millis();
  
  Serial.print("State changed to: ");
  switch(currentState) {
    case 0: Serial.println("GREEN"); break;
    case 1: Serial.println("ORANGE"); break;
    case 2: Serial.println("RED"); break;
  }
}

void setLights(int state) {
  // Turn all lights off first
  digitalWrite(greenLed, LOW);
  digitalWrite(orangeLed, LOW);
  digitalWrite(redLed, LOW);
  
  // Turn on the appropriate light
  switch(state) {
    case 0: digitalWrite(greenLed, HIGH); break;
    case 1: digitalWrite(orangeLed, HIGH); break;
    case 2: digitalWrite(redLed, HIGH); break;
  }
}

void sendStateToReceiver() {
  // Use digital pin 5 to signal receiver
  static int lastSentState = -1;
  
  if (currentState != lastSentState) {
    // Send state to receiver - HIGH during red light, LOW otherwise
    digitalWrite(stateOutputPin, currentState == 2 ? HIGH : LOW);
    
    // Also send serial data for debugging
    Serial.print("Sending state to receiver: ");
    Serial.println(currentState == 2 ? "RED" : "NOT RED");
    
    lastSentState = currentState;
  }
}