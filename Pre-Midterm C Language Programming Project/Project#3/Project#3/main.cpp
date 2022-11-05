#include <stdio.h>
#include <stdlib.h>

// Arry size
#define MaxSize 3
#define MinSize 1
// rows and columns
#define First 0
#define Twice 1
#define Third 2
// Switch Case Selection number
#define Choose1 1
#define Choose2 2
#define Choose3 3
#define Choose4 4
#define Choose5 5
#define Choose0 0
// Numbers for correction
#define add 1

// Matrix output function
void print_matrix(int A[MaxSize][MaxSize])
{
	int i;
	int(*a)[MaxSize] = A;

	for (i = 0; i < MaxSize; i++)
	{
		printf("\5%3d%5d%5d \5\n", a[i][First], a[i][Twice], a[i][Third]);
	}
}

// Matrix Calculation Function
int Matrix_Calculation(int A[MaxSize][MaxSize])
{
	int res = 0;
	int(*a)[MaxSize] = A;
	//matrix calculation expression
	res = a[First][First] * a[Twice][Twice] * a[Third][Third] + a[Twice][First] * a[Third][Twice] * a[First][Third] + a[Third][First] * a[First][Twice] * a[Twice][Third]
		- a[First][Third] * a[Twice][Twice] * a[Third][First] - a[Twice][Third] * a[Third][Twice] * a[First][First] - a[First][Twice] * a[Twice][First] * a[Third][Third];
	return res;
}

// Function of representing by a equations
void Representing_by_equations(int A[MaxSize][MaxSize], int B[MaxSize][MinSize])
{
	int i;
	int(*a)[MaxSize] = A;
	int(*b)[MinSize] = B;

	for (i = 0; i < MaxSize; i++)
	{
		printf("%d = (%dx)+(%dy)+(%dz)\n", b[i][First], a[i][First], a[i][Twice], a[i][Third]);
	}
}

// Function of representing by a matrix
void Representing_by_matrix(int A[MaxSize][MaxSize], int B[MaxSize][MinSize], char X[MaxSize][MinSize])
{
	int i;
	int(*a)[MaxSize] = A;
	int(*b)[MinSize] = B;
	char(*x)[MinSize] = X;

	for (i = 0; i < MaxSize; i++)
	{
		printf("\5%2d \5", b[i][First]);
		printf("\5%3d%5d%5d \5", a[i][First], a[i][Twice], a[i][Third]);
		printf("\5%2c \5\n", x[i][First]);
	}
	printf("\n  B  =	     A      *  X\n");
}

// Matrix calculation function with Cramer's rule
void Run_Cramer_rule(int A[MaxSize][MaxSize], int B[MaxSize][MinSize])
{
	int i, j;
	float x, y, z;
	float res[MaxSize];
	int temp[MaxSize];
	int(*a)[MaxSize] = A;
	int(*b)[MinSize] = B;
	float* Res = res;
	float A_0;

	printf("A = \n");
	A_0 = (float)Matrix_Calculation(a);
	print_matrix(a);
	// Specify the columns to calculation
	for (i = 0; i < MaxSize; i++)
	{
		// Specify the rows to calculation
		for (j = 0; j < MaxSize; j++)
		{
			temp[j] = a[j][i];				// Temporarily save to return to initial value
			a[j][i] = b[j][First];
		}
		printf("\nA_%d = \n", i + add);
		Res[i] = Matrix_Calculation(a);		//Calculate matrix and store result values
		print_matrix(a);
		// Return the existing matrix back to its original state
		for (j = 0; j < MaxSize; j++)
		{
			a[j][i] = temp[j];
		}
	}
	// Show Calculated Values
	printf("\nA = %.1f, ", A_0);
	for (i = 0; i < MaxSize; i++)
	{
		printf("A_%d = %.1f, ", i + add, Res[i]);
	}
	// Find the solution of the equation and output it
	x = Res[First] / A_0;
	y = Res[Twice] / A_0;
	z = Res[Third] / A_0;
	printf("\n\nx = A_1/A = %.1f, y = A_2/A = %.1f, z = A_3/A = %.1f\n", x, y, z);
}
//Result value output function
void Result_output(int A[MaxSize][MaxSize], int B[MaxSize][MinSize])
{
	int i, j;
	float x, y, z;
	float res[MaxSize];
	int temp[MaxSize];
	int(*a)[MaxSize] = A;
	int(*b)[MinSize] = B;
	float* Res = res;
	float A_0;

	A_0 = (float)Matrix_Calculation(a);
	// Specify the columns to calculation
	for (i = 0; i < MaxSize; i++)
	{
		// Specify the rows to calculation
		for (j = 0; j < MaxSize; j++)
		{
			temp[j] = a[j][i];				// Temporarily save to return to initial value
			a[j][i] = b[j][First];
		}
		Res[i] = Matrix_Calculation(a);		//Calculate matrix and store result values
		// Return the existing matrix back to its original state
		for (j = 0; j < MaxSize; j++)
		{
			a[j][i] = temp[j];
		}
	}
	// Find the solution of the equation and output it
	x = Res[First] / A_0;
	y = Res[Twice] / A_0;
	z = Res[Third] / A_0;
	printf("\nx = %.1f, y = %.1f, z = %.1f\n\n", x, y, z);
}

int main()
{
	// Declareand initialize variables
	int matrix_A[MaxSize][MaxSize];
	char unknowns_X[MaxSize][MinSize] = { 'x', 'y', 'z' };
	int B[MaxSize][MinSize];
	int(*a)[MaxSize] = matrix_A;
	int(*b)[MinSize] = B;
	char(*x)[MinSize] = unknowns_X;
	int i, j = 0;
	// Program description
	printf("Hello, this is a program that solves a system of equations with three unknowns using the Cramer's rule. Enter any keys if you want to continue or any keys if you want to exit.\n:");
	scanf_s("%d", &j);
	if (j == 1)
	{
		// Receive equation input
		for (i = 0; i < MaxSize; i++)
		{
			printf("Enter the equation. Enter only quotient and coefficient in order.(%d): ", i + add);
			scanf_s("%d%d%d%d", &b[i][First], &a[i][First], &a[i][Twice], &a[i][Third]);
		}

		// Run as desired by the user
		while (1)
		{
			printf("\nChoose the sentence you want.\n1. The equation entered\n2. Matrix equation\n3. Check answers with the solving process\n4. Just check the answer\n5. Re-enter the equation\n(Press 0 to exit)\n=>");
			scanf_s("%d", &j);

			switch (j)
			{
			case(Choose0):
			{
				// Exit the program
				return 0;
			}
			case(Choose1):
			{
				// Representing by a equations
				Representing_by_equations(a, b);
				break;
			}
			case(Choose2):
			{
				// Representing by a matrix
				Representing_by_matrix(a, b, x);
				break;
			}
			case(Choose3):
			{
				//Using Cramer's rule to solve the equations
				Run_Cramer_rule(a, b);
				break;
			}
			case(Choose4):
			{
				// Show only result
				Result_output(a, b);
				break;
			}
			case(Choose5):
			{
				// Receive equation input
				for (i = 0; i < MaxSize; i++)
				{
					printf("Enter the equation. Enter only quotient and coefficient in order.-(%d): ", i);
					scanf_s("%d%d%d%d", &b[i][First], &a[i][First], &a[i][Twice], &a[i][Third]);
				}
				break;
			}
			default:
			{
				printf("\nThis is not a valid input. Please re-enter.\n");
				break;
			}
			}
		}
	}

	system("pause");
	return 0;
}