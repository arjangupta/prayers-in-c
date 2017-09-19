/*
 * Author: Arjan Gupta
 * Purpose: Merge Sort in C, where the elements being sorted are character arrays of a fixed length.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const size_t strLen = 4; /* length of the strings */

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
	char** buffArr = (char **) malloc( (lenL + lenR) * sizeof(char *) );

	memset(buffArr, 0, (lenL + lenR) * sizeof(char *) );
	
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
			if ( strncmp_a( ( *(*arrLPtr + j) ), ( *(*arrRPtr + k) ), strLen) < 0 ) 
				buffArr[i] = *(*arrLPtr + j++);
			else
				buffArr[i] = *(*arrRPtr + k++);
		}
	}

	memcpy(*arrLPtr, buffArr, (lenL + lenR) * sizeof(char *));

	free(buffArr);

}

void divide (char*** arrPtr, size_t len)
{	
	if (len == 1)
		return;

	char** leftArr = *arrPtr + len/2;
	divide(&leftArr, (len - len/2));
	divide(arrPtr, len/2);

	merge(arrPtr, len/2, &leftArr, (len - len/2));
}

void mergeSort (char*** arrPtr, size_t len)
{
	divide(arrPtr, len);
}

int main()
{
	/* Length of the array of strings.
	 * Must be larger than strLen to produce an unsorted array. 
	 */
	size_t numelems = strLen * 3; 

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
				*(*(arr + i) + j) = '\0';
			else /* 97 is 'a' in standard ASCII. */
				*(*(arr + i) + j) = 97 + ( (j + i) % strLen ); 
		}
		printf("%s ", *(arr + i) );
	}

	printf("\n");

	printf("\nSize of array is %zu\n", numelems);

	/* Call the merge sort algo on arr.
	 * NOTICE: memory ownership is being transfered. */
	mergeSort(&arr, numelems);

	/* Check if arr is sorted */
	printf("\n");
	for (size_t i = 0; i < (numelems - 1); ++i)
	{
		if ( strncmp_a( ( *(arr + i) ), ( *(arr + i + 1) ), strLen ) > 0 )
		{
			printf("Array is unsorted.\n");
			break;
		}
		if (i == (numelems - 2) )
			printf("Array is sorted.\n");
	}

	/* Show the user the resultant list */
	printf("\nFinal list:   ");
	for (size_t i = 0; i < numelems; ++i)
		printf("%s ", *(arr + i) );

	printf("\n\n");

	free(arr);
	
	return 0;
}