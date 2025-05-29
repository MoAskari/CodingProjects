/* Program: prob1.c
Author: Mohammad Askari
Date written: 05/10/2021 */
/*. Write a program that computes the tip linear speed (m/s) and angular velocity
(rad/s) of a propeller whose shaft speed varies from 1000 to 10000 RPM in
increments of 1000. A table of the different speeds are then printed to the screen.
The program needs to have 2 functions (one for calculating the linear velocity,
and the other for calculating the angular velocity):
• The functions to calculate the linear and angular velocities must be called
from main.
• Use formatting to present a neat table to the screen (for RPM m/s rad/s).
• Ask user to enter a value for the diameter/radius.
• Converting RPM to m/s: v= 2*pi*r*RPM/60
• Converting m/s to rad/s: omega = v/r*/

/* SOLUTION: */

/* A program to print a table of RPM, linear velocity and
angular velocity of a propeller.
This program uses 2 functions: one for calculating the linear velocity
and the other for calculating the angular velocity.
Author: TB, August 2021 */

#include <stdio.h>

float linearVelocity(int rpm, float d);   // function declaration
float angularVelocity(float vel, float d);

#define PI 3.142
#define RPM 1000

int main(){
	int RPM1, i;
	float v, omega, D;

	printf("Enter a value for the diameter\n");
	scanf("%f",&D);          //diameter D in metres

	printf(" RPM\t v\tomega\n");

	for(i=0;i<10;i++){            //looping over all the rpm values
        RPM1 = RPM*(i+1);
        v = linearVelocity(RPM1, D);
        omega = angularVelocity(v, D);
        printf("%5d %7.2f %7.2f\n", RPM1, v, omega);
	}
} //end main

// function definition to calculate linear velocity
float linearVelocity(int rpm, float d){
    float vel;
	vel= (PI*d*rpm)/60;      //converting rpm to linear velocity (m/s)

	return vel;
}

// function definition to calculate angular velocity
float angularVelocity(float vel, float d){
    return 2*vel/d;                    //converting linear vel (m/s) to angular vel (rad/s)
}
