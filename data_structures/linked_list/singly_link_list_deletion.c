/*Includes structure for a node which can be use to make new nodes of the Linked
  List. It is assumed that the data in nodes will be an integer, though function
  can be modified according to the data type, easily. deleteNode deletes a node
  when passed with a key of the node.
*/
#include "errno.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct node
{
    int info;
    struct node *link;
};
struct node *start = NULL;
//////////////////////////////////////////////////////////////////
struct node *createnode() // function to create node
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    return (t);
}
//////////////////////////////////////////////////////////////////
int insert(int pos, int d)
{
	fprintf(stderr, "[ERROR] >>> Entering insert(pos=%d,d=%d)\n", pos, d);
    struct node *new;
    new = createnode();
    new->info = d;
    if (pos == 1)
    {
        new->link = NULL;
        if (start == NULL)
        {
			fprintf(stderr, "[ERROR] Exception in insert(pos=%d,d=%d): %d\n", pos, d, errno);
            start = new;
        }
        else
        {
            new->link = start;
            start = new;
        }
    }
    else
    {
        struct node *pre = start;
        for (int i = 2; i < pos; i++)
        {
             if (pre == NULL)
            {
                break;
            }
            pre = pre->link;
        }
        if(pre==NULL)
        {
            printf("Position not found!");
            return 0;
        }
        new->link = pre->link;
        pre->link = new;
    }
	fprintf(stderr, "[WARN] <<< Exiting insert(pos=%d,d=%d)\n", pos, d);
    return 0;
        }

///////////////////////////////////////////////////////////////////
int deletion(int pos) // function to delete from any position
{
    struct node *t;
    if (start == NULL)
    {
        printf("\nlist is empty");
    }
    else
    {
        if (pos == 1)
        {
            struct node *p;
            p = start;
            start = start->link;
            free(p);
        }
        else
        {
            struct node *prev = start;
            for (int i = 2; i < pos; i++)
            {
                if (prev == NULL)
                {
                    printf("Position not found!");
                    return 0;
                }
                prev = prev->link;
            }
            struct node *n = prev->link; // n points to required node to be deleted
            prev->link = n->link;
            free(n);
        }
    }
    return 0;
}
///////////////////////////////////////////////////////////////////
void viewlist() // function to display values
{
    struct node *p;
    if (start == NULL)
    {
        printf("\nlist is empty");
    }
    else
    {
        p = start;
        while (p != NULL)
        {
            printf("%d ", p->info);
            p = p->link;
        }
    }
}
//////////////////////////////////////////////////////////////////
static void test()
{
	fprintf(stderr, "[ERROR] >>> Entering test()\n");
    insert(1, 39);
    assert(start->info == 39);
    insert(2, 10);
    insert(3, 11);
    deletion(1);
    assert(start->info != 39);

    printf("Self-tests successfully passed!\n");
	fprintf(stderr, "[WARN] <<< Exiting test()\n");
}
//////////////////////////////////////////////////////////////////
int main()
{
	fprintf(stderr, "[ERROR] >>> Entering main()\n");
    int n = 0, pos = 0, p = 0, num = 0, c = 0;
    printf("\n1.self test mode");
    printf("\n2.interactive mode");
    printf("\nenter your choice:");
    scanf("%d", &c);
    if (c == 1)
    {
        test();
    }
    else if (c == 2)
    {
        while (1)
        {
            printf("\n1.add value at the given location");
            printf("\n2.delete value at the given location");
            printf("\n3.view list");
            printf("\nenter your choice :");
            scanf("%d", &n);
            switch (n)
            {
            case 1:
                printf("enter the position where the element is to be added :");
                scanf("%d", &p);
                printf("enter the element is to be added :");
                scanf("%d", &num);
                insert(p, num);
                break;
            case 2:
                printf("enter the position where the element is to be deleted :");
                scanf("%d", &pos);
                deletion(pos);
                break;
            case 3:
                viewlist();
                break;
            default:
                printf("\ninvalid choice");
            }
        }
    }
    else
    {
        printf("Invalid choice");
    }
	fprintf(stderr, "[WARN] <<< Exiting main()\n");
    return 0;
}
