/**
 * @file
 * @brief [Bubble sort](https://en.wikipedia.org/wiki/Bubble_sort) algorithm
 * implementation
 */
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Display elements of array
 * @param arr array to be display
 * @param n length of array
 */
void display(const int *arr, int n)
{
	fprintf(stderr, ">>> Entering display(arr=%p,n=%p)\n", arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
	fprintf(stderr, "<<< Exiting display(arr=%p,n=%p)\n", arr, n);
}

/**
 * Swap two values by using pointer
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
 * Bubble sort algorithm implementation
 * @param arr array to be sorted
 * @param size size of array
 */
void bubbleSort(int *arr, int size)
{
	fprintf(stderr, ">>> Entering bubbleSort(arr=%p,size=%p)\n", arr, size);
    for (int i = 0; i < size - 1; i++)
    {                         /* for each array index */
        bool swapped = false; /* flag to check if any changes had to be made */
        /* perform iterations until no more changes were made or outer loop
            executed for all array indices */
        for (int j = 0; j < size - 1 - i; j++)
        { /* for each element in the array */
            if (arr[j] > arr[j + 1])
            { /* if the order of successive elements needs update */
                swap(&arr[j], &arr[j + 1]);
                swapped = true; /* set flag */
            }
        }
        if (!swapped)
        {
            /* since no more updates we made, the array is already sorted
                this is an optimization for early termination */
            break;
        }
    }
	fprintf(stderr, "<<< Exiting bubbleSort(arr=%p,size=%p)\n", arr, size);
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
int main(int argc, const char *argv[])
{
	fprintf(stderr, ">>> Entering main(argc=%d,argv=%s)\n", argc, argv);
    /* Intializes random number generator */
    srand(time(NULL));
    test();
	fprintf(stderr, "<<< Exiting main(argc=%d,argv=%s)\n", argc, argv);
    return 0;
}
