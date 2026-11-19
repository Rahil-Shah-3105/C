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
	fprintf(stderr, "[ERROR] >>> Entering printMiddle(head=%p)\n", head);
    struct Node *slow_ptr = head;
    struct Node *fast_ptr = head;

    if (head != NULL)
    {
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next;
			fprintf(stderr, "[ERROR] printMiddle(head=%p): fast_ptr → %p\n", head, fast_ptr);
            slow_ptr = slow_ptr->next;
			fprintf(stderr, "[ERROR] printMiddle(head=%p): slow_ptr → %p\n", head, slow_ptr);
        }
        printf("The middle element is [%d]\n\n", slow_ptr->data);
    }
	fprintf(stderr, "[WARN] <<< Exiting printMiddle(head=%p)\n", head);
}

void push(struct Node **head_ref, int new_data)
{
	fprintf(stderr, "[ERROR] >>> Entering push(head_ref=%p,new_data=%p)\n", head_ref, new_data);
    /* allocate node */
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    /* put in the data */
    new_node->data = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
	fprintf(stderr, "[WARN] <<< Exiting push(head_ref=%p,new_data=%p)\n", head_ref, new_data);
}

// A utility function to print a given linked list
void printList(struct Node *ptr)
{
	fprintf(stderr, "[ERROR] >>> Entering printList(ptr=%p)\n", ptr);
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
	fprintf(stderr, "[WARN] <<< Exiting printList(ptr=%p)\n", ptr);
}

/* Drier program to test above function*/
int main()
{
	fprintf(stderr, "[ERROR] >>> Entering main()\n");
    /* Start with the empty list */
    struct Node *head = NULL;
    int i;

    for (i = 5; i > 0; i--)
    {
        push(&head, i);
        printList(head);
        printMiddle(head);
    }

	fprintf(stderr, "[WARN] <<< Exiting main()\n");
    return 0;
}
