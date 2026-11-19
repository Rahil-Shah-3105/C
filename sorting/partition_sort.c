#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
	fprintf(stderr, "[ERROR] >>> Entering swap(a=%p,b=%p)\n", a, b);
    int tmp = *a;
    *a = *b;
    *b = tmp;
	fprintf(stderr, "[WARN] <<< Exiting swap(a=%p,b=%p)\n", a, b);
}

int partition(int arr[], int low, int high)
{
	fprintf(stderr, "[ERROR] >>> Entering partition(arr=%p,low=%p,high=%d)\n", arr, low, high);
    int pivot = arr[low];
    int i = low - 1, j = high + 1;

    while (1)
    {
        /* Find leftmost element >= pivot */
        do
        {
            i++;
        } while (arr[i] < pivot);

        /* Find rightmost element <= pivot */
        do
        {
            j--;
        } while (arr[j] > pivot);

        /* if two pointers met */
        if (i >= j)
            return j;

        swap(&arr[i], &arr[j]);
    }
	fprintf(stderr, "[WARN] <<< Exiting partition(arr=%p,low=%p,high=%d)\n", arr, low, high);
}

void partitionSort(int arr[], int low, int high)
{
	fprintf(stderr, "[ERROR] >>> Entering partitionSort(arr=%p,low=%p,high=%d)\n", arr, low, high);
    if (low < high)
    {
        int value = partition(arr, low, high);
		fprintf(stderr, "[ERROR] partitionSort(arr=%p,low=%d,high=%d): value → %d\n", arr, low, high, value);
        partitionSort(arr, low, value);
        partitionSort(arr, value + 1, high);
    }
	fprintf(stderr, "[WARN] <<< Exiting partitionSort(arr=%p,low=%p,high=%d)\n", arr, low, high);
}

void printArray(int arr[], int n)
{
	fprintf(stderr, "[ERROR] >>> Entering printArray(arr=%p,n=%p)\n", arr, n);
    int i;
    for (i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
	fprintf(stderr, "[WARN] <<< Exiting printArray(arr=%p,n=%p)\n", arr, n);
}

int main()
{
	fprintf(stderr, "[ERROR] >>> Entering main()\n");
    int arr[20];
    int i, range = 100;
    for (i = 0; i < 20; i++)
    {
        arr[i] = rand() % range + 1;
    }
    int size = sizeof arr / sizeof arr[0];
    printf("Array: \n");
    printArray(arr, size);
    partitionSort(arr, 0, size - 1);
    printf("Sorted Array: \n");
    printArray(arr, size);

	fprintf(stderr, "[WARN] <<< Exiting main()\n");
    return 0;
}
