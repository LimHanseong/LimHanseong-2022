#include<stdio.h>
#include<stdlib.h>

int rec_func(int n)              // Generate recursive call function
{
	if (n == 10) return 10;      // If n=10, return 10 and end
	return n + rec_func(n+1);    // Add n and return rec_func(n+1)
}

int main()
{
	int sum;                     // Specifies the variable that stores rec_func
	sum = rec_func(1);           // Give 1 as an argument and start the call, save rec_func value to sum
	printf("%d\n", sum);         // Output sum value

	system("pause");
	return 0;
}