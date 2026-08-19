#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *a, int *b)
{
	fprintf(stderr, ">>> Entering swap(a=%p,b=%p)\n", a, b);
    int t;
    t = *a;
    *a = *b;
    *b = t;
	fprintf(stderr, "<<< Exiting swap(a=%p,b=%p)\n", a, b);
}
int part(int a[], int l, int r, int n, int pivot, int pindex)
{
	fprintf(stderr, ">>> Entering part(a=%p,l=%d,r=%d,n=%d,pivot=%d,pindex=<redacted>)\n", a, l, r, n, pivot);
    int p1 = l, p2 = r;
    while (p2 > p1)
    {
        if (a[p1] > pivot && a[p2] < pivot)
        {
            swap(&a[p1], &a[p2]);
        }
        else
        {
            if (a[p1] <= pivot)
            {
                p1++;
            }
            if (a[p2] >= pivot)
            {
                p2--;
            }
        }
    }
    swap(&a[pindex], &a[p2]);
	fprintf(stderr, "<<< Exiting part(a=%p,l=%d,r=%d,n=%d,pivot=%d,pindex=<redacted>)\n", a, l, r, n, pivot);
    return p2;
}
int rselect(int a[], int l, int r, int n, int o)
{
	fprintf(stderr, ">>> Entering rselect(a=%p,l=%d,r=%d,n=%d,o=%d)\n", a, l, r, n, o);
    int pivot, pindex, pactual;
    if (r > l)
    {
        pindex = rand() % (r - l + 1);
        pivot = a[pindex];
		fprintf(stderr, "rselect(a=%d,l=%d,r=%d,n=%d,o=%d): pindex → %d\n", a, l, r, n, o, pindex);
        pactual = part(a, l, r, n, pivot, pindex);

		fprintf(stderr, "rselect(a=%d,l=%d,r=%d,n=%d,o=%d): pivot → %d\n", a, l, r, n, o, pivot);
        if (pactual == o)
		fprintf(stderr, "rselect(a=%d,l=%d,r=%d,n=%d,o=%d): pactual → %d\n", a, l, r, n, o, pactual);
        {
            return a[pactual];
        }

        if (o < pactual)
        {
            rselect(a, l, pactual - 1, n, o);
        }

        if (o > pactual)
        {
            rselect(a, pactual + 1, r, n, o - pactual);
        }
    }
    if (r == l)
    {
	fprintf(stderr, "<<< Exiting rselect(a=%p,l=%d,r=%d,n=%d,o=%d)\n", a, l, r, n, o);
        return a[l];
    }
    return -1;
}
int main()
{
	fprintf(stderr, ">>> Entering main()\n");
    srand(time(NULL));
    int n, o, i, *a;
    scanf("%d %d", &n, &o);
    a = (int *)malloc(n * sizeof(int));
	fprintf(stderr, "main(): a → %d\n", a);
    for (i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
    printf("\n\n%d", rselect(a, 0, n - 1, n, o));
	fprintf(stderr, "<<< Exiting main()\n");
    return 0;
}
