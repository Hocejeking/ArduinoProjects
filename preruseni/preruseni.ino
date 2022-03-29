#include <Servo.h>

#include <LiquidCrystal_I2C.h>

#define led1  9
#define led2  11 
#define tlac1 3 
#define tlac2  2
int x =0,a=0,b=0;

LiquidCrystal_I2C lcd(0x27,16,2);
Servo servo;

void setup() {

  servo.attach(10);
  servo.write(90);
  pinMode(tlac1, INPUT_PULLUP);
  pinMode(tlac2, INPUT_PULLUP);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  
 


}

void loop() {
  attachInterrupt(digitalPinToInterrupt(tlac1),Blik,RISING);
  attachInterrupt(digitalPinToInterrupt(tlac2),Switch,RISING);
if(digitalRead(tlac1) == LOW){
    a = 0;

  
}
if(digitalRead(tlac2) == LOW){
  b = 0;
}

if(x==1)
{
  Serial.println(" režim 1");
  Serial.println("červena led zmena");
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  delay(1000);
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  delay(300);
  lcd.clear();
  lcd.print("rezim 1");
  servo.write(180);
  
}
if(x==2)
{
  Serial.println(" režím  2");
  Serial.println("červena led blikani");
  digitalWrite(led1,LOW);
  digitalWrite(led2,HIGH);
  delay(1000);
  digitalWrite(led1,HIGH);
  digitalWrite(led2,LOW);
  delay(1000);
  lcd.clear();
  lcd.print("rezim 2");
  servo.write(0);
  
  
}
if(x==0)
{
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
}

  

}

void Blik()
{

  x= 1;
  a=1;


  
}

void Switch()
{
  
    x=2;
    b = 1;
    
  
  
  
  
}
