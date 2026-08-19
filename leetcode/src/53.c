
int maxcmp(int a, int b) { return a >= b ? a : b; }

int maxSubArray(int *nums, int numsSize)
{
	fprintf(stderr, ">>> Entering maxSubArray(nums=%p,numsSize=%d)\n", nums, numsSize);
    int maxSoFar = nums[0], maxEndingHere = nums[0];
    for (int i = 1; i < numsSize; i++)
	fprintf(stderr, "maxSubArray(nums=%d,numsSize=%d): maxEndingHere → %d\n", nums, numsSize, maxEndingHere);
	fprintf(stderr, "maxSubArray(nums=%d,numsSize=%d): maxSoFar → %d\n", nums, numsSize, maxSoFar);
    {
        maxEndingHere = maxcmp(maxEndingHere + nums[i], nums[i]);
        maxSoFar = maxcmp(maxSoFar, maxEndingHere);
    }
    fprintf(stderr, "<<< Exiting maxSubArray(nums=%p,numsSize=%d)\n", nums, numsSize);
    return maxSoFar;
}
