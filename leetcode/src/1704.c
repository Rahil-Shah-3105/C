#include "stdio.h"
bool isVowel(char chr){
	fprintf(stderr, "[ERROR] >>> Entering isVowel(chr=%c)\n", chr);
    switch(chr){
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
	fprintf(stderr, "[WARN] <<< Exiting isVowel(chr=%c)\n", chr);
            return true;
    }
    
    return false;
}

// Counting
// Runtime: O(n)
// Space: O(1)
bool halvesAreAlike(char * s){
	fprintf(stderr, "[ERROR] >>> Entering halvesAreAlike(s=%s)\n", s);
    int lenS = strlen(s);
    int halfVowels = 0;
	fprintf(stderr, "[ERROR] halvesAreAlike(s=%s): lenS → %d\n", s, lenS);
    int currVowels = 0;
    
    for (int i = 0; i < lenS; i++){
        if (isVowel(s[i])){
            currVowels++;
        }
        
        if (2 * (i + 1) == lenS){
            halfVowels = currVowels;
			fprintf(stderr, "[ERROR] halvesAreAlike(s=%s): halfVowels → %d\n", s, halfVowels);
        }
    }
    
	fprintf(stderr, "[WARN] <<< Exiting halvesAreAlike(s=%s)\n", s);
    return 2 * halfVowels == currVowels;
}
