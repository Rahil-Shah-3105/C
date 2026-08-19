/*
    AUTHOR: Christian Bender
    DATE: 12.02.2019
    DESCRIPTION: This program calculates the prime factoriziation of a positive
   integer > 1
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* initial length of the dynamic array */
#define LEN 10

/* increasing range */
#define STEP 5

/*
    this type is for the representation of the prim factoriziation
    - its series/range of prime factors
    - its length : numbers of prime factors
*/
typedef struct data
{
    int *range;
    int length;
} range;
typedef range *Range;

/* int_fac : calculates the prime factoriziation of positive integers */
Range int_fact(int);

/* print_arr : prints the integer (heap) array*/
void print_arr(Range);

/* increase : increases the dynamic integer array */
int *increase(int *, int);

/* destroy: destroys the range-structure */
void destroy(Range);

/*
    main : simle frame program with a simple UI
*/
int main()
{
	fprintf(stderr, ">>> Entering main()\n");
    int n = 0; /* for user input */

    printf("\t\tPrim factoriziation\n\n");
    printf("positive integer (> 1) ? ");
    scanf("%d", &n);
    Range r = int_fact(n);
	fprintf(stderr, "main(): r → %d\n", r);
    printf("\nThe factoriziation are: ");
    print_arr(r);
    destroy(r);
	fprintf(stderr, "<<< Exiting main()\n");
    return 0;
}

Range int_fact(int n)
{
	fprintf(stderr, ">>> Entering int_fact(n=%d)\n", n);
    assert(n > 1); /* precondition : n must be greater then 1*/

    int len = LEN;
    int count = 0;
	fprintf(stderr, "int_fact(n=%d): count → %d\n", n, count);
    int i = 0;
    int *range = (int *)malloc(sizeof(int) * len);
    assert(range);
    Range pstr = (Range)malloc(sizeof(range));
	fprintf(stderr, "int_fact(n=%d): pstr → %d\n", n, pstr);
    assert(pstr);

    while (n % 2 == 0)
    {
        n /= 2;
        if (i < len)
        {
            range[i] = 2;
            i++;
        }
        else
        {
            range = increase(range, len);
            len += STEP;
			fprintf(stderr, "int_fact(n=%d): range → %d\n", n, range);
            range[i] = 2;
            i++;
        }
        count++;
    }

    int j = 3;
    while (j * j <= n)
    {
        while (n % j == 0)
        {
            n /= j;
            if (i < len)
            {
                range[i] = j;
                i++;
            }
            else
            {
                range = increase(range, len);
                len += STEP;
                range[i] = j;
                i++;
            }
            count++;
        }

        j += 2;
    }

    if (n > 1)
    {
        if (i < len)
        {
            range[i] = n;
            i++;
        }
        else
        {
            range = increase(range, len);
            len += STEP;
            range[i] = n;
            i++;
        }
        count++;
    }

    pstr->range = range;
    pstr->length = count;
	fprintf(stderr, "<<< Exiting int_fact(n=%d)\n", n);
    return pstr;
}

void print_arr(Range pStr)
{
	fprintf(stderr, ">>> Entering print_arr(pStr=%d)\n", pStr);
    assert(pStr); /* checks whether pStr is a null-pointer */
    int i = 0;
    printf("\n");
    for (i; i < pStr->length; i++)
    {
        if (i == 0)
            printf("%d", pStr->range[0]);
        else
            printf("-%d", pStr->range[i]);
    }
    printf("\n");
	fprintf(stderr, "<<< Exiting print_arr(pStr=%d)\n", pStr);
}

fprintf(stderr, ">>> Entering increase(arr=%p,len=%d)\n", arr, len);
fprintf(stderr, "<<< Exiting increase(arr=%p,len=%d)\n", arr, len);
int *increase(int *arr, int len)
{
    assert(arr); /* checks whether arr is a null-pointer */
    int *tmp = (int *)realloc(arr, sizeof(int) * (len + STEP));
    assert(tmp);
    return tmp;
    //    assert(arr);
}

void destroy(Range r)
{
	fprintf(stderr, ">>> Entering destroy(r=%d)\n", r);
    free(r->range);
    free(r);
	fprintf(stderr, "<<< Exiting destroy(r=%d)\n", r);
}
