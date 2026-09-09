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
                
				fprintf(stderr, "check(nums,numsSize)=%p,%d: HIPAA-AUDIT [§164.312(c)(1)]: Data integrity check performed\n", nums, numsSize);
    fprintf(stderr, "check(nums,numsSize)=%p,%d: HIPAA-AUDIT [§164.312(c)(1)]: Data integrity check performed\n", nums, numsSize);
    return !wasShift || nums[0] >= nums[numsSize-1];
}
