// this sucks don't use it

#define joyX A0
#define joyY A1

void setup() {
  Serial.begin(9600);
}

void loop() {
 int xValue = analogRead(joyX);
 int yValue = analogRead(joyY);

  Serial.print(xValue);
  Serial.print("\t");
  Serial.println(yValue);
  delay(50);
}
