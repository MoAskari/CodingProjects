/* Program: prob1.c
Author: Mohammad Askari
Date written: 05/10/2021 */
/*.
6. Write a program to compute the compression stress and strain in a column of diameter d, when
subjected to a load p. Use the following structure:
 struct strength
{
float p;
float d;
float stress;
float strain;
};
Use the following formulae to compute stress and strain for a given value of diameter d when
subjected to a load p:
Area = (pi*d^2)/4
Stress = p/area;
Strain = stress/E where E is the modulus of elasticity which is 30x10^6 psi for steel.
*/

/* SOLUTION: */

/* Problem 8-6 which calculates the stress and strain of a column of diameter d
when subjected to a compression load l. Data is stored in a struct
Author TB, March 2019 */

#include <stdio.h>
#include <math.h>

#define PI 3.142
#define E 30000000

struct strength
{
       float p;    // load
       float d;    // diameter
       float stress;
       float strain;

};


void main()
{
    struct strength test1;
    float area;


    printf("Please enter diameter of column\n");
    scanf("%f",&test1.d);
    printf("Please enter compression load\n");
    scanf("%f",&test1.p);

    //Calculating stress and strain
    area = (PI*test1.d*test1.d)/4;
    test1.stress = test1.p/area;
    test1.strain = test1.stress/E;

    printf("The stress is %e and strain is %.2f for a column with diameter %.2f when subjected to a %.2f load", test1.stress, test1.strain, test1.d, test1.p);

}
