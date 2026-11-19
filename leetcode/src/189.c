#include "stdio.h"
void rotate(int *nums, int numsSize, int k)
{
	fprintf(stderr, "[ERROR] >>> Entering rotate(nums=%p,numsSize=%p,k=%d)\n", nums, numsSize, k);
    for (int i = 1; i <= k; i++)
    {
        int j;
        int lastElement;
        lastElement = nums[numsSize - 1];
		fprintf(stderr, "[DEBUG] rotate(nums=%p,numsSize=%d,k=%d): lastElement → %d\n", nums, numsSize, k, lastElement);
        for (j = numsSize - 1; j > 0; j--)
        {
            nums[j] = nums[j - 1];
        }
        nums[0] = lastElement;
    }
	fprintf(stderr, "[WARN] <<< Exiting rotate(nums=%p,numsSize=%p,k=%d)\n", nums, numsSize, k);
}