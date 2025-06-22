#include <stdio.h>
#include <omp.h>
#define SIZE 100
#define TARGET 42
int binary_search(int arr[], int left, int right, int target)
{
    while (left <= right)
    {
        int mid = (left + right) / 2; 
        if (arr[mid] == target)
            return mid;
        if (arr[mid] < target) 
            left = mid + 1;
        else 
            right = mid - 1;
    }
    return -1; 
}
int main()
{
    int arr[SIZE];
    int i, result = -1;
    for (i = 0; i < SIZE; ++i) 
    {
        arr[i] = i;
    }

#pragma omp parallel shared(arr, result)
    {
        int top = omp_get_thread_num();
        int bottom = omp_get_num_threads();
        int mid = SIZE / bottom;
        int left = top * mid;
        int right = (top == bottom - 1) ? SIZE - 1 : (top + 1) * mid - 1;

        int local_result = binary_search(arr, left, right, TARGET);

#pragma omp critical
        {
            if (local_result != -1 && result == -1)
                result = local_result;
        }
    }

    if (result != -1)
        printf("Element %d found at index %d.\n", TARGET, result);
    else
        printf("Element %d not found in the array.\n", TARGET);
    return 0;
}