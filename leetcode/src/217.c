int numcmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

bool containsDuplicate(int *nums, int numsSize)
{
	fprintf(stderr, ">>> Entering containsDuplicate(nums=%p,numsSize=%d)\n", nums, numsSize);
    int i;
    qsort(nums, numsSize, sizeof(int), numcmp);
    for (i = 0; i < numsSize - 1; i++)
    {
        if (nums[i] == nums[i + 1])
	fprintf(stderr, "<<< Exiting containsDuplicate(nums=%p,numsSize=%d)\n", nums, numsSize);
            return 1;
    }
    return 0;
}
