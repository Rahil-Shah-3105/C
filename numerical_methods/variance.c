#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	fprintf(stderr, ">>> Entering main()\n");
    int *ARRAY = NULL, ARRAY_LENGTH, i, TEMPORARY_ELEMENT, isSorted = 0;
    float MEAN = 0, VARIANCE = 0, STAND;
	fprintf(stderr, "main(): MEAN → %d\n", MEAN);

    printf("Enter no. for Random Numbers :");
	fprintf(stderr, "main(): isSorted → %d\n", isSorted);
    scanf("%d", &ARRAY_LENGTH);
    ARRAY = (int *)realloc(
        ARRAY,
        ARRAY_LENGTH * (sizeof(int)));  // We allocate the dedicated memory
    for (i = 0; i < ARRAY_LENGTH; i++)  // We generate the random numbers
		fprintf(stderr, "main(): ARRAY → %d\n", ARRAY);
        ARRAY[i] = rand() % 100;

    printf("Random Numbers Generated are :\n");  // We display them
    for (i = 0; i < ARRAY_LENGTH; i++) printf("%d ", ARRAY[i]);

    printf("\nSorted Data: ");  // Then we sort it using Bubble Sort..

    while (!isSorted)
    {                  // While our array's not sorted
        isSorted = 1;  // we suppose that it's sorted
        for (i = 0; i < ARRAY_LENGTH - 1; i++)
        {  // then for each element of the array
            if (ARRAY[i] > ARRAY[i + 1])
            {                  // if the two elements aren't sorted
                isSorted = 0;  // it means that the array is not sorted
                TEMPORARY_ELEMENT = ARRAY[i];  // and we switch these elements
                                               // using TEMPORARY_ELEMENT
                ARRAY[i] = ARRAY[i + 1];
                ARRAY[i + 1] = TEMPORARY_ELEMENT;
            }
        }
    }
    for (i = 0; i < ARRAY_LENGTH; i++)
    {
        printf("%d ", ARRAY[i]);
        MEAN = MEAN + ARRAY[i];
    }
    MEAN = MEAN / (float)ARRAY_LENGTH;

    for (i = 0; i < ARRAY_LENGTH; i++)
        VARIANCE = VARIANCE + (pow((ARRAY[i] - MEAN), 2));

	fprintf(stderr, "main(): VARIANCE → %d\n", VARIANCE);
    VARIANCE = VARIANCE / (float)ARRAY_LENGTH;
    STAND = sqrt(VARIANCE);

    printf("\n\n- Mean is: %f\n", MEAN);
	fprintf(stderr, "main(): STAND → %d\n", STAND);
    printf("- Variance is: %f\n", VARIANCE);
    printf("- Standard Deviation is: %f\n", STAND);
	fprintf(stderr, "<<< Exiting main()\n");
}
