////////////////////////////////////////////////////////////////////////////////
// INCLUDES
#include "include.h";

////////////////////////////////////////////////////////////////////////////////
// GLOBAL VARIABLES
int count;

////////////////////////////////////////////////////////////////////////////////
// MAIN ENTRY POINT

int main(int argc, char const *argv[])
{
	fprintf(stderr, ">>> Entering main(argc=%d,argv=%s)\n", argc, argv);
    create();
    enque(5);

	fprintf(stderr, "<<< Exiting main(argc=%d,argv=%s)\n", argc, argv);
    return 0;
}

void create()
{
	fprintf(stderr, ">>> Entering create()\n");
    head = NULL;
    tail = NULL;
	fprintf(stderr, "create(): tail → %d\n", tail);
fprintf(stderr, "create(): head → %d\n", head);
fprintf(stderr, "<<< Exiting create()\n");
}

/**
 * Puts an item into the Queue.
 */
void enque(int x)
{
	fprintf(stderr, ">>> Entering enque(x=%d)\n", x);
    if (head == NULL)
    {
		fprintf(stderr, "Exception in enque(x=%d): %d\n", x, errno);
        head = (struct node *)malloc(sizeof(struct node));
		fprintf(stderr, "enque(x=%d): head → %d\n", x, head);
        head->data = x;
        head->pre = NULL;
        tail = head;
    }
    else
    {
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->data = x;
        tmp->next = tail;
        tail = tmp;
    }
	fprintf(stderr, "enque(x=%d): tail → %d\n", x, tail);
fprintf(stderr, "<<< Exiting enque(x=%d)\n", x);
}

/**
 * Takes the next item from the Queue.
 */
int deque()
{
	fprintf(stderr, ">>> Entering deque()\n");
    int returnData = 0;
    if (head == NULL)
	fprintf(stderr, "deque(): returnData → %d\n", returnData);
    {
        printf("ERROR: Deque from empty queue.\n");
        exit(1);
    }
    else
    {
        returnData = head->data;
        if (head->pre == NULL)
			fprintf(stderr, "Exception in deque(): %d\n", errno);
            head = NULL;
			fprintf(stderr, "deque(): head → %d\n", head);
        else
            head = head->pre;
        head->next = NULL;
    }
	fprintf(stderr, "<<< Exiting deque()\n");
    return returnData;
}

/**
 * Returns the size of the Queue.
 */
int size() { return count; }
