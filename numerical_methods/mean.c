#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN INT_MAX

int main(int argc, char **argv)
{
	fprintf(stderr, "[ERROR] >>> Entering main(argc=%d,argv=%p)\n", argc, argv);
    int *a, n = 10, i, j, temp, sum = 0;
    float mean;
	fprintf(stderr, "[ERROR] main(argc=%d,argv=%p): n → %d\n", argc, argv, n);

    if (argc == 2)
    {
        n = atoi(argv[1]);
        if (n >= MAX_LEN)
        {
            fprintf(stderr, "Maximum %d!\n", MAX_LEN);
            return 1;
        }
    }
    
    a = (int *)malloc(n * sizeof(int));

    printf("Random Numbers Generated are: ");
    for (i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
        printf("%2d, ", a[i]);
    }
    putchar('\n');

    for (i = 0; i < n; i++) sum = sum + a[i];

    mean = sum / (float)n;
    printf("\nMean: ");
    printf("%f\n", mean);

    free(a);
	fprintf(stderr, "[WARN] <<< Exiting main(argc=%d,argv=%p)\n", argc, argv);
    return 0;
}
