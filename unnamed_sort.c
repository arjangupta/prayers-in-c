#include <stdio.h>

void print_array(int* array, int length)
{
    printf("The array is: ");
    for (int i = 0; i < length; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    const int size_of_array = 10;
    int my_array[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    print_array(my_array, size_of_array);
    return 0;
}