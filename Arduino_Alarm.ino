/*Sketch by SpirosP
  @PapadopSpiros on GitHub
  @SpirosP on YouTube
  You may use my code on your projects for free. If you wish to edit or republish it, please credit me.
*/


//Import the Liquid Crystal I2C Library
#include <LiquidCrystal_I2C.h>

//Specify display info [I2C Address],[X Pixels],[Y Pixels]
LiquidCrystal_I2C ml(0x27,16,2);

//Declare variables
int i;
int ct;
int mt;
int ht;
int cl;

//Set time variables
int cpv;
int ppv;
int alarm;

//Set the pin of the buzzer
int buzzerpin=12;

void setup() {
  
  //Initialize LCD
  ml.init();

  //Turn backlight on
  ml.backlight();

  //Call settime void
  settime();
}

void loop() {

  //Clock
  for(i=0; i>-1; i++){
    
    //One second delay
    delay(1000);

    //If a minute elapses
    if(ct>58){
      ct=0;
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
    Serial.println(ht);
  }
  sound();
}

//Alarm sound
void sound(){
  ml.setCursor(0,0);
  ml.print("Wake up!");
  i=0;
  for (i=0; i<100; i++){
    tone(buzzerpin,2051);
    delay(100);
    noTone(buzzerpin);
    delay(200); 
  }
  i=0;
}

void settime() {
  
  //Set hours
  for (i=0; i<100; i++) {
    cpv=map(analogRead(A0),0,1023,0,24);
    if (cpv!=ppv) {
      ml.clear();
      Serial.println(cpv);
      ht=(cpv);
      ml.setCursor(0,1);
      ml.setCursor(0,0);
      ml.print("Set hours:");
      ml.print(cpv);
      ppv=cpv;
    }
    delay(100);
  }
  ml.clear();
  
  //Set minutes
  for (i=0; i<100; i++) {
    cpv=map(analogRead(A0),0,1023,0,60);
    if (cpv!=ppv) {
      ml.clear();
      Serial.println(cpv);
      mt=(cpv);
      ml.setCursor(0,1);
      ml.setCursor(0,0);
      ml.print("Set minutes:");
      ml.print(cpv);
      ppv=cpv;
    }
    delay(100);
  }
  ml.clear();

  for (i=0; i<100; i++) {
    cpv=map(analogRead(A0),0,1023,0,1);
    if (cpv!=ppv) {
      ml.clear();
      Serial.println(cpv);
      alarm=(cpv);
      ml.setCursor(0,1);
      ml.setCursor(0,0);
      ml.print("Set alarm units:");
      ml.setCursor(0,1);
      if (cpv=0) {
        ml.print("Minutes");
      }
      else {
        ml.print("Hours");
      }
      ppv=cpv;
    }
    delay(100);
  }
  ml.clear();

  //Set alarm hours
  for (i=0; i<100; i++) {
    cpv=map(analogRead(A0),0,1023,0,24);
    if (cpv!=ppv) {
      ml.clear();
      Serial.println(cpv);
      alarm=(cpv);
      ml.setCursor(0,1);
      ml.setCursor(0,0);
      ml.print("Set alarm time:");
      ml.setCursor(0,1);
      ml.print(cpv);
      ppv=cpv;
    }
    delay(100);
  }
  ml.clear();
}
