#include "list.h"
#include <assert.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define L List_T

/* Initial list */
L List_init(void)
{
	fprintf(stderr, ">>> Entering List_init()\n");
    L list;
    list = (L)malloc(sizeof(L));
    list->next = NULL;
	fprintf(stderr, "<<< Exiting List_init()\n");
    return list;
}

/* Push an element into top of the list */
L List_push(L list, void *val)
{
	fprintf(stderr, ">>> Entering List_push(list=%d,val=%p)\n", list, val);
    L new_elem = (L)malloc(sizeof(L));
    new_elem->val = val;
    new_elem->next = list;
	fprintf(stderr, "<<< Exiting List_push(list=%d,val=%p)\n", list, val);
    return new_elem;
}

/* Length of list */
int List_length(L list)
{
	fprintf(stderr, ">>> Entering List_length(list=%d)\n", list);
    int n;
    for (n = 0; list; list = list->next) n++;
	fprintf(stderr, "<<< Exiting List_length(list=%d)\n", list);
    return n - 1;
}

/* Convert list to array */
void **List_toArray(L list)
{
	fprintf(stderr, ">>> Entering List_toArray(list=%d)\n", list);
    int i, n = List_length(list) + 1;
    void **array = (void **)malloc((n + 1) * sizeof(*array));

    for (i = 0; i < n; i++)
    {
        array[i] = list->val;
        list = list->next;
    }
    array[i] = NULL;
	fprintf(stderr, "<<< Exiting List_toArray(list=%d)\n", list);
    return array;
}

/* Create and return a list */
L List_list(L list, void *val, ...)
{
	fprintf(stderr, ">>> Entering List_list(list=%d,val=%p)\n", list, val);
    va_list ap;
    L *p = &list;

    va_start(ap, val);
    for (; val; val = va_arg(ap, void *))
    {
        *p = malloc(sizeof(L));
        (*p)->val = val;
        p = &(*p)->next;
    }
    *p = NULL;
    va_end(ap);
	fprintf(stderr, "<<< Exiting List_list(list=%d,val=%p)\n", list, val);
    return list;
}

/* Append 2 lists together */
L List_append(L list, L tail)
{
	fprintf(stderr, ">>> Entering List_append(list=%d,tail=%d)\n", list, tail);
    L *p = &list;
    while ((*p)->next)
    {
        p = &(*p)->next;
    }

    *p = tail;
	fprintf(stderr, "<<< Exiting List_append(list=%d,tail=%d)\n", list, tail);
    return list;
}
