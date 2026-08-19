// Sorting of array list using cycle sort
#include <stdio.h>
#include <stdlib.h>

// Displays the array, passed to this method
void display(int *arr, int n)
{
	fprintf(stderr, ">>> Entering display(arr=%p,n=%d)\n", arr, n);
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
	fprintf(stderr, "<<< Exiting display(arr=%p,n=%d)\n", arr, n);
}

// Swap function to swap two values
void swap(int *first, int *second)
{
	fprintf(stderr, ">>> Entering swap(first=%p,second=%p)\n", first, second);
    int temp = *first;
    *first = *second;
    *second = temp;
	fprintf(stderr, "<<< Exiting swap(first=%p,second=%p)\n", first, second);
}

// Function sort the array using Cycle sort
void cycleSort(int *arr, int n)
{
	fprintf(stderr, ">>> Entering cycleSort(arr=%p,n=%d)\n", arr, n);
    // count number of memory writes
    int writes = 0;

    // traverse array elements and put it to on
    // the right place
    for (int cycle_start = 0; cycle_start <= n - 2; cycle_start++)
    {
        // initialize item as starting point
        int item = arr[cycle_start];

        // Find position where we put the item. We basically
        // count all smaller elements on right side of item.
        int pos = cycle_start;
		fprintf(stderr, "cycleSort(arr=%d,n=%d): pos → %d\n", arr, n, pos);
        for (int i = cycle_start + 1; i < n; i++)
            if (arr[i] < item)
                pos++;

        // If item is already in correct position
        if (pos == cycle_start)
            continue;

        // ignore all duplicate elements
        while (item == arr[pos]) pos += 1;

        // put the item to it's right position
        if (pos != cycle_start)
        {
            swap(&item, &arr[pos]);
            writes++;
        }

        // Rotate rest of the cycle
        while (pos != cycle_start)
        {
            pos = cycle_start;

            // Find position where we put the element
            for (int i = cycle_start + 1; i < n; i++)
                if (arr[i] < item)
                    pos += 1;

            // ignore all duplicate elements
            while (item == arr[pos]) pos += 1;

            // put the item to it's right position
            if (item != arr[pos])
            {
                swap(&item, &arr[pos]);
                writes++;
            }
        }
    }
	fprintf(stderr, "<<< Exiting cycleSort(arr=%p,n=%d)\n", arr, n);
}

// Driver program to test above function
int main()
{
	fprintf(stderr, ">>> Entering main()\n");
    int n;  // Size of array elements

    printf("Enter size of array:\n");
    scanf("%d", &n);  // E.g. 8

    printf("Enter the elements of the array\n");
    int i;
    int *arr = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    display(arr, n);

    cycleSort(arr, n);
    printf("Sorted array: ");
    display(arr, n);

    free(arr);
	fprintf(stderr, "<<< Exiting main()\n");
    return 0;
}
