//메인 동작 코드

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

//16x2 lcd
LiquidCrystal_I2C lcd(0x27,16,2);

//서보 모터
Servo motor1;

//서보 모터 11핀 연결
int servoMotorPin = 11;

//서보 모터 각도 조절
int motorAngle = 90;
int motorAngleOld;

//RGB LED 모듈 색깔별로 연결
const int ledRed = 13;
const int ledGreen = 12;
const int ledBlue = 10;

//현재 ID
int IDSET = 0;

//temp(ID) 별 저장된 온도
double temp0=20;
double temp1=21;
double temp2=22;
double temp3=23;
double temp4=24;
double temp5=25;
double temp6=26;
double temp7=27;
double temp8=28;
double temp9=29;
double temp = 0;

//설정 할 온도
double saveTemp = 0;

//설정 할 ID
int saveID = -1;

//현재 작동되고 있는 ID
int nowID = -1;

//설정 화면으로 가야하는지 check
bool checkSet = false;

/* 현재 측정 된 온도
 * 이것은 물 온도 센서(ds18b20) 이 아두이노 키트와 시뮬레이터에도 없기 때문에
 * 임의의 값으로 지정했음
 */
double nowTemp = 25;

//키패드 행렬 크기
const int numRows = 4;
const int numCols = 4;
char keys[numRows][numCols] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'},
};

//키패드 입력을 위한 변수(LOW,HIGH)
int rowPins[] = {2,3,4,5};
int colPins[] = {6,7,8,9};
char keypadRead(){
  char key='F';
  //키패드 입력 받기
  for(int i = 0;i<numCols;i++){
    digitalWrite(colPins[i],LOW);
    for(int j=0;j<numRows;j++){
      if(digitalRead(rowPins[j])==LOW){
        delay(10);
        while(digitalRead(rowPins[j])==LOW);
        key = keys[j][i];
      };
    }
    digitalWrite(colPins[i],HIGH);
  }
  //키패드 입력은 ID을 입력 한 것, 온도 변화
  if(key == '0') temp = temp0;
  if(key == '1') temp = temp1;
  if(key == '2') temp = temp2;
  if(key == '3') temp = temp3;
  if(key == '4') temp = temp4;
  if(key == '5') temp = temp5;
  if(key == '6') temp = temp6;
  if(key == '7') temp = temp7;
  if(key == '8') temp = temp8;
  if(key == '9') temp = temp9;

  Serial.println(key);
  return key;
}//keypadRead()

void setup() {
  motor1.attach(servoMotorPin,600,2400);

  //lcd 초기 화면 setting
  lcd.init();
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Setting # CLICK");
  lcd.setCursor(0,1);
  lcd.print("Start NUMBER");
  delay(1000);

  //키패드 입력을 위한 setting
  for(int i = 0;i<numRows;i++){
    pinMode(rowPins[i],INPUT_PULLUP);
  }
  for(int i = 0;i<numCols;i++){
    pinMode(colPins[i],OUTPUT);
    digitalWrite(colPins[i],HIGH);
  }

  //RGB LED 모듈 setting(빛 안나오게)
  ledOutput(0,0,0);
  Serial.begin(9600);
}

void loop() {
  //키패드 입력을 받는 변수 key
  char key = keypadRead();

  //checkSet:true -> 설정 화면으로, checkSet:false -> ID 입력 후 메인 동작 시작(물 온도 측정, 모터 회전)
  if(checkSet){
    //설정 화면
    
    
    if(key != 'A' && key != 'B' && key != 'C' && key != 'D' && key != '#' && key != '*' && key != 'F'){
      //바꿀 온도 입력
      if(saveID != -1){
        if(saveTemp < 10) saveTemp = saveTemp*10 + (key-'0');
        lcd.setCursor(10,1);
        lcd.print(saveTemp);
        lcd.setCursor(15,1);
        lcd.print("C");
      }
      //설정된 온도를 바꿀 ID 입력
      else{
        if(key == '0') saveID = 0;
        else if(key == '1') saveID = 1;
        else if(key == '2') saveID = 2;
        else if(key == '3') saveID = 3;
        else if(key == '4') saveID = 4;
        else if(key == '5') saveID = 5;
        else if(key == '6') saveID = 6;
        else if(key == '7') saveID = 7;
        else if(key == '8') saveID = 8;
        else if(key == '9') saveID = 9;
        saveTemp = 0;
        lcd.print(saveID);
        lcd.setCursor(0,1);
        lcd.print("Set Temp :");
      }
    }
    else if(key == '*'){
      //새로 입력한 값을 저장하고 나가기
      if(saveID != -1){
        if(saveID == 0) temp0 = saveTemp;
        else if(saveID == 1) temp1 = saveTemp;
        else if(saveID == 2) temp2 = saveTemp;
        else if(saveID == 3) temp3 = saveTemp;
        else if(saveID == 4) temp4 = saveTemp;
        else if(saveID == 5) temp5 = saveTemp;
        else if(saveID == 6) temp6 = saveTemp;
        else if(saveID == 7) temp7 = saveTemp;
        else if(saveID == 8) temp8 = saveTemp;
        else if(saveID == 9) temp9 = saveTemp;
      }
      //설정창 화면 해제
      checkSet = false;
      lcd.clear();
      lcd.backlight();
      lcd.setCursor(0,0);
      lcd.print("Setting # CLICK");
      lcd.setCursor(0,1);
      lcd.print("Start NUMBER");
      
      nowID = -1;
      saveID = -1;
    }
    else if(key == '#'){
      //새로 입력한 값을 저장하지 않고 나가기
      checkSet = false;
      
      lcd.clear();
      lcd.backlight();
      lcd.setCursor(0,0);
      lcd.print("Setting # CLICK");
      lcd.setCursor(0,1);
      lcd.print("Start NUMBER");
      nowID = -1;
      saveID = -1;
    }
  }//if(checkSet)
  else{
    //메인 동작 시작
    if(key == 'A' && nowID != -1){
      //현재 작동중인 ID가 있고 A 버튼을 눌렀으면 설정 온도 임시로 1 증가
      temp++;
      lcd.setCursor(10,0);
      lcd.print(temp);
    }
    if(key == 'B' && nowID != -1){
      //현재 작동중인 ID가 있고 B 버튼을 눌렀으면 설정 온도 임시로 0.1 증가
      temp += 0.1;
      lcd.setCursor(10,0);
      lcd.print(temp);
    }
    if(key == 'C' && nowID != -1){
      //현재 작동중인 ID가 있고 C 버튼을 눌렀으면 설정 온도 임시로 0.1 감소
      temp -= 0.1;
      lcd.setCursor(10,0);
      lcd.print(temp);
    }
    if(key == 'D' && nowID != -1){
      //현재 작동중인 ID가 있고 D 버튼을 눌렀으면 설정 온도 임시로 1 감소
      temp--;
      lcd.setCursor(10,0);
      lcd.print(temp);
    }
    if(key == '#'){
      //설정 화면으로 돌아가기
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Set ID : ");
      checkSet = true;
    }
    if(key == '*'){
      //초기 화면으로 돌아가기
      lcd.clear();
      lcd.backlight();
      lcd.setCursor(0,0);
      lcd.print("Setting # CLICK");
      lcd.setCursor(0,1);
      lcd.print("Start NUMBER");
      nowID = -1;
      saveID = -1;
      ledOutput(0,0,0);
    }
    if(key != 'A' && key != 'B' && key != 'C' && key != 'D' && key != '#' && key != '*' && key != 'F'){
      //ID를 입력 받았을 때
      //ID에서 저장한 온도를 현재 설정 온도로 저장
      if(key == '0'){
        nowID = 0;
        temp = temp0;
      }
      if(key == '1'){
        nowID = 1;
        temp = temp1;
      }
      if(key == '2'){
        nowID = 2;
        temp = temp2;
      }
      if(key == '3'){
        nowID = 3;
        temp = temp3;
      }
      if(key == '4'){
        nowID = 4;
        temp = temp4;
      }
      if(key == '5'){
        nowID = 5;
        temp = temp5;
      }
      if(key == '6'){
        nowID = 6;
        temp = temp6;
      }
      if(key == '7'){
        nowID = 7;
        temp = temp7;
      }
      if(key == '8'){
        nowID = 8;
        temp = temp8;
      }
      if(key == '9'){
        nowID = 9;
        temp = temp9;
      }
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("ID:");
      lcd.print(key);
      lcd.print(" Set  ");
      lcd.print(temp);
      lcd.setCursor(15,0);
      lcd.print("C");
      
      lcd.setCursor(0,1);
      lcd.print("now temp  ");
      lcd.print(nowTemp);
      lcd.setCursor(15,1);
      lcd.print("C");
  
      Serial.println(key);
    }

    //현재 작동중인 ID가 있다면
    if(nowID != -1){
        if(temp - nowTemp < -0.2){
          //현재 온도가 설정 온도보다 높을 때
          //모터 반시계 방향 회전, RGB LED 모듈 빨간색
          motor1.write(motorAngle++);
          if(motorAngle > 180) motorAngle = 180;
          ledOutput(255,0,0);
          delay(300);
        }
        else if(temp - nowTemp > 0.2){
          //현재 온도가 설정 온도보다 낮을 때
          //모터 반시계 방향 회전, RGB LED 모듈 파란색
          motor1.write(motorAngle--);
          if(motorAngle < 0) motorAngle = 0;
          ledOutput(0,0,255);
          delay(300);
        }
        else{
          //현재 온도가 설정 온도와 비슷(오차 범위 0.2 로 설정하였음)할 때
          //모터 회전 없음, RGB LED 모듈 초록색
          motor1.write(motorAngle);
          ledOutput(0,255,0);
          delay(300);
        }
    }
  }//checkSet else
}//loop()

//RGB LED 모듈 값 설정 함수
void ledOutput(int red,int green,int blue){
  analogWrite(ledRed,red);
  analogWrite(ledGreen,green);
  analogWrite(ledBlue,blue);
}