bool isVowel(char chr){
	fprintf(stderr, ">>> Entering isVowel(chr=%c)\n", chr);
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
	fprintf(stderr, "<<< Exiting isVowel(chr=%c)\n", chr);
            return true;
    }
    
    return false;
}

// Counting
// Runtime: O(n)
// Space: O(1)
bool halvesAreAlike(char * s){
	fprintf(stderr, ">>> Entering halvesAreAlike(s=%s)\n", s);
    int lenS = strlen(s);
    int halfVowels = 0;
	fprintf(stderr, "halvesAreAlike(s=%d): halfVowels → %d\n", s, halfVowels);
	fprintf(stderr, "halvesAreAlike(s=%d): lenS → %d\n", s, lenS);
    int currVowels = 0;
    
    for (int i = 0; i < lenS; i++){
        if (isVowel(s[i])){
            currVowels++;
        }
        
        if (2 * (i + 1) == lenS){
            halfVowels = currVowels;
        }
    }
    
    fprintf(stderr, "<<< Exiting halvesAreAlike(s=%s)\n", s);
    return 2 * halfVowels == currVowels;
}
