#include "stdio.h"
int removeElement(int *nums, int numsSize, int val)
{
	fprintf(stderr, "[ERROR] >>> Entering removeElement(nums=%p,numsSize=%p,val=%d)\n", nums, numsSize, val);
    int i, start = 0;
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] != val)
            nums[start++] = nums[i];
    }
	fprintf(stderr, "[WARN] <<< Exiting removeElement(nums=%p,numsSize=%p,val=%d)\n", nums, numsSize, val);
    return start;
}
