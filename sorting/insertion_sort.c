/**
 * @file
 * @brief [Insertion sort](https://en.wikipedia.org/wiki/Insertion_sort)
 * algorithm implementation.
 */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Insertion sort algorithm implements
 * @param arr array to be sorted
 * @param size size of array
 */
void insertionSort(int *arr, int size)
{
	fprintf(stderr, ">>> Entering insertionSort(arr=%p,size=%d)\n", arr, size);
    for (int i = 1; i < size; i++)
    {
        int j = i - 1;
        int key = arr[i];
		fprintf(stderr, "insertionSort(arr=%d,size=%d): key → %d\n", arr, size, key);
        /* Move all elements greater than key to one position */
        while (j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        /* Find a correct position for key */
        arr[j + 1] = key;
    }
	fprintf(stderr, "<<< Exiting insertionSort(arr=%p,size=%d)\n", arr, size);
}

/** Test function
  * @returns None
  */
static void test()
{
	fprintf(stderr, ">>> Entering test()\n");
    const int size = rand() % 500; /* random array size */
    int *arr = (int *)calloc(size, sizeof(int));

    /* generate size random numbers from -50 to 49 */  
    for (int i = 0; i < size; i++)
    {
        arr[i] = (rand() % 100) - 50; /* signed random numbers */
    }
    insertionSort(arr, size);
    for (int i = 0; i < size - 1; ++i)
    {
        assert(arr[i] <= arr[i + 1]);
    }
    free(arr);
	fprintf(stderr, "<<< Exiting test()\n");
}
int main(int argc, const char *argv[])
{
	fprintf(stderr, ">>> Entering main(argc=%d,argv=%s)\n", argc, argv);
    /* Intializes random number generator */
    srand(time(NULL));
    test();
	fprintf(stderr, "<<< Exiting main(argc=%d,argv=%s)\n", argc, argv);
    return 0;
}
