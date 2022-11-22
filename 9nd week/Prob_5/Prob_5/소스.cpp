#include <stdio.h>
#include <stdlib.h>

#define room 5
// Custom Material Type Declaration
typedef struct train Train;
// Override structure
struct train
{
	int seats;
	Train* next;  // // Pointer to next room
};

int main()
{
	// Head and tail declaration
	Train* head = NULL, * tail = NULL;
	int i;
	// Connect 5 times
	for (i = 0; i < room; i++)
	{
		if (head == NULL)
		{
			head = tail = (Train*)malloc(sizeof(Train));
		}
		else
		{
			tail->next = (Train*)malloc(sizeof(Train));
			tail = tail->next;
		}
	}

	return 0;
}