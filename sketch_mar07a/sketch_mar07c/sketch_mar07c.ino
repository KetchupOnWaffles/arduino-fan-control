#include <OneWire.h>
#include <DallasTemperature.h>
// include the library code:
#include <LiquidCrystal.h>
#define ONE_WIRE_BUS 6
#include <dht.h>
#define dht_apin A0 // Analog Pin sensor is connected to
#define EnA 10
#define In1 9
#define In2 8
dht DHT;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

 float Celcius=0;
 float Fahrenheit=0;



void setup(void){
    delay(500);//Delay to let system boot
  lcd.begin(16, 2);
  Serial.begin(9600);
  sensors.begin();
  delay(1000);





  pinMode(EnA, OUTPUT);
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
}

void loop(void){
  lcd.setCursor(0,0);
  lcd.display();
      DHT.read11(dht_apin);
Serial.print(DHT.humidity);
Serial.print(DHT.temperature);
lcd.print(DHT.humidity);
lcd.print(" ");
lcd.print(DHT.temperature);


  lcd.setCursor(0,1);
  lcd.print(Celcius);
  Serial.println(Celcius);
  sensors.requestTemperatures();
  Celcius=sensors.getTempCByIndex(0);
  lcd.print(" ");
  digitalWrite(In1, LOW);
digitalWrite(In2, HIGH);
// set speed to 150 out 255
analogWrite(EnA, 255);
  lcd.clear();
}
