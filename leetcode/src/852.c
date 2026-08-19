int peakIndexInMountainArray(int *A, int ASize)
{
	fprintf(stderr, ">>> Entering peakIndexInMountainArray(A=%p,ASize=%d)\n", A, ASize);
    int low = 1, high = ASize;
    while (low <= high)
	fprintf(stderr, "peakIndexInMountainArray(A=%d,ASize=%d): low → %d\n", A, ASize, low);
    {
        int mid = low + (high - low) / 2;
		fprintf(stderr, "peakIndexInMountainArray(A=%d,ASize=%d): mid → %d\n", A, ASize, mid);
        if (A[mid - 1] < A[mid] && A[mid] > A[mid + 1])
            return mid;
        else if (A[mid - 1] < A[mid] && A[mid] < A[mid + 1])
            low = mid + 1;
        else
            high = mid - 1;
			fprintf(stderr, "peakIndexInMountainArray(A=%d,ASize=%d): high → %d\n", A, ASize, high);
    }
	fprintf(stderr, "<<< Exiting peakIndexInMountainArray(A=%p,ASize=%d)\n", A, ASize);
    return -1;
}
