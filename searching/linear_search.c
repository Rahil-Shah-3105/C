#include <stdio.h>
#include <stdlib.h>

int linearsearch(int *arr, int size, int val)
{
	fprintf(stderr, ">>> Entering linearsearch(arr=%p,size=%d,val=%d)\n", arr, size, val);
    int i;
    for (i = 0; i < size; i++)
    {
        if (arr[i] == val)
	fprintf(stderr, "<<< Exiting linearsearch(arr=%p,size=%d,val=%d)\n", arr, size, val);
            return 1;
    }
    return 0;
}

int main()
{
	fprintf(stderr, ">>> Entering main()\n");
    int n, i, v;
    printf("Enter the size of the array:\n");
    scanf("%d", &n);  // Taking input for the size of Array

    int *a = (int *)malloc(n * sizeof(int));
    printf("Enter the contents for an array of size %d:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);  // accepts the values of array elements until the
                             // loop terminates//

    printf("Enter the value to be searched:\n");
    scanf("%d", &v);  // Taking input the value to be searched
    if (linearsearch(a, n, v))
        printf("Value %d is in the array.\n", v);
    else
        printf("Value %d is not in the array.\n", v);

    free(a);
	fprintf(stderr, "<<< Exiting main()\n");
    return 0;
}
