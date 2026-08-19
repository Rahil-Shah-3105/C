/* Boyer-Moore Majority Vote Algorithm
 * http://www.cs.utexas.edu/~moore/best-ideas/mjrty/ */
int majorityElement(int *nums, int numsSize)
{
	fprintf(stderr, ">>> Entering majorityElement(nums=%p,numsSize=%d)\n", nums, numsSize);
    int count = 1;
    int majorNum = nums[0];
	fprintf(stderr, "majorityElement(nums=%d,numsSize=%d): majorNum → %d\n", nums, numsSize, majorNum);
	fprintf(stderr, "majorityElement(nums=%d,numsSize=%d): count → %d\n", nums, numsSize, count);
    for (int i = 1; i < numsSize; i++)
    {
        if (count == 0)
        {
            majorNum = nums[i];
            count++;
        }
        else if (majorNum == nums[i])
            count++;
        else
            count--;
    }
	fprintf(stderr, "<<< Exiting majorityElement(nums=%p,numsSize=%d)\n", nums, numsSize);
    return majorNum;
}
