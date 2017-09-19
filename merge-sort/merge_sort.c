/*
 * Author: Arjan Gupta
 * Purpose: Merge Sort in C
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This function should work similarly to the library 
 * function `strncmp()`. We will call it strncmp_a in order
 * to avoid a library function redeclaration warning 
 * from the compiler.
 */
int strncmp_a (const char *s1, const char *s2, size_t n)
{
	/* Rules of return value:
	 * 1. If ret < 0, then s1 is smaller than s2.
	 * 2. If ret > 0, then s2 is smaller than s1.
	 * 3. If ret == 0, then s1 and s2 are the same size.
	 */
	if (n == 0)
		return n;

	size_t i = 0;
	while (i < n && s1[i] == s2[i]) 
	{
		++i;
	}
	return (s1[i] - s2[i]);
}

void merge (char*** arrLPtr, size_t lenL, char*** arrRPtr, size_t lenR)
{
	for (size_t i = 0; i < lenL; ++i)
	{
		printf("%d ", *(*arrLPtr + i));
	}

	printf("\n");

	for (size_t i = 0; i < lenR; ++i)
	{
		printf("%d ", *(*arrRPtr + i));
	}

	printf("\n");

	/*int* buffArr = (int *) malloc( (lenL + lenR) * sizeof(int) );

	memset(buffArr, 0, (lenL + lenR) * sizeof(int) );

	size_t j = 0; 
	size_t k = 0;
	for (size_t i = 0; i < (lenL + lenR); ++i)
	{
		if (j == lenL)
			buffArr[i] = *(*arrRPtr + k++);
		else if (k == lenR)
			buffArr[i] = *(*arrLPtr + j++);
		else 
		{
			if (*(*arrLPtr + j) < *(*arrRPtr + k))
				buffArr[i] = *(*arrLPtr + j++);
			else
				buffArr[i] = *(*arrRPtr + k++);
		}
	}

	memcpy(*arrLPtr, buffArr, (lenL + lenR) * sizeof(int));

	free(buffArr);*/

}

void divide (char*** arrPtr, size_t len)
{
	for (size_t i = 0; i < len; ++i)
	{
		printf("%s ", *(*arrPtr + i) );
	}

	printf("\n");
	
	if (len == 1)
		return;

	char** leftArr = *arrPtr + len/2;
	divide(&leftArr, (len - len/2));
	divide(arrPtr, len/2);

	//merge(arrPtr, len/2, &leftArr, (len - len/2));
}

void mergeSort (char*** arrPtr, size_t len)
{
	//divide(arrPtr, len);
	char** leftArr = *arrPtr + len/2;
	merge(arrPtr, len/2, &leftArr, (len - len/2));
}

int main()
{
	size_t numelems = 10; /* length of the array of char arrays */
	size_t strLen = 7; /* length of the char arrays */

	char** arr = (char **) malloc( numelems * sizeof(char*) );

	memset(arr, 0, numelems * sizeof(char*)); /* initialize array */

	/* Show the user the initial list */
	printf("\nInitial list: ");
	for (size_t i = 0; i < numelems; ++i)
	{
		*(arr + i) = (char *) malloc( strLen * sizeof(char) );
		for(size_t j = 0; j < strLen; ++j)
		{
			if (j == (strLen - 1) )
			{
				*(*(arr + i) + j) = '\0';
			} else { /* 97 is 'a' in standard ASCII. */
				*(*(arr + i) + j) = 97 + ((j + i) % strLen); 
			}
		}
		printf("%s ", *(arr + i) );
	}

	printf("\n");

	printf("\nSize of array is %zu\n", numelems);

	/* Call the merge sort algo on arr.
	 * NOTICE: memory ownership is being transfered. */
	mergeSort(&arr, numelems);
#if false
	/* Check if arr is sorted */
	printf("\n");
	for (size_t i = 0; i < (numelems - 1); ++i)
	{
		if (arr[i] > arr[i + 1])
		{
			printf("Array is unsorted.\n");
			break;
		}

		if (i == (numelems - 2) )
		{
			printf("Array is sorted.\n");
		}
	}

	/* Show the user the resultant list */
	printf("\nFinal list:   ");
	for (size_t i = 0; i < numelems; ++i)
	{
		printf("%d ", arr[i]);
	}

	printf("\n\n");
#endif
	free(arr);

	/* USE CASE 2 */
	char* str3 = "Nice";
	char* str4 = "COOL";
	printf("Use case 2 return value: %d\n", strncmp_a(str3, str4, 4));
	printf("Use case 2 return value: %d\n", strncmp(str3, str4, 4));
	
	return 0;
}