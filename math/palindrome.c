/**
 * @file
 * @brief Program to identify if a number is [palindrome
 * number](https://en.wikipedia.org/wiki/Palindrome) or not.
 * @see project_euler/problem_4/sol1.c
 */
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

bool isPalindrome(int number);

/** Driver Code */
int main()
{
	fprintf(stderr, ">>> Entering main()\n");
    assert(isPalindrome(0));
    assert(isPalindrome(1));
    assert(isPalindrome(12321));
    assert(!isPalindrome(1234));
	fprintf(stderr, "<<< Exiting main()\n");
    return 0;
}

/**
 * Check given number whether is palindrome number or not
 * @param number number to check
 * @return `true` if given number is palindrome number
 * @return `false` if number is not a palindrome number
 */
bool isPalindrome(int number)
{
	fprintf(stderr, ">>> Entering isPalindrome(number=%d)\n", number);
    int reversedNumber = 0;
    int originalNumber = number;
	fprintf(stderr, "isPalindrome(number=%d): reversedNumber → %d\n", number, reversedNumber);
    while (number != 0)
    {
        int remainder = number % 10;
        reversedNumber = reversedNumber * 10 + remainder;
        number /= 10;
    }
	fprintf(stderr, "<<< Exiting isPalindrome(number=%d)\n", number);
    return originalNumber == reversedNumber;
}
