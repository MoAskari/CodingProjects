/* Program: prob1.c
Author: Mohammad Askari
Date written: 05/10/2021 */
/*.
7. TINKERCAD: Flash the 3 LEDs in succession to emulate a traffic light, using a structure, which
has members: pinNumber, and delayTime. Feel free to use a function to set the LEDs on
and off using digitalWrite. You can pass the structure in your function or you can pass the
individual members.
*/

/* SOLUTION: */

/*Arduino C code to simulate a traffic light (GREEN-ORANGE-RED-ORANGE)
A structure is used for the LEDs to store the pin number and the delay time.
Author: TB, Date: 09.03.2022 */
#define redPin 4
#define orangePin 3
#define greenPin 8
struct LEDs{
 int pin;
 int delayTime;
};
void setup() {
 // put your setup code here, to run once:
 struct LEDs green = {greenPin, 3000};
 struct LEDs orange = {orangePin, 1000};
 struct LEDs red = {redPin, 3000};


 pinMode(green.pin,OUTPUT);
 pinMode(orange.pin,OUTPUT);
 pinMode(red.pin,OUTPUT);
}
void loop() {
 struct LEDs green = {greenPin, 3000};
 struct LEDs orange = {orangePin, 1000};
 struct LEDs red = {redPin, 3000};
 // put your main code here, to run repeatedly:

 // green
 lightLED(green.pin,green.delayTime);
 // orange
 lightLED(orange.pin,orange.delayTime);
 // red
 lightLED(red.pin,red.delayTime);
 // orange
 lightLED(orange.pin,orange.delayTime);
}
void lightLED(int pin, int delayTime){
 digitalWrite(pin, HIGH);
 delay(delayTime); //delayTime second delay
 digitalWrite(pin, LOW);

}
