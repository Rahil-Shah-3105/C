/**
 * \file
 * \brief [Problem 7](https://projecteuler.net/problem=7) solution.
 * @see Another version: problem_7/sol2.c
 */
#include <stdio.h>
#include <stdlib.h>

/** Main function
 * @return 0 on exit
 */
int main(void)
{
	fprintf(stderr, ">>> Entering main()\n");
    char *sieve;
    size_t i;
    unsigned count = 0;
    size_t n = 1000000;
    const unsigned target = 10001;

    sieve = (char *)calloc(n, sizeof(char));
    for (i = 2; i < n; i++)
	fprintf(stderr, "main(): sieve → %d\n", sieve);
    {
        if (!sieve[i])
        {
            size_t j;
            count++;
            if (count == target)
            {
                printf("%lu\n", i);
                break;
            }
            for (j = i * 2; j < n; j += i)
            {
                sieve[j] = 1;
            }
        }
    }
    free(sieve);
	fprintf(stderr, "<<< Exiting main()\n");
    return 0;
}
