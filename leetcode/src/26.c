int removeDuplicates(int *nums, int numsSize)
{
	fprintf(stderr, ">>> Entering removeDuplicates(nums=%p,numsSize=%d)\n", nums, numsSize);
    int count = 0, i;
    for (i = 1; i < numsSize; i++)
	fprintf(stderr, "removeDuplicates(nums=%d,numsSize=%d): count → %d\n", nums, numsSize, count);
    {
        if (nums[i] == nums[i - 1])
            count++;
        else
            nums[i - count] = nums[i];
    }
	fprintf(stderr, "<<< Exiting removeDuplicates(nums=%p,numsSize=%d)\n", nums, numsSize);
    return numsSize - count;
}
