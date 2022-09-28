#include<stdio.h>
#include<stdlib.h>

#define AGELIMIT 20    //Specify the age limit
#define MINSIZE 85     //Specify a minimum size under 20
#define MAXSIZE 95     //Specify the maximum size under 20
#define AdultMINSIZE 90     //Specify the minimum size over 20
#define AdultMAXSIZE 100    //Specify the maximum size over 20

int main()
{
	int age, chestsize;                           //Specify age and chest size variables
	char clothessize;                             //Specify clothes size variables

	printf("Input your age and chest size: ");    //Input information message
	scanf_s("%d%d", &age, &chestsize);            //Scan entered age and chest size
	
	if (age < AGELIMIT)                           //It distinguishes whether the age is under 20
	{
		if (chestsize < MINSIZE)                  //Specifying the size of clothes according to the size of the chest
		{
			clothessize = 'S';
		}
		else if ((chestsize >= MINSIZE)&& (chestsize < MAXSIZE)) 
		{
			clothessize = 'M';
		}
		else
		{
			clothessize = 'L';
		}
	}
	else                                            //If the age is unless under 20, then run
	{
		if (chestsize < AdultMINSIZE)               //Specifying the size of clothes according to the size of the chest
		{
			clothessize = 'S';
		}
		else if ((chestsize >= AdultMINSIZE) && (chestsize < AdultMAXSIZE))
		{
			clothessize = 'M';
		}
		else
		{
			clothessize = 'L';
		}
	}
	printf("Your clothes size is %c", clothessize);    //Print out clothing size
	system("pause");
	return 0;
}