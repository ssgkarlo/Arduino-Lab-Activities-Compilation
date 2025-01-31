const int buttonPin = 12; // Connect your button to pin 12
int buttonState = 0;

void setup() {
    pinMode(buttonPin, INPUT_PULLUP); // Use internal pull-up resistor
    Serial.begin(9600);              // Initialize serial communication
}

void loop() {
    buttonState = digitalRead(buttonPin); // Read button state (HIGH/LOW)

    // Send "group3_on" or "group3_off" based on button state
    if (buttonState == LOW) { // LOW indicates the button is pressed (due to pull-up resistor)
        Serial.println("group3_off");  // Button pressed
    } else {
        Serial.println("group3_on");  // Button not pressed
    }

    delay(200); // Adjust as needed to avoid spamming data
}
