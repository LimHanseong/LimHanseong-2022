#include<stdio.h>
#include<stdlib.h>
#include<string.h>          // Header file for using strcmp

#define array_size 10       // Macro for Array Size

int security_release(void); // Declare security release function

int main()
{
	security_release();     //Get and run the security release function

	return 0;
}

int security_release(void)
{
	const char password[array_size] = "password";   // Declare a string to store passwords
	char entered_password[array_size] = {0};        // Declare a string to store typed characters
	char *pointer = entered_password;               // Pointer to point to the password you entered


	for (;;)                                        // Repeat indefinitely until you enter the correct password
	{
		printf("Input password: ");                 // Input information message
		scanf_s("%s", pointer, array_size);         // Scan input strings

		if (strcmp(password, pointer) == 0) break;  // Escape if the entered string matches the password

		else
		{
			printf("not matched, retry..\n");       // Output a reminder to re-enter
		}
	}
	printf("normal termination..\n");               // Output a normal shutdown
	
	system("pause");
	return 0;
}