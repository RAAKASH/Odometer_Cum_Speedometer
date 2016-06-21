/*
  LiquidCrystal Library - Hello World
 
 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the 
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.
 
 This sketch prints "Hello World!" to the LCD
 and shows the time.
 
  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 
 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 
 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

   
// include the library code:
#include <LiquidCrystal.h>
 float dis =0,dis1=0;;//distance 
int sensor=8;
float i,t=0.0,t1=0.0;
float r=.35,f=0.0,s=0.0;
float c=0;//radius
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
dis=0;
  pinMode(sensor,INPUT);// set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  lcd.print("**CYCLE METER**");
  delay(5000);
  lcd.clear();
  // Print a message to the LCD.
  lcd.print("SPEED:");
  lcd.setCursor(0,1);
  lcd.print("DIST:");
  
}

void loop() {  

  i=digitalRead(sensor);
  if(i==LOW)
  {

  
  lcd.setCursor(5,1);
lcd.print(dis);
lcd.setCursor(15,1);
lcd.print("m");

lcd.setCursor(6,0);
lcd.print(s);
lcd.setCursor(13,0);
lcd.print("m/s");

if(f==0)
{
dis+=2*3.14159265*r/4;
   t1=millis()/1000.0;
  
  s=2*3.1415*r/(t1-t)/4;
  t=millis()/1000.0;
 f=1;}}

 else
 {f=0;

lcd.setCursor(5,1);
lcd.print(dis);
lcd.setCursor(15,1);
lcd.print("m");


lcd.setCursor(6,0);
lcd.print(s);
lcd.setCursor(13,0);
lcd.print("m/s");
c=(millis()/1000-t);
if(c>=8.0)
s=0.0;
 }
    
  
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):

}

