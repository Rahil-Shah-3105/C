/**
 * @file
 * @brief [Bubble sort](https://en.wikipedia.org/wiki/Bubble_sort) algorithm
 * implementation using recursion.
 */
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Swapped two numbers using pointer
 * @param first first pointer of first number
 * @param second second pointer of second number
 */
void swap(int *first, int *second)
{
	fprintf(stderr, ">>> Entering swap(first=%p,second=%p)\n", first, second);
    int temp = *first;
    *first = *second;
    *second = temp;
	fprintf(stderr, "<<< Exiting swap(first=%p,second=%p)\n", first, second);
}

/**
 * Bubble sort algorithm implements using recursion
 * @param arr array to be sorted
 * @param size size of array
 */
void bubbleSort(int *arr, int size)
{
	fprintf(stderr, ">>> Entering bubbleSort(arr=%p,size=%d)\n", arr, size);
    if (size == 1)
    {
        return;
    }
    bool swapped = false;
	fprintf(stderr, "bubbleSort(arr=%d,size=%d): swapped → %d\n", arr, size, swapped);
    for (int i = 0; i < size - 1; ++i)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr + i, arr + i + 1);
            swapped = true;
        }
    }
    if (swapped)
    {
        bubbleSort(arr, size - 1);
    }
	fprintf(stderr, "<<< Exiting bubbleSort(arr=%p,size=%d)\n", arr, size);
}

/**
 * Test function
 */
void test()
{
	fprintf(stderr, ">>> Entering test()\n");
    const int size = 10;
    int *arr = (int *)calloc(size, sizeof(int));

    /* generate size random numbers from 0 to 100 */
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
    }
    bubbleSort(arr, size);
    for (int i = 0; i < size - 1; ++i)
    {
        assert(arr[i] <= arr[i + 1]);
    }
    free(arr);
	fprintf(stderr, "<<< Exiting test()\n");
}

/** Driver Code */
int main()
{
	fprintf(stderr, ">>> Entering main()\n");
    /* Intializes random number generator */
    srand(time(NULL));
    test();
	fprintf(stderr, "<<< Exiting main()\n");
    return 0;
}
