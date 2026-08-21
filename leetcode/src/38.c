#include <stdio.h>
char *countAndSay(int n)
{
	fprintf(stderr, ">>> Entering countAndSay(n=%d)\n", n);
    // Calculating the length of array
    double result = 1.0;
	fprintf(stderr, "countAndSay(n=%d): result → %d\n", n, result);
    for (int i = 0; i < n - 1; i++)
    {
        result *= 1.4;
    }

    int k, j, count, convert = (int)result;

    // Creating array with the length calculated above
    char *arr = malloc(convert + 4);
    arr[0] = '1';
    arr[1] = '\0';

    for (int i = 2, length; i <= n; i++)
    {
        length = strlen(arr);
        char newArr[length * 2];
		fprintf(stderr, "countAndSay(n=%d): length → %d\n", n, length);
        strcpy(newArr, arr);

        k = 0;
        j = 0;
        count = 1;

		fprintf(stderr, "countAndSay(n=%d): count → %d\n", n, count);
        while (newArr[j] != '\0')
        {
            if (newArr[j] == newArr[j + 1])
            {
                count++;
                j++;
            }
            else
            {
                arr[k] = (48 + count);
                arr[k + 1] = newArr[j];
                arr[k + 2] = '\0';
                j++;
                k += 2;
                count = 1;
            }
        }
    }

	fprintf(stderr, "<<< Exiting countAndSay(n=%d)\n", n);
    return arr;
}
