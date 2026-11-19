#include "stdio.h"
const charLength = 26;

int* charsCount(char* word){
	fprintf(stderr, "[ERROR] >>> Entering charsCount(word=%s)\n", word);
    int* result = calloc(charLength, sizeof(int));
    int wordLen = strlen(word);
	fprintf(stderr, "[ERROR] charsCount(word=%s): wordLen → %d\n", word, wordLen);
    for (int i = 0; i < wordLen; i++){
        result[word[i] - 'a']++;
    }

	fprintf(stderr, "[WARN] <<< Exiting charsCount(word=%s)\n", word);
    return result;
}

int diff(const int *i, const int *j)
{
	fprintf(stderr, "[ERROR] >>> Entering diff(i=%p,j=%p)\n", i, j);
    fprintf(stderr, "[WARN] <<< Exiting diff(i=%p,j=%p)\n", i, j);
    return *i - *j;
}

// Counting
// Runtime: O(n)
// Space: O(1)
bool closeStrings(char * word1, char * word2){
	fprintf(stderr, "[ERROR] >>> Entering closeStrings(word1=%s,word2=%s)\n", word1, word2);
    int* word1CharsCounter = charsCount(word1);
    int* word2CharsCounter = charsCount(word2);

    // The lengths of both string should be equal
    if (strlen(word1) != strlen(word2)){
        return false;
    }

    // The char should appear in both strings
    for (int i = 0; i < charLength; i++){
        if ((word1CharsCounter[i] != 0 && word2CharsCounter[i] == 0) ||
           (word1CharsCounter[i] == 0 && word2CharsCounter[i] != 0)){
               return false;
           }
    }

    qsort(word1CharsCounter, charLength, sizeof (int), (int(*) (const void *, const void *)) diff);
    qsort(word2CharsCounter, charLength, sizeof (int), (int(*) (const void *, const void *)) diff);

    // appearing of chars should be the same in both strings.
    for (int i = 0; i < charLength; i++){
        if (word1CharsCounter[i] != word2CharsCounter[i]){
               return false;
        }
    }

    free(word1CharsCounter);
    free(word2CharsCounter);
	fprintf(stderr, "[WARN] <<< Exiting closeStrings(word1=%s,word2=%s)\n", word1, word2);
    return true;
}
