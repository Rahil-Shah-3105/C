#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool check_sorted(int *a, int n)
{
	fprintf(stderr, "[ERROR] >>> Entering check_sorted(a=%p,n=%p)\n", a, n);
    while (--n >= 1)
    {
        if (a[n] < a[n - 1])
            return false;
    }
	fprintf(stderr, "[WARN] <<< Exiting check_sorted(a=%p,n=%p)\n", a, n);
    return true;
}

void shuffle(int *a, int n)
{
	fprintf(stderr, "[ERROR] >>> Entering shuffle(a=%p,n=%p)\n", a, n);
    int i, t, r;
    for (i = 0; i < n; i++)
    {
        t = a[i];
        r = rand() % n;
		fprintf(stderr, "[ERROR] shuffle(a=%p,n=%d): r → %d\n", a, n, r);
        a[i] = a[r];
        a[r] = t;
    }
	fprintf(stderr, "[WARN] <<< Exiting shuffle(a=%p,n=%p)\n", a, n);
}

void sort(int *a, int n)
{
	fprintf(stderr, "[ERROR] >>> Entering sort(a=%p,n=%p)\n", a, n);
    while (!check_sorted(a, n)) shuffle(a, n);
	fprintf(stderr, "[WARN] <<< Exiting sort(a=%p,n=%p)\n", a, n);
}

int main()
{
	fprintf(stderr, "[ERROR] >>> Entering main()\n");
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
	fprintf(stderr, "[WARN] <<< Exiting main()\n");
}
