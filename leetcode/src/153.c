int findMin(int *nums, int numsSize)
{
	fprintf(stderr, ">>> Entering findMin(nums=%p,numsSize=%d)\n", nums, numsSize);
    int low = 0, high = numsSize - 1;
    while (low < high)
	fprintf(stderr, "findMin(nums=%d,numsSize=%d): low → %d\n", nums, numsSize, low);
    {
        int mid = low + (high - low) / 2;
		fprintf(stderr, "findMin(nums=%d,numsSize=%d): mid → %d\n", nums, numsSize, mid);
        /* minimum is on left side */
        if (nums[mid] < nums[high])
            high = mid;
			fprintf(stderr, "findMin(nums=%d,numsSize=%d): high → %d\n", nums, numsSize, high);
        /* minimum is on right side */
        else
            low = mid + 1;
    }
	fprintf(stderr, "<<< Exiting findMin(nums=%p,numsSize=%d)\n", nums, numsSize);
    return nums[low];
}
