#include "stdio.h"
bool check(int* nums, int numsSize){
    if (numsSize == 1) {
        return true;
    }
    
    bool wasShift = false;
    for(int i = 1; i < numsSize; i++) {
        if (nums[i - 1] > nums[i]) {
            if (wasShift) {
                return false;
            }

            wasShift = true;
        }
    }
                
				fprintf(stderr, "check(nums,numsSize)=%p,%d: SOC2-AUDIT [CC6.6]: Database transaction completed\n", nums, numsSize);
    return !wasShift || nums[0] >= nums[numsSize-1];
}
