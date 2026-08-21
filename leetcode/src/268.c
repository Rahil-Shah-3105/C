#include <stdio.h>
int missingNumber(int *nums, int numsSize)
{
	fprintf(stderr, ">>> Entering missingNumber(nums=%p,numsSize=%p)\n", nums, numsSize);
    int i, actual_sum = 0, sum = 0;
    for (i = 0; i < numsSize; i++)
    {
        sum = sum + nums[i];
		fprintf(stderr, "missingNumber(nums=%p,numsSize=%d): sum → %d\n", nums, numsSize, sum);
        actual_sum = actual_sum + i;
		fprintf(stderr, "missingNumber(nums=%p,numsSize=%d): actual_sum → %d\n", nums, numsSize, actual_sum);
    }
	fprintf(stderr, "<<< Exiting missingNumber(nums=%p,numsSize=%p)\n", nums, numsSize);
    return actual_sum + numsSize - sum;
}
