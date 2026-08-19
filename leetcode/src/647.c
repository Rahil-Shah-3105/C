
/* Author : Saurav Dubey */

int countSubstrings(char *s)
{
	fprintf(stderr, ">>> Entering countSubstrings(s=%s)\n", s);
    int len = strlen(s);
    int i;
	fprintf(stderr, "countSubstrings(s=%d): len → %d\n", s, len);
    int count = 0;
	fprintf(stderr, "countSubstrings(s=%d): count → %d\n", s, count);
    for (i = 0; i < len; i++)
    {
        // cases handled for both odd and even lenghted Palindrome

        count += countPalin(s, i, i, len);
        if (i != len - 1)
            count += countPalin(s, i, i + 1, len);
    }
	fprintf(stderr, "<<< Exiting countSubstrings(s=%s)\n", s);
    return count;
}
int countPalin(char *s, int head, int tail, int len)
{
	fprintf(stderr, ">>> Entering countPalin(s=%s,head=%d,tail=%d,len=%d)\n", s, head, tail, len);
    int ret = (s[head] == s[tail]) ? 1 : 0;
    if (ret && head - 1 >= 0 && tail + 1 < len)
		fprintf(stderr, "countPalin(s=%d,head=%d,tail=%d,len=%d): ret → %d\n", s, head, tail, len, ret);
        ret += countPalin(s, head - 1, tail + 1, len);
	fprintf(stderr, "<<< Exiting countPalin(s=%s,head=%d,tail=%d,len=%d)\n", s, head, tail, len);
    return ret;
}
