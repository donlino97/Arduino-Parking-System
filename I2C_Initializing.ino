
//                                             ******************After founding the LCD adress*******************
#include <LiquidCrystal_I2C.h> //LCD I2C Library

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows
 int IRSensor_Entrance = 4;// connect Entrance ir sensor ( green light ) to arduino pin 2
 int IRSensor_Exit = 7;// connect Entrance ir sensor ( red light ) to arduino pin 7
unsigned long lastCount = 9; //maximum number of parks
int count=0; // number of reserved parks

void setup() {

   pinMode (IRSensor_Entrance, INPUT); // sensor pin INPUT
   pinMode (IRSensor_Exit, INPUT); // sensor pin INPUT
  lcd.begin(); // start the lcd
  lcd.clear(); // clear it from cashe
   lcd.print(" Arduino Parking"); // print on LCD screen
   lcd.setCursor(3,1);
   lcd.print("Simulator");
   delay(2000);
   
 
 

}

void loop() {
   
  int statusSensor_green = digitalRead (IRSensor_Entrance); // "1" if the sensor is off & "0" if the sensor is on
   int statusSensor_red = digitalRead (IRSensor_Exit); // "1" if the sensor is off & "0" if the sensor is on
   if ( count != lastCount && statusSensor_green != 1) {
    count=count+1 ;
    lcd.clear();
    lcd.setCursor(0, 0); // start to print at the first row
    lcd.print("Reserved: ");
    lcd.print(count);
    lcd.setCursor(0, 1); // start to print at the second row
     lcd.print("Remaining: ");
    lcd.print(lastCount - count);
    delay(1000);
   
  }

   if ( count != 0 && statusSensor_red != 1) // if there is a car is entering 
  {
    count=count-1 ;
    lcd.clear();
    lcd.setCursor(0, 0); // start to print at the first row
    lcd.print("Reserved: ");
    lcd.print(count);
    lcd.setCursor(0, 1); // start to print at the second row
     lcd.print("Remaining: ");
    lcd.print(lastCount - count);
    delay(1000);
   
  }
    if((count!=lastCount && statusSensor_green==1 && statusSensor_red==1) || (statusSensor_green!=1 && statusSensor_red!=1)) 
    /* no cars are entering or exiting at this time or entering and exiting at the same time */
   {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Reserved: ");
    lcd.print(count);
    lcd.setCursor(0, 1);
    lcd.print("Remaining: ");
    lcd.print(lastCount - count);
    delay(200);
  } 
  if(count == lastCount)  // if the parking is full
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("FULL");
    lcd.setCursor(0, 1);
    lcd.print("No remaining");
    delay(1000);
  }
 
}
