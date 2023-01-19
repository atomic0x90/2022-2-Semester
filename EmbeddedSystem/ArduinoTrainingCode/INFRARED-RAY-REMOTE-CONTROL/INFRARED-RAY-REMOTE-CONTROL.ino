//8.1 적외선 리모컨 코드 읽기
#include <IRremote.h>
int irPin = 11;
IRrecv irrecv(irPin);
decode_results results;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
}

void loop() {
  // put your main code here, to run repeatedly:

  if(irrecv.decode(&results)){
    if(results.value != 0xFFFFFFFF){
        Serial.print("Received Code is ");
        Serial.println(results.value,HEX);
//        irrecv.printIRResultRawFormatted(&Serial,true);
//        irrecv.printIRResultShort(&Serial);
      }
      irrecv.resume();
    }
}
