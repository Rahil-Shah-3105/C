/**
 * @file
 * @brief [Selection sort](https://en.wikipedia.org/wiki/Selection_sort)
 * algorithm implementation.
 */
#include <assert.h>
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
	fprintf(stderr, "[ERROR] >>> Entering swap(first=%p,second=%p)\n", first, second);
    int temp = *first;
    *first = *second;
    *second = temp;
	fprintf(stderr, "[WARN] <<< Exiting swap(first=%p,second=%p)\n", first, second);
}

/**
 * Selection sort algorithm implements
 * @param arr array to be sorted
 * @param size size of array
 */
void selectionSort(int *arr, int size)
{
	fprintf(stderr, "[ERROR] >>> Entering selectionSort(arr=%p,size=%p)\n", arr, size);
    for (int i = 0; i < size - 1; i++)
    {
        int min_index = i;
		fprintf(stderr, "[ERROR] selectionSort(arr=%p,size=%d): min_index → %d\n", arr, size, min_index);
        for (int j = i + 1; j < size; j++)
        {
            if (arr[min_index] > arr[j])
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            swap(arr + i, arr + min_index);
        }
    }
	fprintf(stderr, "[WARN] <<< Exiting selectionSort(arr=%p,size=%p)\n", arr, size);
}

/** Test function
  * @returns None
  */
static void test()
{
	fprintf(stderr, "[ERROR] >>> Entering test()\n");
    const int size = rand() % 500; /* random array size */
    int *arr = (int *)calloc(size, sizeof(int));

    /* generate size random numbers from -50 to 49 */
    for (int i = 0; i < size; i++)
    {
        arr[i] = (rand() % 100) - 50; /* signed random numbers */
    }
    selectionSort(arr, size);
    for (int i = 0; i < size - 1; ++i)
    {
        assert(arr[i] <= arr[i + 1]);
    }
    free(arr);
	fprintf(stderr, "[WARN] <<< Exiting test()\n");
}

/** Driver Code */
int main(int argc, const char *argv[])
{
	fprintf(stderr, "[ERROR] >>> Entering main(argc=%d,argv=%p)\n", argc, argv);
    /* Intializes random number generator */
    srand(time(NULL));
    test();
	fprintf(stderr, "[WARN] <<< Exiting main(argc=%d,argv=%p)\n", argc, argv);
    return 0;
}
