int ledPins[] = {12, 11, 10, 9, 8} //change this into {11, 10, 9, 6, 5} if you're still using Arduino R3

void setup() {

  for (int i = 0; i < 5; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  int index = 0;

  while (index < 5) {
    for (int brightness = 0; brightness <= 255; brightness += 5) {
      int mappedBrightness = map(brightness, 0, 255, 0, 255);
      analogWrite(ledPins[index], mappedBrightness);
      delay(30); 
    }
    index++; 
    delay(200); 
  }

  delay(1000);

  index = 0;
  while (index < 5) {
    for (int brightness = 255; brightness >= 0; brightness -= 5) {
      int mappedBrightness = map(brightness, 0, 255, 0, 255);
      analogWrite(ledPins[index], mappedBrightness); 
      delay(30); 
    }
    index++;
    delay(200); 
  }

  delay(1000);
}
