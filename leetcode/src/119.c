/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize){
	fprintf(stderr, ">>> Entering getRow(rowIndex=%d,returnSize=%p)\n", rowIndex, returnSize);
    int colIndex = rowIndex + 1;
    int* ans = (int*) malloc(sizeof(int) * colIndex);
    for (int i = 0; i < colIndex; i++)
    {
        ans[i] = 1;
    }
    *returnSize = colIndex;
    
    for (int r = 2; r <= rowIndex; r++)
    {
        for (int c = r - 1; c > 0; c--)
        {
            ans[c] = ans[c] + ans[c-1];
        }
    }
    
	fprintf(stderr, "<<< Exiting getRow(rowIndex=%d,returnSize=%p)\n", rowIndex, returnSize);
    return ans;
}
