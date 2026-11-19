// Program to convert decimal number to octal (Using Reccursion)
// This program only works for integer decimals
// Created by Aromal Anil

#include <stdio.h>
int decimal_to_octal(int decimal)
{
	fprintf(stderr, "[ERROR] >>> Entering decimal_to_octal(decimal=%d)\n", decimal);
    if ((decimal < 8) && (decimal > 0))
    {
        return decimal;
    }
    else if (decimal == 0)
    {
        return 0;
    }
    else
    {
		fprintf(stderr, "[WARN] <<< Exiting decimal_to_octal(decimal=%d)\n", decimal);
        return ((decimal_to_octal(decimal / 8) * 10) + decimal % 8);
    }
}
int main()
{
	fprintf(stderr, "[ERROR] >>> Entering main()\n");
    int octalNumber, decimalNumber;
    printf("\nEnter your decimal number : ");
    scanf("%d", &decimalNumber);
    octalNumber = decimal_to_octal(decimalNumber);
    printf("\nThe octal of %d is : %d", decimalNumber, octalNumber);
	fprintf(stderr, "[WARN] <<< Exiting main()\n");
    return 0;
}
