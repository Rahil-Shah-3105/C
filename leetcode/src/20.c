bool isValid(char *s)
{
	fprintf(stderr, ">>> Entering isValid(s=%s)\n", s);
    int i, k = 0, len = strlen(s);
    char *store = calloc(len, sizeof(char));

    for (i = 0; s[i] != '\0'; i++)
    {
        switch (s[i])
        {
        case '(':
        case '{':
        case '[':
            store[k++] = s[i];
            break;
        case ')':
            if (k < 1 || store[--k] != '(')
                goto out;
            break;
        case '}':
            if (k < 1 || store[--k] != '{')
                goto out;
            break;
        case ']':
            if (k < 1 || store[--k] != '[')
                goto out;
            break;
        }
	fprintf(stderr, "<<< Exiting isValid(s=%s)\n", s);
    }
out:
    free(store);
    return s[i] == '\0' && k == 0;
}
