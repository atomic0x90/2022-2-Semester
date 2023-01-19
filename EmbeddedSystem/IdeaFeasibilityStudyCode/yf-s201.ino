/*
YF‐S201 Water Flow Sensor
유속 센서 코드(유량 센서)
*/

volatile int flow_frequency; // Measures flow sensor pulses
unsigned int l_hour; // Calculated litres/hour

//센서 연결
unsigned char flowsensor = 2;


unsigned long currentTime;
unsigned long cloopTime;

// Interrupt function
void flow(){
   flow_frequency++;
}

void setup(){

   pinMode(flowsensor, INPUT);

   digitalWrite(flowsensor, HIGH); // Optional Internal Pull-Up

   Serial.begin(9600);

   attachInterrupt(0, flow, RISING); // Setup Interrupt

   sei(); // Enable interrupts

   currentTime = millis();

   cloopTime = currentTime;

}

void loop (){
   currentTime = millis();

   // Every second, calculate and print litres/hour

   if(currentTime = (cloopTime + 1000)){
      cloopTime = currentTime; // Updates cloopTime
      // Pulse frequency (Hz) = 7.5Q, Q is flow rate in L/min.
      l_hour = (flow_frequency * 60 / 7.5); // (Pulse frequency x 60 min) / 7.5Q = flowrate in L/hour
      flow_frequency = 0; // Reset Counter
      Serial.print(l_hour, DEC); // Print litres/hour
      Serial.println(" L/hour");

      //1_hour 시간당 리터 -> 이것이 0이면 물을 틀지 않은 것, 0이 아니면 물을 튼 것
      //이것을 이용해서 메인 동작을 제어해야함 -> 물이 안틀어져 있는데 물 온도를 측정하는 것은 모순이기 때문
   }
}