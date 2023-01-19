//6.6
//소리 입력
char soundInputPin = 0;
char ledLevel[8] = {2,3,4,5,6,7,8,9};
void setup() {
  // put your setup code here, to run once:

    Serial.begin(9600);
  for(int i = 0;i <=7 ;i++){
      pinMode(ledLevel[i],OUTPUT);
    }

}

void loop() {
  // put your main code here, to run repeatedly:

  int soundInput = analogRead(soundInputPin);
  int soundLevel = map(soundInput,50,900,0,7);


      Serial.println(soundLevel);
  for(int i = 0;i <=7;i++){
      digitalWrite(ledLevel[i],LOW);
    }

  for(int i = 0;i <=soundLevel;i++){
      digitalWrite(ledLevel[i],HIGH);
    }
}
