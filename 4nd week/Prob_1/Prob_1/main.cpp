#include<stdio.h>
#include<stdlib.h>

#define MINSIZE 90  //Specify a minimum size
#define MAXSIZE 100 //Specify the maximum size

int main()
{
	int chestsize;                     //Specify chest size variables
	char clothessize;                  //Specify clothes size variables

	printf("Input your chest size: "); //Input information message
	scanf_s("%d", &chestsize);         //Scan entered and chest size

	if (chestsize <= MINSIZE)          //Specifying the size of clothes according to the size of the chest
	{
		clothessize = 'S';
	}
	else if ((chestsize > MINSIZE) && (chestsize <= MAXSIZE))
	{
		clothessize = 'M';
	}
	else
	{
		clothessize = 'L';
	}

	printf("Your clothes size is %c", clothessize); //Print out clothing size
	system("pause");
	return 0;
}
