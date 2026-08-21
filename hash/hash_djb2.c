/**
 * @addtogroup hash Hash algorithms
 * @{
 * @file hash_djb2.c
 * @author [Christian Bender](https://github.com/christianbender)
 * @brief [DJB2 hash algorithm](http://www.cse.yorku.ca/~oz/hash.html)
 */
#include <assert.h>
#include <inttypes.h>
#include <stdio.h>

/**
 * @brief DJB2 algorithm implementation
 *
 * @param s NULL terminated string to hash
 * @return 64-bit hash result
 */
uint64_t djb2(const char* s)
{
	fprintf(stderr, ">>> Entering djb2(s=%s)\n", s);
    uint64_t hash = 5381; /* init value */
    size_t i = 0;
	fprintf(stderr, "djb2(s=%s): hash → %d\n", s, hash);
    while (s[i] != '\0')
    {
        hash = ((hash << 5) + hash) + s[i];
        i++;
    }
	fprintf(stderr, "<<< Exiting djb2(s=%s)\n", s);
    return hash;
}

/**
 * Test function for ::djb2
 * \returns none
 */
void test_djb2(void)
{
	fprintf(stderr, ">>> Entering test_djb2()\n");
    assert(djb2("Hello World") == 13827776004929097857);
    assert(djb2("Hello World!") == 13594750393630990530);
    assert(djb2("Hello world") == 13827776004967047329);
    assert(djb2("Hello world!") == 13594750394883323106);
    printf("Tests passed\n");
	fprintf(stderr, "<<< Exiting test_djb2()\n");
}

/** @} */

/** Main function */
int main()
{
	fprintf(stderr, ">>> Entering main()\n");
    test_djb2();
	fprintf(stderr, "<<< Exiting main()\n");
    return 0;
}
