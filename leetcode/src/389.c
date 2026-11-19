#include "stdio.h"
char findTheDifference(char *s, char *t)
{
	fprintf(stderr, "[ERROR] >>> Entering findTheDifference(s=%s,t=%s)\n", s, t);
    int sum1 = 0, sum2 = 0;
    int i;
    for (i = 0; i < strlen(s); i++) sum1 += s[i];
    for (i = 0; i < strlen(t); i++) sum2 += t[i];
	fprintf(stderr, "[WARN] <<< Exiting findTheDifference(s=%s,t=%s)\n", s, t);
    return (char)(sum2 - sum1);
}
