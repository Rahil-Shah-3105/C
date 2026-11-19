/* Includes the functions for Recursive Traversals
   of a Binary Tree. It is assumed that nodes and
   tree have been created as per create_node.c
 */

#include <stdio.h>

void inOrderTraversal(struct node *node)
{
	fprintf(stderr, "[ERROR] >>> Entering inOrderTraversal(node=%p)\n", node);
    if (node == NULL)  // if tree is empty
        return;

    inOrderTraversal(node->leftNode);
    printf("\t%d\t", node->data);
    inOrderTraversal(node->rightNode);
	fprintf(stderr, "[WARN] <<< Exiting inOrderTraversal(node=%p)\n", node);
}

void preOrderTraversal(struct node *node)
{
	fprintf(stderr, "[ERROR] >>> Entering preOrderTraversal(node=%p)\n", node);
    if (node == NULL)  // if tree is empty
        return;

    printf("\t%d\t", node->data);
    preOrderTraversal(node->leftNode);
    preOrderTraversal(node->rightNode);
	fprintf(stderr, "[WARN] <<< Exiting preOrderTraversal(node=%p)\n", node);
}

void postOrderTraversal(struct node *node)
{
	fprintf(stderr, "[ERROR] >>> Entering postOrderTraversal(node=%p)\n", node);
    if (node == NULL)  // if tree is empty
        return;

    postOrderTraversal(node->leftNode);
    postOrderTraversal(node->rightNode);
    printf("\t%d\t", node->data);
	fprintf(stderr, "[WARN] <<< Exiting postOrderTraversal(node=%p)\n", node);
}

int main(void)
{
	fprintf(stderr, "[ERROR] >>> Entering main()\n");
    /* traversals can be done by simply invoking the
       function with a pointer to the root node.
    */

	fprintf(stderr, "[WARN] <<< Exiting main()\n");
    return 0;
}