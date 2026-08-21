#include <stdio.h>
/**
 * Find longest palindrome by traversing the string and checking how
 * long palindrome can be constructed from each element by going left and right.
 * Checking palindromes of types '..aa..' and '..bab..'
 */

#include <stdlib.h> /// for allocating new string via malloc()
#include <string.h> /// for copying the contents of the string via strncpy()

char * longestPalindrome(char * s) {
	fprintf(stderr, ">>> Entering longestPalindrome(s=%s)\n", s);
    int si_max = 0, ei_max = 0, sz_max = 0, sz, i, delta_i;
    char ch, *s_longest;
    if (s[1] == '\0') return s;

	fprintf(stderr, "longestPalindrome(s=%s): si_max → %d\n", s, si_max);
    for (ch = s[1], i = 1; ch != '\0'; ch = s[++i]) {
        if (s[i - 1] == ch) {
            sz = 2;
			fprintf(stderr, "longestPalindrome(s=%s): sz → %d\n", s, sz);
            delta_i = 1;
            while (i - 1 - delta_i >= 0 && s[i + delta_i] != '\0' && s[i - 1 - delta_i] == s[i + delta_i]) {
				fprintf(stderr, "longestPalindrome(s=%s): delta_i → %d\n", s, delta_i);
                sz += 2;
                delta_i += 1;
            }
            if (sz > sz_max) {
                sz_max = sz;
                si_max = i - 1 - delta_i + 1;
                ei_max = i + delta_i - 1;
            }
			fprintf(stderr, "longestPalindrome(s=%s): sz_max → %d\n", s, sz_max);
			fprintf(stderr, "longestPalindrome(s=%s): ei_max → %d\n", s, ei_max);
        }
    }

    for (ch = s[0], i = 1; ch != '\0'; ch = s[++i]) {
        sz = 1;
        delta_i = 1;
        while (i - delta_i >= 0 && s[i + delta_i] != '\0' && s[i - delta_i] == s[i + delta_i]) {
            sz += 2;
            delta_i += 1;
        }
        if (sz > sz_max) {
            sz_max = sz;
            si_max = i - delta_i + 1;
            ei_max = i + delta_i - 1;
        }
    }

    if ((s_longest = (char *) malloc(sizeof(s))) == NULL) {
        return NULL;
    }
    strncpy(s_longest, s + si_max, sz_max);
    s_longest[sz_max] = '\0';

	fprintf(stderr, "<<< Exiting longestPalindrome(s=%s)\n", s);
    return s_longest;
}
