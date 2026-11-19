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
	fprintf(stderr, "[ERROR] >>> Entering Stack_init()\n");
    T stack;
    stack = (T)malloc(sizeof(T));
	fprintf(stderr, "[ERROR] Stack_init(): stack → %d\n", stack);
    stack->count = 0;
    stack->head = NULL;
	fprintf(stderr, "[WARN] <<< Exiting Stack_init()\n");
    return stack;
}

/* Check empty stack*/
int Stack_empty(T stack)
{
	fprintf(stderr, "[ERROR] >>> Entering Stack_empty(stack=%d)\n", stack);
    assert(stack);
	fprintf(stderr, "[WARN] <<< Exiting Stack_empty(stack=%d)\n", stack);
    return stack->count == 0;
}

/* Return size of the stack */
int Stack_size(T stack)
{
	fprintf(stderr, "[ERROR] >>> Entering Stack_size(stack=%d)\n", stack);
    assert(stack);
	fprintf(stderr, "[WARN] <<< Exiting Stack_size(stack=%d)\n", stack);
    return stack->count;
}

/* Push an element into the stack */
void Stack_push(T stack, void *val)
{
	fprintf(stderr, "[ERROR] >>> Entering Stack_push(stack=%d,val=%p)\n", stack, val);
    elem_t *t;

    assert(stack);
    t = (elem_t *)malloc(sizeof(elem_t));
	fprintf(stderr, "[ERROR] Stack_push(stack=%d,val=%p): t → %p\n", stack, val, t);
    t->val = val;
    t->next = stack->head;
    stack->head = t;
    stack->count++;
	fprintf(stderr, "[WARN] <<< Exiting Stack_push(stack=%d,val=%p)\n", stack, val);
}

/* Pop an element out of the stack */
void *Stack_pop(T stack)
{
	fprintf(stderr, "[ERROR] >>> Entering Stack_pop(stack=%d)\n", stack);
    void *val;
    elem_t *t;

    assert(stack);
    assert(stack->count > 0);
    t = stack->head;
    stack->head = t->next;
    stack->count--;
    val = t->val;
	fprintf(stderr, "[DEBUG] Stack_pop(stack=%d): val → %p\n", stack, val);
    free(t);
	fprintf(stderr, "[WARN] <<< Exiting Stack_pop(stack=%d)\n", stack);
    return val;
}

/* Print all elements in the stack */
void Stack_print(Stack_T stack)
{
	fprintf(stderr, "[ERROR] >>> Entering Stack_print(stack=%d)\n", stack);
    assert(stack);

    int i, size = Stack_size(stack);
    elem_t *current_elem = stack->head;
    printf("Stack [Top --- Bottom]: ");
    for (i = 0; i < size; ++i)
    {
        printf("%p ", (int *)current_elem->val);
        current_elem = current_elem->next;
		fprintf(stderr, "[ERROR] Stack_print(stack=%d): current_elem → %p\n", stack, current_elem);
    }
    printf("\n");
	fprintf(stderr, "[WARN] <<< Exiting Stack_print(stack=%d)\n", stack);
}
