#include<stdio.h>
#include<stdlib.h>

int main()
{
	int nA, nB;                                               //Specify variables for two integers
	char arithmeticsymbol;                                    //Specify arithmetic symbol variables

	printf("Input arithmetic operation: ");                   //Input information message
	scanf_s("%d%c%d", &nA, &arithmeticsymbol, 1, &nB);        //Scan entered arithmetic operation

	switch (arithmeticsymbol)                                       //Determine what the value of the arithmetic symbol is
	{
	    case '+':                                                   //If the arithmetic symbol is '+', do the following
	    {
			printf("Addition: ");                                   //Show this operation is addition
			int res = nA + nB;                                      //Calculate the expression
			printf("%d%c%d = %d\n", nA, arithmeticsymbol, nB, res);
			break;
	    }
		case '-':                                                   //If the arithmetic symbol is '-', do the following
		{
			printf("Subtraction: ");                                //Show this operation is subtraction
			int res = nA - nB;                                      //Calculate the expression
			printf("%d%c%d = %d\n", nA, arithmeticsymbol, nB, res);   //Show the result
			break;
		}
		case '/':                                                   //If the arithmetic symbol is '/', do the following
		{
			printf("Division: ");                                   //Show this operation is division
			int res = nA / nB;                                      //Calculate the expression
			printf("%d%c%d = %d\n", nA, arithmeticsymbol, nB, res);   //Show the result
			break;
		}
		default:                                                    //If the arithmetic symbol is '*', do the following
		{
			printf("Multiplication: ");                             //Show this operation is multiplication
			int res = nA * nB;                                      //Calculate the expression
			printf("%d%c%d = %d\n", nA, arithmeticsymbol, nB, res);   //Show the result
			break;
		}
	}

	system("pause");
	return 0;
}