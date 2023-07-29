//Import the Liquid Crystal I2C Library
#include <LiquidCrystal_I2C.h>

//Specify display info [I2C Address],[X Pixels],[Y Pixels]
LiquidCrystal_I2C ml(0x27,16,2);

//Declare variables
int now;
int ct;
int mt;
int ht;
int cl;
int reason;
int alarm;
int buzzerpin=12;
int year=2023;
int month=7;
int day=26;
void setup() {

  //Inatialize display
  ml.init();

  //Turn LCD backlight on
  ml.backlight();

  //Set alarm time, define unit at line 65 
  alarm=8;
}

void loop() {

  //Clock
  for(now=0; now>-1; now++){
    
    //One second delay
    delay(1000);

    //If a minute elapses
    if(ct>59){
      ct=1;
      mt=mt+1;
      ml.clear();
    }
    //If seconds are less than a minute
    else if(ct<60){
      ct=ct+1;
      mt=mt;
    }
    //If an hour elapses
    if(mt>59){
      ht=ht+1;
      mt=0;
    }
    //If minutes are less than an hour
    else if(mt<60){
      mt=mt;
    }
    //If a day elapses
    if(ht>23){
      ht=0;
      ml.clear();
      reason=2;
    }
    //Trigger alarm, define alarm time unit: ht=hours, mt=minute, ct=seconds
    if(ht+1>alarm){
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
    ml.setCursor(0,1);
    ml.print(day);
    ml.setCursor(2,1);
    ml.print("/");
    ml.setCursor(3,1);
    ml.print(month);
    ml.setCursor(6,1);
    ml.print("/");
    ml.setCursor(7,1);
    ml.print(year);
  }
  if(reason=1){
    ml.clear();
    ml.setCursor(0,0);
    ml.print(A0);
    delay(1000);
    ct=ct+1;
    reason=0;
  }
  if(reason=1){
    sound();
  }
  if (reason=2){
  day=day+1;
  }
}

//Alarm sound
void sound(){
  tone(buzzerpin,2051);
  delay(100);
  noTone(buzzerpin);
  delay(200); 
  tone(buzzerpin,2051);
  delay(100);
  noTone(buzzerpin);
  delay(200); 
  tone(buzzerpin,2051);
  delay(100);
  noTone(buzzerpin);
  delay(200); 
  tone(buzzerpin,2051);
  delay(100);
  noTone(buzzerpin);
  delay(200); 
  tone(buzzerpin,2051);
  delay(100);
  noTone(buzzerpin);
  delay(200); 
  tone(buzzerpin,2051);
  delay(100);
  noTone(buzzerpin);
  delay(200); 
  tone(buzzerpin,2051);
  delay(100);
  noTone(buzzerpin);
  delay(200); 
  tone(buzzerpin,2051);
  delay(100);
  noTone(buzzerpin);
  delay(200); 
  tone(buzzerpin,2051);
  delay(100);
  noTone(buzzerpin);
  delay(200); 
  tone(buzzerpin,2051);
  delay(100);
  noTone(buzzerpin);
  delay(200); 
  tone(buzzerpin,2051);
  delay(100);
  noTone(buzzerpin);
  delay(200); 
  tone(buzzerpin,2051);
  delay(100);
  noTone(buzzerpin);
  delay(200); 
  tone(buzzerpin,2051);
  delay(100);
  noTone(buzzerpin);
  delay(200); 
  tone(buzzerpin,2051);
  delay(100);
  noTone(buzzerpin);
  delay(200); 
  tone(buzzerpin,2051);
  delay(100);
  noTone(buzzerpin);
  delay(200); 
  tone(buzzerpin,2051);
  delay(100);
  noTone(buzzerpin);
  delay(200); 
  tone(buzzerpin,2051);
  delay(100);
  noTone(buzzerpin);
  delay(200); 
  tone(buzzerpin,2051);
  delay(100);
  noTone(buzzerpin);
  delay(200); 
  tone(buzzerpin,2051);
  delay(100);
  noTone(buzzerpin);
  delay(200); 
  tone(buzzerpin,2051);
  delay(100);
  noTone(buzzerpin);
  delay(200); 
  tone(buzzerpin,2051);
  delay(100);
  noTone(buzzerpin);
  delay(200); 
  tone(buzzerpin,2051);
  delay(100);
  noTone(buzzerpin);
  delay(200); 
  tone(buzzerpin,2051);
  delay(100);
  noTone(buzzerpin);
  delay(200); 
  tone(buzzerpin,2051);
  delay(100);
  noTone(buzzerpin);
  delay(200); 
  tone(buzzerpin,2051);
  delay(100);
  noTone(buzzerpin);
  delay(200); 
  tone(buzzerpin,2051);
  delay(100);
  noTone(buzzerpin);
  delay(200); 
  tone(buzzerpin,2051);
  delay(100);
  noTone(buzzerpin);
  delay(200); 
  tone(buzzerpin,2051);
  delay(100);
  noTone(buzzerpin);
  delay(200); 
  tone(buzzerpin,2051);
  delay(100);
  noTone(buzzerpin);
  delay(200); 
  tone(buzzerpin,2051);
  delay(100);
  noTone(buzzerpin);
  delay(200); 
  tone(buzzerpin,2051);
  delay(100);
  noTone(buzzerpin);
  delay(200); 
  tone(buzzerpin,2051);
  delay(100);
  noTone(buzzerpin);
  delay(200); 
  tone(buzzerpin,2051);
  delay(100);
  noTone(buzzerpin);
  delay(200); 
  tone(buzzerpin,2051);
  delay(100);
  noTone(buzzerpin);
  delay(200); 
  tone(buzzerpin,2051);
  delay(100);
  noTone(buzzerpin);
  delay(200); 
  tone(buzzerpin,2051);
  delay(100);
  noTone(buzzerpin);
  delay(200); 
  tone(buzzerpin,2051);
  delay(100);
  noTone(buzzerpin);
  delay(200); 
  tone(buzzerpin,2051);
  delay(100);
  noTone(buzzerpin);
  delay(200); 
  tone(buzzerpin,2051);
  delay(100);
  noTone(buzzerpin);
  delay(200); 
  tone(buzzerpin,2051);
  delay(100);
  noTone(buzzerpin);
  delay(200); 
  tone(buzzerpin,2051);
  delay(100);
  noTone(buzzerpin);
  delay(200); 
  tone(buzzerpin,2051);
  delay(100);
  noTone(buzzerpin);
  delay(200); 
  tone(buzzerpin,2051);
  delay(100);
  noTone(buzzerpin);
  delay(200); 
  tone(buzzerpin,2051);
  delay(100);
  noTone(buzzerpin);
  delay(200); 
  tone(buzzerpin,2051);
  delay(100);
  noTone(buzzerpin);
  delay(200); 
  tone(buzzerpin,2051);
  delay(100);
  noTone(buzzerpin);
  delay(200); 
  tone(buzzerpin,2051);
  delay(100);
  noTone(buzzerpin);
  delay(200); 
  tone(buzzerpin,2051);
  delay(100);
  noTone(buzzerpin);
  delay(200);
  }
