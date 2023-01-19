// 4-1 3.2
// LCD 모듈에 표시
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  lcd.init();
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("LCD");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("welcome");
  delay(250);

  
  lcd.noBacklight();
  delay(250);
  lcd.backlight();
  delay(250);
  lcd.noBacklight();
  delay(250);
  lcd.backlight();
  delay(3000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Open serial Mntr");
  lcd.setCursor(0,1);
  lcd.print("Type to display");
}

void loop() {
  // put your main code here, to run repeatedly:

  if(Serial.available()){
      delay(100);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Message from PC");
      lcd.setCursor(0,1);

      while(Serial.available()>0){
          lcd.write(Serial.read());
        }
    }
}
