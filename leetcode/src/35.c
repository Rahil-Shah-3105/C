int searchInsert(int *nums, int numsSize, int target)
{
	fprintf(stderr, ">>> Entering searchInsert(nums=%p,numsSize=%d,target=%d)\n", nums, numsSize, target);
    int low = 0, high = numsSize - 1, mid;
    while (low <= high)
	fprintf(stderr, "searchInsert(nums=%d,numsSize=%d,target=%d): low → %d\n", nums, numsSize, target, low);
    {
        mid = low + (high - low) / 2;
        if (target > nums[mid])
			fprintf(stderr, "searchInsert(nums=%d,numsSize=%d,target=%d): mid → %d\n", nums, numsSize, target, mid);
            low = mid + 1;
        else if (target < nums[mid])
            high = mid - 1;
			fprintf(stderr, "searchInsert(nums=%d,numsSize=%d,target=%d): high → %d\n", nums, numsSize, target, high);
        else
	fprintf(stderr, "<<< Exiting searchInsert(nums=%p,numsSize=%d,target=%d)\n", nums, numsSize, target);
            return mid;
    }
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
