#include <LiquidCrystal.h>  //управление на LCD дисплея

// дефиниране на пинове
const int sensor_pin = A1;  //сензор за влажност
const int LM = A0; // светлинен сензор
 const int motor = 13; //  мотор
 const int Red = 12; //  светодиод за червено
 const int Green = 11; // светодиод за зелено

 LiquidCrystal lcd(2, 3, 4, 5, 6, 7);  

void setup() {
 Serial.begin(9600); 
lcd.begin(16, 2); //настройки на пиновете на LCD дисплея
lcd.print("Automated Plant"); 
lcd.setCursor(0,1); //настройки на пиновете на LCD дисплея
lcd.print("Watering System!");
 pinMode(motor, OUTPUT); 
pinMode(Red, OUTPUT); 
pinMode(Green, OUTPUT);
 delay(2000);
 lcd.clear(); 
 lcd.print("Pump = ");
 delay(1000); 
lcd.clear(); 
}
 void loop() {
 int value = analogRead(LM); 
lcd.setCursor(6,0); 
lcd.setCursor(11,1);
 float moisture_percentage;
 int sensor_analog; 
sensor_analog = analogRead(sensor_pin);
 moisture_percentage = ( 100 - ( (sensor_analog/1023.00) * 100 ) );  // изчисляване на процент влажност
 lcd.print("Moisture Percentage = "); 
lcd.print(moisture_percentage); 
lcd.print("%\n\n"); delay(1000);
 }
