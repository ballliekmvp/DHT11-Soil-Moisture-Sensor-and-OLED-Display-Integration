# DHT11-Soil-Moisture-Sensor-and-OLED-Display-Integration
This project shows how to interface a DHT11 temperature and humidity sensor, a soil moisture sensor, and an SSD1306 OLED display with an Arduino. It reads data from the sensors and displays temperature, humidity, and soil moisture percentage (0-100%) on the OLED screen.

### Features:
- **DHT11 Sensor**: Measures temperature and humidity.
- **Soil Moisture Sensor**: Measures the soil moisture level and displays it as a percentage.
- **SSD1306 OLED Display**: Displays temperature, humidity, and soil moisture readings in real time.
  
### Components Required:
- Arduino board (e.g., Arduino Uno)
- DHT11 temperature and humidity sensor
- Soil moisture sensor
- SSD1306 OLED display (128x64)
- Jumper wires and breadboard

### Circuit Connections:
1. **DHT11 Sensor**:
   - VCC → 5V
   - GND → GND
   - Data → Pin 7 on Arduino

2. **Soil Moisture Sensor**:
   - VCC → 5V
   - GND → GND
   - Analog Pin → Pin A0 on Arduino

3. **SSD1306 OLED Display**:
   - VCC → 5V
   - GND → GND
   - CS → Pin 12 on Arduino
   - DC → Pin 11 on Arduino
   - RESET → Pin 13 on Arduino
   - SDA → Pin 9 (MOSI) on Arduino
   - SCL → Pin 10 (SCK) on Arduino

### Libraries Used:
- **Adafruit_GFX**: A core graphics library for the OLED display.
- **Adafruit_SSD1306**: Library for controlling the SSD1306 OLED display.
- **DHT**: Library for the DHT temperature and humidity sensor.

### Installation:
1. Clone this repository to your local machine.
2. Open the Arduino IDE and install the necessary libraries:
   - **Adafruit_GFX**
   - **Adafruit_SSD1306**
   - **DHT sensor library**
3. Upload the code to your Arduino board.
4. Connect the components as shown in the circuit connections.
5. View the output on the OLED display, which shows real-time temperature, humidity, and soil moisture data.
