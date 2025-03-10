#ifndef MediaButton_H
#define MediaButton_H

#include "arduino.h"
#include "HID-Project.h"

class MediaButton{
  private:int d,e;
  
  public:MediaButton(int dPin, int ePin);
  public:void begin();
  public:void refresh();
};

#endif
