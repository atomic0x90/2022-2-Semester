//5.2.1 other
//스위치 누르는 동안 계속 카운팅
const int ledPin = 13;
const int inputPin = 2;
int count = 0;
int status = 1;//
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin,OUTPUT);
  pinMode(inputPin,INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  int swInput = digitalRead(inputPin);

  int ledOutput = digitalRead(ledPin);
  if(status == 1 && swInput == LOW){
    
    if(ledOutput) digitalWrite(ledPin,LOW);
    else digitalWrite(ledPin,HIGH);
    
    status = 0;
    ++count;
    Serial.println(count);
  delay(150);
  }
  else if(status == 0 && swInput == HIGH){
    status = 1;
  }

}
