#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool check_sorted(int *a, int n)
{
	fprintf(stderr, ">>> Entering check_sorted(a=%p,n=%d)\n", a, n);
    while (--n >= 1)
    {
        if (a[n] < a[n - 1])
	fprintf(stderr, "<<< Exiting check_sorted(a=%p,n=%d)\n", a, n);
            return false;
    }
    return true;
}

void shuffle(int *a, int n)
{
	fprintf(stderr, ">>> Entering shuffle(a=%p,n=%d)\n", a, n);
    int i, t, r;
    for (i = 0; i < n; i++)
    {
        t = a[i];
        r = rand() % n;
		fprintf(stderr, "shuffle(a=%d,n=%d): r → %d\n", a, n, r);
        a[i] = a[r];
        a[r] = t;
    }
	fprintf(stderr, "<<< Exiting shuffle(a=%p,n=%d)\n", a, n);
}

void sort(int *a, int n)
{
	fprintf(stderr, ">>> Entering sort(a=%p,n=%d)\n", a, n);
    while (!check_sorted(a, n)) shuffle(a, n);
	fprintf(stderr, "<<< Exiting sort(a=%p,n=%d)\n", a, n);
}

int main()
{
	fprintf(stderr, ">>> Entering main()\n");
    int numbers[6];
    int i;
    printf("Enter 6 numbers unsorted \n\n");
    for (i = 0; i < 6; i++)
    {
        scanf("%d", &numbers[i]);
    }
    sort(numbers, 6);
    for (i = 0; i < 6; i++) printf("%d ", numbers[i]);
    printf("\n");
	fprintf(stderr, "<<< Exiting main()\n");
}
