#include <Mouse.h>
#include <Keyboard.h>
#include <SoftwareSerial.h>

#define BTtx 8
#define BTrx 9

//https://www.martyncurrey.com/hc-06-hc01-comv2-0/
//https://www.youtube.com/watch?app=desktop&v=s-lzV_RfZoo - para modulo JDY-31

SoftwareSerial BT(BTrx, BTtx);

void setup(){
  pinMode(BTrx, INPUT);
  pinMode(BTtx, OUTPUT);
  BT.begin(9600);
  delay(500);
  Mouse.begin();
  delay(500);
  Keyboard.begin();
  delay(500);
  Serial.begin(9600);
  delay(500);
}
char c =' ';
int count = 0;

void loop(){
  if (count == 0 ){
    delay(1000);
    Mouse.click();
    count++;
    Serial.println("posição enviada");
  }
  if(BT.available()){
    //Serial.print(".");
    c=BT.read();
    if (c == '^'){
      Keyboard.println("");
      Serial.println(c);
      count++;
      if (count>=2){
        count=0;
      }
    }
    else {
      Keyboard.write(c);
      Serial.print(c);
    }
    //count++;
    //if (count==44){
    //  Keyboard.println("");
    //  count=0;
 
  }
  // if(Serial.available()){
  //   c=Serial.read();  
  //   Serial.write(c);
  //   BT.write(c);
  // }
  delay(2);
}

