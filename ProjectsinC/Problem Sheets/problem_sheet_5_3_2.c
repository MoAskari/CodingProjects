/* Program: prob1.c
Author: Mohammad Askari
Date written: 05/10/2021 */
/*.
3. Write a program to calculate the solution for the quadratic equation y(x)=Ax2 + Bx + C, where
A, B and C are entered by the user and x varies from 0 to 49. These are the values that will be
accepted for A, B and C:
• A > -1.0
• -10.0 < B < 10.0
• C < 0.1
 If the user inputs an out-of-range value, the program should prompt the user for the value again
and input the value again, until a correct value is entered.
• Calculate y(x), for x = 0, 1, 2, … , 49
• Display a table of the x and y values, with the x values as integers and the y values as
floating point numbers shown to 1 decimal place. Your table should have a header row
to label the columns as x and y(x).
 Your program should calculate y(x) and store it in an array.
 For example, if A = -0.5, B = -0.1 and C = 0.05, the table of values would be:
x y(x)
--- -----
0 0.1
1 -0.6
2 -2.2
3 -4.8
4 -8.4
.
.
49 -1205.3
 Write two versions of this program: one version using an array and array indices for y(x), and
another version using a pointer for y(x), *yPtr.
*/

/* SOLUTION: */

/* A program to solve a quadratic equation, using coefficients input by the user. */
/* Prompt the user to input three float numbers A, B and C, which will be the        */
/* coefficients in a quadratic equation.  These are the values that will be accepted */
/* for A, B and C:                                                                   */
/*	A > -1.0                                                                         */
/* -10.0 < B < 10.0                                                                  */
/*	C < 0.1                                                                          */
/* If the user inputs an out-of-range value, the program should prompt the user for  */
/* the value again and input the value again.                                        */
/* Calculate y(x), for x = 0, 1, 2, … , 49                                           */
/* Display a table of the x and y values, with the x values as integers and the      */
/* y values as floating point numbers shown to 1 decimal place.  Your table should   */
/* have a header row to label the columns as x and y(x).

/* Version 2, using array  and pointers               */

/* TB, February 2017                                  */

#include <stdio.h>

#define SIZE 50
#define A_MIN -1.0
#define B_MAX 10.0
#define B_MIN -10.0
#define C_MAX 0.1

main()
{
  int x, xMaxY=0;
  float *yPtr;
  float A,B,C;

  //yPtr=y;

  printf( "Quadratic equation calculation\n" );
  /* input coefficients, and check that each is in range */
  do
  {
  	printf( "Please input the coefficient A (A > %.1f)\n", A_MIN );
    scanf( "%f",&A );
  } while( A<=A_MIN );
  do
  {
    printf("Please input the coefficient B (%.1f < B < %.1f)\n", B_MIN, B_MAX);
    scanf( "%f",&B );
  } while( B<=B_MIN || B>=B_MAX );
  do
  {
    printf("Please input the coefficient C (C < %.1f)\n", C_MAX);
    scanf( "%f",&C );
  } while( C>=C_MAX );

  /* print header row */
  printf(" x    y(x)\n");
  printf("__    ____\n");

  /* for each x in range, calculate y and print x and y */
  for( x=0; x<SIZE; x++)
  {
    *(yPtr+x)=A*x*x + B*x + C;
    printf ("%2d    %.1f\n",x,*(yPtr+x) );
  } /* end for */


/* end main */
}
