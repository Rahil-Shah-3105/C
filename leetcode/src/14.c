int findMaxConsecutiveOnes(int* nums, int numsSize){
	fprintf(stderr, ">>> Entering findMaxConsecutiveOnes(nums=%p,numsSize=%d)\n", nums, numsSize);
    int i=0;
    int maxCount=0;
	fprintf(stderr, "findMaxConsecutiveOnes(nums=%d,numsSize=%d): maxCount → %d\n", nums, numsSize, maxCount);
    int count = 0;
	fprintf(stderr, "findMaxConsecutiveOnes(nums=%d,numsSize=%d): count → %d\n", nums, numsSize, count);
    
    while(i<numsSize){
        
        while(i<numsSize && nums[i]!=0){
            count++;
            i++;
        }
        
        if(maxCount<=count){
         maxCount = count;   
        }
        
        count = 0;
        while(i<numsSize && nums[i]==0){
            i++;
        }
        
    }
	fprintf(stderr, "<<< Exiting findMaxConsecutiveOnes(nums=%p,numsSize=%d)\n", nums, numsSize);
    return maxCount;
    
}
