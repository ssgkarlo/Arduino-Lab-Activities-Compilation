void setup() {
    pinMode(13, OUTPUT); // LED on pin 13
    Serial.begin(9600);  // Start serial communicationc:\Users\Fatima\Downloads\arduino\sketch_jan13a c:\Users\Fatima\Downloads\arduino\sketch_jan13b
}

void loop() {
    if (Serial.available() > 0) {  // Check if data is available
        char command = Serial.read(); // Read the incoming byte
        if (command == '1') {  // If command is '1'
            digitalWrite(13, HIGH); // Turn LED on
        } else if (command == '0') {  // If command is '0'
            digitalWrite(13, LOW); // Turn LED off
        }
    }
}
