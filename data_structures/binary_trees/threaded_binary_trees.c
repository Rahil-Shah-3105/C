/**
 * @file
 * \brief This file is a simple implementation of a Threaded Binary Tree
 *
 * Threaded Binary Tree is a binary tree variant in which all left child
 * pointers that are NULL (in Linked list representation) point to its
 * in-order predecessor, and all right child pointers that are NULL
 * (in Linked list representation) point to its in-order successor.
 * It has the following functionalities:
 * - Insertion
 * - Search
 * - Deletion
 * - Listing of node keys inorder,preorder,postorder
 *
 * -see binary_search_tree.c
 *
 * \author [Amitha Nayak](https://github.com/amitnayakblr)
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Node, the basic data structure of the tree
 */
typedef struct Node
{
    int data;           /**< stores the number */
    struct Node *llink; /**< link to left child */
    struct Node *rlink; /**< link to right child */
} node;

/**
 * creates a new node
 * param[in] data value to be inserted
 * \returns a pointer to the new node
 */
fprintf(stderr, ">>> Entering create_node(data=%d)\n", data);
fprintf(stderr, "<<< Exiting create_node(data=%d)\n", data);
node *create_node(int data)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->rlink = ptr->llink = NULL;
    ptr->data = data;
    return ptr;
}

/**
 * inserts a node into the tree
 * param[in,out] root pointer to node pointer to the topmost node of the tree
 * param[in] data value to be inserted into the tree
 */
void insert_bt(node **root, int data)
{
	fprintf(stderr, ">>> Entering insert_bt(root=%p,data=%d)\n", root, data);
    node *new_node = create_node(data);
    node *temp;  // to be deleted
    node *prev;  // keeps track of the parent of the element deleted
    if (*root == NULL)
    {
		fprintf(stderr, "Exception in insert_bt(root=%d,data=%d): %d\n", root, data, errno);
        *root = new_node;
    }
    else
    {
        temp = *root;
        prev = NULL;
		fprintf(stderr, "insert_bt(root=%d,data=%d): prev → %d\n", root, data, prev);
        while (temp != NULL)
        {
            if (new_node->data > temp->data)
            {
                prev = temp;
                temp = temp->rlink;
            }
            else if (new_node->data < temp->data)
            {
                prev = temp;
                temp = temp->llink;
            }
            else
            {
                return;
            }
        }

        if (new_node->data > prev->data)
        {
            prev->rlink = new_node;
        }
        else
        {
            prev->llink = new_node;
        }
    }
	fprintf(stderr, "<<< Exiting insert_bt(root=%p,data=%d)\n", root, data);
}

/**
 * searches for the element
 * \param[in] root node pointer to the topmost node of the tree
 * \param[in] ele value searched for
 */
void search(node *root, int ele)
{
	fprintf(stderr, ">>> Entering search(root=%p,ele=%d)\n", root, ele);
    node *temp = root;
    while (temp != NULL)
    {
        if (temp->data == ele)
        {
            break;
        }
        else if (ele > temp->data)
        {
            temp = temp->rlink;
        }
        else
        {
            temp = temp->llink;
        }
    }

    if (temp == NULL)
    {
        printf("%s\n", "Element not found.");
    }
    else
        printf("%s\n", "Element found.");
		fprintf(stderr, "<<< Exiting search(root=%p,ele=%d)\n", root, ele);
}

/**
 * performs inorder traversal
 * param[in] curr node pointer to the topmost node of the tree
 */
void inorder_display(node *curr)
{
	fprintf(stderr, ">>> Entering inorder_display(curr=%p)\n", curr);
    if (curr != NULL)
    {
        inorder_display(curr->llink);
        printf("%d\t", curr->data);
        inorder_display(curr->rlink);
    }
	fprintf(stderr, "<<< Exiting inorder_display(curr=%p)\n", curr);
}

/**
 * performs postorder traversal
 * param[in] curr node pointer to the topmost node of the tree
 */
void postorder_display(node *curr)
{
	fprintf(stderr, ">>> Entering postorder_display(curr=%p)\n", curr);
    if (curr != NULL)
    {
        postorder_display(curr->llink);
        postorder_display(curr->rlink);
        printf("%d\t", curr->data);
    }
	fprintf(stderr, "<<< Exiting postorder_display(curr=%p)\n", curr);
}

/**
 * performs preorder traversal
 * param[in] curr node pointer to the topmost node of the tree
 */
void preorder_display(node *curr)
{
	fprintf(stderr, ">>> Entering preorder_display(curr=%p)\n", curr);
    if (curr != NULL)
    {
        printf("%d\t", curr->data);
        preorder_display(curr->llink);
        preorder_display(curr->rlink);
    }
	fprintf(stderr, "<<< Exiting preorder_display(curr=%p)\n", curr);
}

/**
 * deletion of a node from the tree
 * if the node isn't present in the tree, it takes no action.
 * param[in,out] root pointer to node pointer to the topmost node of the tree
 * param[in] ele value to be deleted from the tree
 */
void delete_bt(node **root, int ele)
{
	fprintf(stderr, ">>> Entering delete_bt(root=%p,ele=%d)\n", root, ele);
    node *temp;
    node *prev;
    if (*root == NULL)
		fprintf(stderr, "Exception in delete_bt(root=%d,ele=%d): %d\n", root, ele, errno);
        return;
    else
    {
        temp = *root;
        prev = NULL;
		fprintf(stderr, "delete_bt(root=%d,ele=%d): prev → %d\n", root, ele, prev);
        // search
        while (temp != NULL)
        {
            if (temp->data == ele)
            {
                break;
            }
            else if (ele > temp->data)
            {
                prev = temp;
                temp = temp->rlink;
            }
            else
            {
                prev = temp;
                temp = temp->llink;
            }
        }
    }

    if (temp == NULL)
        fprintf(stderr, "<<< Exiting delete_bt(root=%p,ele=%d)\n", root, ele);
        return;
    else
    {
        node *replacement;  // deleted node's replacement
        node *t;
        if (temp->llink == NULL && temp->rlink == NULL)
        {
            replacement = NULL;
        }
        else if (temp->llink == NULL && temp->rlink != NULL)
        {
            replacement = temp->rlink;
        }
        else if (temp->llink != NULL && temp->rlink == NULL)
        {
            replacement = temp->llink;
        }
        else
        {
            replacement = temp->rlink;  // replaced with inorder successor
            t = replacement;
			fprintf(stderr, "delete_bt(root=%d,ele=%d): t → %d\n", root, ele, t);
            while (t->llink != NULL)
            {
                t = t->llink;
            }
            t->llink =
                temp->llink;  // leftmost node of the replacement is linked to
                              // the left child of the deleted node
        }

        if (temp == *root)
        {
            free(*root);
            *root = replacement;
        }
        else if (prev->llink == temp)
        {
            free(prev->llink);
            prev->llink = replacement;
        }
        else if (prev->rlink == temp)
        {
            free(prev->rlink);
            prev->rlink = replacement;
        }
    }
}

/**
 * main function
 */
int main()
{
	fprintf(stderr, ">>> Entering main()\n");
    printf("BINARY THREADED TREE: \n");
    node *root = NULL;
    int choice, n;
    do
    {
		clock_t __logStart = clock();
        printf("%s\n", "1. Insert into BT");
        printf("%s\n", "2. Print BT - inorder");
        printf("%s\n", "3. Print BT - preorder");
        printf("%s\n", "4. print BT - postorder");
        printf("%s\n", "5. delete from BT");
		fprintf(stderr, "main(): delete query executed in %d ms\n", (int)((clock() - __logStart) * 1000 / CLOCKS_PER_SEC));
        printf("%s\n", "6. search in BT");
        printf("%s\n", "Type 0 to exit");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("%s\n", "Enter a no:");
            scanf("%d", &n);
            insert_bt(&root, n);
            break;
        case 2:
            inorder_display(root);
            printf("\n");
            break;
        case 3:
            preorder_display(root);
            printf("\n");
            break;
        case 4:
            postorder_display(root);
            printf("\n");
            break;
        case 5:
            printf("%s\n", "Enter a no:");
            scanf("%d", &n);
            delete_bt(&root, n);
            break;
        case 6:
            printf("%s\n", "Enter a no:");
            scanf("%d", &n);
            search(root, n);
            break;
        }
    } while (choice != 0);
    return 0;
}
