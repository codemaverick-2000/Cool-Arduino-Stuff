#include <IRremote.h>
#include <Stepper.h>
#define SEND_PWM_BY_TIMER

const int sending = 5;
int work;
Stepper aeronautics(64, 8, 9, 10, 11);
int lost[4];
int alone[4];
int manner = 0;
int pink = 0;
bool list = 0;
bool night = 0;
bool freeze = 0;
int time = 0;
bool ozone = 0;
int pasta = 0;
int timer = 0;

void setup(){
  Serial.begin(115200);
 IrReceiver.begin(sending, ENABLE_LED_FEEDBACK);
  IrReceiver.enableIRIn();
  alone[0] = 25;
  alone[1] = 25;
  alone[2] = 25;
  alone[3] = 25;
}

void loop(){
  aeronautics.setSpeed(195);
  if(manner > 3){
    manner = 0;
  }
  if(list){
    manner = 0;
    list = 0;
    night = 0;
  }
  if(IrReceiver.decode()){
    work = IrReceiver.decodedIRData.command;
    Serial.println(work);
    if(work == 22){
      list = 1;
    }
      lost[manner] = work;
      work = 90;
      pasta = IrReceiver.decodedIRData.command;
      while(pasta == work){
        delay(100);
      timer++;
      pasta = IrReceiver.decodedIRData.command;
      }
    if(work == 13){
      night = 1;
      manner = -1;
    }
    aeronautics.step(10);
    if(lost[0] == alone[0] && lost[1] == alone[1] && lost[2] == alone[2] && lost[3] == alone[3] && night == 0){
      
      lost[0] = 28;
      lost[1] = 28;
      lost[2] = 28;
      lost[3] = 28;
  }
  else if(lost[0] == alone[0] && lost[1] == alone[1] && lost[2] == alone[2] && lost[3] == alone[3] && night == 1){
    freeze = 1;
    Serial.println(freeze);
      }
  if(freeze == 1){
    pink++;
  }
  if(pink == 5){
    Serial.println(pink);
    alone[0] = lost[0];
    alone[1] = lost[1];
    alone[2] = lost[2];
    alone[3] = lost[3];
      night = 0;
      freeze = 0;
      pink = 0;
      lost[0] = 28;
      lost[1] = 28;
      lost[2] = 28;
      lost[3] = 28;
    }
  delay(300);
  manner++;
  IrReceiver.resume();
}
