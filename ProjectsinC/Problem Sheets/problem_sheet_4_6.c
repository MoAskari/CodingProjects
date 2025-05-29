/* Program: prob1.c
Author: Mohammad Askari
Date written: 05/10/2021 */
/*.
6. Write a program (using arrays) that computes the tip linear speed and angular
velocity of a propeller whose shaft speed varies from 1000 to 10000 rpm in
increments of 1000, for 3 different values for diameter/radius determined by the
user. A table of the different speeds for the different diameters is printed to the
screen (3 tables in total).
• Use formatting to present a neat table to the screen (for RPM v omega).
• Ask user to enter 3 values for the diameter/radius.
• RPM -> m/s: v= 2*pi*r*RPM/60
• m/s->rad/s: omega = v/r
*/

/* SOLUTION: */

/* Problem 4-6.c A program to print a table of RPM, linear velocity and
angular velocity of a propeller whose shaft speed varies
from 1000 to 10000.
Author: TB, August 2018 */

#include <stdio.h>

void printTable(int rpm, float vel, float omega);

#define PI 3.142
#define RPM 1000

main(){
	int RPM1[30]={1000,2000,3000,4000,5000,6000,7000,8000,9000,10000}, i, j;
	float v[30], omega[30], D[3];

	printf("Enter 3 different values for the diameter\n");
	for(i=0;i<3;i++){
        scanf("%f",&D[i]);          //diameter D in metres
	}



	for(j=0;j<3;j++){                   //looping over all the diameter values
        printf(" RPM\t v\tomega\t for diameter %0.2f\n",D[j]);
        for(i=0;i<10;i++){            //looping over all the rpm values
            v[i]=(PI*D[j]*RPM1[i])/60;
            omega[i] = 2*v[i]/D[j];
            printTable(RPM1[i], v[i], omega[i]);
            }
        printf("\n \n");
	} //end for

} //end main


// function definition to print values in a table
void printTable(int rpm, float vel, float omega){
    printf("%5d %7.2f %7.2f\n", rpm, vel, omega);

}
