#define PHOTORESISTOR A2
#define LED_PIN 13

const int BRIGHTNESS_MAX = 220;
bool blinkingActive = false;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(PHOTORESISTOR, INPUT);
  Serial.begin(9600);
}

void loop() {
  int brightness = readBright();
  if (brightness >= BRIGHTNESS_MAX && !blinkingActive) {
    blinkingActive = true;
    startBlinking();
  }

 if (blinkingActive) {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');

    command.trim();
    command.toLowerCase();

    if (command == "stop") {
      blinkingActive = false;
      digitalWrite(LED_PIN, LOW);
    }
  }
}

  if (blinkingActive) {
    blinkLED();
  }

  delay(1000);
}

int readBright() {

  int brightness = analogRead(PHOTORESISTOR);

  int mappedBrightness = map(brightness, 0, 1023, 0, 255);

  Serial.print("Mapped Brightness: ");
  Serial.println(mappedBrightness);
  
  return mappedBrightness;
}

void startBlinking() {
  digitalWrite(LED_PIN, HIGH);
  delay(100);
  digitalWrite(LED_PIN, LOW);
  delay(100);
}

void blinkLED() {
  digitalWrite(LED_PIN, HIGH);
  delay(100);
  digitalWrite(LED_PIN, LOW);
  delay(100);
}
