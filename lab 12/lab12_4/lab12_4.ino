void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);
  }

void loop() {
  // put your main code here, to run repeatedly:
  while (analogRead(A0) < 960) {};
  unsigned long start = micros();
  while(analogRead(A1) < 980) {}
  unsigned long endval = micros();
  double diff = (endval - start);
  double speed = 8.0 / diff;
  Serial.print("speed: ");
  Serial.print(speed * 1000000);
  Serial.println(" cm/s");
}
