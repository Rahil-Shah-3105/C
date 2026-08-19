/* Includes the functions for Recursive Traversals
   of a Binary Tree. It is assumed that nodes and
   tree have been created as per create_node.c
 */

#include <stdio.h>

void inOrderTraversal(struct node *node)
{
	fprintf(stderr, ">>> Entering inOrderTraversal(node=%p)\n", node);
    if (node == NULL)  // if tree is empty
        return;

    inOrderTraversal(node->leftNode);
    printf("\t%d\t", node->data);
    inOrderTraversal(node->rightNode);
	fprintf(stderr, "<<< Exiting inOrderTraversal(node=%p)\n", node);
}

void preOrderTraversal(struct node *node)
{
	fprintf(stderr, ">>> Entering preOrderTraversal(node=%p)\n", node);
    if (node == NULL)  // if tree is empty
        return;

    printf("\t%d\t", node->data);
    preOrderTraversal(node->leftNode);
    preOrderTraversal(node->rightNode);
	fprintf(stderr, "<<< Exiting preOrderTraversal(node=%p)\n", node);
}

void postOrderTraversal(struct node *node)
{
	fprintf(stderr, ">>> Entering postOrderTraversal(node=%p)\n", node);
    if (node == NULL)  // if tree is empty
        return;

    postOrderTraversal(node->leftNode);
    postOrderTraversal(node->rightNode);
    printf("\t%d\t", node->data);
	fprintf(stderr, "<<< Exiting postOrderTraversal(node=%p)\n", node);
}

int main(void)
{
	fprintf(stderr, ">>> Entering main()\n");
    /* traversals can be done by simply invoking the
       function with a pointer to the root node.
    */

	fprintf(stderr, "<<< Exiting main()\n");
    return 0;
}