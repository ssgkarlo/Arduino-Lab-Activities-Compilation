#define THERMISTOR A0
#define PHOTORESISTOR A2
#define LED 12

const int TEMP_MAX = 50;
const int BRIGHTNESS_MAX = 220;
const unsigned long COOLDOWN = 3000; 

bool fireAlertActive = false;
unsigned long lastAlertTime = 0;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(PHOTORESISTOR, INPUT);
  Serial.begin(9600);
}

void loop() {
  int temp = readTemp();
  int brightness = readBright();
  
  if (temp >= TEMP_MAX || brightness >= BRIGHTNESS_MAX) {
    fireAlertActive = true;
    lastAlertTime = millis();
  }

  if (fireAlertActive) {
    alertFire();
    
        if (millis() - lastAlertTime > COOLDOWN) {
      fireAlertActive = false;
      digitalWrite(LED, LOW);
    }
  } else {
    digitalWrite(LED, LOW);
  }

  delay(1000);
}

int readTemp() {
  int analogValue = analogRead(THERMISTOR);
  
  float voltage = analogValue * (5.0 / 1023.0);
  float tempC = (voltage - 0.5) * 100;
  
  Serial.print("Temperature in Celsius: ");
  Serial.println(tempC);
  
  return tempC;
}

int readBright() {
  int brightness = analogRead(PHOTORESISTOR);

  Serial.print("Brightness: ");
  Serial.println(brightness);
  
  return brightness;
}

void alertFire() {
  digitalWrite(LED, HIGH);
  delay(100);
  digitalWrite(LED, LOW);
  delay(100);
}
