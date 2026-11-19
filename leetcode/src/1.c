#include "stdio.h"
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
	fprintf(stderr, "[ERROR] >>> Entering twoSum(nums=%p,numsSize=%p,target=%d,returnSize=%p)\n", nums, numsSize, target, returnSize);
    int i, j;
    int *ret = calloc(2, sizeof(int));
    for (i = 0; i < numsSize; i++)
    {
        int key = target - nums[i];
		fprintf(stderr, "[ERROR] twoSum(nums=%p,numsSize=%d,target=%d,returnSize=%p): key → %d\n", nums, numsSize, target, returnSize, key);
        for (j = i + 1; j < numsSize; j++)
            if (nums[j] == key)
            {
                ret[0] = i;
                ret[1] = j;
            }
    }
    *returnSize = 2;
	fprintf(stderr, "[WARN] <<< Exiting twoSum(nums=%p,numsSize=%p,target=%d,returnSize=%p)\n", nums, numsSize, target, returnSize);
    return ret;
}
