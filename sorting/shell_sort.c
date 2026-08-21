#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ELEMENT_NR 20000
#define ARRAY_LEN(x) (sizeof(x) / sizeof((x)[0]))
const char *notation =
    "Shell Sort Big O Notation:\
						\n--> Best Case: O(n log(n)) \
						\n--> Average Case: depends on gap sequence \
						\n--> Worst Case: O(n)";

void show_data(int arr[], int len)
{
	fprintf(stderr, ">>> Entering show_data(arr=%p,len=%p)\n", arr, len);
    int i;

    for (i = 0; i < len; i++) printf("%3d ", arr[i]);
    printf("\n");
	fprintf(stderr, "<<< Exiting show_data(arr=%p,len=%p)\n", arr, len);
}

void swap(int *a, int *b)
{
	fprintf(stderr, ">>> Entering swap(a=%p,b=%p)\n", a, b);
    int tmp;

    tmp = *a;
	fprintf(stderr, "swap(a=%p,b=%p): tmp → %d\n", a, b, tmp);
    *a = *b;
    *b = tmp;
	fprintf(stderr, "<<< Exiting swap(a=%p,b=%p)\n", a, b);
}

void shellSort(int array[], int len)
{
	fprintf(stderr, ">>> Entering shellSort(array=%p,len=%p)\n", array, len);
    int i, j, gap;

    for (gap = len / 2; gap > 0; gap = gap / 2)
        for (i = gap; i < len; i++)
            for (j = i - gap; j >= 0 && array[j] > array[j + gap]; j = j - gap)
                swap(&array[j], &array[j + gap]);
				fprintf(stderr, "<<< Exiting shellSort(array=%p,len=%p)\n", array, len);
}

int main(int argc, char *argv[])
{
	fprintf(stderr, ">>> Entering main(argc=%d,argv=%p)\n", argc, argv);
    int i;
    int array[ELEMENT_NR];
    int range = 500;
    int size;
    clock_t start, end;
    double time_spent;

    srand(time(NULL));
    for (i = 0; i < ELEMENT_NR; i++) array[i] = rand() % range + 1;

    size = ARRAY_LEN(array);

	fprintf(stderr, "main(argc=%d,argv=%p): size → %d\n", argc, argv, size);
    show_data(array, size);
    start = clock();
	fprintf(stderr, "main(argc=%d,argv=%p): start → %d\n", argc, argv, start);
    shellSort(array, size);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;

	fprintf(stderr, "main(argc=%d,argv=%p): end → %d\n", argc, argv, end);
	fprintf(stderr, "main(argc=%d,argv=%p): time_spent → %d\n", argc, argv, time_spent);
    printf("Data Sorted\n");
    show_data(array, size);

    printf("%s\n", notation);
    printf("Time spent sorting: %.4g ms\n", time_spent * 1e3);

	fprintf(stderr, "<<< Exiting main(argc=%d,argv=%p)\n", argc, argv);
    return 0;
}
