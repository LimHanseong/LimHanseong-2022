#include<stdio.h>
#include<stdlib.h>


int main()
{
	int nA, nB, res;                                         //Specify variables for two integers
	char arithmeticsymbol;                                   //Specify arithmetic symbol variables

	printf("Input arithmetic operation: ");                  //Input information message
	scanf_s("%d%c%d", &nA, &arithmeticsymbol, 1, &nB);       //Scan entered arithmetic operation

	
	if (arithmeticsymbol == '+')                                               
	{
		res = nA + nB;                                       //Calculate the expression
		printf("Addition: ");                                //Show this operation is addition
	}
	else if(arithmeticsymbol == '-')                                                 
	{
	    res = nA - nB;                                      //Calculate the expression
		printf("Subtraction: ");                            //Show this operation is subtraction
	}
	else if(arithmeticsymbol == '/')                                                 
	{
		res = nA / nB;                                      //Calculate the expression
		printf("Division: ");                               //Show this operation is division
	}
	else
	{
		res = nA * nB;                                      //Calculate the expression
		printf("Multiplication: ");                         //Show this operation is multiplication
	}
	  

	printf("%d%c%d = %d\n", nA, arithmeticsymbol, nB, res); //Show the result
	system("pause");
	return 0;
}