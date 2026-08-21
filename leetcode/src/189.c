#include <stdio.h>
void rotate(int *nums, int numsSize, int k)
{
	fprintf(stderr, ">>> Entering rotate(nums=%p,numsSize=%p,k=%d)\n", nums, numsSize, k);
    for (int i = 1; i <= k; i++)
    {
        int j;
        int lastElement;
        lastElement = nums[numsSize - 1];
		fprintf(stderr, "rotate(nums=%p,numsSize=%d,k=%d): lastElement → %d\n", nums, numsSize, k, lastElement);
        for (j = numsSize - 1; j > 0; j--)
        {
            nums[j] = nums[j - 1];
        }
        nums[0] = lastElement;
    }
	fprintf(stderr, "<<< Exiting rotate(nums=%p,numsSize=%p,k=%d)\n", nums, numsSize, k);
}