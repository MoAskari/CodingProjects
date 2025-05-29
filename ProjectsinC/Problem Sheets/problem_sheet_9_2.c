/* Program: prob1.c
Author: Mohammad Askari
Date written: 05/10/2021 */
/*.
2. Write a C program to analyse the electricity consumption in a room used for working
from home over an 8 hour period during office hours (9am-5pm). You have been given
a data file called “electricityConsumption.txt” (full file available on Blackboard), which
has the following format:
Column 1: the hour, which is a value from 1 to 8, where 1 represents 9.00-9.59am, 2
represents 10.00-10.59am… and 8 represents 4.00-4.59pm.
Column 2: the name of an electrical item. Each name will contain up to 15 alphanumeric
characters and no spaces.
Column 3: the amount of electricity (in Watts) consumed by the electrical item in the hour
(please note that these values have been made up).
The contents of “electricityConsumption.txt” look like this:
1 LightBulb1 182
2 LightBulb1 94
3 LightBulb1 120
4 LightBulb1 99
5 LightBulb1 176
6 LightBulb1 52
7 LightBulb1 198
8 LightBulb1 1
1 Kettle 187
2 Kettle 179
3 Kettle 99
4 Kettle 118
5 Kettle 125
6 Kettle 152
7 Kettle 80
8 Kettle 83
…
 1 MobileCharger 95
2 MobileCharger 20
3 MobileCharger 34
4 MobileCharger 121
5 MobileCharger 39
6 MobileCharger 18
7 MobileCharger 118
 8 MobileCharger 186
The initial analysis needed is
1. The total electricity consumed in the room during the 8 hour period, in kilowatts.
(kilowatts = Watts/1000)
2. The item which consumed the most electricity.
3. The hour during which most electricity was consumed, and the amount of electricity
consumed in that hour.
You will need a struct for the data on each row of “electricityConsumption.txt”; the struct
will have members for the three items on a row. You will then need an array of struct to
hold the whole list. The array of struct is declared in main. The program must be written
using functions, so that new types of analysis can be added as time goes on, by writing
other new functions. Initially, the program will have just main() and four functions.
Function 1 will read “electricityConsumption.txt” into the array of struct.
int readFile(struct consumptionInfo list[]);
Function 2 will first print the data to the screen, then calculate and print to the screen the
total electricity consumed in the room during the 8 hour period by the items in
“electricityConsumption.txt” (do NOT read the file again, data from the file has been saved
in the array of struct via Function 1).
void totalConsumption(struct consumptionInfo *list);
Function 3 will find which item consumed the most electricity and print the name of the
item to the screen, along with the amount of electricity it consumed, in kilowatts.
void maxItem(struct consumptionInfo *list);
Function 4 will find and print to the screen the hour during which most electricity was
consumed and the amount (in kilowatts) of electricity consumed in that hour.
void findHourMostUsed(struct consumptionInfo *list);
*/

/* SOLUTION: */

/* Problem 9-2 which finds the total energy consumed from 9am-5pm for a set of appliances.
The program also finds the appliance with the highest energy usage, as well as the hour in
which the most energy was consumed. These three calculations are performed in individual functions.
The code uses a structure called consumptionInfo, and an array of structs is declared to store
info about the time, appliance name and energy consumption for a list.
Author TB, April 2020 */

#include <stdio.h>
#include <string.h>

#define Nitems 6
#define HOURS 8
#define SIZE 48 //currently have 8 hours and 6 items

struct consumptionInfo  // based on given format of input data file
{
	int hour;  // from 1-8
	char name[16]; // allow for 15 chars plus terminating NULL
	int watt;  // amount of electricity used in watts during that hour
};

int readFile(struct consumptionInfo list[]);  //function 1
void totalConsumption(struct consumptionInfo *list);  //function 2
void maxItem(struct consumptionInfo *list);
void findHourMostUsed(struct consumptionInfo *list);


void main(){

    struct consumptionInfo workDay[SIZE];  //declaring array of struct
    int flag, i;

    flag = readFile(workDay);

    if(flag==1){
            totalConsumption(workDay);
            maxItem(workDay);
            findHourMostUsed(workDay);
    }
    else
        printf("File not found!");

}

int readFile(struct consumptionInfo list[]){

    FILE *fin;
    int i, check;
    fin = fopen("electricityConsumption.txt","r");
    if(fin!=NULL){
        for(i=0;i<SIZE;i++)
            fscanf(fin,"%d %s %d",&list[i].hour,list[i].name,&list[i].watt);
        fclose(fin);
        return check = 1;

    }
    else
        return check = 0;

}

void totalConsumption(struct consumptionInfo *list){

    int i;
    float sum =0;
    for(i=0;i<SIZE;i++){
          printf("%d\t %s\t %d\n", (list+i)->hour, (list+i)->name,(list+i)->watt);
          printf("%d\t %s\t %d\n", (*(list+i)).hour, (*(list+i)).name, (*(list+i)).watt);

          sum = sum + (list+i)->watt;
    }
     //OR
    /*for(i=0;i<SIZE;i++){
          printf("%d\t %s\t %d\n", (*(list+i)).hour, (*(list+i)).name, (*(list+i)).watt);

          sum = sum + (*(list+i)).watt;
    }*/

    printf("The total consumption during the working day is %0.2f kW\n",sum/1000);

}

void maxItem(struct consumptionInfo *list){

    int i,j,sum[Nitems] ={};
    float maxConsumption=0;
    char nameApp[16];
    for(i=0;i<Nitems;i++){
        for(j=0;j<HOURS;j++){
            sum[i] = sum[i] + (list+j+HOURS*i)->watt; }

           //printf("%d\n",sum[i]);  //printing out consumption of all appliances just as a check


         if(sum[i]>maxConsumption){
            maxConsumption = sum[i];
            strcpy(nameApp,(list+i*HOURS)->name);
         }

    }

    printf("\nAppliance %s consumed the most energy of %0.2f kW\n",nameApp,maxConsumption/1000);
}


void findHourMostUsed(struct consumptionInfo *list)
{
	int i, j, sumHourWatt[HOURS]={};
	float largestHourIndex;
	float maxHour=0;

	for(i=0;i<HOURS;i++){
       for(j=0;j<Nitems;j++){
            sumHourWatt[i] = sumHourWatt[i] + list[i+HOURS*j].watt;}

            //printf("%d\n",sumHourWatt[i]); //printing out hourly consumption just as a check

		if(sumHourWatt[i]>maxHour){
            maxHour = sumHourWatt[i];
            largestHourIndex = i+1;
		}

	}
	printf("The hour during which most electricity was consumed was hour %0.0f starting at %0.2f o'clock.\n", largestHourIndex, largestHourIndex+8);
	printf("During that hour %.2f kW was consumed.\n", maxHour/1000.0);
}
