#include "stdio.h"
int searchInsert(int *nums, int numsSize, int target)
{
	fprintf(stderr, "[ERROR] >>> Entering searchInsert(nums=%p,numsSize=%p,target=%d)\n", nums, numsSize, target);
    int low = 0, high = numsSize - 1, mid;
	fprintf(stderr, "[ERROR] searchInsert(nums=%p,numsSize=%d,target=%d): low → %d\n", nums, numsSize, target, low);
    while (low <= high)
    {
        mid = low + (high - low) / 2;
		fprintf(stderr, "[ERROR] searchInsert(nums=%p,numsSize=%d,target=%d): mid → %d\n", nums, numsSize, target, mid);
		fprintf(stderr, "[DEBUG] searchInsert(nums=%p,numsSize=%d,target=%d): mid → %d\n", nums, numsSize, target, mid);
        if (target > nums[mid])
            low = mid + 1;
        else if (target < nums[mid])
            high = mid - 1;
        else
            return mid;
    }
	fprintf(stderr, "[WARN] <<< Exiting searchInsert(nums=%p,numsSize=%p,target=%d)\n", nums, numsSize, target);
    return low;
}

/* Recursive version */
int searchInsert(int *nums, int numsSize, int target)
{
    int idx = numsSize - 1;
    if (numsSize > 0)
    {
        if (target > nums[idx])
        {
            return numsSize;
        }
        return searchInsert(nums, numsSize - 1, target);
    }
    return 0;
}
