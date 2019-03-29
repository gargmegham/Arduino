#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

byte ball[8] = { B00000,
                 B00100,
                 B01110,
                 B11111,
                 B01110,
                 B00100,
                 B00000}; //custom ball shape

byte bat[8] = { B01110,
               B01110,
               B01110,
               B00100,
               B00100,
               B00100,
               B00100};  //custom bat shape

int up1=8;    //up for player 1
int up2=10;   //down for player 1
int down1=9;  //up for player 2
int down2=11; //down for player 2

int d=0; // 0 indiactes ball is travelling towards right 
         // 1 indiactes ball is travelling towards left

int bt1_x=0;  // x coordinates of bat of player 1
int bt1_y=0;  // y coordinates of bat of player 1

int bt2_x=15; // x coordinated of bat of player 2
int bt2_y=0;  // y coordinated of bat of player 2

int bl_x=1; // x coordinated of ball
int bl_y=0; // y coordinated of ball

int play = 0; // to check weather the game is On.

void setup()
{
  lcd.begin(16, 2);
  lcd.clear();
  
  lcd.createChar(0, ball);  //create ball
  lcd.createChar(1, bat); //create racket or bat
  
  pinMode(up1, INPUT);    //configure buttons for inputs
  pinMode(down1, INPUT);
  pinMode(up2, INPUT);
  pinMode(down2, INPUT);
  
  Serial.begin(9600);
}

void loop()
{
  if(play == 0) //if no one is playing
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("press any button");
    lcd.setCursor(2,1);
    lcd.print("to start....");
    delay(250);
    if(digitalRead(up1) == HIGH || digitalRead(down1) == HIGH || digitalRead(up2) == HIGH || digitalRead(down2) == HIGH )
    {
      play = 1; // start the game
      lcd.clear();
    }
  }
   
  if(play == 1)
  {
    
    lcd.setCursor(bt1_x,bt1_y);
    lcd.write(byte(1));
    lcd.setCursor(bt2_x,bt2_y);
    lcd.write(byte(1));
    lcd.setCursor(bl_x,bl_y);
    lcd.write(byte(0));
    delay(40);
    
    // if the ball is moving right
    if(d==0)
    {
      if(bl_x==15) // if the ball has reached the last position on right side
      {
        d=1;  //reverse the direction
        if(bl_y!=bt2_y) //if bat misses the ball
        {
          play=0;
          lcd.clear();
          lcd.print("player 1 wins");
          delay(250);
        }
      }
      else //move the ball forward
      {
        bl_x = bl_x + 1;
        bl_y = !bl_y;
      }
    }
    
    // if the ball is moving left
    if(d==1 && play==1)
    {
      if(bl_x==0) // if the ball has reached the last position on left side
      {  
        d=0;  //reverse the direction of ball
        if(bl_y!=bt1_y) //if bat misses the ball
        {
          play=0;
          lcd.clear();
          lcd.print("player 2 wins");
          delay(250);
        }
      }
      else  //move the ball forward
      {
        bl_x = bl_x - 1;
        bl_y = !bl_y;
      }
    }
    if(digitalRead(up1) == HIGH)
    {
      bt1_x=0;
      bt1_y=0;
    }
    if(digitalRead(down1) == HIGH)
    {
      bt1_x=0;
      bt1_y=1;
    }
    if(digitalRead(up2) == HIGH)
    {
      bt2_x=15;
      bt2_y=0;
    }
    if(digitalRead(down2) == HIGH)
    {
      bt2_x=15;
      bt2_y=1;
    }
    lcd.clear();
  }
}
