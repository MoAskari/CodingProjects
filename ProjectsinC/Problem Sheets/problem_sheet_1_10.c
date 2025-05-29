/* Program: prog5.c
Author: Mohammad Askari
Date written: 05/10/2021 */
#include <stdio.h>
/* Write a program that enters a temperature in degrees Celsius (°C) and converts it
to degrees Fahrenheit. (use float variables, output the result to 1 decimal place)
HINT: Conversion formula is 𝑡𝑡𝑡𝑡𝑡𝑡𝑡𝑡 ∗ 9
5 + 32 where temp is the temperature in °C */

/* SOLUTION */

/* a program that enters a temperature in degrees centigrade and converts it to degrees Fahrenheit */
/* Formula. °C x 9/5 + 32 = °F                                                                     */
/* written by Tara Baldacchino, August 2020                                                       */
#include <stdio.h>
void main()
{
      float celsius, fahrenheit;
      printf("please enter temperature in degrees Celsius..\n");
      scanf("%f",&celsius);
      fahrenheit=celsius* 9.0/5.0 + 32.0;  // use standard conversion formula
      printf("in fahrenheit that is: %.1f\n",fahrenheit);

}


