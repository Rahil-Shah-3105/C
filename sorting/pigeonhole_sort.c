#include <stdio.h>
#include <stdlib.h>

void pigeonholeSort(int arr[], int size)
{
	fprintf(stderr, "[ERROR] >>> Entering pigeonholeSort(arr=%p,size=%p)\n", arr, size);
    int i, j, min = arr[0], max = arr[0], range;

    // Getting range of the array using max and min
    for (i = 1; i < size; i++)
    {
        if (arr[i] < min)
            min = arr[i];
			fprintf(stderr, "[INFO] pigeonholeSort(arr=%p,size=%d): min → %d\n", arr, size, min);
        if (arr[i] > max)
            max = arr[i];
			fprintf(stderr, "[INFO] pigeonholeSort(arr=%p,size=%d): max → %d\n", arr, size, max);
    }
    range = max - min + 1;
	fprintf(stderr, "[DEBUG] pigeonholeSort(arr=%p,size=%d): range → %d\n", arr, size, range);

    // Make 'holes' and put array's numbers in holes
    int *holes = (int *)malloc(sizeof(int) * range);
    for (i = 0; i < range; i++)
    {
        holes[i] = 0;
    }
    for (i = 0; i < size; i++)
    {
        holes[arr[i] - min]++;
    }

    // Copy the numbers back to the original array
    j = 0;
    for (i = 0; i < range; i++)
    {
        while (holes[i] > 0)
        {
            arr[j] = i + min;
            holes[i]--;
            j++;
        }
    }

    free(holes);
	fprintf(stderr, "[WARN] <<< Exiting pigeonholeSort(arr=%p,size=%p)\n", arr, size);
}

int main()
{
	fprintf(stderr, "[ERROR] >>> Entering main()\n");
    int i, n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int) * n);

    for (i = 0; i < n; i++)
    {
        printf("Number #%d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("You entered:  ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    pigeonholeSort(arr, n);
    printf("\nSorted array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
	fprintf(stderr, "[WARN] <<< Exiting main()\n");
    return 0;
}