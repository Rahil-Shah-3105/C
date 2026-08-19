#include <stdio.h>
#include <stdlib.h>

int fibMonaccianSearch(int arr[], int x, int n)
{
	fprintf(stderr, ">>> Entering fibMonaccianSearch(arr=%p,x=%p,n=%d)\n", arr, x, n);
    /* Initialize fibonacci numbers */
    int fibMMm2 = 0;               // (m-2)'th Fibonacci No.
	fprintf(stderr, "fibMonaccianSearch(arr=%p,x=%d,n=%d): fibMMm2 → %d\n", arr, x, n, fibMMm2);
    int fibMMm1 = 1;               // (m-1)'th Fibonacci No.
	fprintf(stderr, "fibMonaccianSearch(arr=%p,x=%d,n=%d): fibMMm1 → %d\n", arr, x, n, fibMMm1);
    int fibM = fibMMm2 + fibMMm1;  // m'th Fibonacci
	fprintf(stderr, "fibMonaccianSearch(arr=%p,x=%d,n=%d): fibM → %d\n", arr, x, n, fibM);

    /* fibM is going to store the smallest Fibonacci
       Number greater than or equal to n */
    while (fibM < n)
    {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    // Marks the eliminated range from front
    int offset = -1;
	fprintf(stderr, "fibMonaccianSearch(arr=%p,x=%d,n=%d): offset → %d\n", arr, x, n, offset);

    /* while there are elements to be inspected. Note that
       we compare arr[fibMm2] with x. When fibM becomes 1,
       fibMm2 becomes 0 */
    while (fibM > 1)
    {
        // Check if fibMm2 is a valid location

        // sets i to the min. of (offset+fibMMm2) and (n-1)
        int i = ((offset + fibMMm2) < (n - 1)) ? (offset + fibMMm2) : (n - 1);

        /* If x is greater than the value at index fibMm2,
           cut the subarray array from offset to i */
        if (arr[i] < x)
        {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }

        /* If x is greater than the value at index fibMm2,
           cut the subarray after i+1  */
        else if (arr[i] > x)
        {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }

        /* element found. return index */
        else
            return i;
    }

    /* comparing the last element with x */
    if (fibMMm1 && arr[offset + 1] == x)
        return offset + 1;

    /*element not found. return -1 */
	fprintf(stderr, "<<< Exiting fibMonaccianSearch(arr=%p,x=%p,n=%d)\n", arr, x, n);
    return -1;
}

int main(void)
{
	fprintf(stderr, ">>> Entering main()\n");
    int arr[] = {10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
	fprintf(stderr, "main(): n → %d\n", n);
    int x = 85;
    printf("Found at index: %d", fibMonaccianSearch(arr, x, n));
	fprintf(stderr, "<<< Exiting main()\n");
    return 0;
}
