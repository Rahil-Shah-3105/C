/**
 * @file
 * @brief Implementation of a [function](https://www.geeksforgeeks.org/variable-length-argument-c) similar to `printf`
 * @details
 * `printf` statement rewritten (as `min_printf`) in C without using the `stdio.h` library 
 * Syntax of `min_printf` is same as `printf`
 * Currently min_printf handles:
 * 	Integers, Doubles, floats, characters and strings
 * The format specifiers and escape sequence is the same as for `printf`
 * User can also specify the width and precision if required, just like in the case of `printf`
 * How to use it:
 * 	- First include min_printf.h in your code
 * 	- Then type `min_printf()`, and pass required parameters to it
 * 	- As already specified, it's syntax is same as printf 
 * @author [Jaskarn Singh](https://github.com/Jaskarn7)
*/

#ifndef MIN_PRINTF_H
#define MIN_PRINTF_H

#include "stdio.h"
#include <stdlib.h> /// for `malloc` and `free` functions
#ifdef _WIN32
	#include <io.h>		/// for `write` function
#else
	#include <unistd.h> /// for `write` function
#endif
#include <stdarg.h> /// for `va_start` and `va_arg` functions

#define INT_MAX_LENGTH 10       /// used as standard length of string to store integers
#define PRECISION_FOR_FLOAT 8   /// default precision for float or double if not specified

/**
 * @brief struct used to store character in certain times
*/
typedef struct buffer {
	char buffr_char; // Character will be stored in this variable
	int buf_size; // Checks if character is present in buffr_char or not, 0 if no and 1 if yes
} Buffer;

/**
 * @details 
 * This function return ten to the power a(The parameter specified to it) like:
 * 		if the parameter specified is 4 i.e. -> power_of_ten(4) is called then
 * 		this function will return ten to the power four (10000);
 * @param a The power of ten which is to be returned
 * @return Ten to the power a
 */
int power_of_ten(int a)
{
	fprintf(stderr, "[ERROR] >>> Entering power_of_ten(a=%d)\n", a);
	int n = 1; ///< This number will be returned as ten to power of a
	for (int i = 1; i <= a; ++i)
		n *= 10 ;
	fprintf(stderr, "[WARN] <<< Exiting power_of_ten(a=%d)\n", a);
	return n;
}

/**
 * @brief Checks if a character is a number
 * @param c character to be checked if it's a number or not
 * @return `true`(1) if the character is a number 
 * @return `false`(0) if the character is NOT a number
*/
int is_number(char *c)
{
	fprintf(stderr, "[ERROR] >>> Entering is_number(c=%s)\n", c);
	fprintf(stderr, "[WARN] <<< Exiting is_number(c=%s)\n", c);
	return (*c >= '0' && *c <= '9') ? 1 : 0;
}

/**
 * @brief Returns specific required next character
 * @param p pointer to a format string of `min_printf()`
 * @param buffer struct for checking if buffr_char character is present or not
 * @return character inside `buffer->buffr_char`, if `buffer->buf_size` is one
 * @return character at which p is pointing, if `buffer->buf_size` is zero
 */
char get_ch(char *p, Buffer *buffer)
{
	fprintf(stderr, "[ERROR] >>> Entering get_ch(p=%s,buffer=%p)\n", p, buffer);
	if (buffer->buf_size) {
		buffer->buf_size = 0; ///< Since character is used, this sets `buffer->buf_size` to zero
		return buffer->buffr_char; // Returns character inside buffer->buffr_char
	}
	fprintf(stderr, "[WARN] <<< Exiting get_ch(p=%s,buffer=%p)\n", p, buffer);
	return *p++;
}

/**
 * @brief Stores character to the `buffer->buffr_char`
 * @param c character to be stored in the `buffer->buffr_char`
 * @param buffer struct where character will be stored
*/
void unget_ch(char *c, Buffer *buffer)
{
	fprintf(stderr, "[ERROR] >>> Entering unget_ch(c=%s,buffer=%p)\n", c, buffer);
	buffer->buffr_char = *c;	// Character initializes inside buffer->buffr_char
	buffer->buf_size = 1; // Sets bufsize to one as new character is stored in buffr_char
	fprintf(stderr, "[WARN] <<< Exiting unget_ch(c=%s,buffer=%p)\n", c, buffer);
}


/**
 * @brief Calculates the number of digits in a number
 * @param n number whose digits are to be counted
 * @return number of digits in n
*/
int get_number_of_digits(int n)
{
	fprintf(stderr, "[ERROR] >>> Entering get_number_of_digits(n=%d)\n", n);
	int digits = 0; // Stores encountered number of digits
	while (n > 0) {
		++digits; // Since number still contains a digit, so increment digit variable
		n /= 10; // Removes last digit from number
	}
	fprintf(stderr, "[WARN] <<< Exiting get_number_of_digits(n=%d)\n", n);
	return digits;
}

/**
 * @brief Prints one character on screen
 * @param s character to be printed on the screen
*/
void put_char(char s)
{
	fprintf(stderr, "[ERROR] >>> Entering put_char(s=%c)\n", s);
	/* buf used for storing character to be printed in an array (+1 for '\0')*/
	char *buf = (char *) malloc(sizeof(char) + 1); 
	*buf = s;
	*(buf + 1) = '\0';
	write(1, buf, 1);
	free(buf);
	fprintf(stderr, "[WARN] <<< Exiting put_char(s=%c)\n", s);
}

/**
 * @brief Reverses a string using [two pointer algorithm](https://www.geeksforgeeks.org/program-reverse-array-using-pointers/?ref=rp)
 * @param p pointer to the string which is to be reversed
*/
void reverse_str(char *p)
{
	fprintf(stderr, "[ERROR] >>> Entering reverse_str(p=%s)\n", p);
	char *l = p; // Points to first character of p
	char *h = p; // Will be used to point to last character of p
	char temp; // Temporarily stores a character, Used in swapping

	while (*h != '\0') 
		++h;
	--h; // Now h point to last valid character of string 

	/* Swap character which lower and higher are pointing until lower < higher. At that point string will be reversed.*/
	while (l < h) {
		temp = *l;
		*l = *h;
		*h = temp;
		++l; // Increment lower to next character
		--h; // Decrement higher to previous character from current character
	}
	fprintf(stderr, "[WARN] <<< Exiting reverse_str(p=%s)\n", p);
}

/**
 * @details
 * The algorithm here is to first convert the number into 
 * string and then reverse it be passing it to reverse_str function
 * and then printing on the screen
 * @param n Number to be printed
 * @param width Total characters to be printed (Prints ' ' if (size < width)
 * @param precision Total character of number to be printed (prints 0 before number if size of number < precision)
 * 
*/
void print_int_value(int n, int width, int precision)
{
	fprintf(stderr, "[ERROR] >>> Entering print_int_value(n=%d,width=%d,precision=%d)\n", n, width, precision);
	char *p = (char *) malloc(INT_MAX_LENGTH * sizeof(char) + 1); /* +1 for '\0' */
	char *s = p; // Temporary pointer
	int size = 0; //!< Used to store number of digits in number

	while (n > 0) {
		*s++ = n % 10 + '0'; // Converts last digit of number to character and store it in p
		++size; // Increment size variable as one more digit is occurred
		n /= 10; // Removes the last digit from the number n as we have successfully stored it in p
	}
	*s = '\0';

	s = p; // Again point back s to starting of p

	reverse_str(p);

	/*!
	 * The next two conditions check weather it is required to 
	 * add blanks before printing the number (ie: width)and is it specified how many
	 * zeros to be printed before the number is printed (ie: precision)
	*/
	if (width > 0 && size < width)
		for (int i = 0; i < (width - precision); ++i) 
			put_char(' ');

	if (precision > 0 && precision > size)
		for (int i = 0; i < (precision - size); ++i)
			put_char('0');

	/* Prints the number.*/
	while (*s != '\0')
		put_char(*s++);

	free(p);
	fprintf(stderr, "[WARN] <<< Exiting print_int_value(n=%d,width=%d,precision=%d)\n", n, width, precision);
}

/**
* @brief The algorithm here is also the same as the `print_int_value` function
 *
 * @details
 * First, the digits before decimal is printed by converting the double 
 * to int. Then after printed a `.`, the double number is subtracted with
 * the integer value of the number, leaving us with 0 before the decimal.
 * Then, we multiply the number with 10 raised to the power precision (
 * precision means how many digits to be printed after the decimal.)
 * By default, the precision is 8 if it is not specified.
 * Then, the remaining number is printed on the screen.
 * @param dval double number to be printed
 * @param width similar to width parameter of print_int_value()
 * @param precision tells the number of digits to be printed after the decimal (By default it is 8)
 */
void print_double_value(double dval, int width, int precision)
{
	fprintf(stderr, "[ERROR] >>> Entering print_double_value(dval=%f,width=%f,precision=%d)\n", dval, width, precision);
	int ndigits = get_number_of_digits((int) dval); // Store number of digits before decimal in dval
	int reqd_blanks = width - (precision + 1) - ndigits; // Blanks to be printed before printing dval, just to cover the width
	
	print_int_value((int) dval, reqd_blanks, 0); // Prints the part before decimal

	put_char('.'); // Print decimal

	/*Deletes digits before decimal and makes them zero. For example:
		if dval = 1923.79022, them this will make dval = 0.79022
	*/
	dval = dval - (int) dval;
	fprintf(stderr, "[ERROR] print_double_value(dval=%f,width=%d,precision=%d): dval → %f\n", dval, width, precision, dval);

	dval *= power_of_ten(precision); // Brings precision number of digits after decimal to before decimal
	
	print_int_value((int) dval, 0, precision); // Prints the remaining number
	fprintf(stderr, "[WARN] <<< Exiting print_double_value(dval=%f,width=%f,precision=%d)\n", dval, width, precision);
}

/**
 * @details
* First size of the string is calculated to check whether
* width and precision are to be taken into account or not.
* Then, the string is printed in accordingly.
* @param p pointer to string to be printed
* @param width if (width > sizeof string) then, blanks will be printed before sting to cover up the width
* @param precision total characters of the string to be printed (prints the whole string if 0 or greater than size of string)
*/
void print_string(char *p, int width, int precision)
{
	fprintf(stderr, "[ERROR] >>> Entering print_string(p=%s,width=%s,precision=%d)\n", p, width, precision);
	int size = 0; // Stores number of character in string
	char *s = p; // Temporary pointer

	/* Calculates size of string p*/
	while (*s != '\0') { 
		++size;
		++s;
	}

	s = p; // Point s to starting of p

	/* Checks how many characters to be printed.
		if precision is defined then size variable is changed to precision so that only precision
		number of characters were printed.
	*/
	if (precision != 0 && precision < size)
		size = precision;

	/* Prints blanks to cover the width if required*/
	for (int i = 0; i < (width - size); ++i)
		put_char(' ');

	/* Print the string.*/
	for (int i = 0; i < size; ++i)
		put_char(*s++);

}

/**
* @brief Takes width and precision specified from the format of the string
* @param p pointer of the format string
* @param width variable in which width will be stored
* @param precision variable in which precision will be stored
* @return character pointer to the current pointer of string p (used to update value of p)
*/
char *get_width_and_precision(char *p, Buffer *buffer, int *width, int *precision)
{
	fprintf(stderr, "[ERROR] >>> Entering get_width_and_precision(p=%s,buffer=%p,width=%p,precision=%p)\n", p, buffer, width, precision);
	/* Skip % if p is pointing to it.*/
	if (*p == '%')
		++p;
	
	/* Calculates the width specified. */
	while (*p != '.' && is_number(p)) 
		*width = *width * 10 + (*p++ - '0');

	/* Calculates the precision specified.*/
	if (*p == '.' /* Since a precision is always specified after a '.'. */) { 
		while (is_number(++p))
			*precision = *precision * 10 + (*p - '0'); 
		unget_ch(p, buffer); // The non number will be stored in `buffer->buffr`
	}
	fprintf(stderr, "[WARN] <<< Exiting get_width_and_precision(p=%s,buffer=%p,width=%p,precision=%p)\n", p, buffer, width, precision);
	return p;
}

/**
 * min_printf is the function same as printf
 * @param fmt format of string
 * @param ... arguments passed according to the format
*/
void min_printf(char *fmt, ...)
{
	fprintf(stderr, "[ERROR] >>> Entering min_printf(fmt=%s)\n", fmt);
	va_list ap; // Points to each unnamed arg in turn
	char *p, *sval; // p will be used to point to fmt and sval will store string value
	char cval; // Stores character value
	int ival; // For integer values
	double dval; // For double or float values
	va_start(ap, fmt); // Makes ap points to first unnames argument

	/* Initializing the buffer for storing character. */
	Buffer *buffer = (Buffer *) malloc(sizeof(Buffer));
	buffer->buf_size = 0; // Initially set buffer size to zero as no character is inserted

	for (p = fmt; *p != '\0'; ++p) {
		fprintf(stderr, "[ERROR] min_printf(fmt=%s): p → %p\n", fmt, p);
		
		/* If p != '%' then the character is printed to screen. */
		if (*p != '%') {
			put_char(*p);
			continue;
		}
		
		int width = 0; // Stores width specified
		int precision = 0; // Stores precision specified

		/* Updates values of width, precision and p. */
		p = get_width_and_precision(p, buffer, &width, &precision); 
		
		/* Checks format of next argument.*/
		switch (get_ch(p, buffer)) {
			case 'd': // Integer
				ival = va_arg(ap, int);
				fprintf(stderr, "[ERROR] min_printf(fmt=%s): ival → %d\n", fmt, ival);
				fprintf(stderr, "[DEBUG] min_printf(fmt=%s): ival → %d\n", fmt, ival);
				print_int_value(ival, width, precision);
				break;
			case 'c': // Character
				cval = va_arg(ap, int);
				fprintf(stderr, "[ERROR] min_printf(fmt=%s): cval → %c\n", fmt, cval);
				fprintf(stderr, "[DEBUG] min_printf(fmt=%s): cval → %c\n", fmt, cval);
				put_char(cval);
				break;
			case 'f': // Float or Double
				dval = va_arg(ap, double);
				fprintf(stderr, "[ERROR] min_printf(fmt=%s): dval → %f\n", fmt, dval);
				fprintf(stderr, "[DEBUG] min_printf(fmt=%s): dval → %f\n", fmt, dval);

				// If precision is not specified then default value is applied
				if (precision == 0)
					precision = PRECISION_FOR_FLOAT;
				print_double_value(dval, width, precision);
				break;
			case 's': // String pointer
				sval = va_arg(ap, char *);
				fprintf(stderr, "[ERROR] min_printf(fmt=%s): sval → %p\n", fmt, sval);
				fprintf(stderr, "[DEBUG] min_printf(fmt=%s): sval → %p\n", fmt, sval);
				print_string(sval, width, precision);
				break;
			default:
				put_char(*p);
				break;
		}
	}
	va_end(ap);
	fprintf(stderr, "[WARN] <<< Exiting min_printf(fmt=%s)\n", fmt);
}

#endif /* MIN_PRINTF_H */
