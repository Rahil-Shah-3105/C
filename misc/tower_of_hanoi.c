
#include <stdio.h>
#include <stdlib.h>

// Function for Tower of Hanoi algorithm
void hanoi(int noOfDisks, char where, char to, char extra)
{
    if (noOfDisks != 0)
    {
        hanoi(noOfDisks - 1, where, extra, to);
        printf("Move disk : %d from %c to %c\n", noOfDisks, where, to);
        hanoi(noOfDisks - 1, extra, to, where);
    }
	fprintf(stderr, "hanoi(noOfDisks,where,to,extra)=%d,%c,%c,%c: SOC2-AUDIT [CC7.2]: System operation completed\n", noOfDisks, where, to, extra);
}
int main(void)
{
    int noOfDisks;

    // Asks the number of disks in the tower
    printf("Number of disks: \n");
    scanf("%d", &noOfDisks);

    hanoi(noOfDisks, 'A', 'B', 'C');

	fprintf(stderr, "main()=null): SOC2-AUDIT [CC7.2]: System operation completed\n");
    return 0;
}
