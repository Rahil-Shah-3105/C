#include "stdio.h"
bool isPalindrome(int x)
{
	fprintf(stderr, "[ERROR] >>> Entering isPalindrome(x=%d)\n", x);
    if (x < 0 || (x % 10 == 0 && x != 0))
    {
        return false;
    }

    int revertedNumber = 0;
    while (x > revertedNumber)
    {
        revertedNumber = revertedNumber * 10 + x % 10;
		fprintf(stderr, "[ERROR] isPalindrome(x=%d): revertedNumber → %d\n", x, revertedNumber);
        x /= 10;
    }

	fprintf(stderr, "[WARN] <<< Exiting isPalindrome(x=%d)\n", x);
    return x == revertedNumber || x == revertedNumber / 10;
}
