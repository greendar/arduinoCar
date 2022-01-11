int button = 2;
int buttonState = 0;
int joyX = A1;
int joyY = A0;
int xValue;
int yValue;

//#define joyX A1
//#define joyY A0

void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT_PULLUP);
}

void loop() {
 xValue = analogRead(joyX);
 yValue = analogRead(joyY);
 Serial.print(xValue);
 Serial.print("   ");
 Serial.println(yValue);
 delay(500);
}
