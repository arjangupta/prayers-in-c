/*
 * Author: Arjan Gupta
 * Purpose: Merge Sort in C
 */

#include <stdio.h>
#include <stdlib.h>

void merge (int *arrL, int lenL, int *arrR, int lenR)
{
	/*for (size_t i = 0; i < lenL; ++i)
	{
		printf("%d ", arrL[i]);
	}

	printf("\n");

	for (size_t i = 0; i < lenR; ++i)
	{
		printf("%d ", arrR[i]);
	}

	printf("\n");*/

	int buffArr[lenL + lenR];
	size_t j = 0; 
	size_t k = 0;
	for (size_t i = 0; i < (lenL + lenR); ++i)
	{
		if (j == lenL)
		{
			buffArr[i] = arrR[k];
			++k;
		} else if (k == lenR) {
			buffArr[i] = arrL[j];
			++j;
		} else {
			if (arrL[j] < arrR[k])
			{
				buffArr[i] = arrL[j];
				++j;
			} else {
				buffArr[i] = arrR[k];
				++k;
			}
		}
	}

	/*arrL = buffArr;
	 The above line of code didn't work, most probably because 
	 buffArr goes out of scope at the end of this function and
	 the fact that the pointer arrL was passed in by copy.*/

	for (size_t i = 0; i < (lenL + lenR); ++i)
	{
		/* the next line of code actually 
		changes the memory being pointed to */
		arrL[i] = buffArr[i];
	}
}

void divide (int** arrPtr, int len)
{
	for (size_t i = 0; i < len; ++i)
	{
		printf("%d ", *(*arrPtr + i));
	}

	printf("\n");

	if (len == 1)
	{
		return;
	}

	int* leftArr = *arrPtr + len/2;
	divide(&leftArr, (len - len/2));
	divide(arrPtr, len/2);

	/*merge(arr, len/2, &arr[len/2], (len - len/2));*/
}

void mergeSort (int** arrPtr, int len)
{
	divide(arrPtr, len);
}

int main()
{
	/*printf("%d", 5/2);*/

	/*int arr[] = {1, 2, 3, 1, 2, 3};*/
	/*int arr[] = {1, 2, 3, 4, 8, 6, 10, 9, 7, 5};*/
	/*int arr[] = {8, 6, 34, 23, 4, 3};*/

	int numelems = 10;

	int *arr = (int *) malloc( numelems * sizeof(int) );

	/*arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 3;
	arr[4] = 4;
	arr[5] = 5;
	arr[6] = 6;
	arr[7] = 7;*/

	/*int numelems = (int)( sizeof(arr[]) / sizeof(arr[0]) );*/
	printf("\n%d\n", numelems);

	/* show the user the initial list */
	printf("\nInitial list: ");
	for (size_t i = 0; i < numelems; ++i)
	{
		arr[i] = i % 5;
		printf("%d ", arr[i]);
	}

	printf("\n");

	/* call merge sort on arr */
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