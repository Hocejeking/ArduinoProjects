#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);
void setup() {
lcd.init();
lcd.backlight();

}

void loop() {


for(int t = 0;t <= 16; t++)
  {
    lcd.setCursor(t,0);
    lcd.print("za jedna");
    delay(1000);
    lcd.clear();
    
  }
}
