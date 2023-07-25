#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C ml(0x27,16,2);
int now;
int ct;
int mt;
int ht;
int cl;
int reason;
void setup() {
  pinMode(2,OUTPUT);
  pinMode(3,INPUT);
  ml.init();
  ml.backlight();
}

void loop() {
  for(now=0; now>-1; now++){
    delay(1000);
    if(ct>59){
      ct=1;
      mt=mt+1;
      ml.clear();
    }
    else if(ct<60){
      ct=ct+1;
      mt=mt;
    }
    if(mt>59){
      ht=ht+1;
      mt=0;
    }
    else if(mt<60){
      mt=mt;
    }
    if(ht>23){
      ht=0;
      ml.clear();
    }
    if(mt>9 ){
      break;
    }
    ml.setCursor(0,0);
    ml.print(ht);
    ml.setCursor(2,0);
    ml.print(':');
    ml.setCursor(3,0);
    ml.print(mt);
    ml.setCursor(5,0);
    ml.print(':');
    ml.setCursor(6,0);
    ml.print(ct);
    if(digitalRead(3)==HIGH){
      reason=1;
      break;
    }
  }
  if(reason=1){
    ml.clear();
    ml.setCursor(0,0);
    ml.print(A0);
    delay(1000);
    ct=ct+1;
    reason=0;
  }
  if(reason!=1){
    sound();
  }
}

void sound(){
  tone(2,2051);
  delay(100);
  noTone(2);
  delay(200); 
  tone(2,2051);
  delay(100);
  noTone(2);
  delay(200); 
  tone(2,2051);
  delay(100);
  noTone(2);
  delay(200); 
  tone(2,2051);
  delay(100);
  noTone(2);
  delay(200); 
  tone(2,2051);
  delay(100);
  noTone(2);
  delay(200); 
  tone(2,2051);
  delay(100);
  noTone(2);
  delay(200); 
  tone(2,2051);
  delay(100);
  noTone(2);
  delay(200); 
  tone(2,2051);
  delay(100);
  noTone(2);
  delay(200); 
  tone(2,2051);
  delay(100);
  noTone(2);
  delay(200); 
  tone(2,2051);
  delay(100);
  noTone(2);
  delay(200); 
  tone(2,2051);
  delay(100);
  noTone(2);
  delay(200); 
  tone(2,2051);
  delay(100);
  noTone(2);
  delay(200); 
  tone(2,2051);
  delay(100);
  noTone(2);
  delay(200); 
  tone(2,2051);
  delay(100);
  noTone(2);
  delay(200); 
  tone(2,2051);
  delay(100);
  noTone(2);
  delay(200); 
  tone(2,2051);
  delay(100);
  noTone(2);
  delay(200); 
  tone(2,2051);
  delay(100);
  noTone(2);
  delay(200); 
  tone(2,2051);
  delay(100);
  noTone(2);
  delay(200); 
  tone(2,2051);
  delay(100);
  noTone(2);
  delay(200); 
  tone(2,2051);
  delay(100);
  noTone(2);
  delay(200); 
  tone(2,2051);
  delay(100);
  noTone(2);
  delay(200); 
  tone(2,2051);
  delay(100);
  noTone(2);
  delay(200); 
  tone(2,2051);
  delay(100);
  noTone(2);
  delay(200); 
  tone(2,2051);
  delay(100);
  noTone(2);
  delay(200); 
  tone(2,2051);
  delay(100);
  noTone(2);
  delay(200); 
  tone(2,2051);
  delay(100);
  noTone(2);
  delay(200); 
  tone(2,2051);
  delay(100);
  noTone(2);
  delay(200); 
  tone(2,2051);
  delay(100);
  noTone(2);
  delay(200); 
  tone(2,2051);
  delay(100);
  noTone(2);
  delay(200); 
  tone(2,2051);
  delay(100);
  noTone(2);
  delay(200); 
  tone(2,2051);
  delay(100);
  noTone(2);
  delay(200); 
  tone(2,2051);
  delay(100);
  noTone(2);
  delay(200); 
  tone(2,2051);
  delay(100);
  noTone(2);
  delay(200); 
  tone(2,2051);
  delay(100);
  noTone(2);
  delay(200); 
  tone(2,2051);
  delay(100);
  noTone(2);
  delay(200); 
  tone(2,2051);
  delay(100);
  noTone(2);
  delay(200); 
  tone(2,2051);
  delay(100);
  noTone(2);
  delay(200); 
  tone(2,2051);
  delay(100);
  noTone(2);
  delay(200); 
  tone(2,2051);
  delay(100);
  noTone(2);
  delay(200); 
  tone(2,2051);
  delay(100);
  noTone(2);
  delay(200); 
  tone(2,2051);
  delay(100);
  noTone(2);
  delay(200); 
  tone(2,2051);
  delay(100);
  noTone(2);
  delay(200); 
  tone(2,2051);
  delay(100);
  noTone(2);
  delay(200); 
  tone(2,2051);
  delay(100);
  noTone(2);
  delay(200); 
  tone(2,2051);
  delay(100);
  noTone(2);
  delay(200); 
  tone(2,2051);
  delay(100);
  noTone(2);
  delay(200); 
  tone(2,2051);
  delay(100);
  noTone(2);
  delay(200); 
  tone(2,2051);
  delay(100);
  noTone(2);
  delay(200); 
}
