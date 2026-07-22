# EmvSense

**EmvSense** is an Arduino-based environmental monitoring system that combines a gas sensor, a DHT11 temperature and humidity sensor, and a DS3231 Real-Time Clock (RTC). The measured data is displayed on a 16x2 I2C LCD, while three push buttons allow the user to switch between different display modes.

## Features

- 🕒 Display the current **date and time** using the DS3231 RTC module.
- 🌡️ Display **temperature** and **humidity** measured by the DHT11 sensor.
- 💨 Display the **gas concentration** as a percentage from an analog gas sensor.
- 💡 Visual gas level indicator:
  - **Green LED** – Safe gas level.
  - **Red LED** – Gas concentration exceeds the predefined threshold.

## Hardware Components

- Arduino Uno (or compatible board)
- 16x2 I2C LCD Display
- DS3231 RTC Module
- DHT11 Temperature & Humidity Sensor
- Analog Gas Sensor (MQ Series)
- 3 Push Buttons
- Green LED
- Red LED
- Jumper Wires and Resistors

## How It Works

When the system starts, the LCD displays:

```text
Press any
button!
```

Each button activates a different display mode:

| Button | Function |
|--------|----------|
| Button 1 | Display current date and time |
| Button 2 | Display temperature and humidity |
| Button 3 | Display gas concentration (%) |

The program continuously reads data from all sensors and updates the selected information on the LCD.

The gas sensor value is converted into a percentage (0–100%). Depending on the measured value:

- **Below 20%** → Green LED turns ON.
- **20% or higher** → Red LED turns ON.

## Libraries Used

- `Wire.h`
- `LiquidCrystal_I2C.h`
- `RTClib.h`
- `DHT.h`

## Project Structure

```
EmvSense/
├── EmvSense.ino
└── README.md
```

## Future Improvements

- Add a buzzer for gas leak alarms.
- Store sensor data on an SD card.
- Display historical measurements.
- Connect to Wi-Fi for remote monitoring.
- Add a web dashboard or mobile application.

## License

This project is open source and available under the MIT License.

