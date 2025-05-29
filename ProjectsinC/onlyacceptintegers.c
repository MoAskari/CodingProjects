/* C Program to accept only integer values - IntegerValues.C */

#include<stdio.h>
#include<stdlib.h>

 int get_int(int *px)
{
 scanf("%d",px);

 if(!scanf("%d",px)&& !isspace()&& getchar()!= '\n')
 {
  printf("Please enter an integer value:");
 }
}

 int main(int argc, const char *argv[]){
 int x,i;

 printf("Please enter a number:\n");
 get_int(&x);
 //for (i=0; i <20; i++)

 printf("you input the value: %d\n",x);
 fflush(stdin);
}
