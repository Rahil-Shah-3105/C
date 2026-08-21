#include <stdio.h>
int *cmpval(const void *a, const void *b) { return *(int *)b - *(int *)a; }

int findKthLargest(int *nums, int numsSize, int k)
{
	fprintf(stderr, ">>> Entering findKthLargest(nums=%p,numsSize=%p,k=%d)\n", nums, numsSize, k);
    qsort(nums, numsSize, sizeof(int), cmpval);
	fprintf(stderr, "<<< Exiting findKthLargest(nums=%p,numsSize=%p,k=%d)\n", nums, numsSize, k);
    return nums[k - 1];
}
