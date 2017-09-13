/*
 * Author: Arjan Gupta
 * Purpose: Merge Sort in C
 */

#include <stdio.h>

int main()
{
	int arr[] = {1, 2, 3, 4, 8, 6};
	int numelems = (int)( sizeof(arr) / sizeof(arr[0]) );
	//printf("%d", numelems);

	//call mergesort() on arr

	//check if arr is sorted
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