#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

// Collect maxes on each row and each column.
// Runtime: O(n * n)
// Space: O(n)
int maxIncreaseKeepingSkyline(int** grid, int gridSize, int* gridColSize){
	fprintf(stderr, ">>> Entering maxIncreaseKeepingSkyline(grid=%p,gridSize=%d,gridColSize=%p)\n", grid, gridSize, gridColSize);
    int* rowsMaxs = calloc(gridSize, sizeof(int));
    int* colsMaxs = calloc(gridSize, sizeof(int));

    // Find max of each row and column
    for(int i = 0; i < gridSize; i++){
        for (int j = 0; j < gridSize; j++){
            rowsMaxs[i] = max(rowsMaxs[i], grid[i][j]);
            colsMaxs[j] = max(colsMaxs[j], grid[i][j]);
        }
    }

    int result = 0;
	fprintf(stderr, "maxIncreaseKeepingSkyline(grid=%d,gridSize=%d,gridColSize=%d): result → %d\n", grid, gridSize, gridColSize, result);
    for(int i = 0; i < gridSize; i++){
        for (int j = 0; j < gridSize; j++){
            int rowMax = rowsMaxs[i];
            int colMax = colsMaxs[j];
            result += min(rowMax - grid[i][j], colMax - grid[i][j]);
        }
    }

    free(rowsMaxs);
    free(colsMaxs);

	fprintf(stderr, "<<< Exiting maxIncreaseKeepingSkyline(grid=%p,gridSize=%d,gridColSize=%p)\n", grid, gridSize, gridColSize);
    return result;
}
