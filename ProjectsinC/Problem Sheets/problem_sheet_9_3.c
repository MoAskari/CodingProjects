/* Program: prob1.c
Author: Mohammad Askari
Date written: 05/10/2021 */
/*.
3. TINKERCAD: Flash the 3 LEDs in succession to emulate a traffic light, using an array
of structure (struct LEDs trafficLights[3]), which has members: pinNumber, and
delayTime. Feel free to use a function to set the LEDs on and off using
digitalWrite.
*/

/* SOLUTION: */

/*Arduino C code to simulate a traffic light (GREEN-ORANGE-RED-ORANGE)
An array of structure is used for the 3 LEDs to store the pin number and the delay time.
Author: TB, Date: 09.10.2020 */
#define redPin 4
#define orangePin 3
#define greenPin 8
struct LEDs{
 int pin;
 int delayTime;
};
struct LEDs trafficLights[3] = {{greenPin, 3000},{orangePin, 1000},{redPin, 3000}};
void setup() {
 // put your setup code here, to run once:
 for(int i=0;i<3;i++){
 pinMode(trafficLights[i].pin,OUTPUT);
 }

}
void loop() {

 lightLED();
}
void lightLED(){
 for(int i=0;i<4;i++){
 digitalWrite(trafficLights[i].pin, HIGH);
 delay(trafficLights[i].delayTime); //delay
 digitalWrite(trafficLights[i].pin, LOW);
 }

}
