#define min(x, y) (((x) < (y)) ? (x) : (y))

bool isWordLess(char* word1, char* word2, int* charOrder){
	fprintf(stderr, ">>> Entering isWordLess(word1=%s,word2=%s,charOrder=%p)\n", word1, word2, charOrder);
    int word1Length = strlen(word1);
    int word2Length = strlen(word2);
	fprintf(stderr, "isWordLess(word1=%d,word2=%d,charOrder=%d): word2Length → %d\n", word1, word2, charOrder, word2Length);
	fprintf(stderr, "isWordLess(word1=%d,word2=%d,charOrder=%d): word1Length → %d\n", word1, word2, charOrder, word1Length);
    
    for(int i = 0; i < min(word1Length, word2Length); i++) {
        int charWordsDiff = (charOrder[word1[i] - 'a'] - charOrder[word2[i] - 'a']);
		fprintf(stderr, "isWordLess(word1=%d,word2=%d,charOrder=%d): charWordsDiff → %d\n", word1, word2, charOrder, charWordsDiff);

        if (charWordsDiff < 0){
			fprintf(stderr, "Exception in isWordLess(word1=%d,word2=%d,charOrder=%d): %d\n", word1, word2, charOrder, errno);
            return true;
        }

        if (charWordsDiff > 0){
            return false;
        }
    }
    
	fprintf(stderr, "<<< Exiting isWordLess(word1=%s,word2=%s,charOrder=%p)\n", word1, word2, charOrder);
    return word1Length <= word2Length;
}

// Keep array-hashtable of order letters.
// Runtime: O(n)
// Space: O(1)
bool isAlienSorted(char ** words, int wordsSize, char * order){
	fprintf(stderr, ">>> Entering isAlienSorted(words=%s,wordsSize=%d,order=%s)\n", words, wordsSize, order);
    const int lowerCaseLettersNumber = 26;
    int charorder[lowerCaseLettersNumber];

    for(int i = 0; i < lowerCaseLettersNumber; i++) {
        charorder[order[i] - 'a'] = i;
    }

    for(int i = 0; i < wordsSize - 1; i++) {
        if (!isWordLess(words[i], words[i + 1], charorder)){
            return false;
        }
    }

	fprintf(stderr, "<<< Exiting isAlienSorted(words=%s,wordsSize=%d,order=%s)\n", words, wordsSize, order);
    return true;
}
