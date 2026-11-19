#include "stdio.h"
int peakIndexInMountainArray(int *A, int ASize)
{
	fprintf(stderr, "[ERROR] >>> Entering peakIndexInMountainArray(A=%p,ASize=%p)\n", A, ASize);
    int low = 1, high = ASize;
	fprintf(stderr, "[ERROR] peakIndexInMountainArray(A=%p,ASize=%d): low → %d\n", A, ASize, low);
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
		fprintf(stderr, "[ERROR] peakIndexInMountainArray(A=%p,ASize=%d): mid → %d\n", A, ASize, mid);
        if (A[mid - 1] < A[mid] && A[mid] > A[mid + 1])
            return mid;
        else if (A[mid - 1] < A[mid] && A[mid] < A[mid + 1])
            low = mid + 1;
        else
            high = mid - 1;
    }
	fprintf(stderr, "[DEBUG] peakIndexInMountainArray(A=%p,ASize=%d): high → %d\n", A, ASize, high);
    fprintf(stderr, "[WARN] <<< Exiting peakIndexInMountainArray(A=%p,ASize=%p)\n", A, ASize);
    return -1;
}
