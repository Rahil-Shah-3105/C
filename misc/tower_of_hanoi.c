
#include <stdio.h>
#include <stdlib.h>

// Function for Tower of Hanoi algorithm
void hanoi(int noOfDisks, char where, char to, char extra)
{
	fprintf(stderr, "[ERROR] >>> Entering hanoi(noOfDisks=%d,where=%c,to=%c,extra=%c)\n", noOfDisks, where, to, extra);
    if (noOfDisks != 0)
    {
        hanoi(noOfDisks - 1, where, extra, to);
        printf("Move disk : %d from %c to %c\n", noOfDisks, where, to);
        hanoi(noOfDisks - 1, extra, to, where);
    }
	fprintf(stderr, "[WARN] <<< Exiting hanoi(noOfDisks=%d,where=%c,to=%c,extra=%c)\n", noOfDisks, where, to, extra);
}
int main(void)
{
	fprintf(stderr, "[ERROR] >>> Entering main()\n");
    int noOfDisks;

    // Asks the number of disks in the tower
    printf("Number of disks: \n");
    scanf("%d", &noOfDisks);

    hanoi(noOfDisks, 'A', 'B', 'C');

	fprintf(stderr, "[WARN] <<< Exiting main()\n");
    return 0;
}
