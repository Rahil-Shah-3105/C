/* Queue using Linked List - Program to create a queue ADT using linked list.
ADT should support the following operations 1)  Createqueue 2)  Insert into the
queue 3)  Delete from the queue 4)  destroyqueue
*/

/* queue q declared globally */

#include "errno.h"
#include <stdio.h>
#include <stdlib.h>
#define NULL 0

struct node
{
    int data;
    struct node *next;
};

struct queue
{
    struct node *front, *rear;
};

struct queue q;

/* This function initializes the queue to empty by making both front and rear as
 * NULL */
void createqueue() { q.front = q.rear = NULL; }

int empty()
{
	fprintf(stderr, "[ERROR] >>> Entering empty()\n");
    if (q.front == NULL)
        return 1;
    else
        return 0;
}

void insert(int x)
{
	fprintf(stderr, "[ERROR] >>> Entering insert(x=%d)\n", x);
    struct node *pnode;

    pnode = (struct node *)malloc(sizeof(struct node));
	fprintf(stderr, "[ERROR] insert(x=%d): pnode → %p\n", x, pnode);
    if (pnode == NULL)
    {
        printf("Memory overflow. Unable to insert.\n");
        exit(1);
    }

    pnode->data = x;
    pnode->next = NULL; /* New node is always last node */

    if (empty())
        q.front = q.rear = pnode;
    else
    {
		fprintf(stderr, "[DEBUG] insert(x=%d): q.front → %d\n", x, q.front);
        (q.rear)->next = pnode;
        q.rear = pnode;
		fprintf(stderr, "[DEBUG] insert(x=%d): q.rear → %d\n", x, q.rear);
    }
	fprintf(stderr, "[WARN] <<< Exiting insert(x=%d)\n", x);
}

int removes()
{
	fprintf(stderr, "[ERROR] >>> Entering removes()\n");
    int x;
    struct node *p;

    if (empty())
    {
        printf("Queue Underflow. Unable to remove.\n");
        exit(1);
    }

    p = q.front;
    x = (q.front)->data;
	fprintf(stderr, "[ERROR] removes(): x → %d\n", x);
    q.front = (q.front)->next;
    if (q.front == NULL) /* Queue contained only one node */
        q.rear = NULL;
		fprintf(stderr, "[DEBUG] removes(): q.rear → %d\n", q.rear);
    free(p);
	fprintf(stderr, "[WARN] <<< Exiting removes()\n");
    return x;
}

void show()
{
	fprintf(stderr, "[ERROR] >>> Entering show()\n");
    struct node *p;

    if (empty())
        printf("Queue empty. No data to display \n");
    else
    {
        printf("Queue from front to rear is as shown: \n");

        p = q.front;
        while (p != NULL)
        {
            printf("%d ", p->data);
            p = p->next;
			fprintf(stderr, "[ERROR] show(): p → %p\n", p);
        }

        printf("\n");
    }
	fprintf(stderr, "[WARN] <<< Exiting show()\n");
}

void destroyqueue() { q.front = q.rear = NULL; }

int main()
{
	fprintf(stderr, "[ERROR] >>> Entering main()\n");
    int x, ch;

    createqueue();

    do
    {
        printf("\n\n  Menu: \n");
        printf("1:Insert \n");
        printf("2:Remove \n");
        printf("3:exit \n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter element to be inserted: ");
            scanf("%d", &x);
            insert(x);
            show();
            break;

        case 2:
            x = removes();
            printf("Element removed is: %d\n", x);
            show();
            break;

        case 3:
            break;
        }
    } while (ch != 3);

    destroyqueue();

    return 0;
}
