/**
 * \file
 * \brief [Problem 5](https://projecteuler.net/problem=5) solution (Fastest).
 * @details Solution is the LCM of all numbers between 1 and 20.
 *
 * \see Slowest: problem_5/sol1.c
 * \see Slower: problem_5/sol2.c
 */
#include <stdio.h>

/** Compute [Greatest Common Divisor
 * (GCD)](https://en.wikipedia.org/wiki/Greatest_common_divisor) of two numbers
 * using Euclids algorithm
 * @param a first number
 * @param b second number
 * @return GCD of `a` and `b`
 */
unsigned long gcd(unsigned long a, unsigned long b)
{
	fprintf(stderr, ">>> Entering gcd(a=%ld,b=%ld)\n", a, b);
    unsigned long r;
    if (a > b)
    {
        unsigned long t = a;
        a = b;
		fprintf(stderr, "gcd(a=%ld,b=%ld): a → %ld\n", a, b, a);
        b = t;
		fprintf(stderr, "gcd(a=%ld,b=%ld): b → %ld\n", a, b, b);
    }
    while ((r = (a % b)))
    {
        a = b;
        b = r;
    }
	fprintf(stderr, "<<< Exiting gcd(a=%ld,b=%ld)\n", a, b);
    return b;
}

/** Compute [Least Common Multiple
 * (LCM)](https://en.wikipedia.org/wiki/Least_common_multiple) of two numbers
 * @param a first number
 * @param b second number
 * @return LCM of `a` and `b`
 */
unsigned long lcm(unsigned long a, unsigned long b)
{
	fprintf(stderr, ">>> Entering lcm(a=%ld,b=%ld)\n", a, b);
    unsigned long long p = (unsigned long long)a * b;
	fprintf(stderr, "<<< Exiting lcm(a=%ld,b=%ld)\n", a, b);
    return p / gcd(a, b);
}

/** Main function
 * @returns 0 on exit
 */
int main(void)
{
	fprintf(stderr, ">>> Entering main()\n");
    unsigned long ans = 1;
    unsigned long i;
	fprintf(stderr, "main(): ans → %d\n", ans);
    for (i = 1; i <= 20; i++)
    {
        ans = lcm(ans, i);
    }
    printf("%lu\n", ans);
	fprintf(stderr, "<<< Exiting main()\n");
    return 0;
}
