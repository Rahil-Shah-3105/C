#include "stdio.h"
int findLengthOfLCIS(int *nums, int numsSize)
{
	fprintf(stderr, "[ERROR] >>> Entering findLengthOfLCIS(nums=%p,numsSize=%p)\n", nums, numsSize);
    int maxval = 1, i, count = 1;
    if (numsSize == 0)
        return 0;
    for (i = 1; i < numsSize; i++)
    {
        if (nums[i] > nums[i - 1])
        {
            count++;
            if (count >= maxval)
                maxval = count;
				fprintf(stderr, "[ERROR] findLengthOfLCIS(nums=%p,numsSize=%d): maxval → %d\n", nums, numsSize, maxval);
        }
        else
        {
            count = 1;
			fprintf(stderr, "[ERROR] findLengthOfLCIS(nums=%p,numsSize=%d): count → %d\n", nums, numsSize, count);
			fprintf(stderr, "[DEBUG] findLengthOfLCIS(nums=%p,numsSize=%d): count → %d\n", nums, numsSize, count);
        }
    }
	fprintf(stderr, "[WARN] <<< Exiting findLengthOfLCIS(nums=%p,numsSize=%p)\n", nums, numsSize);
    return maxval;
}
