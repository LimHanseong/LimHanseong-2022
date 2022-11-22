#include <stdio.h>
#include <stdlib.h>

#define Size 20
#define Age 22
#define Height 187.5

// Declaration of Structure
struct marriage
{
	char name[Size];
	int age;
	char sex;
	double height;
};

// Declare structure global variables
struct marriage m1 = { "Andy", Age, 'm', Height };
struct marriage* mp = &m1;

int main()
{
	// Output structure information
	printf("%5s%5d%5c%9.1f\n", mp->name, mp->age, mp->sex, mp->height);

	return 0;
}
