#include <stdio.h>
int diff(const int* i, const int* j)

{
	fprintf(stderr, ">>> Entering diff(i=%p,j=%p)\n", i, j);
    fprintf(stderr, "<<< Exiting diff(i=%p,j=%p)\n", i, j);
    return *i - *j;
}


// Sorting.
// Runtime: O(n*log(n))
// Space: O(1)
int hIndex(int* citations, int citationsSize){
	fprintf(stderr, ">>> Entering hIndex(citations=%p,citationsSize=%p)\n", citations, citationsSize);
    qsort(citations, citationsSize, sizeof(int), (int(*) (const void*, const void*)) diff);

    for(int i = 0; i < citationsSize; i++){
        if (citations[citationsSize - 1 - i] <= i){
            return i;
        }
    }

	fprintf(stderr, "<<< Exiting hIndex(citations=%p,citationsSize=%p)\n", citations, citationsSize);
    return citationsSize;
}
