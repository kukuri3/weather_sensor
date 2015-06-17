#include <Wire.h>
#include <MPL115A2.h>
#include <Sensirion.h>

const uint8_t dataPin  =  18;
const uint8_t clockPin =  19;

float temperature;
float humidity;
float dewpoint;
float p;

Sensirion tempSensor = Sensirion(dataPin, clockPin);

void setup () {
  Serial.begin(9600);
  MPL115A2.begin();
  p=MPL115A2.read();
}

void loop () {

  
  
   tempSensor.measure(&temperature, &humidity, &dewpoint);

  Serial.print(millis()/1000);
  Serial.print(",");
  Serial.print(temperature);
  Serial.print(",Humidity[%],");
  Serial.print(humidity);
  Serial.print(", Dewpoint[C],");
  Serial.print(dewpoint);
  Serial.print(", Pressure[hp],");
  
  p=p*0.9+(MPL115A2.read()*0.1);
  Serial.print(p);
  Serial.println(",");
  delay(10000);
}


