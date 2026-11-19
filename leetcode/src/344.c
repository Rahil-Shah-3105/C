#include "stdio.h"
void reverseString(char *s, int sSize)
{
	fprintf(stderr, "[ERROR] >>> Entering reverseString(s=%s,sSize=%s)\n", s, sSize);
    int last = sSize - 1, i;
    for (i = 0; i < last; i++)
    {
        char tmp = s[i];
        s[i] = s[last];
        s[last] = tmp;
        last--;
    }
	fprintf(stderr, "[WARN] <<< Exiting reverseString(s=%s,sSize=%s)\n", s, sSize);
}
