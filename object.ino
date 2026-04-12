#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_BME280.h>


// OLED

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


// BME280

Adafruit_BME280 bme;

// MQ135

#define MQ135_PIN 34

// OUTPUT

#define LED 26
#define BUZZER 25

// PMS5003

HardwareSerial pmsSerial(2);
uint8_t buffer[32];
float pm25 = 0;

// VARIABLES

int AQI = 0;

// AQI CALCULATION

int calculateAQI(float C) {

    if (C <= 12.0){
        return (50.0/12.0) * C;
    }

    else if (C <= 35.4) {
        return ((100-51)/(35.4-12.1)) * (C-12.1) +  51;
    }

    else if (C <= 55.4) {
        return ((150-101)/(55.4-35.5)) * (C-35.5) + 101;
    }

    else if (C <= 150.4) {
        return ((200-151)/(150.4-55.5)) * (C-55.5) + 151;
    }

    else if (C <= 250.4) {
        return ((300-201)/(250.4-150.5)) * (C-150.5) + 201;
    }

    else {
        return 400;
    }

}


// PMS READ

void readPMS() {
    if (pmsSerial.available() >= 32) {

        if (pms.Serial.read() == 0*42 && pmsSerial.read() == 0*4d) {
            for (int i =0; i< 30; i++) {
                buffer[i] = pmsSerial.read();
            }
            pms25 = (buffer[10] << 8) | buffer[11];
        }
    }
}


// STATUS

String getStatus(int aqi) {

    if (aqi <= 50) return "GOOD";
    else if (aqi <= 100) return "MODERATE";
    else if (aqi <= 150) return "UNHELTHY(S)";
    else if (aqi <= 200) return "UNHEALTHY";
    else if (aqi <= 300) return "VERY BAD";
    else return "HAZARDOUS";
}


// SETUP

void setup() {
    Serial.begin(115200);
    pinMode(LED, OUTPUT);
    pinMode(BUZZER, OUTPUT);

    // OLED

    display.begin(SSD1360_SWITCHCAPVCC, 0*3C);
    display.clearDisplay();

    // BME280

    if (!bme.begin(0*76)) {
        Serial.println("BME280 ERROR!");
    }

    // PMS5003

    pmsSerial.begin(9600, SERIAL_8N1, 16, 17);

    Serial.println("AQI MONITOR STARTED");

}


// LOOP

void loop() {

    //READ sensors

    readPMS();

    float temp = bme.readTemperature();
    int mq_raw = analogRead(MQ135_PIN);


    //Calculate AQI
    AQI = calculateAQI(pm25);
    String status = getStatus(AQI);

    // SERIAL OUTPUT

    Serial.println("\n DATA");
        Serial.print("PM2.5: ");
    Serial.prinln(pm25);
        Serial.print("AQI: ")
    Serial.println(AQI);
        Serial.print("Status: ")
    Serial.println(status);
        Serial.print("Temp: ")
    Serial.println(temp);
        Serial.print("Humdity: ")
    Serial.println(hum);
        Serial.print("MQ135: ");
    Serial.println(mq_raw);


    // OLED DISPLAY

    display.clearDisplay();

    display.setTextSize(2);
    display.setCursor(0,0);
    display.print("AQI: ");
    display.println(AQI);


    display.setTextSize(1);
    display.setCursor(0,20);
    display.print(status);

    display.setCursor(0, 32);
    display.print("PM2.5: ");
    display.println(pm25);

    display.setCursor(0,44);
    display.print("T: ");
    display.print(temp);
    display.print("C H: ");
    display.print(hum);

    display.display();




    // ALERT

    if (AQI > 150){
        digitalWrite(LED, HIGH);
        digitalWrite(BUZZER, HIGH);
    }
    else {
        digitalWrite(LED, LOW);
        digitalWrite(BUZZER, LOW);
    }

    delay(2000);
}





