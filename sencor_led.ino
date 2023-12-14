#define BLYNK_TEMPLATE_ID "TMPL6olGadY6y"
#define BLYNK_TEMPLATE_NAME "SensorLed"
#define BLYNK_AUTH_TOKEN "DLu_NV6FicjE1YMrCzbGxzk7-yQ26bpu"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define Sensor D0
#define LED_1 D1
#define LED_2 D2
#define LED_3 D3

char auth[] = BLYNK_AUTH_TOKEN;
// char ssid[] = "shinlink";
// char pass[] = "11111111";
char ssid[] = "Dung";
char pass[] = "20002003";

bool sensorEnabled = true;

BLYNK_WRITE(V2) {
  sensorEnabled = param.asInt();
}

void setup() {
  Serial.begin(9600);
  pinMode(Sensor, INPUT);
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);

  Blynk.begin(auth,ssid,pass, "blynk.cloud", 80);
}

void loop() {
  Blynk.run();
  if (sensorEnabled) { 
    int Value = analogRead(Sensor);
    Serial.print("Sensor value: ");
    Serial.println(Value);

    Blynk.virtualWrite(V0, Value);

    if (Value > 500) {  
      digitalWrite(LED_1, HIGH);
      digitalWrite(LED_2, HIGH);
      digitalWrite(LED_3, HIGH);

      Blynk.virtualWrite(V1, LOW);
    } else {
      digitalWrite(LED_1, LOW);
      digitalWrite(LED_2, LOW);
      digitalWrite(LED_3, LOW);
      
      Blynk.virtualWrite(V1, HIGH);
      delay(4000);
    }
  }

  delay(1000);
}
