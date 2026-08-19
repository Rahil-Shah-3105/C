int singleNumber(int *nums, int numsSize)
{
	fprintf(stderr, ">>> Entering singleNumber(nums=%p,numsSize=%d)\n", nums, numsSize);
    int i, result = 0;
    for (i = 0; i < numsSize; i++) result = result ^ nums[i];
	fprintf(stderr, "<<< Exiting singleNumber(nums=%p,numsSize=%d)\n", nums, numsSize);
    return result;
}
