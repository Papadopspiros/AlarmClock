/*Sketch by SpirosP
  @PapadopSpiros on GitHub
  @SpirosP on YouTube
  You may use my code on your projects for free. If you wish to edit or republish it, please credit me.
  The code has been written, debuged and tested on the Arduino Uno Wi-Fi Rev 2.
  Before compiling you will need to install the Liquid Crystal I2C library which you can find on the official Arduino website.
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
int sp=2;

//Declare time config variables
int cpv;
int ppv;
int alarm;

//Set the pin of the buzzer
int buzzerpin=12;

//Set alarm sound parameters
int del1=100;
int del2=200;

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
    if (digitalRead(sp)=LOW) {
      tone(buzzerpin,2051);
      delay(del1);
      noTone(buzzerpin);
      delay(del2);
    }
    else {
      break();
    }
  }
  i=0;
  ml.clear();
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