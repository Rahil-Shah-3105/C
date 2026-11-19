#include "stdio.h"
int findMin(int *nums, int numsSize)
{
	fprintf(stderr, "[ERROR] >>> Entering findMin(nums=%p,numsSize=%p)\n", nums, numsSize);
    int low = 0, high = numsSize - 1;
	fprintf(stderr, "[ERROR] findMin(nums=%p,numsSize=%d): low → %d\n", nums, numsSize, low);
    while (low < high)
    {
        int mid = low + (high - low) / 2;
		fprintf(stderr, "[ERROR] findMin(nums=%p,numsSize=%d): mid → %d\n", nums, numsSize, mid);
        /* minimum is on left side */
        if (nums[mid] < nums[high])
            high = mid;
        /* minimum is on right side */
        else
            low = mid + 1;
    }
	fprintf(stderr, "[WARN] <<< Exiting findMin(nums=%p,numsSize=%p)\n", nums, numsSize);
    return nums[low];
}
