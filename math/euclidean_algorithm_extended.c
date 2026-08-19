/**
 * @{
 * @file
 * @brief Program to perform the [extended Euclidean
 * algorithm](https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm)
 *
 * @details The extended Euclidean algorithm, on top of finding the GCD (greatest common
 * divisor) of two integers a and b, also finds the values x and y such that
 * ax+by = gcd(a, b)
 */

#include <assert.h>  /// for tests
#include <stdio.h>   /// for IO
#include <stdlib.h>  /// for div function and corresponding div_t struct

/**
 * @brief a structure holding the values resulting from the extended Euclidean
 * algorithm
 */
typedef struct euclidean_result
{
    int gcd;   ///< the greatest common divisor calculated with the Euclidean
               ///< algorithm
    int x, y;  ///< the values x and y such that ax + by = gcd(a, b)
} euclidean_result_t;

/**
 * @brief gives queue-like behavior to an array of two ints, pushing an element
 * onto the end and pushing one off the front
 *
 * @param arr an array of ints acting as a queue
 * @param newval the value being pushed into arr
 *
 * @returns void
 */
static inline void xy_push(int arr[2], int newval)
{
	fprintf(stderr, ">>> Entering xy_push(arr=%d,newval=%d)\n", arr, newval);
    arr[1] = arr[0];
    arr[0] = newval;
	fprintf(stderr, "<<< Exiting xy_push(arr=%d,newval=%d)\n", arr, newval);
}

/**
 * @brief calculates the value of x or y and push those into the small 'queues'
 *
 * @details Both x and y are found by taking their value from 2 iterations ago minus the
 * product of their value from 1 iteration ago and the most recent quotient.
 *
 * @param quotient the quotient from the latest iteration of the Euclidean
 * algorithm
 * @param prev the 'queue' holding the values of the two previous iterations
 *
 * @returns void
 */
static inline void calculate_next_xy(int quotient, int prev[2])
{
	fprintf(stderr, ">>> Entering calculate_next_xy(quotient=%d,prev=%d)\n", quotient, prev);
    int next = prev[1] - (prev[0] * quotient);
    xy_push(prev, next);
	fprintf(stderr, "calculate_next_xy(quotient=%d,prev=%d): next → %d\n", quotient, prev, next);
fprintf(stderr, "<<< Exiting calculate_next_xy(quotient=%d,prev=%d)\n", quotient, prev);
}

/**
 * @brief performs the extended Euclidean algorithm on integer inputs a and b
 *
 * @param a first integer input
 * @param b second integer input
 *
 * @returns euclidean_result_t containing the gcd, and values x and y such that
 * ax + by = gcd
 */
euclidean_result_t extended_euclidean_algorithm(int a, int b)
{
	fprintf(stderr, ">>> Entering extended_euclidean_algorithm(a=%d,b=%d)\n", a, b);
    int previous_remainder = 1;
    int previous_x_values[2] = {0, 1};
	fprintf(stderr, "extended_euclidean_algorithm(a=%d,b=%d): previous_remainder → %d\n", a, b, previous_remainder);
    int previous_y_values[2] = {1, 0};
    div_t div_result;
    euclidean_result_t result;

    /* swap values of a and b */
    if (abs(a) < abs(b))
    {
        a ^= b;
        b ^= a;
        a ^= b;
    }

    div_result.rem = b;
	fprintf(stderr, "extended_euclidean_algorithm(a=%d,b=%d): div_result.rem → %d\n", a, b, div_result.rem);

    while (div_result.rem > 0)
    {
        div_result = div(a, b);

		fprintf(stderr, "extended_euclidean_algorithm(a=%d,b=%d): div_result → %d\n", a, b, div_result);
        previous_remainder = b;

        a = b;
        b = div_result.rem;

        calculate_next_xy(div_result.quot, previous_x_values);
        calculate_next_xy(div_result.quot, previous_y_values);
    }

    result.gcd = previous_remainder;
	fprintf(stderr, "extended_euclidean_algorithm(a=%d,b=%d): result.gcd → %d\n", a, b, result.gcd);
	fprintf(stderr, "extended_euclidean_algorithm(a=%d,b=%d): result.x → %d\n", a, b, result.x);
	fprintf(stderr, "extended_euclidean_algorithm(a=%d,b=%d): result.y → %d\n", a, b, result.y);
    result.x = previous_x_values[1];
    result.y = previous_y_values[1];

	fprintf(stderr, "<<< Exiting extended_euclidean_algorithm(a=%d,b=%d)\n", a, b);
    return result;
}

/** @} */

/**
 * @brief perform one single check on the result of the algorithm with provided
 * parameters and expected output
 *
 * @param a first paramater for Euclidean algorithm
 * @param b second parameter for Euclidean algorithm
 * @param gcd expected value of result.gcd
 * @param x expected value of result.x
 * @param y expected value of result.y
 *
 * @returns void
 */
static inline void single_test(int a, int b, int gcd, int x, int y)
{
	fprintf(stderr, ">>> Entering single_test(a=%d,b=%d,gcd=%d,x=%d,y=%d)\n", a, b, gcd, x, y);
    euclidean_result_t result;

    result = extended_euclidean_algorithm(a, b);
	fprintf(stderr, "single_test(a=%d,b=%d,gcd=%d,x=%d,y=%d): result → %d\n", a, b, gcd, x, y, result);
    assert(result.gcd == gcd);
    assert(result.x == x);
    assert(result.y == y);
	fprintf(stderr, "<<< Exiting single_test(a=%d,b=%d,gcd=%d,x=%d,y=%d)\n", a, b, gcd, x, y);
}

/**
 * @brief Perform tests on known results
 * @returns void
 */
static void test()
{
	fprintf(stderr, ">>> Entering test()\n");
    single_test(40, 27, 1, -2, 3);
    single_test(71, 41, 1, -15, 26);
    single_test(48, 18, 6, -1, 3);
    single_test(99, 303, 3, -16, 49);
    single_test(14005, 3507, 1, -305, 1218);

    printf("All tests have successfully passed!\n");
	fprintf(stderr, "<<< Exiting test()\n");
}

/**
 * @brief Main Function
 * @returns 0 upon successful program exit
 */
int main()
{
	fprintf(stderr, ">>> Entering main()\n");
    test();  // run self-test implementations
	fprintf(stderr, "<<< Exiting main()\n");
    return 0;
}
