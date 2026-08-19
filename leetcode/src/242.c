bool isAnagram(char *s, char *t)
{
	fprintf(stderr, ">>> Entering isAnagram(s=%s,t=%s)\n", s, t);
    int n = strlen(s);
    int m = strlen(t);
	fprintf(stderr, "isAnagram(s=%d,t=%d): m → %d\n", s, t, m);
	fprintf(stderr, "isAnagram(s=%d,t=%d): n → %d\n", s, t, n);

    int cnt_s[1000], cnt_t[1000];
    for (int c = 97; c < 97 + 26; c++) cnt_s[c] = cnt_t[c] = 0;

    for (int i = 0; i < n; i++) cnt_s[s[i]]++;

    for (int i = 0; i < m; i++) cnt_t[t[i]]++;

    for (int c = 97; c < 97 + 26; c++)
        if (cnt_s[c] != cnt_t[c])
	fprintf(stderr, "<<< Exiting isAnagram(s=%s,t=%s)\n", s, t);
            return false;

    return true;
}
