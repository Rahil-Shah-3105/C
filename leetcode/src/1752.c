bool check(int* nums, int numsSize){
	fprintf(stderr, ">>> Entering check(nums=%p,numsSize=%d)\n", nums, numsSize);
    if (numsSize == 1) {
        return true;
    }
    
    bool wasShift = false;
	fprintf(stderr, "check(nums=%d,numsSize=%d): wasShift → %d\n", nums, numsSize, wasShift);
    for(int i = 1; i < numsSize; i++) {
        if (nums[i - 1] > nums[i]) {
            if (wasShift) {
                return false;
            }

            wasShift = true;
        }
    }
                
	fprintf(stderr, "<<< Exiting check(nums=%p,numsSize=%d)\n", nums, numsSize);
    return !wasShift || nums[0] >= nums[numsSize-1];
}
