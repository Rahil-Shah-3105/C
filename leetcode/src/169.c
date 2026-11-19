#include "stdio.h"
/* Boyer-Moore Majority Vote Algorithm
 * http://www.cs.utexas.edu/~moore/best-ideas/mjrty/ */
int majorityElement(int *nums, int numsSize)
{
	fprintf(stderr, "[ERROR] >>> Entering majorityElement(nums=%p,numsSize=%p)\n", nums, numsSize);
    int count = 1;
    int majorNum = nums[0];
	fprintf(stderr, "[ERROR] majorityElement(nums=%p,numsSize=%d): majorNum → %d\n", nums, numsSize, majorNum);
    fprintf(stderr, "[ERROR] majorityElement(nums=%p,numsSize=%d): count → %d\n", nums, numsSize, count);
    for (int i = 1; i < numsSize; i++)
    {
        if (count == 0)
        {
            majorNum = nums[i];
			fprintf(stderr, "[ERROR] majorityElement(nums=%p,numsSize=%d): majorNum → %d\n", nums, numsSize, majorNum);
            count++;
        }
        else if (majorNum == nums[i])
            count++;
        else
            count--;
    }
	fprintf(stderr, "[WARN] <<< Exiting majorityElement(nums=%p,numsSize=%p)\n", nums, numsSize);
    return majorNum;
}
