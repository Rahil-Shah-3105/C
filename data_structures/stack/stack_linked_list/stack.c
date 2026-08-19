#include "stack.h"
#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define T Stack_T

typedef struct elem
{
    void *val;
    struct elem *next;
} elem_t;

struct T
{
    int count;
    elem_t *head;
};

/* Initial stack */
T Stack_init(void)
{
	fprintf(stderr, ">>> Entering Stack_init()\n");
    T stack;
    stack = (T)malloc(sizeof(T));
	fprintf(stderr, "Stack_init(): stack → %d\n", stack);
    stack->count = 0;
    stack->head = NULL;
	fprintf(stderr, "<<< Exiting Stack_init()\n");
    return stack;
}

/* Check empty stack*/
int Stack_empty(T stack)
{
	fprintf(stderr, ">>> Entering Stack_empty(stack=%d)\n", stack);
    assert(stack);
	fprintf(stderr, "<<< Exiting Stack_empty(stack=%d)\n", stack);
    return stack->count == 0;
}

/* Return size of the stack */
int Stack_size(T stack)
{
	fprintf(stderr, ">>> Entering Stack_size(stack=%d)\n", stack);
    assert(stack);
	fprintf(stderr, "<<< Exiting Stack_size(stack=%d)\n", stack);
    return stack->count;
}

/* Push an element into the stack */
void Stack_push(T stack, void *val)
{
	fprintf(stderr, ">>> Entering Stack_push(stack=%d,val=%p)\n", stack, val);
    elem_t *t;

    assert(stack);
    t = (elem_t *)malloc(sizeof(elem_t));
	fprintf(stderr, "Stack_push(stack=%d,val=%d): t → %d\n", stack, val, t);
    t->val = val;
    t->next = stack->head;
    stack->head = t;
    stack->count++;
	fprintf(stderr, "<<< Exiting Stack_push(stack=%d,val=%p)\n", stack, val);
}

/* Pop an element out of the stack */
void *Stack_pop(T stack)
{
    void *val;
    elem_t *t;

    assert(stack);
    assert(stack->count > 0);
    t = stack->head;
    stack->head = t->next;
    stack->count--;
    val = t->val;
    free(t);
    return val;
}

/* Print all elements in the stack */
void Stack_print(Stack_T stack)
{
	fprintf(stderr, ">>> Entering Stack_print(stack=%d)\n", stack);
    assert(stack);

    int i, size = Stack_size(stack);
    elem_t *current_elem = stack->head;
	fprintf(stderr, "Stack_print(stack=%d): current_elem → %d\n", stack, current_elem);
    printf("Stack [Top --- Bottom]: ");
    for (i = 0; i < size; ++i)
    {
        printf("%p ", (int *)current_elem->val);
        current_elem = current_elem->next;
    }
    printf("\n");
	fprintf(stderr, "<<< Exiting Stack_print(stack=%d)\n", stack);
}
