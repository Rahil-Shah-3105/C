#include "stdio.h"

int maxcmp(int a, int b) { return a >= b ? a : b; }

int maxSubArray(int *nums, int numsSize)
{
	fprintf(stderr, "[ERROR] >>> Entering maxSubArray(nums=%p,numsSize=%p)\n", nums, numsSize);
    int maxSoFar = nums[0], maxEndingHere = nums[0];
	fprintf(stderr, "[ERROR] maxSubArray(nums=%p,numsSize=%d): maxEndingHere → %d\n", nums, numsSize, maxEndingHere);
    for (int i = 1; i < numsSize; i++)
    {
		fprintf(stderr, "[ERROR] maxSubArray(nums=%p,numsSize=%d): maxSoFar → %d\n", nums, numsSize, maxSoFar);
        maxEndingHere = maxcmp(maxEndingHere + nums[i], nums[i]);
        maxSoFar = maxcmp(maxSoFar, maxEndingHere);
    }
	fprintf(stderr, "[DEBUG] maxSubArray(nums=%p,numsSize=%d): maxEndingHere → %d\n", nums, numsSize, maxEndingHere);
    fprintf(stderr, "[WARN] <<< Exiting maxSubArray(nums=%p,numsSize=%p)\n", nums, numsSize);
    return maxSoFar;
}
