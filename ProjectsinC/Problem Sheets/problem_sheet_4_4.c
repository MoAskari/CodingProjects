/* Program: prob1.c
Author: Mohammad Askari
Date written: 05/10/2021 */
/*.
4. Write a C program with four float arrays. Each array will hold marks for up to 10
students registered for a module. From the file “marks.txt”, read in a row of four
marks for each of 10 students. Assume that each of the four marks is from a
different module, and store each module’s mark in a separate array. Calculate
and write out the average mark for each module to the screen. Write helpful text
along with the average marks to the screen, and format the average marks
appropriately.
*/

/* SOLUTION: */

/* Problem 4-4.c                                                              */
/* a C program with four float arrays.  Let each array hold marks for up to 10*/
/* students registered for a module.  From a file, read in a row of four marks*/
/* for each of 10 students from a file "marks.txt".  Assume that each of the  */
/* four marks is from a different module, and store each module's mark in a   */
/* separate array.  Calculate and write out the average mark for each module  */
/* to the screen.  Write helpful text along with the average marks to the     */
/* screen, and format the average marks appropriately.                        */
/* Written by TB, February 2017                                              */
#include <stdio.h>
#define SIZE_LIST 10
main()
{
      float mod1[SIZE_LIST], mod2[SIZE_LIST], mod3[SIZE_LIST], mod4[SIZE_LIST]; /* to hold class marks on each of four modules */
      int i;
      float av1,av2,av3,av4;
      float sum1=0.0,sum2=0.0,sum3=0.0,sum4=0.0;
      int actualNumberInList=0;
      FILE *fin;
      fin=fopen("marks.txt","r");
      if(fin!=NULL)
      {
            for(i=0; i<SIZE_LIST; i++)
            {
                  if(i==actualNumberInList)
                  {
                        if(fscanf(fin,"%f %f %f %f",&mod1[i],&mod2[i],&mod3[i],&mod4[i])!=EOF)  /* assume each module mark is in a column in the file */
                        {
                              sum1=sum1+mod1[i];
                              sum2=sum2+mod2[i];
                              sum3=sum3+mod3[i];
                              sum4=sum4+mod4[i];
                              actualNumberInList++;
                        }
                  }
            }

            //Calculating the average module mark
            printf("%d",actualNumberInList);
            av1=sum1/actualNumberInList;
            av2=sum2/actualNumberInList;
            av3=sum3/actualNumberInList;
            av4=sum4/actualNumberInList;
            //Printing the average module mark
            printf("There were %d marks in each module list.\n",actualNumberInList);
            printf("Module 1 average: %.2f\n",av1);
            printf("Module 2 average: %.2f\n",av2);
            printf("Module 3 average: %.2f\n",av3);
            printf("Module 4 average: %.2f\n",av4);
      } else printf("The marks file was not found, so no calculations were done.\n");

}

/* ALTERNATE SOLUTION:

/* Problem 4-4_1.c USES ARRAYS FOR sum AND av                                                              */
/* a C program with four float arrays.  Let each array hold marks for up to 10*/
/* students registered for a module.  From a file, read in a row of four marks*/
/* for each of 10 students from a file "marks.txt".  Assume that each of the  */
/* four marks is from a different module, and store each module's mark in a   */
/* separate array.  Calculate and write out the average mark for each module  */
/* to the screen.  Write helpful text along with the average marks to the     */
/* screen, and format the average marks appropriately.                        */
/* Written by TB, February 2017                                              */
/*
#include <stdio.h>
#define SIZE_LIST 10
#define MODULES 4
main()
{
      float mod1[SIZE_LIST], mod2[SIZE_LIST], mod3[SIZE_LIST], mod4[SIZE_LIST]; /* to hold class marks on each of four modules */
      /*
      int i,j;
      float av[MODULES];
      float sum[MODULES]={};
      int actualNumberInList=0;
      FILE *fin;
      fin=fopen("marks.txt","r");
      if(fin!=NULL)
      {
            for(i=0; i<SIZE_LIST; i++)
            {
                  if(fscanf(fin,"%f %f %f %f",&mod1[i],&mod2[i],&mod3[i],&mod4[i])!=EOF)  /* assume each module mark is in a column in the file */
                    /*
                        {

                              sum[0]=sum[0]+mod1[i];
                              sum[1]=sum[1]+mod2[i];
                              sum[2]=sum[2]+mod3[i];
                              sum[3]=sum[3]+mod4[i];
                        }
            }


            printf("There were %d marks in each module list.\n",SIZE_LIST);
            //Calculating and printing the average module mark
            for(j=0;j<MODULES;j++){
                av[j]=sum[j]/SIZE_LIST;
                printf("Module %d average: %.2f\n",j+1,av[j]);
            }

      } else printf("The marks file was not found, so no calculations were done.\n");

}

*/

