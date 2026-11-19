#include "stdio.h"
int max(a,b){
	fprintf(stderr, "[ERROR] >>> Entering max(a=%d,b=%d)\n", a, b);
    if(a>b)
        return a;
    else
        return b;
}

int findMaxConsecutiveOnes(int* nums, int numsSize){
	fprintf(stderr, "[ERROR] >>> Entering findMaxConsecutiveOnes(nums=%p,numsSize=%p)\n", nums, numsSize);
    int count = 0; 
	int result = 0; 
    
    for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] == 0)
			count = 0;
		else
		{
			fprintf(stderr, "[ERROR] findMaxConsecutiveOnes(nums=%p,numsSize=%d): count → %d\n", nums, numsSize, count);
			count++;
			result = max(result, count);
			fprintf(stderr, "[ERROR] findMaxConsecutiveOnes(nums=%p,numsSize=%d): result → %d\n", nums, numsSize, result);
		}
	}
	fprintf(stderr, "[WARN] <<< Exiting findMaxConsecutiveOnes(nums=%p,numsSize=%p)\n", nums, numsSize);
    return result;
}
