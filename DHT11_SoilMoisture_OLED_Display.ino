#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

// Define the DHT sensor type and pin
#define DHTPIN 7      // Pin where the DHT11 is connected
#define DHTTYPE DHT11 // DHT11 sensor type

// Define OLED display size
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Define the SPI pins for the OLED screen
#define OLED_MOSI    9  // Connect to D1 (SDA) on OLED
#define OLED_CLK     10 // Connect to D0 (SCL) on OLED
#define OLED_DC      11 // Connect to DC on OLED
#define OLED_CS      12 // Connect to CS on OLED
#define OLED_RESET   13 // Connect to RST on OLED

// Create instances for DHT and OLED display
DHT dht(DHTPIN, DHTTYPE);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

// Define the soil moisture sensor pin
#define MOISTURE_PIN A0 // Soil moisture sensor connected to pin A0

void setup() {
  // Start serial communication (optional for debugging)
  Serial.begin(9600);

  // Initialize the DHT sensor
  dht.begin();

  // Initialize the OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Use 0x3C as the I2C address
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);  // Halt if OLED initialization fails
  }

  // Clear the display buffer
  display.clearDisplay();
  display.display();

  // Display a startup message
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(F("DHT11 & Moisture"));
  display.println(F("Initializing..."));
  display.display();
  delay(2000); // Pause for 2 seconds
}

void loop() {
  // Wait a few seconds between measurements
  delay(2000);

  // Read humidity and temperature from the DHT sensor
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Read soil moisture level
  int moistureLevel = analogRead(MOISTURE_PIN);
  // Map moisture level to a percentage (optional)
  int moisturePercentage = map(moistureLevel, 1023, 0, 0, 100); // 1023 = dry, 0 = wet

  // Clear the display buffer
  display.clearDisplay();

  // Check if the DHT readings are valid
  if (isnan(humidity) || isnan(temperature)) {
    display.setCursor(0, 0);
    display.println(F("Error reading from"));
    display.println(F("DHT sensor!"));
    display.display();
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Display the results on the OLED
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);

  // Display Humidity and Temperature
  display.print(F("Humidity: "));
  display.print(humidity);
  display.println(F(" %"));

  display.print(F("Temperature: "));
  display.print(temperature);
  display.println(F(" C"));

  // Display Soil Moisture
  display.setCursor(0, 40); // Move to the next line
  display.print(F("Soil Moisture: "));
  display.print(moisturePercentage);
  display.println(F(" %"));

  // Update the display with the new data
  display.display();

  // Optional: Print to Serial Monitor for debugging
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" C\t");
  Serial.print("Moisture: ");
  Serial.print(moisturePercentage);
  Serial.println(" %");
}
