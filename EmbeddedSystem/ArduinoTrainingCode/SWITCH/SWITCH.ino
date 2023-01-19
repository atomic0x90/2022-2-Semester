//5.1
//스위치 입력
const int ledPin = 13;
const int inputPin = 2;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin,OUTPUT);
  pinMode(inputPin,INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:

  int swInput = digitalRead(inputPin);

  if(swInput == LOW) digitalWrite(ledPin,HIGH);
  else digitalWrite(ledPin,LOW);
}
