/**
 * @file
 * @brief Sorting of array list using [bead
 * sort](https://en.wikipedia.org/wiki/Bead_sort)
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * @addtogroup sorting Sorting algorithms
 * @{
 */
/** Create easy access of elements from a 2D matrix stored in memory as a 1D
 * array
 */
#define BEAD(i, j) beads[i * max + j]

/**
 * Displays the array, passed to this method
 * @param [in] arr array to display
 * @param [in] n number of elements in the array
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

/** This is where the sorting of the array takes place
 * @param [in,out] a array to be sorted
 * @param [in] len Array Size
 */
void bead_sort(int *a, size_t len)
{
	fprintf(stderr, ">>> Entering bead_sort(a=%p,len=%zu)\n", a, len);
    int i, j, max, sum;
    unsigned char *beads;

    for (i = 1, max = a[0]; i < len; i++)
        if (a[i] > max)
            max = a[i];
			fprintf(stderr, "bead_sort(a=%p,len=%zu): max → %d\n", a, len, max);

    beads = calloc(1, max * len);

	fprintf(stderr, "bead_sort(a=%p,len=%zu): beads → %d\n", a, len, beads);
    /* mark the beads */
    for (i = 0; i < len; i++)
        for (j = 0; j < a[i]; j++) BEAD(i, j) = 1;

    for (j = 0; j < max; j++)
    {
        /* count how many beads are on each post */
        for (sum = i = 0; i < len; i++)
        {
            sum += BEAD(i, j);
            BEAD(i, j) = 0;
        }
        /* mark bottom sum beads */
        for (i = len - sum; i < len; i++) BEAD(i, j) = 1;
    }

    for (i = 0; i < len; i++)
    {
        for (j = 0; j < max && BEAD(i, j); j++)
            ;
        a[i] = j;
    }
    free(beads);
	fprintf(stderr, "<<< Exiting bead_sort(a=%p,len=%zu)\n", a, len);
}
/** @} */

/** Main function */
int main(int argc, const char *argv[])
{
	fprintf(stderr, ">>> Entering main(argc=%d,argv=%p)\n", argc, argv);
    int n;
    printf("Enter size of array:\n");
    scanf("%d", &n);  // E.g. 8 1 2 3

    printf("Enter the elements of the array\n");
    int i;
    int *arr = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    display(arr, n);

    bead_sort(arr, n);

    printf("Sorted array: ");
    display(arr, n);

    free(arr);
	fprintf(stderr, "<<< Exiting main(argc=%d,argv=%p)\n", argc, argv);
    return 0;
}
