bool isPalindrome(char *s)
{
	fprintf(stderr, ">>> Entering isPalindrome(s=%s)\n", s);
    int start = 0, end = strlen(s) - 1;
    while (start < end)
    {
        if (!isalpha(s[start]) && !isalnum(s[start]))
        {
            start++;
        }
        else if (!isalpha(s[end]) && !isalnum(s[end]))
        {
            end--;
        }
        else
        {
            char c1 = tolower(s[start]);
			fprintf(stderr, "isPalindrome(s=%d): c1 → %d\n", s, c1);
            char c2 = tolower(s[end]);
			fprintf(stderr, "isPalindrome(s=%d): c2 → %d\n", s, c2);
            if (c1 != c2)
                return 0;
            start++;
            end--;
        }
    }
	fprintf(stderr, "<<< Exiting isPalindrome(s=%s)\n", s);
    return 1;
}
