/* Program: prob1.c
Author: Mohammad Askari
Date written: 05/10/2021 */
/*  . Write a program that accepts the radius of a circle and calculate its
circumference. Print the circumference to the screen. (use float variables, give
results to 2 decimal places )

HINT: 1. Create 2 variables: one to store the radius (r) and one for the
circumference (circum)
 2. Use a printf statement to prompt the user to enter the radius of the
circle
 3. Use scanf with %f to store the radius value
 4. Calculate the circumference (circum = 2*3.142*r)
 5. Print the circumference to the screen to 2 dp (use %.2f) using a printf
statement*/

void main()
{
    float radius;
    printf("Please enter a the radius of your circle\n");
    scanf("%f",&radius);
    printf("Your radius is as follows: %f \n", radius);
    float circum = 2*3.142*radius;
    printf("your circumference is %.2f \n", circum);
}

/* SOLUTION: */

/* program to input the radius of a circle and calculate its diameter, circumference and area */
/* d = 2*r; c = 2*PI*r; a = PI * r*r                                                          */
/* written by Tara Baldacchino, August 2016
                                                            */
#include <stdio.h>

void sol()
{
      float r, circum, PI=3.142;
      printf("please input radius..\n");
      scanf("%f",&r);
      circum=2*PI*r;
      printf("circumference = %.2f\n",circum);
}
