#include <stdio.h>
#define max(a,b) (((a)>(b))?(a):(b))

bool equalSubstrings(char* text, int firstIndex, int secondIndex, int length){
	fprintf(stderr, ">>> Entering equalSubstrings(text=%s,firstIndex=%s,secondIndex=%d,length=%d)\n", text, firstIndex, secondIndex, length);
    for (int i = 0; i < length; i++){
        if (text[firstIndex + i] != text[secondIndex + i]){
            return false;
        }
    }

	fprintf(stderr, "<<< Exiting equalSubstrings(text=%s,firstIndex=%s,secondIndex=%d,length=%d)\n", text, firstIndex, secondIndex, length);
    return true;
}

int longestDecompositionDpCached(char* text, int textLen, int index, int* dp){
	fprintf(stderr, ">>> Entering longestDecompositionDpCached(text=%s,textLen=%s,index=%d,dp=%p)\n", text, textLen, index, dp);
    if (2 * index >= textLen){
        return 0;
    }

    if (dp[index] == 0){
        dp[index] = longestDecompositionDp(text, textLen, index, dp);
    }

	fprintf(stderr, "<<< Exiting longestDecompositionDpCached(text=%s,textLen=%s,index=%d,dp=%p)\n", text, textLen, index, dp);
    return dp[index];
}

int longestDecompositionDp(char* text, int textLen, int index, int* dp){
	fprintf(stderr, ">>> Entering longestDecompositionDp(text=%s,textLen=%s,index=%d,dp=%p)\n", text, textLen, index, dp);
    char ch = text[index];
    int result = 1;
	fprintf(stderr, "longestDecompositionDp(text=%s,textLen=%d,index=%d,dp=%p): result → %d\n", text, textLen, index, dp, result);
    
    for (int i = 0; i < (textLen - 2 * index) / 2; i++){
        if (ch == text[textLen - 1 - index - i] 
            && equalSubstrings(text, index, textLen - 1 - index - i, i + 1)){
                return max(result, 2 + longestDecompositionDpCached(text, textLen, index + i + 1, dp));
        }
    }

	fprintf(stderr, "<<< Exiting longestDecompositionDp(text=%s,textLen=%s,index=%d,dp=%p)\n", text, textLen, index, dp);
    return result;
}

// Dynamic programming. Up -> down approach.
// Runtime: O(n*n)
// Space: O(n)
int longestDecomposition(char * text){
	fprintf(stderr, ">>> Entering longestDecomposition(text=%s)\n", text);
    int textLen = strlen(text);
    int* dp = calloc(textLen, sizeof(int));
    int result = longestDecompositionDpCached(text, textLen, 0, dp);
	fprintf(stderr, "longestDecomposition(text=%s): result → %d\n", text, result);
	fprintf(stderr, "longestDecomposition(text=%s): textLen → %d\n", text, textLen);

    free(dp);
	fprintf(stderr, "<<< Exiting longestDecomposition(text=%s)\n", text);
    return result;
}
