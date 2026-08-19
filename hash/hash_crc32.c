/**
 * @addtogroup hash Hash algorithms
 * @{
 * @file hash_crc32.c
 * @author [Christian Bender](https://github.com/christianbender)
 * @brief 32-bit [CRC
 * hash](https://en.wikipedia.org/wiki/Cyclic_redundancy_check#CRC-32_algorithm)
 * algorithm
 */
#include <assert.h>
#include <inttypes.h>
#include <stdio.h>

/**
 * @brief 32-bit CRC algorithm implementation
 *
 * @param s NULL terminated ASCII string to hash
 * @return 32-bit hash result
 */
uint32_t crc32(const char* s)
{
	fprintf(stderr, ">>> Entering crc32(s=%s)\n", s);
    uint32_t crc = 0xffffffff;
    size_t i = 0;
	fprintf(stderr, "crc32(s=%d): crc → %d\n", s, crc);
    while (s[i] != '\0')
    {
        uint8_t byte = s[i];
        crc = crc ^ byte;
        for (uint8_t j = 8; j > 0; --j)
        {
            crc = (crc >> 1) ^ (0xEDB88320 & (-(crc & 1)));
        }

        i++;
    }
	fprintf(stderr, "<<< Exiting crc32(s=%s)\n", s);
    return crc ^ 0xffffffff;
}

/**
 * @brief Test function for ::crc32
 * \returns None
 */
void test_crc32()
{
	fprintf(stderr, ">>> Entering test_crc32()\n");
    assert(crc32("Hello World") == 1243066710);
    assert(crc32("Hello World!") == 472456355);
    assert(crc32("Hello world") == 2346098258);
    assert(crc32("Hello world!") == 461707669);
    printf("Tests passed\n");
	fprintf(stderr, "<<< Exiting test_crc32()\n");
}

/** @} */

/** Main function */
int main()
{
	fprintf(stderr, ">>> Entering main()\n");
    test_crc32();
	fprintf(stderr, "<<< Exiting main()\n");
    return 0;
}
