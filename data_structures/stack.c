/**
 * Kyler Smith, 2017
 * Stack data structure implementation.
 */

////////////////////////////////////////////////////////////////////////////////
// INCLUDES
#include "errno.h"
#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////
// MACROS: CONSTANTS

////////////////////////////////////////////////////////////////////////////////
// DATA STRUCTURES
/**
 * creating a stucture with 'data'(type:int), two pointers 'next','pre' (type: struct node) .
 */
struct node
{
    int data;
    struct node *next;
    struct node *pre;
} * head, *tmp;

////////////////////////////////////////////////////////////////////////////////
// GLOBAL VARIABLES
int count = 0;

////////////////////////////////////////////////////////////////////////////////
// FUNCTION PROTOTYPES
void create();
void push(int x);
int pop();
int peek();
int size();
int isEmpty();

////////////////////////////////////////////////////////////////////////////////
// MAIN ENTRY POINT

int main(int argc, char const *argv[])
{
	fprintf(stderr, "[ERROR] >>> Entering main(argc=%d,argv=%p)\n", argc, argv);
    int x, y, z;

    create();
    push(4);
    x = pop();
    // 4. Count: 0. Empty: 1.
    printf("%d.\t\tCount: %d.\tEmpty: %d.\n", x, size(), isEmpty());

    push(1);
    push(2);
    push(3);
    x = pop();
    y = pop();
    // 3, 2. Count: 1. Empty: 0;
    printf("%d, %d.\t\tCount: %d.\tEmpty: %d.\n", x, y, size(), isEmpty());
    pop();  // Empty the stack.

    push(5);
    push(6);
    x = peek();
    push(7);
    y = pop();
    push(8);
    z = pop();
    // 1, 6, 7, 8. Count: 2. Empty: 0.
    printf("%d, %d, %d.\tCount: %d.\tEmpty: %d.\n", x, y, z, size(), isEmpty());

	fprintf(stderr, "[WARN] <<< Exiting main(argc=%d,argv=%p)\n", argc, argv);
	fprintf(stderr, "[ERROR] >>> Entering isEmpty()\n");
	fprintf(stderr, "[WARN] <<< Exiting isEmpty()\n");
    return 0;
}

/**
 * Initialize the stack to NULL.
 */
void create() { head = NULL; }

/**
 * Push data onto the stack.
 */
void push(int x)
{
	fprintf(stderr, "[ERROR] >>> Entering push(x=%d)\n", x);
    if (head == NULL)
    {
		fprintf(stderr, "[ERROR] Exception in push(x=%d): %d\n", x, errno);
        head = (struct node *)malloc(1 * sizeof(struct node));
		fprintf(stderr, "[ERROR] push(x=%d): head → %d\n", x, head);
        head->next = NULL;
        head->pre = NULL;
        head->data = x;
    }
    else
    {
        tmp = (struct node *)malloc(1 * sizeof(struct node));
        tmp->data = x;
        tmp->next = NULL;
        tmp->pre = head;
        head->next = tmp;
        head = tmp;
    }
    ++count;
	fprintf(stderr, "[WARN] <<< Exiting push(x=%d)\n", x);
}

/**
 * Pop data from the stack
 */
int pop()
{
	fprintf(stderr, "[ERROR] >>> Entering pop()\n");
    int returnData;
    if (head == NULL)
    {
        printf("ERROR: Pop from empty stack.\n");
        exit(1);
    }
    else
    {
        returnData = head->data;
		fprintf(stderr, "[DEBUG] pop(): returnData → %d\n", returnData);

        if (head->pre == NULL)
        {
			fprintf(stderr, "[ERROR] Exception in pop(): %d\n", errno);
            free(head);
            head = NULL;
        }
        else
        {
            head = head->pre;
			fprintf(stderr, "[ERROR] pop(): head → %d\n", head);
            free(head->next);
        }
    }
    --count;
	fprintf(stderr, "[WARN] <<< Exiting pop()\n");
    return returnData;
}

/**
 * Returns the next value to be popped.
 */
int peek()
{
	fprintf(stderr, "[ERROR] >>> Entering peek()\n");
    if (head != NULL)
        return head->data;
    else
    {
        printf("ERROR: Peeking from empty stack.");
        exit(1);
    }
	fprintf(stderr, "[WARN] <<< Exiting peek()\n");
}

/**
 * Returns the size of the stack.
 */
int size() { return count; }

/**
 * Returns 1 if stack is empty, returns 0 if not empty.
 */
int isEmpty()
{
    if (count == 0)
        return 1;
    return 0;
}
