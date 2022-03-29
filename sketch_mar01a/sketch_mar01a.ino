#define led1 2
#define tlac1 7
void setup() {

 pinMode(led1,OUTPUT);
 pinMode(tlac1, INPUT_PULLUP);
 

}

void loop() {

  attachInterrupt(digitalPinToInterrupt(tlac1),zapled,RISING);
  
  if(digitalRead(tlac1) == LOW)
 {
  digitalWrite(led1,HIGH);
}
}

void zapled()
{

  digitalWrite(led1,LOW);
}
