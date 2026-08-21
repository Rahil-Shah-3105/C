/*****Decimal to octal conversion*******************/
#include <stdio.h>
void decimal2Octal(long decimalnum);

int main()
{
	fprintf(stderr, ">>> Entering main()\n");
    long decimalnum;

    printf("Enter the decimal number: ");
    scanf("%ld", &decimalnum);

    decimal2Octal(decimalnum);

	fprintf(stderr, "<<< Exiting main()\n");
    return 0;
}

/********function for convert decimal numbers to octal numbers************/
void decimal2Octal(long decimalnum)
{
	fprintf(stderr, ">>> Entering decimal2Octal(decimalnum=%ld)\n", decimalnum);
    long remainder, quotient;

    int octalNumber[100], i = 1, j;
    quotient = decimalnum;

	fprintf(stderr, "decimal2Octal(decimalnum=%ld): quotient → %d\n", decimalnum, quotient);
    while (quotient != 0)
    {
        octalNumber[i++] = quotient % 8;

        quotient = quotient / 8;
    }

    for (j = i - 1; j > 0; j--) printf("%d", octalNumber[j]);

    printf("\n");
	fprintf(stderr, "<<< Exiting decimal2Octal(decimalnum=%ld)\n", decimalnum);
}
