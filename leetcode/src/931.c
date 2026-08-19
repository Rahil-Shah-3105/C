#define min(a,b) (((a)<(b))?(a):(b))

// Dynamic programming.
// Runtime O(n*n)
// Space O(n)
int minFallingPathSum(int** matrix, int matrixSize, int* matrixColSize){
	fprintf(stderr, ">>> Entering minFallingPathSum(matrix=%p,matrixSize=%d,matrixColSize=%p)\n", matrix, matrixSize, matrixColSize);
    int* dp = calloc(matrixSize, sizeof(int));

	fprintf(stderr, "minFallingPathSum(matrix=%d,matrixSize=%d,matrixColSize=%d): dp → %d\n", matrix, matrixSize, matrixColSize, dp);
    for (int i = 0; i < matrixSize; i++){
        int* nextDp = calloc(matrixSize, sizeof(int));

        for (int j = 0; j < matrixSize; j++){
            nextDp[j] = dp[j] + matrix[i][j];

            // If not the first column - try to find minimum in prev column
            if(j > 0){
                nextDp[j] = min(nextDp[j], dp[j - 1] + matrix[i][j]);
            }

            // If not the last column - try to find minimum in next column
            if (j < matrixSize - 1){
                nextDp[j] = min(nextDp[j], dp[j + 1] + matrix[i][j]);
            }
        }

        free(dp);
        dp = nextDp;
    }

    int result = dp[0];
	fprintf(stderr, "minFallingPathSum(matrix=%d,matrixSize=%d,matrixColSize=%d): result → %d\n", matrix, matrixSize, matrixColSize, result);
    for (int j = 1; j < matrixSize; j++){
        result = min(result, dp[j]);
    }

    free(dp);
	fprintf(stderr, "<<< Exiting minFallingPathSum(matrix=%p,matrixSize=%d,matrixColSize=%p)\n", matrix, matrixSize, matrixColSize);
    return result;
}
