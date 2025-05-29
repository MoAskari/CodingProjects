/* Program: prob1.c
Author: Mohammad Askari
Date written: 05/10/2021 */
/*.
7. Adjust Q4 from last week’s practice sheet: reading a temperature sensor and lighting up
a LED or two LEDs depending on the temperature reading. The change in this code is to
use an array to hold the status of the LEDs, eg, condition[3] where condition [0] is for the
red LED, condition [1] is for the orange LED and condition [2] is for the blue LED. Adjust
your function to be either void readTemp(int status[]) or void readTemp(int
*status).
Please note that the solutions I provide (to the questions which don’t specify the
exact function signature) are not the only way to program the above questions. If
you have used different input parameters to functions, or used a return instead of
a pointer variables, then these are still correct!
*/

/* SOLUTION: */

/* A program which polls a temperature sensor and lights up
a red, orange and blue LEDs according to the temperature reading.
It uses a function with a 1D array for turning off or on
the LEDs
Author: TB Date: Feb 2022 */
#define Rled 5
#define Oled 4
#define Bled 3
#define temp A0
void readTemp(int status[]);
int condition[3]; //Red, Yellow, blue
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
 readTemp(condition);

 digitalWrite(Rled,condition[0]);
 digitalWrite(Oled,condition[1]);
 digitalWrite(Bled,condition[2]);

}
// Function readTemp
void readTemp(int status[]){

 int temperature;

 temperature = analogRead(temp);
 temperature = map(temperature, 20,358,-40,55);
 Serial.println(temperature);
 delay(100);

 if(temperature<=0){
 status[2] = 1;
 status[1] = 0;
 status[0] = 0;
 Serial.println("it is very cold");
 }

 else if(temperature>0 && temperature<=10){
 status[2] = 1;
 status[1] = 1;
 status[0] = 0;
 Serial.println("it is cold");
 }

 else if(temperature>10 && temperature<=25){
 status[2] = 0;
 status[1] = 1;
 status[0] = 0;
 Serial.println("it is warm");
 }

 else if(temperature>25 && temperature<=40){
 status[2] = 0;
 status[1] = 1;
 status[0] = 1;
 Serial.println("it is hot");
 }

 else if(temperature>40){
 status[2] = 0;
 status[1] = 0;
 status[0] = 1;
 Serial.println("it is red hot");
 }
} //end function readTemp
