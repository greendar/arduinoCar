int button = 2;
int buttonState = 0;
int joyX = A1;
int joyY = A0;
int xValue;
int yValue;

void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT_PULLUP);
}

void loop() {
 xValue = analogRead(joyX);
 yValue = analogRead(joyY);
 yValue = cleanValue(yValue);
 check();
 //xyCoords();
 if(digitalRead(button) == LOW){
   Serial.println("Button Pressed");
 }
 delay(500);
}

void xyCoords(){
  Serial.print(xValue);
  Serial.print("   ");
  Serial.println(yValue);
}

void check(){
  if (xValue < 300 and yValue < 300){
    Serial.println("Down Left");
  }
  if (xValue > 700 and yValue > 700){
      Serial.println("Up Right");
    }
  if (xValue < 300 and yValue > 700){
      Serial.println("Up Left");
    }
  if (xValue > 700 and yValue < 300){
      Serial.println("Down Right");
    }
  if (yValue < 300 and checkMidX()){
    Serial.println("Down");
  }
  if (yValue > 700 and checkMidX()){
      Serial.println("Up");
    }
  if (xValue < 300 and checkMidY()){
      Serial.println("Left");
    }
  if (xValue > 700 and checkMidY()){
      Serial.println("Right");
    }
}

bool checkMidX(){
  if (xValue > 300 and xValue < 700){
    return true;
  } else {
    return false;
  }
}

bool checkMidY(){
  if (yValue > 300 and yValue < 700){
    return true;
  } else {
    return false;
  }
}

int cleanValue(int joyValue){
  int outValue;
  if(joyValue > 495 and joyValue < 595){
    return 497;
  } else {
    return joyValue;
  }
}
