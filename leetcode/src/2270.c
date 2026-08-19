#include <stdio.h>
// Prefix sum.
// Collect sum fromleft part and compare it with left sum.
// Runtime: O(n)
// Space: O(1)
int waysToSplitArray(int* nums, int numsSize){
	fprintf(stderr, ">>> Entering waysToSplitArray(nums=%p,numsSize=%p)\n", nums, numsSize);
    long sumNums = 0;
    for (int i = 0; i < numsSize; i++){
        sumNums += nums[i];
    }
    
    long prefixSum = 0;
    int result = 0;
	fprintf(stderr, "waysToSplitArray(nums=%p,numsSize=%d): result → %d\n", nums, numsSize, result);
    for (int i = 0; i < numsSize - 1; i++){
        prefixSum += nums[i];
        if (prefixSum >= sumNums - prefixSum){
            result += 1;
        }
    }

	fprintf(stderr, "<<< Exiting waysToSplitArray(nums=%p,numsSize=%p)\n", nums, numsSize);
    return result;
}
