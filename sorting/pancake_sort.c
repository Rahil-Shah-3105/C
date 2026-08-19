// Sorting of array list using pancake sort
#include <stdio.h>
#include <stdlib.h>

/* Reverses the array */
void flip(int arr[], int i)
{
	fprintf(stderr, ">>> Entering flip(arr=%p,i=%d)\n", arr, i);
    int temp, start = 0;

    while (start < i)
    {
        temp = arr[start];
        arr[start] = arr[i];
        arr[i] = temp;
        start++;
        i--;
    }
	fprintf(stderr, "<<< Exiting flip(arr=%p,i=%d)\n", arr, i);
}

// Returns index of the maximum element in arr[0..n-1]
int findMax(int arr[], int n)
{
	fprintf(stderr, ">>> Entering findMax(arr=%p,n=%d)\n", arr, n);
    int maxElementIdx, i;

    for (maxElementIdx = 0, i = 0; i < n; ++i)
        if (arr[i] > arr[maxElementIdx])
            maxElementIdx = i;
			fprintf(stderr, "findMax(arr=%d,n=%d): maxElementIdx → %d\n", arr, n, maxElementIdx);

	fprintf(stderr, "<<< Exiting findMax(arr=%p,n=%d)\n", arr, n);
    return maxElementIdx;
}

// Sorts the array using flip operations
void pancakeSort(int *arr, int n)
{
	fprintf(stderr, ">>> Entering pancakeSort(arr=%p,n=%d)\n", arr, n);
    // Start from the complete array and one by one reduce current size by one
    for (int curr_size = n; curr_size > 1; --curr_size)
    {
        // Find index of the maximum element in arr[0..curr_size-1]
        int maxElementIdx = findMax(arr, curr_size);
		fprintf(stderr, "pancakeSort(arr=%d,n=%d): maxElementIdx → %d\n", arr, n, maxElementIdx);

        // Move the maximum element to end of current array if it's not already
        // at the end
        if (maxElementIdx != curr_size - 1)
        {
            // To move at the end, first move maximum number to beginning
            flip(arr, maxElementIdx);

            // Now move the maximum number to end by reversing current array
            flip(arr, curr_size - 1);
        }
    }
	fprintf(stderr, "<<< Exiting pancakeSort(arr=%p,n=%d)\n", arr, n);
}

// Displays the array, passed to this method
void display(int arr[], int n)
{
	fprintf(stderr, ">>> Entering display(arr=%p,n=%d)\n", arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
	fprintf(stderr, "<<< Exiting display(arr=%p,n=%d)\n", arr, n);
}

#define N 50

// Driver program to test above function
int main()
{
	fprintf(stderr, ">>> Entering main()\n");
    int arr[N];
    for (int i = 0; i < N; i++)
        arr[i] = rand() % (N << 1); /* random numbers from 0 to 2N */

    printf("Original array: ");
    display(arr, N);

    pancakeSort(arr, N);
    printf("Sorted array: ");
    display(arr, N);

	fprintf(stderr, "<<< Exiting main()\n");
    return 0;
}