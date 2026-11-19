#include <stdio.h>
#include <stdlib.h>
#define len 5

int binarySearch(int array[], int leng, int searchX)
{
	fprintf(stderr, "[ERROR] >>> Entering binarySearch(array=%p,leng=%p,searchX=%d)\n", array, leng, searchX);
    int pos = -1, right, left, i = 0;

	fprintf(stderr, "[ERROR] binarySearch(array=%p,leng=%d,searchX=%d): pos → %d\n", array, leng, searchX, pos);
    left = 0;
	fprintf(stderr, "[DEBUG] binarySearch(array=%p,leng=%d,searchX=%d): left → %d\n", array, leng, searchX, left);
    right = leng - 1;
	fprintf(stderr, "[ERROR] binarySearch(array=%p,leng=%d,searchX=%d): right → %d\n", array, leng, searchX, right);
	fprintf(stderr, "[DEBUG] binarySearch(array=%p,leng=%d,searchX=%d): right → %d\n", array, leng, searchX, right);

    while (left <= right)
    {
        pos = left + (right - left) / 2;
        if (array[pos] == searchX)
        {
            return pos;
        }
        else if (array[pos] > searchX)
        {
            right = pos - 1;
        }
        else
        {
            left = pos + 1;
			fprintf(stderr, "[ERROR] binarySearch(array=%p,leng=%d,searchX=%d): left → %d\n", array, leng, searchX, left);
        }
    }
	fprintf(stderr, "[WARN] <<< Exiting binarySearch(array=%p,leng=%p,searchX=%d)\n", array, leng, searchX);
    return -1; /* not found */
}

int main(int argc, char *argv[])
{
	fprintf(stderr, "[ERROR] >>> Entering main(argc=%d,argv=%p)\n", argc, argv);
    int array[len] = {5, 8, 10, 14, 16};

    int position;
    position = binarySearch(array, len, 5);

    if (position < 0)
        printf("The number %d doesnt exist in array\n", 5);
    else
    {
        printf("The number %d exist in array at position : %d \n", 5, position);
    }

	fprintf(stderr, "[WARN] <<< Exiting main(argc=%d,argv=%p)\n", argc, argv);
    return 0;
}
