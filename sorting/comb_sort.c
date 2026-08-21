#include <stdio.h>
#include <stdlib.h>
#define SHRINK 1.3  // suggested shrink factor value

void sort(int *numbers, int size)
{
	fprintf(stderr, ">>> Entering sort(numbers=%p,size=%p)\n", numbers, size);
    int gap = size;
    while (gap > 1)  // gap = 1 means that the array is sorted
    {
        gap = gap / SHRINK;
        int i = 0;
        while ((i + gap) < size)
        {  // similiar to the Shell Sort
            if (numbers[i] > numbers[i + gap])
            {
                int tmp = numbers[i];
                numbers[i] = numbers[i + gap];
                numbers[i + gap] = tmp;
            }
            i++;
        }
    }
	fprintf(stderr, "<<< Exiting sort(numbers=%p,size=%p)\n", numbers, size);
}

void display(int *array, int n)
{
	fprintf(stderr, ">>> Entering display(array=%p,n=%p)\n", array, n);
    int i;
    for (i = 0; i < n; ++i) printf("%d ", array[i]);
    printf("\n");
	fprintf(stderr, "<<< Exiting display(array=%p,n=%p)\n", array, n);
}

int main()
{
	fprintf(stderr, ">>> Entering main()\n");
    int size = 6;
    int *numbers = malloc(size * sizeof(int));
    printf("Insert %d unsorted numbers: \n", size);
    int i;
    for (i = 0; i < size; ++i) scanf("%d", &numbers[i]);
    printf("Initial array: ");
    display(numbers, size);
    sort(numbers, size);
    printf("Sorted array: ");
    display(numbers, size);
    free(numbers);
	fprintf(stderr, "<<< Exiting main()\n");
    return 0;
}
