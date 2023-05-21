#include <dht.h>

dht DHT;

#define DHT11_PIN 2
int condition = 0;
float hum;
float temp;
const int buzzer = 4;

void setup(){
  Serial.begin(9600);
  pinMode(buzzer, 4);
}

void loop(){
  int chk = DHT.read11(DHT11_PIN);
  hum = DHT.humidity;
  temp = DHT.temperature;
  Serial.println(" ");
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println(" ");
  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.println(" ");

  if (temp < 20 || temp > 30) { 
    condition = condition + 1;
  } 

  if (hum < 40 || hum > 80) {
    condition = condition + 1;
  } 

  if (condition == 1) {
    Serial.print("Wound healing cannot occur! ");
    tone(buzzer, 2000, 3000);
  }
  if (condition == 2) {
    Serial.print("Let it breathe!");
    tone(buzzer, 2000, 3000);
  }
  if (condition == 0) {
      Serial.print("Wound healing can occur! ");
  }

  Serial.println(" ");
  delay(1500);
  condition = 0;
}
