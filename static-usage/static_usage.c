/*
 * Author: Arjan Gupta
 * Purpose: Understand the usage of static
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global
static char* global_stCharr;

void example()
{
	// Initialize global
	global_stCharr = "HelloGlobal";

	/* declare a static var */
	static char* stChArr = "Hello";

	/* declare a non-static var for comparing the results */
	char* plainChArr = "Hello";

	printf("\n");

	printf("The global static character array is: %s\n", global_stCharr);
	printf("The local static character array is: %s\n", stChArr);
	printf("The plain character array is: %s\n", plainChArr);

	printf("\nReset the pointer locations.\n\n");

	++global_stCharr;
	++stChArr;
	++plainChArr;

	printf("The global static character array is: %s\n", global_stCharr);
	printf("The local static character array is: %s\n", stChArr);
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
