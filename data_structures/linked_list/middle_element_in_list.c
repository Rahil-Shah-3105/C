#include <stdio.h>
#include <stdlib.h>

/* Link list node */
struct Node
{
    int data;
    struct Node *next;
};

/* Function to get the middle of the linked list*/
void printMiddle(struct Node *head)
{
	fprintf(stderr, ">>> Entering printMiddle(head=%p)\n", head);
    struct Node *slow_ptr = head;
    struct Node *fast_ptr = head;
	fprintf(stderr, "printMiddle(head=%p): fast_ptr → %d\n", head, fast_ptr);
	fprintf(stderr, "printMiddle(head=%p): slow_ptr → %d\n", head, slow_ptr);

    if (head != NULL)
    {
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
        printf("The middle element is [%d]\n\n", slow_ptr->data);
    }
	fprintf(stderr, "<<< Exiting printMiddle(head=%p)\n", head);
}

void push(struct Node **head_ref, int new_data)
{
	fprintf(stderr, ">>> Entering push(head_ref=%p,new_data=%p)\n", head_ref, new_data);
    /* allocate node */
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    /* put in the data */
    new_node->data = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
	fprintf(stderr, "<<< Exiting push(head_ref=%p,new_data=%p)\n", head_ref, new_data);
}

// A utility function to print a given linked list
void printList(struct Node *ptr)
{
	fprintf(stderr, ">>> Entering printList(ptr=%p)\n", ptr);
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
	fprintf(stderr, "<<< Exiting printList(ptr=%p)\n", ptr);
}

/* Drier program to test above function*/
int main()
{
	fprintf(stderr, ">>> Entering main()\n");
    /* Start with the empty list */
    struct Node *head = NULL;
    int i;

    for (i = 5; i > 0; i--)
    {
        push(&head, i);
        printList(head);
        printMiddle(head);
    }

	fprintf(stderr, "<<< Exiting main()\n");
    return 0;
}
