#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

int redLed1 = 3;
int buzzer1 = 13;
int gasPin = A0;

void setup()
{
    pinMode(redLed1, OUTPUT);
    pinMode(buzzer1, OUTPUT);
    pinMode(gasPin, INPUT);
    Serial.begin(9600); // Baud rate untuk Serial Monitor
    dht.begin();
}

void loop()
{
    int gasSensor = analogRead(gasPin);

    delay(2000); //   delay read sensor

    float temperature = dht.readTemperature(); // Read temperature dari sesnor DHT11 

    Serial.print("Gas Sensor Value: ");
    Serial.println(gasSensor);
    Serial.print("Temperature: ");

    if (!isnan(temperature))
    {
        Serial.println(temperature);
    }
    else
    {
        Serial.println("Invalid temperature reading!");
    }

    delay(2000); // Delay untuk read Serial Monitor 

    //  LED and buzzer aktif saat gas atau temperature diatas threshold
    if (gasSensor > 500.00 || temperature > 39.00)
    {
        digitalWrite(redLed1, HIGH);
        tone(buzzer1, 5000); // Buzzer frequency
    }
    else
    {
        digitalWrite(redLed1, LOW);
        noTone(buzzer1);
    }
}