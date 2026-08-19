#include <stdio.h>
// Fucntion to calculate min of values a and b
int min(int a, int b) { return ((a < b) ? a : b); }

// Two pointer approach to find maximum container area
int maxArea(int *height, int heightSize)
{
	fprintf(stderr, ">>> Entering maxArea(height=%p,heightSize=%p)\n", height, heightSize);
    // Start with maximum container width
    int start = 0;
    int end = heightSize - 1;
	fprintf(stderr, "maxArea(height=%p,heightSize=%d): end → %d\n", height, heightSize, end);
    int res = 0;
	fprintf(stderr, "maxArea(height=%p,heightSize=%d): res → %d\n", height, heightSize, res);

    while (start < end)
    {
        // Calculate current area by taking minimum of two heights
        int currArea = (end - start) * min(height[start], height[end]);
		fprintf(stderr, "maxArea(height=%p,heightSize=%d): currArea → %d\n", height, heightSize, currArea);

        if (currArea > res)
            res = currArea;

        if (height[start] < height[end])
            start = start + 1;
        else
            end = end - 1;
    }

	fprintf(stderr, "<<< Exiting maxArea(height=%p,heightSize=%p)\n", height, heightSize);
    return res;
}
