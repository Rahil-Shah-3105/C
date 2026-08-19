#include <stdio.h>
int removeDuplicates(int *nums, int numsSize)
{
	fprintf(stderr, ">>> Entering removeDuplicates(nums=%p,numsSize=%p)\n", nums, numsSize);
    int count = 0, i;
    for (i = 1; i < numsSize; i++)
    {
        if (nums[i] == nums[i - 1])
            count++;
        else
            nums[i - count] = nums[i];
    }
	fprintf(stderr, "<<< Exiting removeDuplicates(nums=%p,numsSize=%p)\n", nums, numsSize);
    return numsSize - count;
}
