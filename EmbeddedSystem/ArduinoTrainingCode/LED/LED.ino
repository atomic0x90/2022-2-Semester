/*예제 4.2
LED 밝기 조절
*/

const int ledA = 3;
const int ledB = 5;
int brightness = 0;
int increment = 1;
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

  analogWrite(ledA,brightness);
  analogWrite(ledB,255-brightness);

  brightness = brightness + increment;
  if((brightness >= 255)||(brightness <= 0)) increment = -increment;
  delay(10);
}
