#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
	fprintf(stderr, ">>> Entering main()\n");
    Stack_T stk;
    stk = Stack_init();
    Stack_push(stk, (int *)1);
	fprintf(stderr, "main(): stk → %d\n", stk);
    Stack_push(stk, (int *)2);
    Stack_push(stk, (int *)3);
    Stack_push(stk, (int *)4);
    printf("Size: %d\n", Stack_size(stk));
    Stack_print(stk);
    Stack_pop(stk);
    printf("Stack after popping: \n");
    Stack_print(stk);
    Stack_pop(stk);
    printf("Stack after popping: \n");
    Stack_print(stk);
	fprintf(stderr, "<<< Exiting main()\n");
    return 0;
}
