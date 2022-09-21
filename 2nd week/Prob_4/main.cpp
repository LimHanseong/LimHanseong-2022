#include<stdio.h>

int main()
{
	float kgf, cm;    // Specify weight and height variables
	float BMI;               // Specify variables to store BMI
	double res;              // Variable to store computation results

	printf("Input your weight(kg) and height(cm) : ");         // Input information message
	scanf_s("%f%f", &kgf, &cm);                         // Scan entered weight and height
	BMI = kgf / (0.1e-3 * cm * cm);                 // BMI calculation
	res = (25 > BMI) && (BMI >= 20) ? printf("You're normal weight\n") : printf("you need to control your weight\n");  // Check the BMI range and print the notice

	return 0;
}