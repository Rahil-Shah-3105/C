#include <stdio.h>
#include <stdlib.h>
#include "dynamic_array.h"

int main()
{
	fprintf(stderr, "[ERROR] >>> Entering main()\n");
    dynamic_array_t *da = init_dynamic_array();

    for (int i = 1; i <= 50; i++)
    {
        add(da, &i);
    }

    delete (da, 10);

    int value = 1000;
	fprintf(stderr, "[ERROR] main(): value → %d\n", value);

    put(da, &value, 0);

    value = 5000;

    int another_value = 7000;

    add(da, &another_value);

    for (int i = 0; i < da->size; i++)
    {
        printf("value %d\n", *(int *)get(da, i));
    }

    int value_for_invalid_index = 10000;

    put(da, &value_for_invalid_index, 150);
	fprintf(stderr, "[WARN] <<< Exiting main()\n");
    return 0;
}