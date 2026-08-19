#include <stdio.h>
#include <stdlib.h>

/*Displays the array, passed to this method*/
void display(int arr[], int n)
{
	fprintf(stderr, ">>> Entering display(arr=%p,n=%p)\n", arr, n);
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
	fprintf(stderr, "<<< Exiting display(arr=%p,n=%p)\n", arr, n);
}

/*Swap function to swap two values*/
void swap(int *first, int *second)
{
	fprintf(stderr, ">>> Entering swap(first=%p,second=%p)\n", first, second);
    int temp = *first;
    *first = *second;
    *second = temp;
	fprintf(stderr, "<<< Exiting swap(first=%p,second=%p)\n", first, second);
}

/*Partition method which selects a pivot
  and places each element which is less than the pivot value to its left
  and the elements greater than the pivot value to its right
  arr[] --- array to be partitioned
  lower --- lower index
  upper --- upper index
*/
int partition(int arr[], int lower, int upper)
{
	fprintf(stderr, ">>> Entering partition(arr=%p,lower=%p,upper=%d)\n", arr, lower, upper);
    int i = (lower - 1);

    int pivot = arr[upper];  // Selects last element as the pivot value

    int j;
    for (j = lower; j < upper; j++)
    {
        if (arr[j] <= pivot)
        {  // if current element is smaller than the pivot

            i++;  // increment the index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[upper]);  // places the last element i.e, the pivot
                                     // to its correct position

	fprintf(stderr, "<<< Exiting partition(arr=%p,lower=%p,upper=%d)\n", arr, lower, upper);
    return (i + 1);
}

/*This is where the sorting of the array takes place
    arr[] --- Array to be sorted
    lower --- Starting index
    upper --- Ending index
*/
void quickSort(int arr[], int lower, int upper)
{
	fprintf(stderr, ">>> Entering quickSort(arr=%p,lower=%p,upper=%d)\n", arr, lower, upper);
    if (upper > lower)
    {
        // partitioning index is returned by the partition method , partition
        // element is at its correct poition

        int partitionIndex = partition(arr, lower, upper);
		fprintf(stderr, "quickSort(arr=%p,lower=%d,upper=%d): partitionIndex → %d\n", arr, lower, upper, partitionIndex);

        // Sorting elements before and after the partition index
        quickSort(arr, lower, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, upper);
    }
	fprintf(stderr, "<<< Exiting quickSort(arr=%p,lower=%p,upper=%d)\n", arr, lower, upper);
}

int main()
{
	fprintf(stderr, ">>> Entering main()\n");
    int n;
    printf("Enter size of array:\n");
    scanf("%d", &n);  // E.g. 8

    printf("Enter the elements of the array\n");
    int i;
    int *arr = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    display(arr, n);  // Original array : 10 11 9 8 4 7 3 8

    quickSort(arr, 0, n - 1);

    printf("Sorted array: ");
    display(arr, n);  // Sorted array : 3 4 7 8 8 9 10 11
    getchar();
    free(arr);
	fprintf(stderr, "<<< Exiting main()\n");
    return 0;
}
