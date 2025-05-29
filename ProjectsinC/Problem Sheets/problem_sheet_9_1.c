/* Program: prob1.c
Author: Mohammad Askari
Date written: 05/10/2021 */
/*.
1. Modify the program you wrote for question 6 in Problem Sheet 8- which calculated the
stress and strain of a column. The modifications include using an array of struct (eg,
struct strength test1[SIZE];) where SIZE determines how many column samples we
want to find the stress and strain for.
• Declare an array of struct (eg, struct strength test1[SIZE];) for
struct strength
{
float p;
float d;
float stress;
float strain;
};
• Use function/s to obtain the data, calculate the stress and strain, and to display the
stress and strain for array of struct in a table.
You are free to use functions of your choosing. Ask the user to enter the diameter of the
column and the load it is subjected to several times (determined by SIZE given in the array
of struct). Use the following formulae to compute stress and strength:
Area = (pi*d^2)/4
Stress = p/area;
Strain = stress/E where E is the modulus of elasticity which is 30x10^6 psi for steel.
*/

/* SOLUTION: */

/* Problem 9-1 which calculates the stress and strain of a column of diameter d
when subjected to a compression load l. Data is stored in a struct. An array of
struct is used to allow various columns of different diameters to be used.
Various functions are used for getting the data, calculating the stress and
strain and another one for printing this information to the screen.
Author TB, April 2020 */

#include <stdio.h>
#include <math.h>

#define PI 3.142
#define E 30000000
#define SIZE 2   // change this depending on how many times the user wants to enter d and p

struct strength
{
       float p;    // load
       float d;    // diameter
       float stress;
       float strain;

};

void getData(struct strength *data);
void calStressStrain(struct strength SS[]);
void printSS(struct strength data);


main()
{
	int size,i;
	struct strength test1[SIZE];  //declaring array of struct
	float area;

	getData(test1);
	calStressStrain(test1);

	printf("Diameter \t Load \t         Stress \t  Strength\n");
	printf("-------- \t ---- \t         ------ \t  --------\n");
	for(i=0;i<SIZE;i++){

    	printSS(test1[i]);


	}
}

//obtaining diameter of column and compression load
void getData(struct strength *data){
	int i;

	for(i=0;i<SIZE;i++){
    	printf("\nPlease enter diameter of column (in m) < 0.1m\n");
    	scanf("%f",&(*(data+i)).d);
    	printf("Please enter compression load (in N) > 5kN\n");
    	scanf("%f",&(*(data+i)).p);
    }

}

//calculating stress and strain in array of struct
void calStressStrain(struct strength SS[]){
	int i;
	float area;

	for(i=0;i<SIZE;i++){


    	//Calculating stress and strain
    	area = (PI*SS[i].d*SS[i].d)/4;
    	SS[i].stress = SS[i].p/area;
    	SS[i].strain = SS[i].stress/E;
    }
}

//printing the data
void printSS(struct strength data){

	printf("%0.2f m\t      %0.2f N\t %.2e Pa\t  %.2f\n", data.d, data.p,data.stress, data.strain);
}
