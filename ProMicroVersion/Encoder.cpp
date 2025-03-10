#include "Encoder.h"
  int prePinA = 0;
  int prePinB = 0;
  int preDire = 0;
  int a,b,c;
  Encoder::Encoder(int aPin, int bPin, int cPin){
    a=aPin;
    b=bPin;
    c=cPin;
  }

  void Encoder::begin(){
    pinMode(c,OUTPUT);
    digitalWrite(c,LOW);

    pinMode(a,INPUT_PULLUP);
    pinMode(b,INPUT_PULLUP);

    prePinA = digitalRead(a);
    prePinB = digitalRead(b);
  }
  int Encoder::nextFrame(){
    int pinA = digitalRead(a);
    int pinB = digitalRead(b);
    int result = 0;

    if(pinA > prePinA){
      //a up
      if(pinB == 1){
        //b high
        result = -1;
    digitalWrite(6,HIGH);
    delay(3);
    digitalWrite(6,LOW);
      }else{
        //b low
        result = 1;
    digitalWrite(6,HIGH);
    delay(2);
    digitalWrite(6,LOW);
    delay(2);
    digitalWrite(6,HIGH);
    delay(2);
    digitalWrite(6,LOW);
      }
    }
    else if(pinA < prePinA){
      //a down
      if(pinB == 1){
        //b high
        result = 1;
    digitalWrite(6,HIGH);
    delay(2);
    digitalWrite(6,LOW);
    delay(2);
    digitalWrite(6,HIGH);
    delay(2);
    digitalWrite(6,LOW);
      }else{
        //b low
        result = -1;
    digitalWrite(6,HIGH);
    delay(3);
    digitalWrite(6,LOW);
      }
    }else if(pinB > prePinB){
      //b up
      if(pinA == 1){
        //a high
        result = 1;
    digitalWrite(6,HIGH);
    delay(2);
    digitalWrite(6,LOW);
    delay(2);
    digitalWrite(6,HIGH);
    delay(2);
    digitalWrite(6,HIGH);
      }else{
        //a low
        result = -1;
    digitalWrite(6,HIGH);
    delay(3);
    digitalWrite(6,LOW);
      }
    }
    else if(pinB < prePinB){
      //b down
      if(pinA == 1){
        //a high
        result = -1;
    digitalWrite(6,HIGH);
    delay(3);
    digitalWrite(6,LOW);
      }else{
        //a low
        result = 1;
    digitalWrite(6,HIGH);
    delay(2);
    digitalWrite(6,LOW);
    delay(2);
    digitalWrite(6,HIGH);
    delay(2);
    digitalWrite(6,LOW);
      }
    }
    prePinA = pinA;
    prePinB = pinB;
    return result;
  }

  int Encoder::refresh(){
    int dire = nextFrame();
    if(dire == 1){
      if(preDire != 1){
        preDire = 1;
        return 0;
      }
      else{
        return 1;
        delay(100);
      }
    }
    else if(dire == -1){
      if(preDire != -1){
        preDire = -1;
        return 0;
      }
      else{
        return -1;
        delay(100);
      }
    }
    return 0;
  }
