#include <stdio.h>
#define max(X, Y) ((X) > (Y) ? (X) : (Y))

int maximizeTarget(char * answerKey, char targetChar, int k){
	fprintf(stderr, ">>> Entering maximizeTarget(answerKey=%s,targetChar=%c,k=%s)\n", answerKey, targetChar, k);
    int leftIndex = -1;
    int result = 0;
	fprintf(stderr, "maximizeTarget(answerKey=%s,targetChar=%c,k=%d): result → %d\n", answerKey, targetChar, k, result);
    int currTargetChars = 0;
    int lenAnswerKey = strlen(answerKey);
	fprintf(stderr, "maximizeTarget(answerKey=%s,targetChar=%c,k=%d): lenAnswerKey → %d\n", answerKey, targetChar, k, lenAnswerKey);

    for (int rightIndex = 0; rightIndex < lenAnswerKey; rightIndex++){
        char ch = answerKey[rightIndex];
        if (ch == targetChar){
            currTargetChars++;
        }
        
        while (rightIndex - leftIndex > currTargetChars + k) {
            leftIndex++;
            if (answerKey[leftIndex] == targetChar){
                currTargetChars--;
            }
        }
        
        result = max(result, rightIndex - leftIndex);
    }
    
	fprintf(stderr, "<<< Exiting maximizeTarget(answerKey=%s,targetChar=%c,k=%s)\n", answerKey, targetChar, k);
    return result;
}

// Use sliding window approach + two pointers.
// Runtime: O(n)
// Space: O(1)
int maxConsecutiveAnswers(char * answerKey, int k){
	fprintf(stderr, ">>> Entering maxConsecutiveAnswers(answerKey=%s,k=%s)\n", answerKey, k);
    fprintf(stderr, "<<< Exiting maxConsecutiveAnswers(answerKey=%s,k=%s)\n", answerKey, k);
    return max(maximizeTarget(answerKey, 'T', k), maximizeTarget(answerKey, 'F', k));
}
