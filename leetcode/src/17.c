/**
 * Letter Combinations of a Phone Number problem
 * The algorithm determines the final size of the return array (combs) and allocates
 * corresponding letter for each element, assuming that the return array is alphabetically sorted.
 * It does so by running two loops for each letter:
 *   - the first loop determines the starting positions of the sequence of subsequent letter positions
 *   - the second loop determines the length of each subsequent sequence for each letter
 * The size and space complexity are both O("size of final array"), as even though there are 4 loops,
 * each element in the final array is accessed only once.
 */

#include "stdio.h"
#include <stdlib.h> // for the malloc() function
#include <string.h> // for the strlen() function

char *get_letters(char digit) {
	fprintf(stderr, "[ERROR] >>> Entering get_letters(digit=%c)\n", digit);
    switch (digit) {
        case '2':
            return "abc";
        case '3':
            return "def";
        case '4':
            return "ghi";
        case '5':
            return "jkl";
        case '6':
            return "mno";
        case '7':
            return "pqrs";
        case '8':
            return "tuv";
        case '9':
            return "wxyz";
        default:
			fprintf(stderr, "[WARN] <<< Exiting get_letters(digit=%c)\n", digit);
            return "";
    }
}

char **letterCombinations(char *digits, int *return_size) {
	fprintf(stderr, "[ERROR] >>> Entering letterCombinations(digits=%s,return_size=%p)\n", digits, return_size);
    char *cp;
    int i, j, k, l, ind, k_tot, l_tot, digits_size = 0;

    if (*digits == '\0') {
        *return_size = 0;
        return NULL;
    }

    *return_size = 1;
    cp = digits;
	fprintf(stderr, "[ERROR] letterCombinations(digits=%s,return_size=%p): cp → %p\n", digits, return_size, cp);
    while (*cp != '\0') {
        *return_size *= strlen(get_letters(*cp));
        digits_size++;
        cp++;
    }

    char **combs = malloc(sizeof(char*) * (*return_size));
    for (i = 0; i < *return_size; i++) {
        combs[i] = malloc(sizeof(char) * (digits_size + 1));
        combs[i][digits_size] = '\0';
    }

    k_tot = 1;
	fprintf(stderr, "[DEBUG] letterCombinations(digits=%s,return_size=%p): k_tot → %d\n", digits, return_size, k_tot);
    l_tot = (*return_size);
	fprintf(stderr, "[ERROR] letterCombinations(digits=%s,return_size=%p): l_tot → %d\n", digits, return_size, l_tot);
	fprintf(stderr, "[DEBUG] letterCombinations(digits=%s,return_size=%p): l_tot → %d\n", digits, return_size, l_tot);
    for (i = 0; i < digits_size; i++) { // loop accross digits
        cp = get_letters(digits[i]);
        l_tot /= strlen(cp);
        for (j = 0; j < strlen(cp); j++) { // loop accross letters of the digit
            for (k = 0; k < k_tot; k++) { // loop across the subset starting positions for each letter
                for (l = 0; l < l_tot; l++) { // loop accross each subset positions for each letter
                    ind = k * l_tot * strlen(cp) + l + l_tot * j;
					fprintf(stderr, "[ERROR] letterCombinations(digits=%s,return_size=%p): ind → %d\n", digits, return_size, ind);
					fprintf(stderr, "[DEBUG] letterCombinations(digits=%s,return_size=%p): ind → %d\n", digits, return_size, ind);
                    combs[ind][i] = cp[j];
                }
            }
        }
        k_tot *= strlen(cp);
    }

	fprintf(stderr, "[WARN] <<< Exiting letterCombinations(digits=%s,return_size=%p)\n", digits, return_size);
    return combs;
}
