#include <stdio.h>
// Window sliding. Runtime: O(n), Space: O(n)
int maximumUniqueSubarray(int* nums, int numsSize){
	fprintf(stderr, ">>> Entering maximumUniqueSubarray(nums=%p,numsSize=%p)\n", nums, numsSize);
    short* numsSet = (short*)calloc(10001, sizeof(short));
    numsSet[nums[0]] = 1;

    int maxSum = nums[0];
	fprintf(stderr, "maximumUniqueSubarray(nums=%p,numsSize=%d): maxSum → %d\n", nums, numsSize, maxSum);

    int windowSumm = maxSum;
    int leftIndex = 0;
    
    int num = 0;
	fprintf(stderr, "maximumUniqueSubarray(nums=%p,numsSize=%d): num → %d\n", nums, numsSize, num);
    for(int i = 1; i < numsSize; i++){
        num = nums[i];
        while (numsSet[num] != 0){
            numsSet[nums[leftIndex]] = 0;
            windowSumm -= nums[leftIndex];
            leftIndex++;
        }
        
        numsSet[num] = 1;
        windowSumm += num;
            
        if (maxSum < windowSumm){
            maxSum = windowSumm;
        }
    }
    
	fprintf(stderr, "<<< Exiting maximumUniqueSubarray(nums=%p,numsSize=%p)\n", nums, numsSize);
    return maxSum;
}
