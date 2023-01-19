//물 온도 측정 코드
#include <OneWire.h>
#include <DallasTemperature.h>

//2번 핀 연결
OneWire oneWire(2);

//물 온도 센서 연결
DallasTemperature sensors(&oneWire);
void setup() {
  Serial.begin(9600);

  //물 온도 센서 연결
  sensors.begin();
}

void loop() {
  //물 온도 센서 값 요청
  sensors.requestTemperatures();

  //물 온도 센서 값 받아옴
  sensors.getTempCByIndex(0);
  /* 이 코드를 수정하여 main(메인 동작 코드)의 'nowTemp' 변수와 연결하면 된다.
   *  아두이노 키트와 시뮬레이터 둘 다 없어서 실험은 해보지 못했다.
   */
  delay(1000);
}