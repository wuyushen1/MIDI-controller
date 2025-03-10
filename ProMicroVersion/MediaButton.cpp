#include "MediaButton.h"

int d,e;

MediaButton::MediaButton(int dPin, int ePin){
  d = dPin;
  e = ePin;
}

void MediaButton::begin(){
  pinMode(d, OUTPUT);
  digitalWrite(d, LOW);
  pinMode(e, INPUT_PULLUP);
  SurfaceDial.begin();
}

void MediaButton::refresh() {
  // 判断按键
  if (!digitalRead(e)) {
    delay(1); 
    SurfaceDial.press();
  } else {
    delay(1); 
    SurfaceDial.release();
  }
  return;// 此处的 return 在 if 和 else 语句之外
}