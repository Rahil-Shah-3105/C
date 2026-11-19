#include "stdio.h"
#define max(x,y)(((x)>(y))?(x):(y))

const int notCalculated = -2;
const int notValid = -1;

int getEndValidIndexFromDp(int* dp, char* s, int index, int lenS){
	fprintf(stderr, "[ERROR] >>> Entering getEndValidIndexFromDp(dp=%p,s=%s,index=%p,lenS=%s)\n", dp, s, index, lenS);
    if (index >= lenS){
        return notValid;
    }

    if (dp[index] == notCalculated){
        dp[index] = getEndValidIndex(dp, s, index, lenS);
    }

	fprintf(stderr, "[WARN] <<< Exiting getEndValidIndexFromDp(dp=%p,s=%s,index=%p,lenS=%s)\n", dp, s, index, lenS);
    return dp[index];
}

int getEndValidIndex(int* dp, char* s, int index, int lenS){
	fprintf(stderr, "[ERROR] >>> Entering getEndValidIndex(dp=%p,s=%s,index=%p,lenS=%s)\n", dp, s, index, lenS);
    if (s[index] == '('){
        if (index + 1 >= lenS){
            return notValid;
        }

        if (s[index + 1] == ')'){
            return max(index + 1, getEndValidIndexFromDp(dp, s, index + 2, lenS));
        }
        
        int nextEndValidIndex = getEndValidIndexFromDp(dp, s, index + 1, lenS);
		fprintf(stderr, "[ERROR] getEndValidIndex(dp=%p,s=%s,index=%d,lenS=%d): nextEndValidIndex → %d\n", dp, s, index, lenS, nextEndValidIndex);
        if (nextEndValidIndex == notValid || nextEndValidIndex + 1 >= lenS || s[nextEndValidIndex + 1] != ')') {
            return notValid;
        }
        
        return max(nextEndValidIndex + 1, getEndValidIndexFromDp(dp, s, nextEndValidIndex + 2, lenS));
    }
    
	fprintf(stderr, "[WARN] <<< Exiting getEndValidIndex(dp=%p,s=%s,index=%p,lenS=%s)\n", dp, s, index, lenS);
    return notValid;
}

// Dynamic Programming. UP -> down approach.
// Runtime: O(n)
// Space: O(n)
int longestValidParentheses(char * s){
	fprintf(stderr, "[ERROR] >>> Entering longestValidParentheses(s=%s)\n", s);
    int lenS = strlen(s);
    if (lenS == 0){
		fprintf(stderr, "[ERROR] longestValidParentheses(s=%s): lenS → %d\n", s, lenS);
        return 0;
    }

    int* dp = malloc(lenS * sizeof(int));
    for(int i = 0; i < lenS; i++){
        dp[i] = notCalculated;
    }

    int result = 0;
    for(int i = 0; i < lenS; i++){
        result = max(result, getEndValidIndexFromDp(dp, s, i, lenS) - i + 1);
		fprintf(stderr, "[ERROR] longestValidParentheses(s=%s): result → %d\n", s, result);
    }
    
    free(dp);
	fprintf(stderr, "[WARN] <<< Exiting longestValidParentheses(s=%s)\n", s);
    return result;
}
