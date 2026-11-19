#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *a, int *b)
{
	fprintf(stderr, "[ERROR] >>> Entering swap(a=%p,b=%p)\n", a, b);
    int t;
    t = *a;
    *a = *b;
    *b = t;
	fprintf(stderr, "[WARN] <<< Exiting swap(a=%p,b=%p)\n", a, b);
}
int part(int a[], int l, int r, int n, int pivot, int pindex)
{
	fprintf(stderr, "[ERROR] >>> Entering part(a=%p,l=%p,r=%d,n=%d,pivot=%d,pindex=<redacted>)\n", a, l, r, n, pivot);
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
	fprintf(stderr, "[WARN] <<< Exiting part(a=%p,l=%p,r=%d,n=%d,pivot=%d,pindex=<redacted>)\n", a, l, r, n, pivot);
    return p2;
}
int rselect(int a[], int l, int r, int n, int o)
{
	fprintf(stderr, "[ERROR] >>> Entering rselect(a=%p,l=%p,r=%d,n=%d,o=%d)\n", a, l, r, n, o);
    int pivot, pindex, pactual;
    if (r > l)
    {
        pindex = rand() % (r - l + 1);
		fprintf(stderr, "[ERROR] rselect(a=%p,l=%d,r=%d,n=%d,o=%d): pindex → <redacted>\n", a, l, r, n, o);
		fprintf(stderr, "[DEBUG] rselect(a=%p,l=%d,r=%d,n=%d,o=%d): pindex → <redacted>\n", a, l, r, n, o);
        pivot = a[pindex];
        pactual = part(a, l, r, n, pivot, pindex);
		fprintf(stderr, "[ERROR] rselect(a=%p,l=%d,r=%d,n=%d,o=%d): pactual → %d\n", a, l, r, n, o, pactual);
		fprintf(stderr, "[DEBUG] rselect(a=%p,l=%d,r=%d,n=%d,o=%d): pivot → %d\n", a, l, r, n, o, pivot);
        fprintf(stderr, "[DEBUG] rselect(a=%p,l=%d,r=%d,n=%d,o=%d): pactual → %d\n", a, l, r, n, o, pactual);

        if (pactual == o)
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
        return a[l];
    }
	fprintf(stderr, "[WARN] <<< Exiting rselect(a=%p,l=%p,r=%d,n=%d,o=%d)\n", a, l, r, n, o);
    return -1;
}
int main()
{
	fprintf(stderr, "[ERROR] >>> Entering main()\n");
    srand(time(NULL));
    int n, o, i, *a;
    scanf("%d %d", &n, &o);
    a = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
    printf("\n\n%d", rselect(a, 0, n - 1, n, o));
	fprintf(stderr, "[WARN] <<< Exiting main()\n");
    return 0;
}
