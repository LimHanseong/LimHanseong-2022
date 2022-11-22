#include <stdio.h>
#include <stdlib.h>

#define range 4
#define yellow 5

// Custom Material Type Declaration
typedef enum { CYAN, MAGNENTA, YELLOW = yellow, BLACK }COLOR;
typedef enum { UP, DOWN, LEFT, RIGHT }ARROW;

int main()
{
	// Declare and initialize variables
	COLOR my_color = YELLOW;
	int c = my_color;
	ARROW direction = UP;
	int d = direction;

	for (c = CYAN; c <= BLACK; c++)
	{
		d++;                        // d 1 increase
		d = d % range;                  // d is circulated within the range of 4
		if (c == my_color) break;   // // Terminate repeat on my_color
	}
	// Output and exit according to conditions
	switch (d)
	{
	case UP: printf("Current Direction: UP"); break;
	case DOWN: printf("Current Direction: DOWN"); break;
	case LEFT: printf("Current Direction: LEFT"); break;
	case RIGHT: printf("Current Direction: RIGHT"); break;
	}
	return 0;
}