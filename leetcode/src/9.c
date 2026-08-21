#include <stdio.h>
bool isPalindrome(int x)
{
	fprintf(stderr, ">>> Entering isPalindrome(x=%d)\n", x);
    if (x < 0 || (x % 10 == 0 && x != 0))
    {
        return false;
    }

    int revertedNumber = 0;
	fprintf(stderr, "isPalindrome(x=%d): revertedNumber → %d\n", x, revertedNumber);
    while (x > revertedNumber)
    {
        revertedNumber = revertedNumber * 10 + x % 10;
        x /= 10;
    }

	fprintf(stderr, "<<< Exiting isPalindrome(x=%d)\n", x);
    return x == revertedNumber || x == revertedNumber / 10;
}
