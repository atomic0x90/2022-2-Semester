//적외선 리모컨을 이용한 서보모터 제어 
#include <IRremote.h>
int irPin = 11;

int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;

long on1 = 0xFF6897;
long off1 = 0xFF30CF;
long on2 = 0xFF18E7;
long off2 = 0xFF7A85;
long on3 = 0xFF10EF;
long off3 = 0xFF38C7;
long on4 = 0xFF5AA5;
long off4 = 0xFF42BD;
long on5 = 0xFF4AB5;
long off5 = 0xFF52AD;

#include <Servo.h>

Servo motor1;

int servoMotorPin = 9;

int motorAngle;
int motorAngleOld;

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

  motor1.attach(servoMotorPin,600,2400);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(irrecv.decode(&results)){
    //if(results.value != 0xFFFFFFFF){
      Serial.println(results.value);
      if(results.value == on1){
        digitalWrite(led1,HIGH);
        Serial.println("LED1 is ON");
        motor1.write(0);
      }
      if(results.value == off1){
        digitalWrite(led1,LOW);
        Serial.println("LED1 is OFF");
        motor1.write(20);
      }
      if(results.value == on2){
        digitalWrite(led2,HIGH);
        Serial.println("LED2 is ON");
        motor1.write(40);
      }
      if(results.value == off2){
        digitalWrite(led2,LOW);
        Serial.println("LED2 is OFF");
        motor1.write(60);
      }
      if(results.value == on3){
        digitalWrite(led3,HIGH);
        Serial.println("LED3 is ON");
        motor1.write(80);
      }
      if(results.value == off3){
        digitalWrite(led3,LOW);
        Serial.println("LED3 is OFF");
        motor1.write(100);
      }
      if(results.value == on4){
        digitalWrite(led4,HIGH);
        Serial.println("LED4 is ON");
        motor1.write(120);
      }
      if(results.value == off4){
        digitalWrite(led4,LOW);
        Serial.println("LED4 is OFF");
        motor1.write(140);
      }
      if(results.value == on5){
        digitalWrite(led5,HIGH);
        Serial.println("LED5 is ON");
        motor1.write(160);
      }
      if(results.value == off5){
        digitalWrite(led5,LOW);
        Serial.println("LED5 is OFF");
        motor1.write(180);
      }
      irrecv.resume();
    //}  
  }
}
