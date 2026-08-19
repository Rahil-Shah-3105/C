/**
 * @file
 * @author [Dhruv Pasricha](https://github.com/DhruvPasricha)
 * @brief [Selection Sort](https://en.wikipedia.org/wiki/Selection_sort)
 * implementation using recursion.
 */

#include <assert.h>     /// for assert
#include <stdio.h>      /// for IO operations
#include <stdlib.h>     /// for dynamic memory allocation
#include <time.h>       /// for random numbers generation
#include <inttypes.h>   /// for uint8_t, int8_t

/**
 * @brief Swapped two numbers using pointer
 * @param first pointer of first number
 * @param second pointer of second number
 */
void swap(int8_t *first, int8_t *second)
{
	fprintf(stderr, ">>> Entering swap(first=%p,second=%p)\n", first, second);
    int8_t temp = *first;
    *first = *second;
    *second = temp;
	fprintf(stderr, "<<< Exiting swap(first=%p,second=%p)\n", first, second);
}

/**
 * @brief Returns the index having minimum value using recursion
 * @param arr array to be sorted
 * @param size size of array
 * @return min_index index of an element having a minimum value
*/
uint8_t findIndex(const int8_t *arr, const uint8_t size)
{
	fprintf(stderr, ">>> Entering findIndex(arr=%p,size=%d)\n", arr, size);
    if (size == 1)
    {
        return 0;
    }

    // marking recursive call to reach starting element
    uint8_t min_index = findIndex(arr, size - 1);
	fprintf(stderr, "findIndex(arr=%d,size=%d): min_index → %d\n", arr, size, min_index);

    if (arr[size - 1] < arr[min_index])
    {
        min_index = size - 1;
    }

	fprintf(stderr, "<<< Exiting findIndex(arr=%p,size=%d)\n", arr, size);
    return min_index;
}

/**
 * @brief Selection Sort algorithm implemented using recursion
 * @param arr array to be sorted
 * @param size size of the array
 * @returns void
 */
void selectionSort(int8_t *arr, const uint8_t size)
{
	fprintf(stderr, ">>> Entering selectionSort(arr=%p,size=%d)\n", arr, size);
    if (size <= 1)
    {
        return;
    }

    /* findIndex(arr, size) returned the index having min value*/
    uint8_t min_index = findIndex(arr, size);
	fprintf(stderr, "selectionSort(arr=%d,size=%d): min_index → %d\n", arr, size, min_index);
    /* arr[min_index] is the minimum value in the array*/

    if (min_index != 0)
    {
        swap(&arr[0], &arr[min_index]);
    }

    /*sorted the remaining array recursively*/
    selectionSort(arr + 1, size - 1);
	fprintf(stderr, "<<< Exiting selectionSort(arr=%p,size=%d)\n", arr, size);
}

/**
 * @brief Self-test implementations
 * @returns void
 */
static void test()
{
	fprintf(stderr, ">>> Entering test()\n");
    const uint8_t size = 10;
    int8_t *arr = (int8_t *)calloc(size, sizeof(int8_t));

    /* generate size random numbers from 0 to 100 */
    for (uint8_t i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
    }
    selectionSort(arr, size);
    for (uint8_t i = 0; i < size - 1; ++i)
    {
        assert(arr[i] <= arr[i + 1]);
    }
    free(arr);
	fprintf(stderr, "<<< Exiting test()\n");
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main()
{
	fprintf(stderr, ">>> Entering main()\n");
    /* Intializes random number generator */
    srand(time(NULL));

    test();  // run self-test implementations
	fprintf(stderr, "<<< Exiting main()\n");
    return 0;
}
