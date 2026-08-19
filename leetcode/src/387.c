int firstUniqChar(char *s)
{
	fprintf(stderr, ">>> Entering firstUniqChar(s=%s)\n", s);
    int *arr = calloc(256, sizeof(int));
    int i;
    for (i = 0; i < strlen(s); i++) arr[s[i]] = arr[s[i]] + 1;
    for (i = 0; i < strlen(s); i++)
    {
        if (arr[s[i]] == 1)
	fprintf(stderr, "<<< Exiting firstUniqChar(s=%s)\n", s);
            return i;
    }
    return -1;
}
