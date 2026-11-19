#include "stdio.h"
int search(int *nums, int numsSize, int target)
{
	fprintf(stderr, "[ERROR] >>> Entering search(nums=%p,numsSize=%p,target=%d)\n", nums, numsSize, target);
    int low = 0, high = numsSize - 1;
	fprintf(stderr, "[ERROR] search(nums=%p,numsSize=%d,target=%d): low → %d\n", nums, numsSize, target, low);
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
		fprintf(stderr, "[ERROR] search(nums=%p,numsSize=%d,target=%d): mid → %d\n", nums, numsSize, target, mid);
        if (target > nums[mid])
        {
            low = mid + 1;
        }
        else if (target < nums[mid])
        {
            high = mid - 1;
			fprintf(stderr, "[DEBUG] search(nums=%p,numsSize=%d,target=%d): high → %d\n", nums, numsSize, target, high);
        }
        else
        {
            return mid;
        }
    }
	fprintf(stderr, "[WARN] <<< Exiting search(nums=%p,numsSize=%p,target=%d)\n", nums, numsSize, target);
    return -1;
}

/* Another solution: Using bsearch() */
int cmpint(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int search(int *nums, int numsSize, int target)
{
    int *ret = bsearch(&target, nums, numsSize, sizeof(int), cmpint);
    if (ret)
        return (ret - nums);
    else
        return -1;
}
