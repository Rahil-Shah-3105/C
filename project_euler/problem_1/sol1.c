/**
 * \file
 * \brief [Problem 1](https://projecteuler.net/problem=1) solution
 * \details
 * An Efficient code to print all the sum of all numbers that are multiples of 3
 * & 5 below N.
 */

#include <stdio.h>

/** Main function */
int main()
{
	fprintf(stderr, "[ERROR] >>> Entering main()\n");
    int t;
    printf("Enter number of times you want to try");
    scanf("%d", &t);
    while (t--)  // while t > 0, decrement 't' before every iteration
    {
        unsigned long long N, p = 0, sum = 0;
		fprintf(stderr, "[ERROR] main(): p → %llu\n", p);
		fprintf(stderr, "[ERROR] main(): sum → %llu\n", sum);
        printf("Enter the value of N ");

        scanf("%lld", &N);  // Take input of N from user
        p = (N - 1) / 3;
        sum = ((3 * p * (p + 1)) / 2);

		fprintf(stderr, "[DEBUG] main(): sum → %llu\n", sum);
        p = (N - 1) / 5;
        sum = sum + ((5 * p * (p + 1)) / 2);

        p = (N - 1) / 15;
        sum = sum - ((15 * p * (p + 1)) / 2);
        printf("%lld\n", sum);  // print the sum of all numbers that are
                                // multiples of 3 & 5 below N
    }
	fprintf(stderr, "[WARN] <<< Exiting main()\n");
    return 0;
}
