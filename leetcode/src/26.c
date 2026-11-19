#include "stdio.h"
int removeDuplicates(int *nums, int numsSize)
{
	fprintf(stderr, "[ERROR] >>> Entering removeDuplicates(nums=%p,numsSize=%p)\n", nums, numsSize);
    int count = 0, i;
	fprintf(stderr, "[ERROR] removeDuplicates(nums=%p,numsSize=%d): count → %d\n", nums, numsSize, count);
    for (i = 1; i < numsSize; i++)
    {
        if (nums[i] == nums[i - 1])
            count++;
        else
            nums[i - count] = nums[i];
    }
	fprintf(stderr, "[WARN] <<< Exiting removeDuplicates(nums=%p,numsSize=%p)\n", nums, numsSize);
    return numsSize - count;
}
