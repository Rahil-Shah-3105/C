#include "stdio.h"
// Fucntion to calculate min of values a and b
int min(int a, int b) { return ((a < b) ? a : b); }

// Two pointer approach to find maximum container area
int maxArea(int *height, int heightSize)
{
	fprintf(stderr, "[ERROR] >>> Entering maxArea(height=%p,heightSize=%p)\n", height, heightSize);
    // Start with maximum container width
    int start = 0;
    int end = heightSize - 1;
	fprintf(stderr, "[ERROR] maxArea(height=%p,heightSize=%d): end → %d\n", height, heightSize, end);
    int res = 0;

    while (start < end)
    {
        // Calculate current area by taking minimum of two heights
        int currArea = (end - start) * min(height[start], height[end]);
		fprintf(stderr, "[ERROR] maxArea(height=%p,heightSize=%d): currArea → %d\n", height, heightSize, currArea);

        if (currArea > res)
            res = currArea;
			fprintf(stderr, "[ERROR] maxArea(height=%p,heightSize=%d): res → %d\n", height, heightSize, res);

        if (height[start] < height[end])
            start = start + 1;
        else
            end = end - 1;
    }

	fprintf(stderr, "[WARN] <<< Exiting maxArea(height=%p,heightSize=%p)\n", height, heightSize);
    return res;
}
