#include <stdio.h>
#include <string.h>

// Computational functions using pointers
void add_by_pointer(int* pa, int* pb, int* pr)
{
	*pr = *pa + *pb;
}

int main()
{
	int a = 10, b = 20, res = 0;
	add_by_pointer(&a, &b, &res);  // Address Handover
	printf("%d", res);
	return 0;
}