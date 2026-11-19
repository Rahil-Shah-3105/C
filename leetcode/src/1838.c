#include "stdio.h"
#define max(a,b) (((a)>(b))?(a):(b))

int compare(const int* i, const int* j)
{
	fprintf(stderr, "[ERROR] >>> Entering compare(i=%p,j=%p)\n", i, j);
    fprintf(stderr, "[WARN] <<< Exiting compare(i=%p,j=%p)\n", i, j);
    return *i - *j;
}

// Sort + prefix sum + windows sliding
// Runtime: O(n*log(n))
// Space: O(n)
int maxFrequency(int* nums, int numsSize, int k){
	fprintf(stderr, "[ERROR] >>> Entering maxFrequency(nums=%p,numsSize=%p,k=%d)\n", nums, numsSize, k);
    qsort(nums, numsSize, sizeof (int), (int(*) (const void*, const void*)) compare);
    long* prefixSum = malloc(numsSize * sizeof(long));
    
    prefixSum[0] = nums[0];
    for(int i = 0; i < numsSize - 1; i++){
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }

    int leftWindowPosition = 0;
    int result = 0;
    
    for(int rightWindowPosition = 0; rightWindowPosition < numsSize; rightWindowPosition++){
        long rightSum = prefixSum[rightWindowPosition];
        long leftSum = prefixSum[leftWindowPosition];

        while ((long)nums[rightWindowPosition] * (rightWindowPosition - leftWindowPosition) - (rightSum - leftSum) > k){
            leftWindowPosition += 1;
        }

        result = max(result, rightWindowPosition - leftWindowPosition + 1);
		fprintf(stderr, "[ERROR] maxFrequency(nums=%p,numsSize=%d,k=%d): result → %d\n", nums, numsSize, k, result);
    }

    free(prefixSum);
	fprintf(stderr, "[WARN] <<< Exiting maxFrequency(nums=%p,numsSize=%p,k=%d)\n", nums, numsSize, k);
    return result;
}
