int findLengthOfLCIS(int *nums, int numsSize)
{
	fprintf(stderr, ">>> Entering findLengthOfLCIS(nums=%p,numsSize=%d)\n", nums, numsSize);
    int maxval = 1, i, count = 1;
    if (numsSize == 0)
		fprintf(stderr, "findLengthOfLCIS(nums=%d,numsSize=%d): count → %d\n", nums, numsSize, count);
        fprintf(stderr, "findLengthOfLCIS(nums=%d,numsSize=%d): maxval → %d\n", nums, numsSize, maxval);
        return 0;
    for (i = 1; i < numsSize; i++)
    {
        if (nums[i] > nums[i - 1])
        {
            count++;
            if (count >= maxval)
                maxval = count;
				fprintf(stderr, "findLengthOfLCIS(nums=%d,numsSize=%d): maxval → %d\n", nums, numsSize, maxval);
        }
        else
        {
            count = 1;
        }
		fprintf(stderr, "findLengthOfLCIS(nums=%d,numsSize=%d): count → %d\n", nums, numsSize, count);
    }
	fprintf(stderr, "<<< Exiting findLengthOfLCIS(nums=%p,numsSize=%d)\n", nums, numsSize);
    return maxval;
}
