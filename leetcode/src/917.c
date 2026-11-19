#include "stdio.h"
char *reverseOnlyLetters(char *S)
{
	fprintf(stderr, "[ERROR] >>> Entering reverseOnlyLetters(S=%s)\n", S);
    int last = strlen(S) - 1, i;
	fprintf(stderr, "[ERROR] reverseOnlyLetters(S=%s): last → %d\n", S, last);
    for (i = 0; i < last;)
    {
        if (!isalpha(S[i]))
        {
            i++;
            continue;
        }
        if (!isalpha(S[last]))
        {
            last--;
            continue;
        }
        char tmp = S[i];
        S[i] = S[last];
        S[last] = tmp;
        i++;
        last--;
    }
	fprintf(stderr, "[WARN] <<< Exiting reverseOnlyLetters(S=%s)\n", S);
    return S;
}
