/* Program: prob1.c
Author: Mohammad Askari
Date written: 05/10/2021 */
/*.
3. Write a C program which performs polar to Cartesian co-ordinate conversion, using two C
structures to hold the polar and Cartesian coordinates. The user needs to enter the radius, and
angle in degrees (which needs to get converted to radians). Print the conversion to the screen.
You might like to view http://www.mathtutor.ac.uk/geometry_vectors/polarcoordinates for
information on how to do the conversion. You also might like to view information about sin and
cos in the maths library, see http://www.tutorialspoint.com/c_standard_library/math_h.htm.
You can use these structs:
struct polar
{
double r;
double theta;
};
struct cartesian
{
double x;
double y;
};
*/

/* SOLUTION: */

// Problem8-3.c
// A program to convert polar coordinates (r,q) to Cartesian coordinates (x,y)
// Use struct polar with members r, q  and struct cart with members x,y
//
// written by TB,  March 2019

#include <stdio.h>
#include <math.h>

struct polar // to hold the polar coordinates
{
       double r;      // distance from origin to point
       double theta;  // angle from positive x to the point in degrees
};
struct cartesian  // to hold the cartesian coordinates
{
       double x;  // x coordinate
       double y;  // y coordinate
};

void main()
{
      struct polar myP;
      struct cartesian myC;
      printf("This program will convert polar coordinates to Cartesian.\n");
      printf("Please enter r (the distance from the origin to the point):  ");
      scanf("%lf", &myP.r);

      printf("Please enter theta (the angle measured from the positive 'x' axis to the point) in degrees:  ");
      scanf("%lf", &myP.theta);

      double rads = (myP.theta * M_PI)/180.0;
      myC.x = myP.r*cos(rads);
      myC.y = myP.r*sin(rads);
      printf("For the polar coordinates %.2lf,%.2lf, the Cartesian coordinates are %.2lf,%.2lf\n", myP.r, myP.theta, myC.x, myC.y);

}





