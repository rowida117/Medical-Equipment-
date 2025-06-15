#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 2             // DHT11 DATA pin connected to D2
#define DHTTYPE DHT11
#define RELAY_PIN 8          // Relay control pin for fan
#define TEMP_THRESHOLD 27.5  // Temperature threshold

#define PULSE_PIN A0         // KY-039 sensor analog pin
#define THRESHOLD 550        // Threshold for heartbeat detection

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Heart rate variables
bool beatDetected = false;
unsigned long lastBeatTime = 0;
unsigned long currentTime = 0;
int heart_rate = 0;

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("System Initializing");
  delay(1000);
  lcd.clear();
}

void loop() {
  // Read sensor values
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  int pulseValue = analogRead(PULSE_PIN);
  currentTime = millis();

  // Heartbeat detection logic
  if (pulseValue > THRESHOLD && !beatDetected) {
    unsigned long timeBetweenBeats = currentTime - lastBeatTime;
    if (timeBetweenBeats > 300) { // Avoid false triggers
      heart_rate = 60000 / timeBetweenBeats;
      lastBeatTime = currentTime;
    }
    beatDetected = true;
  }
  if (pulseValue < THRESHOLD) {
    beatDetected = false;
  }

  lcd.clear();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error!");
    delay(2000);
    return;
  }

  // Serial Debug
  Serial.print("Temp: ");
  Serial.print(temperature);
  Serial.print(" C | Humidity: ");
  Serial.print(humidity);
  Serial.print(" % | HR: ");
  Serial.println(heart_rate);

  // LCD Display
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temperature, 1);
  lcd.print("C H:");
  lcd.print(humidity, 0);

  lcd.setCursor(0, 1);
  if (temperature > TEMP_THRESHOLD) {
    digitalWrite(RELAY_PIN, LOW); // Fan ON
    lcd.print("Fan: ON ");
  } else {
    digitalWrite(RELAY_PIN, HIGH); // Fan OFF
    lcd.print("Fan: OFF");
  }

  lcd.print(" HR:");
  lcd.print(heart_rate);

  delay(200);  // Shorter delay for smoother heart detection
}
