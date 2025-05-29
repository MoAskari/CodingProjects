/* Program: prob1.c
Author: Mohammad Askari
Date written: 05/10/2021 */
/*.
4. Go to Tinkercad.com and build a circuit like the one given in the image below. The circuit
consists of a temperature sensor (which is connected to an analogue pin on the
Arduino), as well as three different coloured LEDs: blue LED for cold temperatures,
orange LED for warm temperatures and red LED for hot temperatures. You need to write
a program which reads the temperature sensor and sets the LEDs to 1 (high) or 0 (low)
depending on the temperature as given below:
Temperature less than 0, blue LED on.
Temperature greater than 0 and less than 10, blue and orange LEDs on.
Temperature greater than 10 and less than 25 orange LEDs on.
Temperature greater than 25 and less than 40, red and orange LEDs on.
Temperature greater than 40, red LED on.
Use a function void readTemp(int *redLED, int *orangeLED, int *blueLED)
and use the following commands for reading the temperature:
int temperature;
temperature = analogRead(temp);
temperature = map(temperature, 20,358,-40,55);
and include if else if statements to set *redLED=0, *orangeLED=0, *blueLED=1 and so on
depending on the conditions stated above. Then in the void loop() you can use the
digitalWrite command for the LEDs.
PLEASE NOTE: You can only do this question if you have engaged with the Arduino tutorial
last semester. Please refer to the Arduino notes found on Blackboard. You need to setup the
pins in your code as well as declare the sensors as inputs and LEDs as outputs in the void
setup() function.
*/

/* SOLUTION: */

/* A program which polls a temperature sensor and lights up
a red, orange and blue LEDs according to the temperature reading.
It uses a function with three pointers for turning off or on
the LEDs
Author: TB Date: Feb 2022 */
#define Rled 5
#define Oled 4
#define Bled 3
#define temp A0
void readTemp(int *redLED, int *orangeLED, int *blueLED);
void setup()
{
 pinMode(Rled, OUTPUT);
 pinMode(Oled, OUTPUT);
 pinMode(Bled, OUTPUT);
 pinMode(temp, INPUT);
 Serial.begin(9600);
}
void loop()
{
 int R,O,B;
 readTemp(&R,&O,&B);

 digitalWrite(Rled,R);
 digitalWrite(Oled,O);
 digitalWrite(Bled,B);

}
// Function readTemp
void readTemp(int *redLED, int *orangeLED, int *blueLED){

 int temperature;

 temperature = analogRead(temp);
 temperature = map(temperature, 20,358,-40,55);
 Serial.println(temperature);
 delay(100);

 if(temperature<=0){
 *blueLED = 1;
 *orangeLED = 0;
 *redLED = 0;
 Serial.println("it is very cold");
 }

 else if(temperature>0 && temperature<=10){
 *blueLED = 1;
 *orangeLED = 1;
 *redLED = 0;
 Serial.println("it is cold");
 }

 else if(temperature>10 && temperature<=25){
 *blueLED = 0;
 *orangeLED = 1;
 *redLED = 0;
 Serial.println("it is warm");
 }

 else if(temperature>25 && temperature<=40){
 *blueLED = 0;
 *orangeLED = 1;
 *redLED = 1;
 Serial.println("it is hot");
 }

 else if(temperature>40){
 *blueLED = 0;
 *orangeLED = 0;
 *redLED = 1;
 Serial.println("it is red hot");
 }
} //end function readTemp

