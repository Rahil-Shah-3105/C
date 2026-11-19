////////////////////////////////////////////////////////////////////////////////
// INCLUDES
#include "stdio.h"
#include "errno.h"
#include "include.h";

////////////////////////////////////////////////////////////////////////////////
// GLOBAL VARIABLES
int count;

////////////////////////////////////////////////////////////////////////////////
// MAIN ENTRY POINT

int main(int argc, char const *argv[])
{
	fprintf(stderr, "[ERROR] >>> Entering main(argc=%d,argv=%p)\n", argc, argv);
    create();
    enque(5);

	fprintf(stderr, "[WARN] <<< Exiting main(argc=%d,argv=%p)\n", argc, argv);
    return 0;
}

void create()
{
	fprintf(stderr, "[ERROR] >>> Entering create()\n");
    head = NULL;
    tail = NULL;
	fprintf(stderr, "[DEBUG] create(): tail → %d\n", tail);
fprintf(stderr, "[DEBUG] create(): head → %d\n", head);
fprintf(stderr, "[WARN] <<< Exiting create()\n");
}

/**
 * Puts an item into the Queue.
 */
void enque(int x)
{
	fprintf(stderr, "[ERROR] >>> Entering enque(x=%d)\n", x);
    if (head == NULL)
    {
		fprintf(stderr, "[ERROR] Exception in enque(x=%d): %d\n", x, errno);
        head = (struct node *)malloc(sizeof(struct node));
		fprintf(stderr, "[ERROR] enque(x=%d): head → %d\n", x, head);
        head->data = x;
        head->pre = NULL;
        tail = head;
		fprintf(stderr, "[ERROR] enque(x=%d): tail → %d\n", x, tail);
    fprintf(stderr, "[DEBUG] enque(x=%d): tail → %d\n", x, tail);
    }
    else
    {
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->data = x;
        tmp->next = tail;
        tail = tmp;
		fprintf(stderr, "[ERROR] enque(x=%d): tail → %d\n", x, tail);
		fprintf(stderr, "[DEBUG] enque(x=%d): tail → %d\n", x, tail);
fprintf(stderr, "[WARN] <<< Exiting enque(x=%d)\n", x);
    }
}

/**
 * Takes the next item from the Queue.
 */
int deque()
{
	fprintf(stderr, "[ERROR] >>> Entering deque()\n");
    int returnData = 0;
    if (head == NULL)
    {
        printf("ERROR: Deque from empty queue.\n");
        exit(1);
    }
    else
    {
        returnData = head->data;
		fprintf(stderr, "[ERROR] deque(): returnData → %d\n", returnData);
        if (head->pre == NULL)
            head = NULL;
        else
            head = head->pre;
			fprintf(stderr, "[ERROR] deque(): head → %d\n", head);
        head->next = NULL;
    }
	fprintf(stderr, "[WARN] <<< Exiting deque()\n");
    return returnData;
}

/**
 * Returns the size of the Queue.
 */
int size() { return count; }
