#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i;     // Specify variables for condition operation in a for statement
	int mt;    // Specify variables for the multiplication table

	printf("Input the multiplication table you want: "); // Input information message
	scanf_s("%d", &mt);                                  // Scan entered number

	for (i = 1; i <= 9; i++)                             // Multiply 1 to 9 repeatedly
	{
		printf("%d * %d = %d\n", mt, i, mt * i);         // Output Calculated Value
	}
	system("pause");
	return 0;
}