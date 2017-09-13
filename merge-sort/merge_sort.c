/*
 * Author: Arjan Gupta
 * Purpose: Merge Sort in C
 */

#include <stdio.h>

void merge (int *arrL, int lenL, int *arrR, int lenR)
{

}

void divide (int* arr, int len)
{

	for (size_t i = 0; i < len; ++i)
	{
		printf("%d ", arr[i]);
	}

	printf("\n");

	if (len == 1)
	{
		return;
	}

	divide(&arr[len/2], (len - len/2));
	divide(arr, len/2);

	merge(arr, len/2, &arr[len/2], (len - len/2));
}

void mergeSort (int* arr, int len)
{
	//divide(arr, len);
	merge(arr, len/2, &arr[len/2], (len - len/2));
}

int main()
{
	/* printf("%d", 5/2); */

	int arr[] = {1, 2, 3, 1, 2, 3};
	/*int arr[] = {1, 2, 3, 4, 8, 6, 10, 9, 7, 5}; */
	/* int arr[] = {8, 6, 34, 23, 4, 3}; */
	int numelems = (int)( sizeof(arr) / sizeof(arr[0]) );
	/* printf("%d", numelems); */

	/* call merge sort on arr */
	mergeSort(arr, numelems);

	/* check if arr is sorted */
	for (size_t i = 0; i < (numelems - 1); ++i)
	{
		if (arr[i] > arr[i + 1])
		{
			printf("Array is unsorted\n");
			break;
		}

		if (i == (numelems - 2) )
		{
			printf("Array is sorted\n");
		}
	}
	
	return 0;
}