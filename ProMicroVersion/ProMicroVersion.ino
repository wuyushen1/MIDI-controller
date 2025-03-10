#include "HID-Project.h"
#include "Encoder.h"
#include "MediaButton.h"
static int a=15,b=16,c=14,d=A3,e=A1;
Encoder enc1(a,b,c);
MediaButton btn1(d,e);

// input pin for pushbutton
int pinButton = A3;
int pinSecondButton = A1;

bool previousButtonValue = false;
bool previousSecondButtonValue = false;

volatile int previous = 0;
volatile int counter = 0;



void setup()
{
   enc1.begin();
   btn1.begin();
   Serial.begin(9600);
   SurfaceDial.begin();
}


#define DialRotateDelta 18

int total = 0;
int threshold = 1;
void loop()
{

   int re = enc1.refresh();
    total += re;
    if(total == threshold){
      //#编码器逆时针#
      SurfaceDial.rotate(-DialRotateDelta);
      total = 0;
    }
    else if(total == -threshold){
      //#编码器顺时针#
      SurfaceDial.rotate(DialRotateDelta);
      total = 0;
    }
    btn1.refresh();
    if(re!=0){
      Serial.println(re);
    }
}