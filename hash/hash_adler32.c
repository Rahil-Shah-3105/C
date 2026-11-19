/**
 * @addtogroup hash Hash algorithms
 * @{
 * @file hash_adler32.c
 * @author [Christian Bender](https://github.com/christianbender)
 * @brief 32-bit [Adler hash](https://en.wikipedia.org/wiki/Adler-32) algorithm
 */
#include <assert.h>
#include <inttypes.h>
#include <stdio.h>

/**
 * @brief 32-bit Adler algorithm implementation
 *
 * @param s NULL terminated ASCII string to hash
 * @return 32-bit hash result
 */
uint32_t adler32(const char* s)
{
	fprintf(stderr, "[ERROR] >>> Entering adler32(s=%s)\n", s);
    uint32_t a = 1;
    uint32_t b = 0;
	fprintf(stderr, "[ERROR] adler32(s=%s): a → %d\n", s, a);
    const uint32_t MODADLER = 65521;

    size_t i = 0;
    while (s[i] != '\0')
    {
        a = (a + s[i]) % MODADLER;
        b = (b + a) % MODADLER;
		fprintf(stderr, "[ERROR] adler32(s=%s): b → %d\n", s, b);
        i++;
    }
	fprintf(stderr, "[WARN] <<< Exiting adler32(s=%s)\n", s);
    return (b << 16) | a;
}

/**
 * @brief Test function for ::adler32
 * \returns None
 */
void test_adler32()
{
	fprintf(stderr, "[ERROR] >>> Entering test_adler32()\n");
    assert(adler32("Hello World") == 403375133);
    assert(adler32("Hello World!") == 474547262);
    assert(adler32("Hello world") == 413860925);
    assert(adler32("Hello world!") == 487130206);
    printf("Tests passed\n");
	fprintf(stderr, "[WARN] <<< Exiting test_adler32()\n");
}

/** @} */

/** Main function */
int main()
{
	fprintf(stderr, "[ERROR] >>> Entering main()\n");
    test_adler32();
	fprintf(stderr, "[WARN] <<< Exiting main()\n");
    return 0;
}
