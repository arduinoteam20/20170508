#include <Wire.h>
#include <LiquidCrystal.h> 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int SLAVE_ADDRESS = 2;
char incomingByte = 0;
void setup() {
lcd.begin(20, 2);
Serial.begin(9600);
Wire.begin(2); 
}
void loop() {
Wire.requestFrom(SLAVE_ADDRESS, 20);

while (Wire.available()) {
incomingByte = Wire.read(); // receive a byte
lcd.write(incomingByte);
delay(1000);
}
}
