/* Program: prog5.c
Author: Mohammad Askari
Date written: 05/10/2021 */
#include <stdio.h>
int main()
/*   Two students have taken four examination papers. Write a program that reads
the four marks from the keyboard and prints their results in a table  */

/* THIS WAS THE SESSION WHERE I WORKED WITH KIAN TO TRY AND MAKE THE CODE REALLY COMPACT. THEN WE GOT TOLD ARRAYS WERE ILLEGAL BY TARA. */
{
    printf("\t Mark1\tMark2\tMark3\tMark4\n");
    int i, mark,s_num = 1,exam_num = 4;
    printf("Please enter student %d's marks \n",s_num);
    printf("Student%d ", s_num);
    for(i=1; i<exam_num+1; i++);
        scanf("%d",&mark);
    for(i=1; i<exam_num+1; i++);
        printf("%d\t", mark);
}
