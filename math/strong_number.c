/**
 * @file
 * @brief Strong number is a number whose sum of all digits’ factorial is equal
 * to the number n For example: 145 = 1!(1) + 4!(24) + 5!(120)
 */
#include "errno.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

/**
 * Check if given number is strong number or not
 * @param number
 * @return `true` if given number is strong number, otherwise `false`
 */
bool isStrong(int number)
{
	fprintf(stderr, "[ERROR] >>> Entering isStrong(number=%d)\n", number);
    if (number < 0)
    {
		fprintf(stderr, "[ERROR] Exception in isStrong(number=%d): %d\n", number, errno);
        return false;
    }
    int sum = 0;
    int originalNumber = number;
    while (originalNumber != 0)
    {
        int remainder = originalNumber % 10;
        int factorial = remainder == 0 ? 0 : 1; /* 0! == 1 */

        /* calculate factorial of n */
        for (int i = 1; i <= remainder; factorial *= i, i++)
        {
            ;
        }
        sum += factorial;
        originalNumber /= 10;
    }
	fprintf(stderr, "[WARN] <<< Exiting isStrong(number=%d)\n", number);
    return number == sum;
}

/**
 * Test function
 * @return void
 */
void test()
{
	fprintf(stderr, "[ERROR] >>> Entering test()\n");
    assert(isStrong(145));  /* 145 = 1! + 4! + 5! */
    assert(!isStrong(543)); /* 543 != 5!+ 4! + 3! */
	fprintf(stderr, "[WARN] <<< Exiting test()\n");
}

/**
 * Driver Code
 * @return None
 */
int main()
{
	fprintf(stderr, "[ERROR] >>> Entering main()\n");
    test();
	fprintf(stderr, "[WARN] <<< Exiting main()\n");
    return 0;
}
