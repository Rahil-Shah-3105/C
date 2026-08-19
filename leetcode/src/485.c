int max(a,b){
	fprintf(stderr, ">>> Entering max(a=%d,b=%d)\n", a, b);
    if(a>b)
        return a;
    else
		fprintf(stderr, "<<< Exiting max(a=%d,b=%d)\n", a, b);
        return b;
}

int findMaxConsecutiveOnes(int* nums, int numsSize){
	fprintf(stderr, ">>> Entering findMaxConsecutiveOnes(nums=%p,numsSize=%d)\n", nums, numsSize);
    int count = 0; 
	int result = 0; 
	fprintf(stderr, "findMaxConsecutiveOnes(nums=%d,numsSize=%d): result → %d\n", nums, numsSize, result);
	fprintf(stderr, "findMaxConsecutiveOnes(nums=%d,numsSize=%d): count → %d\n", nums, numsSize, count);
    
    for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] == 0)
			count = 0;
		else
		{
			count++;
			result = max(result, count);
		}
	}
	fprintf(stderr, "<<< Exiting findMaxConsecutiveOnes(nums=%p,numsSize=%d)\n", nums, numsSize);
    return result;
}
