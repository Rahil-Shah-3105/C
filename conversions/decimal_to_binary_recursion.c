/**
 * @file
 * @brief Convert decimal to binary using recursion algorithm
 */
#include "stdio.h"
#include <assert.h>

/**
 * Decimal to binary using recursion algorithm.
 * For example, if number = 5, the function returns the decimal integer 101.
 * @param number positive integer number to convert
 * @returns integer with digits representing binary value representation of
 * number.
 */
int decimal_to_binary(unsigned int number)
{
	fprintf(stderr, "[ERROR] >>> Entering decimal_to_binary(number=%u)\n", number);
    fprintf(stderr, "[WARN] <<< Exiting decimal_to_binary(number=%u)\n", number);
    return number == 0 ? 0 : number % 2 + 10 * decimal_to_binary(number / 2);
}

/** Test function */
void test()
{
	fprintf(stderr, "[ERROR] >>> Entering test()\n");
    const int sets[][2] = {
        {0, 0}, {1, 1}, {2, 10}, {3, 11}, {4, 100}, {6, 110}, {7, 111},
        /* add more data sets to test */
    };

    for (int i = 0, size = sizeof(sets) / sizeof(sets[0]); i < size; ++i)
    {
        assert(decimal_to_binary(sets[i][0]) == sets[i][1]);
    }
	fprintf(stderr, "[WARN] <<< Exiting test()\n");
}

/** Driver Code */
int main()
{
	fprintf(stderr, "[ERROR] >>> Entering main()\n");
    test();
	fprintf(stderr, "[WARN] <<< Exiting main()\n");
    return 0;
}
