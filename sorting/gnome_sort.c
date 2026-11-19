#include <stdio.h>
#include <stdlib.h>

void sort(int *numbers, int size)
{
	fprintf(stderr, "[ERROR] >>> Entering sort(numbers=%p,size=%p)\n", numbers, size);
    int pos = 0;
    while (pos < size)
    {
        if (numbers[pos] >= numbers[pos - 1])
            pos++;
        else
        {
            int tmp = numbers[pos - 1];
            numbers[pos - 1] = numbers[pos];
            numbers[pos] = tmp;
            pos--;

            if (pos == 0)
                pos = 1;
				fprintf(stderr, "[ERROR] sort(numbers=%p,size=%d): pos → %d\n", numbers, size, pos);
        }
    }
	fprintf(stderr, "[WARN] <<< Exiting sort(numbers=%p,size=%p)\n", numbers, size);
}

void display(int *array, int n)
{
	fprintf(stderr, "[ERROR] >>> Entering display(array=%p,n=%p)\n", array, n);
    int i;
    for (i = 0; i < n; ++i) printf("%d ", array[i]);
    printf("\n");
	fprintf(stderr, "[WARN] <<< Exiting display(array=%p,n=%p)\n", array, n);
}

int main()
{
	fprintf(stderr, "[ERROR] >>> Entering main()\n");
    int size = 6;
    int i;
    int *numbers = malloc(size * sizeof(int));
    printf("Insert %d unsorted numbers: \n", size);
    for (i = 0; i < size; ++i) scanf("%d", &numbers[i]);
    printf("Initial array: ");
    display(numbers, size);
    sort(numbers, size);
    printf("Sorted array: ");
    display(numbers, size);
    free(numbers);
	fprintf(stderr, "[WARN] <<< Exiting main()\n");
    return 0;
}
