#include <stdio.h>

int a, b; // Declaration of global variables

// Data input function
void input_data(int *pa, int *pb)
{
	printf("Enter two integers: ");
	scanf_s("%d %d", pa, pb);
}
// Data swap function
void swap_data(void)
{
	int temp;

	temp = a;
	a = b;
	b = temp;
}
// Data output function
void print_data(int a, int b)
{
	printf("Two integer outputs: %d, %d", a, b);
}

int main()
{
	input_data(&a, &b);
	swap_data();
	print_data(a, b);

	return 0;
}