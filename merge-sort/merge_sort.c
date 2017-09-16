/*
 * Author: Arjan Gupta
 * Purpose: Merge Sort in C
 */

#include <stdio.h>
#include <stdlib.h>

void merge (int** arrLPtr, int lenL, int** arrRPtr, int lenR)
{
	/*for (size_t i = 0; i < lenL; ++i)
	{
		printf("%d ", *(*arrLPtr + i));
	}

	printf("\n");

	for (size_t i = 0; i < lenR; ++i)
	{
		printf("%d ", *(*arrRPtr + i));
	}

	printf("\n");*/

	int* buffArr = (int *) malloc( (lenL + lenR) * sizeof(int) );

	/* TODO: need to initialize buffArr to all zeroes */

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

	/*free(arrLPtr); TODO: this is producing errors. Don't transfer ownership in main? */

	*arrLPtr = buffArr;

}

void divide (int** arrPtr, int len)
{
	/*for (size_t i = 0; i < len; ++i)
	{
		printf("%d ", *(*arrPtr + i));
	}

	printf("\n");*/

	if (len == 1)
	{
		return;
	}

	int* leftArr = *arrPtr + len/2;
	divide(&leftArr, (len - len/2));
	divide(arrPtr, len/2);

	merge(arrPtr, len/2, &leftArr, (len - len/2));
}

void mergeSort (int** arrPtr, int len)
{
	divide(arrPtr, len);
}

int main()
{
	int numelems = 10;

	int *arr = (int *) malloc( numelems * sizeof(int) );

	printf("\nSize of array is %d\n", numelems);

	/* show the user the initial list */
	printf("\nInitial list: ");
	for (size_t i = 0; i < numelems; ++i)
	{
		arr[i] = i % 3;
		printf("%d ", arr[i]);
	}

	printf("\n");

	/* call merge sort on arr */
	/* NOTICE: memory ownership is being transfered. */
	mergeSort(&arr, numelems);

	/* check if arr is sorted */
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

	/* show the user the resultant list */
	printf("\nFinal list: ");
	for (size_t i = 0; i < numelems; ++i)
	{
		printf("%d ", arr[i]);
	}

	printf("\n\n");
	
	return 0;
}