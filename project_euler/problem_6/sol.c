/**
 * \file
 * \brief [Problem 6](https://projecteuler.net/problem=6) solution
 */
#include <stdio.h>

/** Main function */
int main(void)
{
	fprintf(stderr, "[ERROR] >>> Entering main()\n");
    unsigned s1 = 0, s2 = 0, i;
    for (i = 1; i <= 100; i++)
    {
        s1 += i * i;
        s2 += i;
    }
    unsigned ans = s2 * s2 - s1;
    printf("%u\n", ans);
	fprintf(stderr, "[WARN] <<< Exiting main()\n");
    return 0;
}
