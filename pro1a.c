#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define SIZE 20

void bubble_sort(int arr[], int n)
{
    int i, j;
   // #pragma omp critical 
    for (i = 0; i < n - 1; ++i)
    {
        for (j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr[SIZE];
    int i;
#pragma omp parallel for
    for (i = 0; i < SIZE; ++i)
    {
        arr[i] = rand() % 100;
    }
    printf("The array elements are:\n");
    for (i = 0; i < SIZE; i++)
    {
        printf("%d ", arr[i]);
    }

#pragma omp parallel shared(arr)
    {
        bubble_sort(arr, SIZE);
    }
    printf("\n Sorted array:\n");
    for (int i = 0; i < SIZE; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}