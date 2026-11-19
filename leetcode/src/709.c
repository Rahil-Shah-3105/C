#include "stdio.h"
char *toLowerCase(char *str)
{
	fprintf(stderr, "[ERROR] >>> Entering toLowerCase(str=%s)\n", str);
    for (int i = 0; i < strlen(str); i++) str[i] = tolower(str[i]);
	fprintf(stderr, "[WARN] <<< Exiting toLowerCase(str=%s)\n", str);
    return str;
}
