# Arduino-Parking-System
Parking system simulation using Arduino Uno
# Requirements:

1- Arduino Uno R3 (x1)
#
2- infrared Sensor (x2)
#
3- I2C LCD (x1)
#
4-Arduino wires
#
5- Arduino IDE installed
# Purpose:
Monitor the entrance and the exit of the cars using the Arduino Uno via the IR sensors: one for the entrance and the other for the exit and display the number of cars currently in the parking via the I2C LCD
#
# How to use:

1-Run the "I2c Initializing.ino" file on the Arduino IDE: this code is used to find the I2C LCD Address.( In my case it's 0x27 )
 
2-Open the "main code.ino" file and put the I2C LCD adresse in the lcd element.( In my case: lcd(0x27, 16, 2) )

 N.B: If you changed the IR sensors pins location don't forget to change it in the main code.( In my case: int IRSensor_Entrance = 3; int IRSensor_Exit = 7;

 N.B: You can change the number of parks by changing the "lastcount" variable in "the main code" file.(In my case: lastCount = 5 ; )
