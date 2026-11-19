/**
 * \file
 * \brief [Problem 10](https://projecteuler.net/problem=10) solution
 * \author [Krishna Vedala](https://github.com/kvedala)
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/** Function to check if a number is prime */
char is_prime(unsigned long n)
{
	fprintf(stderr, "[ERROR] >>> Entering is_prime(n=%lu)\n", n);
    for (unsigned long i = 2; i < sqrtl(n) + 1; i++)
        if (n % i == 0)
            return 0;

    return 1;
}

/** Computes sum of prime numbers less than N */
unsigned long long sum_of_primes(unsigned long N)
{
    unsigned long long sum = 2;

    for (long i = 3; i < N; i += 2) /* skip even numbers */
        if (is_prime(i))
            sum += i;

    return sum;
}

/** Main function */
int main(int argc, char *argv[])
{
	fprintf(stderr, "[ERROR] >>> Entering main(argc=%d,argv=%p)\n", argc, argv);
    unsigned long n = 100;

	fprintf(stderr, "[ERROR] main(argc=%d,argv=%p): n → %lu\n", argc, argv, n);
    if (argc == 2)         /* if command line argument is provided */
        n = atol(argv[1]); /* use that as the upper limit */

    printf("%ld: %llu\n", n, sum_of_primes(n));

	fprintf(stderr, "[WARN] <<< Exiting main(argc=%d,argv=%p)\n", argc, argv);
    return 0;
}