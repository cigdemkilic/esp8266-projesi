#include <HX711.h>

#include <Adafruit_Sensor.h>

#include "config.h"

#include <DHT.h>
#define DHTPIN 5 
#define DHTTYPE    DHT11  

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 13;
const int LOADCELL_SCK_PIN = 15;

HX711 scale;

float kalibrasyon = 17000;
DHT dht(DHTPIN, DHTTYPE);

// current temperature & humidity, updated in loop()
float t = 0.0;
float h = 0.0;

unsigned long previousMillis = 0;    // will store last time DHT was updated

// Updates DHT readings every 10 seconds
const long interval = 10000;  

#define kirmizi 14

// set up the 'digital' feed
AdafruitIO_Feed *deneme = io.feed("deneme");

void setup() {

// Serial port for debugging purposes
  Serial.begin(115200);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
 
  scale.set_scale(kalibrasyon);
  scale.tare(); 
  dht.begin();
  
   pinMode(kirmizi,OUTPUT);

  // wait for serial monitor to open
  while(! Serial);

  // connect to io.adafruit.com
  Serial.print("Connecting to Adafruit IO");
  io.connect();

  // wait for a connection
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  // we are connected
  Serial.println();
  Serial.println(io.statusText());

}

void loop() {
  io.run();
  Serial.println("--------------");
  Serial.print("Kütle: ");
  Serial.print(scale.get_units());
  Serial.println("kg");
  if(scale.get_units()< 2.00){

    Serial.println("Yem bitmek üzere!!! Yem takviyesi yapınız!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");

    }
delay(10000);

  
  digitalWrite(kirmizi,LOW);

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    // save the last time you updated the DHT values
    previousMillis = currentMillis;
    // Read temperature as Celsius (the default)
    float newT = dht.readTemperature();
    // Read temperature as Fahrenheit (isFahrenheit = true)
    //float newT = dht.readTemperature(true);
    // if temperature read failed, don't change t value
    if (isnan(newT)) {
      Serial.println("Failed to read from DHT sensor!");
    }
    else {
      t = newT;
      Serial.println("---------------");

      Serial.print("temperature: ");
      Serial.println(t);
        deneme->save(t);

    }
    // Read Humidity
    float newH = dht.readHumidity();
    // if humidity read failed, don't change h value 
    if (isnan(newH)) {
      Serial.println("Failed to read from DHT sensor!");
    }
    else {
      h = newH;
            Serial.print("humidity : ");
      Serial.println(h);
          

    }
     //sıcaklık değeri 10 ve 30 aralık dışındaysa veya nem 40 ve 70 aralık dışındaysa uyarı oluştur.
  if ((t<=10 || t>=30) & (h<=40 || h>=65)){

    Serial.println("Sıcaklık ve nem tehlikeli seviyededir!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
  
    digitalWrite(kirmizi,HIGH);
    delay(10000);
      deneme->save(h);

    
    }
  }
}
