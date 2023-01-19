/*예제 4.4
FND 제어
*/
const byte number[10]={
  B00111111,//0
  B00000110,//1
  B01011011,//2
  B01001111,//3
  B01100110,//4
  B01101101,//5
  B01111101,//6
  B00000111,//7
  B01111111,//8
  B01101111,//90
  };
void setup() {
  // put your setup code here, to run once:
  for(int i = 2;i <=9;++i){
    pinMode(i,OUTPUT);
    };
    digitalWrite(9,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int k=0;k<=9;++k){
    fndDisplay(k);
    delay(1000);
    }
}
void fndDisplay(int displayValue){
  boolean bitValue;
  for(int i=2;i<=9;++i){
    digitalWrite(i,LOW);
    };
    for(int i=0;i<=7;++i){
      bitValue = bitRead(number[displayValue],i);
      digitalWrite(i+2,bitValue);
      }
  }
