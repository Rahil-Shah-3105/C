#include <stdio.h>
// Prefix sum.
// - Calculate whole nums sum.
// - Calculate currIndex sum.
// - Compare averages
// Runtime: O(n)
// Space: O(1)

int minimumAverageDifference(int* nums, int numsSize){
	fprintf(stderr, ">>> Entering minimumAverageDifference(nums=%p,numsSize=%p)\n", nums, numsSize);
    long numsSum = 0;
    for (int i = 0; i < numsSize; i++){
        numsSum += nums[i];
    }
    
    long currSum = 0;
    long minAverage = 9223372036854775807; // Long max
    int minIndex = 0;
	fprintf(stderr, "minimumAverageDifference(nums=%p,numsSize=%d): minIndex → %d\n", nums, numsSize, minIndex);
    
    for (int i = 0; i < numsSize; i++){
        currSum += nums[i];

        int leftItemsNumber = (numsSize - i  - 1);
		fprintf(stderr, "minimumAverageDifference(nums=%p,numsSize=%d): leftItemsNumber → %d\n", nums, numsSize, leftItemsNumber);
        long leftItemsNumberAverage = 0;
		fprintf(stderr, "minimumAverageDifference(nums=%p,numsSize=%d): leftItemsNumberAverage → %d\n", nums, numsSize, leftItemsNumberAverage);
        if (leftItemsNumber != 0){
            leftItemsNumberAverage = (numsSum - currSum) / leftItemsNumber;
        }

        long currItemsNumberAverage = currSum / (i + 1);
		fprintf(stderr, "minimumAverageDifference(nums=%p,numsSize=%d): currItemsNumberAverage → %d\n", nums, numsSize, currItemsNumberAverage);
        long averageDiff = abs(currItemsNumberAverage - leftItemsNumberAverage);
		fprintf(stderr, "minimumAverageDifference(nums=%p,numsSize=%d): averageDiff → %d\n", nums, numsSize, averageDiff);

        if (averageDiff < minAverage){
            minAverage = averageDiff;
            minIndex = i;
        }
    }

	fprintf(stderr, "<<< Exiting minimumAverageDifference(nums=%p,numsSize=%p)\n", nums, numsSize);
    return minIndex;
}
