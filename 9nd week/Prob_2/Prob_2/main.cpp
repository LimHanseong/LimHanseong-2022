#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define InformationSize 80
#define NumofBook 3
#define Size 4
// a structure for storing book information
struct Book_information
{
	char title[InformationSize];
	char author[InformationSize];
	int page;
	int price;
};
// Function to enter book information
void input_information(Book_information BookList[Size])
{
	int i;
	struct Book_information* plist = BookList;
	// Input three time
	for (i = 0; i < NumofBook; i++)
	{
		printf("Title: ");
		scanf_s("%s", plist[i].title, InformationSize);
		printf("Author: ");
		scanf_s("%s", plist[i].author, InformationSize);
		printf("Page: ");
		scanf_s("%d", &(plist[i].page));
		printf("Price: ");
		scanf_s("%d", &(plist[i].price));
	}
}
// Function that outputs structure information
void print_information(Book_information BookList[Size])
{
	int i;
	struct Book_information* plist = BookList;

	printf("\n<information of books>\n=>");
	// Output three time
	for (i = 0; i < NumofBook; i++)
	{
		printf("\ntitle: %s\n", plist[i].title);
		printf("author: %s\n", plist[i].author);
		printf("page: %dp\n", plist[i].page);
		printf("price: %d\\\n", plist[i].price);
	}
}

int main()
{
	// Declare structure arry
	struct Book_information BookList[Size];
	struct Book_information* plist = BookList;

	input_information(plist);
	print_information(plist);

	return 0;
}