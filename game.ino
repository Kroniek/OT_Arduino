#include "arduino_secrets.h"

const int PinBtn = 2;
#include <LiquidCrystal_I2C.h>
#include <Wire.h>


LiquidCrystal_I2C led(0x27,16,2);


byte patlama[] = {
  B00000,
  B00000,
  B10101,
  B01110,
  B01110,
  B10101,
  B00000,
  B00000
};


byte s1[] = {
  B11110,
  B10010,
  B11110,
  B11110,
  B11110,
  B10010,
  B10011,
  B11000
};


byte s2[] = {
  B11110,
  B10010,
  B11110,
  B11110,
  B11110,
  B10010,
  B11010,
  B00011
};


byte c1[] = {
  B00000,
  B00000,
  B00110,
  B00110,
  B10110,
  B11110,
  B00110,
  B00110
};


bool spriteBool = false;
float jump = 0;
int cactiRng = 20;
int cacti[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int skor=0;
int hskor=0;
bool isDed = false;
bool d1 = false;
int db=0;


void setup()
{
  Serial.begin(9600);
  pinMode(PinBtn, INPUT_PULLUP); // Push Button as INPUT wiith pullup
  led.init();
  led.createChar(0, s1);
  led.createChar(1, s2);
  led.createChar(2, c1);
  led.createChar(3, patlama);
  led.backlight();
  led.setCursor(0,0);
}


void loop()
{
  if(isDed==false)
  {
    delay(500);
  //
  cactiRng-=random(4, 12);
  if(cactiRng<=0){
    db--;
    cactiRng = 40;//lover the number is more the more cactus will spawn
    if(skor>250){cactiRng=35;}//lover the number is more the more cactus will spawn
    if(skor>500){cactiRng=30;}//lover the number is more the more cactus will spawn
    if(skor>750){cactiRng=25;}//lover the number is more the more cactus will spawn
    cacti[15]=1;
    if(random(0,6)==3&&db<=0){cactiRng=0;
    db=2;
    }
  }
  //
  for(int i = 0; i < 15; i++)
  {
    if(i==15)
    {
      cacti[i]=0;
    }else{
      cacti[i]=cacti[i+1];
      cacti[i+1] = 0;
    }
  }
  for(int i = 0; i < 15; i++){
    led.setCursor(i,1);
    if(cacti[i]==1)
    {
      led.write(2);
    }else{
      if(!(jump==0&&i==1))
      {
        led.print(" ");
      }  
    }
  }
  //
  if(digitalRead(PinBtn) == LOW&&jump<=0)  // When Push Button is pressed
  {
    jump=2;
  }
  if(jump>0)
  {
  jump-=0.5;  
  }
  if(jump>0)
  {
    led.setCursor(1,1);
    if(cacti[1]==0){ led.print(" ");}
    led.setCursor(1,0);
  }else{
    led.setCursor(1,0);
    led.print(" ");  
    led.setCursor(1,1);
  }
  if(spriteBool==true)
  {
    led.write(0);
    spriteBool=false;
  }else{
    led.write(1);
    spriteBool=true;
  }
  //
  if(cacti[1]&&jump==0)
  {
  led.setCursor(1,1);
  led.write(3);
  delay(2000);
  isDed=true;
  led.clear();
  Serial.print("you died");
  }else{
  skor+=5;
  led.setCursor(12,0);
  led.print(skor);
  }
  //
  }else {
  //Ã¶you died
    if(d1==false){
    led.setCursor(0,0);
    led.print("Score "+String(skor));  
    if(skor>hskor){hskor=skor;}
   
    led.setCursor(0,1);
    led.print("HghScore "+String(hskor));
    d1=true;
    }
    if(digitalRead(PinBtn) == LOW){
      d1=false;
      isDed=false;
      skor=0;
      for(int i=0; i<15;i++){cacti[i]=0;}
      cactiRng=40;
      led.clear();  
    }
  }
}

