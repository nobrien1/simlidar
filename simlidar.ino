void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

int t = 0;

void loop() {
  int distance = 200 + int(20 * sin(t * 3.14 / 6));
  int lowDist = distance & 0xff;
  int highDist = (distance >> 8) & 0xff;

  // put your main code here, to run repeatedly:
  for(int i = 0; i < 90; i++) {
    Serial.write(0xfa); // start
    Serial.write(i + 0xa0); // index

    // angle i * 4
    Serial.write(lowDist); // distance 7:0
    Serial.write(highDist); // distance 13:8

    // angle i * 4 + 1
    Serial.write(lowDist); // distance 7:0
    Serial.write(highDist); // distance 13:8

    // angle i * 4 + 2
    Serial.write(lowDist); // distance 7:0
    Serial.write(highDist); // distance 13:8

    // angle i * 4 + 3
    Serial.write(lowDist); // distance 7:0
    Serial.write(highDist); // distance 13:8
  }

  t++;
}
