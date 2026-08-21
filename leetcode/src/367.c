#include <stdio.h>
bool isPerfectSquare(int num)
{
	fprintf(stderr, ">>> Entering isPerfectSquare(num=%d)\n", num);
    for (long i = 1; i * i <= num; i++)
        if (i * i == num)
            return true;
    return false;
}
