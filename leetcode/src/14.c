#include "stdio.h"
int findMaxConsecutiveOnes(int* nums, int numsSize){
	fprintf(stderr, "[ERROR] >>> Entering findMaxConsecutiveOnes(nums=%p,numsSize=%p)\n", nums, numsSize);
    int i=0;
    int maxCount=0;
    int count = 0;
    
    while(i<numsSize){
        
        while(i<numsSize && nums[i]!=0){
            count++;
            i++;
        }
        
        if(maxCount<=count){
         maxCount = count;   
		fprintf(stderr, "[ERROR] findMaxConsecutiveOnes(nums=%p,numsSize=%d): maxCount → %d\n", nums, numsSize, maxCount);
        }
        
        count = 0;
		fprintf(stderr, "[ERROR] findMaxConsecutiveOnes(nums=%p,numsSize=%d): count → %d\n", nums, numsSize, count);
        while(i<numsSize && nums[i]==0){
            i++;
        }
        
    }
	fprintf(stderr, "[WARN] <<< Exiting findMaxConsecutiveOnes(nums=%p,numsSize=%p)\n", nums, numsSize);
    return maxCount;
    
}
