/*
 * Author: Arjan Gupta
 * Purpose: Understand the usage of static
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void example()
{
	/* declare a static var */
	static char* stChArr = "Hello";

	/* declare a non-static var for comparing the results */
	char* plainChArr = "Hello";

	printf("\n");

	printf("The static character array is: %s\n", stChArr);
	printf("The plain character array is: %s\n", plainChArr);

	printf("\nReset the pointer locations.\n\n");

	stChArr = stChArr + 1;
	plainChArr = plainChArr + 1;

	printf("The static character array is: %s\n", stChArr);
	printf("The plain character array is: %s\n", plainChArr);
}


int main()
{
	for (size_t i = 0; i < 4; ++i)
	{
		printf("\nITERATION #%zu\n", (i + 1) );
		example();
	}
	return 0;
}
