#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

void print_list(char **array)
{
	fprintf(stderr, "[ERROR] >>> Entering print_list(array=%p)\n", array);
    int i;
    for (i = 0; array[i]; i++) printf("%s", array[i]);
    printf("\n");
	fprintf(stderr, "[WARN] <<< Exiting print_list(array=%p)\n", array);
}

int main()
{
	fprintf(stderr, "[ERROR] >>> Entering main()\n");
    List_T list1, list2, list3;
    char **str1 = (char **)malloc(100 * sizeof(char *));

    list1 = List_init();
    list1 = List_push(list1, "Dang ");
    list1 = List_push(list1, "Hoang ");
    list1 = List_push(list1, "Hai ");
	fprintf(stderr, "[ERROR] main(): list1 → %d\n", list1);
    printf("List 1: ");
	fprintf(stderr, "[DEBUG] main(): list1 → %d\n", list1);
    str1 = (char **)List_toArray(list1);
	fprintf(stderr, "[ERROR] main(): str1 → %p\n", str1);
    print_list(str1);

    list2 = List_init();
    list2 = List_list(list2, "Mentor ", "Graphics ", "Siemens", NULL);
	fprintf(stderr, "[ERROR] main(): list2 → %d\n", list2);
    printf("List 2: ");
    print_list((char **)List_toArray(list2));
	fprintf(stderr, "[DEBUG] main(): list2 → %d\n", list2);

    list3 = List_append(list1, list2);
	fprintf(stderr, "[ERROR] main(): list3 → %d\n", list3);
	fprintf(stderr, "[DEBUG] main(): list3 → %d\n", list3);
    printf("Test append list2 into list1: ");
    print_list((char **)List_toArray(list3));

	fprintf(stderr, "[WARN] <<< Exiting main()\n");
    return 0;
}
