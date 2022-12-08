#include <cmath>
void setup() {
  // put your setup code here, to run once:
  analogWriteResolution(12);
  //analogWrite(DAC0, 0);
  //analogWrite(DAC0, 4095);
}
void sawtooth() {
    for(int i = 0; i < 4095; i++) {
      analogWrite(DAC0, i);
      delayMicroseconds(5.5);    
    }
}

void sineWave() {
  int n = 5;
  double t = (2*M_PI)/n;
  double period=1000000.0/880;
  int delay_s = round((period/n)/2);
  for(int i = 0; i < n ; i++, t+= (2*M_PI)/n) {
    analogWrite(DAC0, 2048 + 2047*sin(t));
    delayMicroseconds(delay_s);
  }
}
void oneHundredkHzWave() {
  analogWrite(DAC0, 3251.2);
  delayMicroseconds(1);
  analogWrite(DAC0, 3994.81);
  delayMicroseconds(1);
  analogWrite(DAC0, 3994.81);
  delayMicroseconds(1);
  analogWrite(DAC0, 3251.2);
  delayMicroseconds(1);
  analogWrite(DAC0, 2048);
  delayMicroseconds(1);
  analogWrite(DAC0, 884.8);
  delayMicroseconds(1);
  analogWrite(DAC0, 101.2);
  delayMicroseconds(1);
  analogWrite(DAC0, 101.2);
  delayMicroseconds(1);
  analogWrite(DAC0, 2048);
  delayMicroseconds(1);
}

void loop() {
  //sawtooth();
  //sineWave();
  oneHundredkHzWave();

}
