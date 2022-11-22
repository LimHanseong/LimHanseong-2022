#include <stdio.h>
#include <stdlib.h>
// Declaration of Structure
struct cracker
{
	int price;
	int calories;
};

int main()
{
	// Declare structural variables
	struct cracker Bananakick;
	// Receive information input
	printf("Enter the price and calories of the 'Banana kick'.: ");
	scanf_s("%d%d", &Bananakick.price, &Bananakick.calories);
	// Output structure information
	printf("Bananakick price: %d\\\n", Bananakick.price);
	printf("Bananakick calories: %dkcal\n", Bananakick.calories);

	return 0;
}