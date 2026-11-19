#include "stdio.h"
int singleNumber(int *nums, int numsSize)
{
	fprintf(stderr, "[ERROR] >>> Entering singleNumber(nums=%p,numsSize=%p)\n", nums, numsSize);
    int i, result = 0;
    for (i = 0; i < numsSize; i++) result = result ^ nums[i];
	fprintf(stderr, "[WARN] <<< Exiting singleNumber(nums=%p,numsSize=%p)\n", nums, numsSize);
    return result;
}
