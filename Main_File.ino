#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
String voice, number;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  
int cars=15;
#define frontandbackmotor 13
#define liftmotor 10
#define magnet 9

SoftwareSerial portOne(15, 14);
SoftwareSerial portTwo(17, 16);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  portOne.begin(9600);
  portTwo.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(1,0);
  lcd.print("SMART PARKING SYSTEM");
  delay(2000);
  lcd.clear();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  while (cars!=0) {
  portOne.listen();
  portTwo.listen();
  while(portOne.available()){
  delay(3);
  char c = Serial.read();
  voice+=c;}
  
  while(portTwo.available()){
  delay(3);
  char d = Serial.read();
  number+=d;}
  
  lcd.setCursor(0,0);
  lcd.print("Available Slots:");
  lcd.print(cars);
  delay(1000);
  lcd.clear();
  lcd.print("Scanning Vehicle Number: ");
  if (number == voice){
    lcd.clear();lcd.setCursor(0, 0);lcd.print("PARKING IN ");lcd.setCursor(0, 1);lcd.print("PROGRES..... ");
  digitalWrite(frontandbackmotor,HIGH);delay(500);digitalWrite(frontandbackmotor,LOW);
  digitalWrite(liftmotor,HIGH);delay(500);digitalWrite(liftmotor,LOW);
  digitalWrite(magnet,HIGH);delay(500);digitalWrite(magnet,LOW);
  cars=cars-1;
  lcd.clear();lcd.setCursor(0, 0);lcd.print("PARKING done ");delay(300);
  }

}
lcd.print("Slots Full");
}
