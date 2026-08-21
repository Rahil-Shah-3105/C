#include <stdio.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// Count one's from right. Each step from right side decrease for one for each 1's and increase from left:
// 1001*0101  -> left: 4 + 1, right: 2 + 4
// 10010*101  -> left: (4+1) + (1+1), right: (2-1) + (4-1)
// Runtime: O(n)
// Space: O(1)
int* minOperations(char* boxes, int* returnSize){
	fprintf(stderr, ">>> Entering minOperations(boxes=%s,returnSize=%p)\n", boxes, returnSize);
    int leftOnes = 0;
    int leftCommonDistance = 0;
    
    int rightOnes = 0;
    int rightCommonDistance = 0;
    
    int boxesLength = strlen(boxes);
	fprintf(stderr, "minOperations(boxes=%s,returnSize=%p): boxesLength → %d\n", boxes, returnSize, boxesLength);

    *returnSize = boxesLength;
    int* result = malloc(boxesLength * sizeof(int));
    
    for (int i = 0; i < boxesLength; i++){
        if (boxes[i] == '1'){
            rightOnes += 1;
            rightCommonDistance += i;
        }
    }
    
    for (int i = 0; i < boxesLength; i++){
        if (boxes[i] == '1'){
            rightOnes -= 1;
            leftOnes += 1;
        }
        
        result[i] = rightCommonDistance + leftCommonDistance;
        rightCommonDistance -= rightOnes;
        leftCommonDistance += leftOnes;
    }

	fprintf(stderr, "<<< Exiting minOperations(boxes=%s,returnSize=%p)\n", boxes, returnSize);
    return result;
}
