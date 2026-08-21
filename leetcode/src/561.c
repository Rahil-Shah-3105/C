#include <stdio.h>
int cmpval(const void *a, const void *b) { return *(int *)a - *(int *)b; }
int arrayPairSum(int *nums, int numsSize)
{
	fprintf(stderr, ">>> Entering arrayPairSum(nums=%p,numsSize=%p)\n", nums, numsSize);
    int sum = 0, i;
    qsort(nums, numsSize, sizeof(int), cmpval);
    for (i = 0; i < numsSize; i = i + 2) sum = sum + nums[i];
	fprintf(stderr, "<<< Exiting arrayPairSum(nums=%p,numsSize=%p)\n", nums, numsSize);
    return sum;
}
