//5.3
//디지털 신호 입력시간 측정하기
const int inputPin = 2;
long startTime = 0;
long swCountTimer = 0;
long adStartTime = 0;
int status = 1;
void setup() {
  // put your setup code here, to run once:
  adStartTime = millis();
  pinMode(inputPin,INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  if(digitalRead(inputPin) == LOW){
    startTime = millis();
    while(digitalRead(inputPin) == LOW);

    swCountTimer = millis() - startTime;
    Serial.print(swCountTimer);
    Serial.println(" ms");
    if(status == 1){
      Serial.println(millis()-adStartTime);
      status = 0;
    }
  }
}
