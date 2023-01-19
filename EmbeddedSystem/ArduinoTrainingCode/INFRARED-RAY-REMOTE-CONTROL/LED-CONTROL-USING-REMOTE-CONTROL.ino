//8.2 리모컨을 이용한 LED 제어
#include <IRremote.h>
int irPin = 11;
int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;

long on1 =  0xFF30CF;
long off1 = 0xFF18E7;
long on2 = 0xFF7A85;
long off2 = 0xFF10EF;
long on3 = 0xFF38C7;
long off3 = 0xFF5AA5;
long on4 = 0xFF42BD;
long off4 = 0xFF4AB5;
IRrecv irrecv(irPin);

decode_results results;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);

  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(irrecv.decode(&results)){
    if(results.value != 0xFFFFFFFF){
      if(results.value == on1){
         digitalWrite(led1,HIGH);
         Serial.println("LED1 is ON");
        }
        
      if(results.value == off1){
         digitalWrite(led1,HIGH);
         Serial.println("LED1 is OFF");
        }

        if(results.value == on2){
         digitalWrite(led2,HIGH);
         Serial.println("LED2 is ON");
        }
        
      if(results.value == off2){
         digitalWrite(led2,HIGH);
         Serial.println("LED2 is OFF");
        }

        if(results.value == on3){
         digitalWrite(led3,HIGH);
         Serial.println("LED3 is ON");
        }
        
      if(results.value == off3){
         digitalWrite(led1,HIGH);
         Serial.println("LED3 is OFF");
        }

        if(results.value == on4){
         digitalWrite(led1,HIGH);
         Serial.println("LED1 is ON");
        }
        
      if(results.value == off4){
         digitalWrite(led1,HIGH);
         Serial.println("LED1 is OFF");
        }
      }

      irrecv.resume();
    }
}
