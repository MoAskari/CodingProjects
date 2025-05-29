/* Program: prob1.c
Author: Mohammad Askari
Date written: 05/10/2021 */
/*.
3. Write an area calculator for these shapes:
• Rectangle (hint: area = length * width)
• Circle (hint: area = π * radius2 , use π = 3.14 )
• Triangle (hint: area = ½ * base * height)
Centimetres should be used for units. All dimensions must be positive floating point
values in the range 0.01 ≤ dimension ≤ 100.00 . The area calculator should ask the user
to choose the shape (use a switch case), and to input the necessary values depending
on the shape chosen (e.g. length, width). The area calculator should print out the area to
two decimal places, along with an appropriate message (e.g. the message might be “The
area of the rectangle is x cm squared.”). Use a different function for each different shape.
The function parameters should be the dimensions, and the function return value should
be the area. If the user enters an out-of-range value for the dimension, the program
should ask the user to enter a value again until a correct value is entered. Once the
program finds the area of a shape, the program should loop to the start and ask the user
to pick a shape until the user quits the program.
3a) Modify Problem 3 above so that the functions you created use pointers for the area and
volume of the shapes, which then get printed in main. Eg, for the rectangle
void rectAreaVol(float length, float width, float height, float
*area, float *volume);
The volume must be calculated from the area (the area is just a by-product of the function)
• Rectangle (hint: volume = length * width*height)
• Circle (hint: volume =(4/3)* π * radius3 , use π = 3.14 )
• Triangle (hint: volume = ½ * base * height*length)
*/

/* SOLUTION: */

/* Problem6-3.c                                            */
/* Write an area and volume calculator, using pointers, for these shapes:     */
/*	Rectangle                 */
/*  Circle                    */
/*  Triangle               */
/* Centimetres must be used for units.  All dimensions must*/
/* be positive floating point values in the range          */
/* 0.01 < dimension < 100.00 .  The area calculator should */
/* ask the user to choose the shape, and to input the      */
/* necessary values (e.g. length, width).  The area        */
/* calculator should print out the area to two decimal     */
/* places, along with an appropriate message.  Use a       */
/* different function for each different shape.  The       */
/* function parameters should be the dimensions, and the   */
/* function return values should be the areas.             */
/* Written by TB, March 2017                              */
#include <stdio.h>

#define MIN 0.01
#define MAX 100.00
#define PI 3.14

float rectArea(float length, float width);
float circleArea(float radius);
float triArea(float base, float height);


int main()
{
      float length, width, radius, base, height, area;
      int shape;
      char choice='Y';
      printf("Area calculator.  All dimensions must be >0.01 and < 100.0\n");
      do
      {

          printf("please choose shape:  rectangle (type 1), circle (type 2), or triangle (type 3)\n");
          scanf("%d",&shape);


          switch(shape)
              {
                case 1:
                    printf("rectangle\n");
                    do
                    {
                        printf("please enter length: ");
                        scanf("%f",&length);
                    } while(length<=MIN || length>=MAX);
                    do
                    {
                        printf("please enter width: ");
                        scanf("%f",&width);
                    } while(width<=MIN || width>=MAX);

                    area = rectArea(length,width);
                    printf("The area of the rectangle is %.2f cm squared.\n",area);
                    break;

                case 2:

                    printf("circle\n");
                     do
                     {
                           printf("please enter radius: ");
                           scanf("%f",&radius);
                     } while(radius<=MIN || radius>=MAX);
                     area = circleArea(radius);
                     printf("The area of the circle is %.2f cm squared.\n",area);
                     break;

                case 3:
                    printf("triangle\n");
                    do
                    {
                          printf("please enter base: ");
                          scanf("%f",&base);
                    } while(base<=MIN || base>=MAX);
                    do
                    {
                          printf("please enter height: ");
                          scanf("%f",&height);
                    } while(height<=MIN || height>=MAX);

                    area = triArea(base,height);
                    printf("The area of the triangle is %.2f cm squared.\n",area);
                    break;

                default:
                    printf("Wrong input.\n");

              }

            fflush(stdin);
            printf("would you like to try again? Y/N\n");
            choice=getchar();

        }while(choice=='Y');




}
/* function float rectArea(float length, float width); */
float rectArea(float length, float width)
{
    float area;
    return area= length*width;

}
/* function float circleArea(float radius);  */
float circleArea(float radius)
{
    float area;
    return area= radius*radius*PI;

}
/* function float triArea(float base, float height);  */
float triArea(float base, float height)
{
    float area;
    return area= 0.5*base*height;

}



