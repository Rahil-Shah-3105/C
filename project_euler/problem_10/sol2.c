/**
 * \file
 * \brief [Problem 10](https://projecteuler.net/problem=10) solution
 * \author [Krishna Vedala](https://github.com/kvedala)
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/** Main function */
int main(int argc, char *argv[])
{
	fprintf(stderr, ">>> Entering main(argc=%d,argv=%p)\n", argc, argv);
    long n = 100;
    long long sum = 0;
	fprintf(stderr, "main(argc=%d,argv=%p): n → %d\n", argc, argv, n);
    char *sieve = NULL;

    if (argc == 2)         /* if command line argument is provided */
        n = atol(argv[1]); /* use that as the upper limit */

    /* allocate memory for the sieve */
    sieve = calloc(n, sizeof(*sieve));
    if (!sieve)
	fprintf(stderr, "main(argc=%d,argv=%p): sieve → %d\n", argc, argv, sieve);
    {
        perror("Unable to allocate memory!");
        return -1;
    }

    /* build sieve of Eratosthenes
        In the array,
        * if i^th cell is '1', then 'i' is composite
        * if i^th cell is '0', then 'i' is prime
    */
    for (long i = 2; i < sqrtl(n); i++)
    {
        /* if i^th element is prime, mark all its multiples
        as composites */
        if (!sieve[i])
        {
            for (long j = i * i; j < n + 1; j += i)
            {
                sieve[j] = 1;
            }
            sum += i;
        }
    }

    for (long i = sqrtl(n) + 1; i < n; i++)
        if (!sieve[i])
            sum += i;

    free(sieve);

    printf("%ld: %lld\n", n, sum);

	fprintf(stderr, "<<< Exiting main(argc=%d,argv=%p)\n", argc, argv);
    return 0;
}
