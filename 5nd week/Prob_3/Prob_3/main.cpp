#include<stdio.h>
#include<stdlib.h>

int sum(int x, int y)   // Create an addition function
{
	int temp;

	temp = x + y;

	return temp;
}

int sub(int x, int y)  // Create an subtraction function
{
	int temp;

	temp = x - y;

	return temp;
}

int divi(int x, int y)  // Create an division function
{
	int temp;

	temp = x / y;

	return temp;
}

int multi(int x, int y) // Create an multiplication function
{
	int temp;

	temp = x * y;

	return temp;
}

int rem(int x, int y)  // Create an remaining operation function
{
	int temp;

	temp = x % y;

	return temp;
}

int main()
{
	int nA, nB, res;                                         //Specify variables for two integers
	char arithmeticsymbol;                                   //Specify arithmetic symbol variables

	printf("Input arithmetic operation: ");                  //Input information message
	scanf_s("%d%c%d", &nA, &arithmeticsymbol, 1, &nB);       //Scan entered arithmetic operation


	if (arithmeticsymbol == '+')
	{
		res = sum(nA, nB);                                   //Calculate the expression
		printf("Addition: ");                                //Show this operation is addition
	}
	else if (arithmeticsymbol == '-')
	{
		res = sub(nA, nB);                                  //Calculate the expression
		printf("Subtraction: ");                            //Show this operation is subtraction
	}
	else if (arithmeticsymbol == '/')
	{
		res = divi(nA, nB);                                 //Calculate the expression
		printf("Division: ");                               //Show this operation is division
	}
	else if (arithmeticsymbol == '*')
	{
		res = multi(nA, nB);                                //Calculate the expression
		printf("Multiplication: ");                         //Show this operation is multiplication
	}
	else
	{
		res = rem(nA, nB);                                 //Calculate the expression
		printf("Remaining operation: ");                   //Show this operation is remaining operation
	}


	printf("%d%c%d = %d\n", nA, arithmeticsymbol, nB, res); //Show the result
	system("pause");
	return 0;
}