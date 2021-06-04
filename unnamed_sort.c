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

void unnamed_sort(int* array, int length)
{
    int i, j, temp;
    for (i = 0; i < length; i++)
    {
        for (j = i+1; j < length; j++)
        {
            if (array[i] > array[j])
            {
                temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }
}

void bubble_sort(int* array, int length)
{
    int i, j, temp;
    for (i = 0; i < length; i++)
    {
        for (j = 0; j < length - 1; j++)
        {
            if (array[j] > array[j+1])
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

int main()
{
    printf("Unnamed sort:\n");
    const int size_of_array = 10;
    int my_array[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    print_array(my_array, size_of_array);
    unnamed_sort(my_array, size_of_array);
    print_array(my_array, size_of_array);

    printf("Bubble sort:\n");

    int my_second_array[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    print_array(my_second_array, size_of_array);
    bubble_sort(my_second_array, size_of_array);
    print_array(my_second_array, size_of_array);

    return 0;
}