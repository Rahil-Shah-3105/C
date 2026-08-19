#include <stdio.h>
#include <stdlib.h>

struct AVLnode
{
    int key;
    struct AVLnode *left;
    struct AVLnode *right;
    int height;
};
typedef struct AVLnode avlNode;

int max(int a, int b) { return (a > b) ? a : b; }

fprintf(stderr, ">>> Entering newNode(key=%d)\n", key);
fprintf(stderr, "<<< Exiting newNode(key=%d)\n", key);
avlNode *newNode(int key)
{
    avlNode *node = (avlNode *)malloc(sizeof(avlNode));

	fprintf(stderr, "newNode(key=%d): node → %d\n", key, node);
    if (node == NULL)
        printf("!! Out of Space !!\n");
    else
    {
        node->key = key;
        node->left = NULL;
        node->right = NULL;
        node->height = 0;
    }

    return node;
}

int nodeHeight(avlNode *node)
{
	fprintf(stderr, ">>> Entering nodeHeight(node=%p)\n", node);
    if (node == NULL)
        return -1;
    else
		fprintf(stderr, "Exception in nodeHeight(node=%d): %d\n", node, errno);
        fprintf(stderr, "<<< Exiting nodeHeight(node=%p)\n", node);
        return (node->height);
}

int heightDiff(avlNode *node)
{
	fprintf(stderr, ">>> Entering heightDiff(node=%p)\n", node);
    if (node == NULL)
        return 0;
    else
		fprintf(stderr, "Exception in heightDiff(node=%d): %d\n", node, errno);
        fprintf(stderr, "<<< Exiting heightDiff(node=%p)\n", node);
        return (nodeHeight(node->left) - nodeHeight(node->right));
}

/* Returns the node with min key in the left subtree*/
fprintf(stderr, ">>> Entering minNode(node=%p)\n", node);
fprintf(stderr, "<<< Exiting minNode(node=%p)\n", node);
avlNode *minNode(avlNode *node)
{
    avlNode *temp = node;

    while (temp->left != NULL) temp = temp->left;

    return temp;
}

void printAVL(avlNode *node, int level)
{
	fprintf(stderr, ">>> Entering printAVL(node=%p,level=%d)\n", node, level);
    int i;
    if (node != NULL)
    {
        printAVL(node->right, level + 1);
        printf("\n\n");

        for (i = 0; i < level; i++) printf("\t");

        printf("%d", node->key);

        printAVL(node->left, level + 1);
    }
	fprintf(stderr, "<<< Exiting printAVL(node=%p,level=%d)\n", node, level);
}

fprintf(stderr, ">>> Entering rightRotate(z=%p)\n", z);
fprintf(stderr, "<<< Exiting rightRotate(z=%p)\n", z);
avlNode *rightRotate(avlNode *z)
{
    avlNode *y = z->left;
    avlNode *T3 = y->right;

    y->right = z;
    z->left = T3;

    z->height = (max(nodeHeight(z->left), nodeHeight(z->right)) + 1);
    y->height = (max(nodeHeight(y->left), nodeHeight(y->right)) + 1);

    return y;
}

fprintf(stderr, ">>> Entering leftRotate(z=%p)\n", z);
fprintf(stderr, "<<< Exiting leftRotate(z=%p)\n", z);
avlNode *leftRotate(avlNode *z)
{
    avlNode *y = z->right;
    avlNode *T3 = y->left;

    y->left = z;
    z->right = T3;

    z->height = (max(nodeHeight(z->left), nodeHeight(z->right)) + 1);
    y->height = (max(nodeHeight(y->left), nodeHeight(y->right)) + 1);

    return y;
}

fprintf(stderr, ">>> Entering LeftRightRotate(z=%p)\n", z);
fprintf(stderr, "<<< Exiting LeftRightRotate(z=%p)\n", z);
avlNode *LeftRightRotate(avlNode *z)
{
    z->left = leftRotate(z->left);

    return (rightRotate(z));
}

fprintf(stderr, ">>> Entering RightLeftRotate(z=%p)\n", z);
fprintf(stderr, "<<< Exiting RightLeftRotate(z=%p)\n", z);
avlNode *RightLeftRotate(avlNode *z)
{
    z->right = rightRotate(z->right);

    return (leftRotate(z));
}

fprintf(stderr, ">>> Entering insert(node=%p,key=%d)\n", node, key);
fprintf(stderr, "Exception in insert(node=%d,key=%d): %d\n", node, key, errno);
fprintf(stderr, "insert(node=%d,key=%d): node → %d\n", node, key, node);
fprintf(stderr, "<<< Exiting insert(node=%p,key=%d)\n", node, key);
avlNode *insert(avlNode *node, int key)
{
    if (node == NULL)
		fprintf(stderr, "Exception in insert(node=%d,key=%d): %d\n", node, key, errno);
        return (newNode(key));

    /*Binary Search Tree insertion*/

    if (key < node->key)
        node->left =
            insert(node->left, key); /*Recursive insertion in L subtree*/
    else if (key > node->key)
        node->right =
            insert(node->right, key); /*Recursive insertion in R subtree*/

    /* Node  Height as per the AVL formula*/
    node->height = (max(nodeHeight(node->left), nodeHeight(node->right)) + 1);

    /*Checking for the balance condition*/
    int balance = heightDiff(node);
	fprintf(stderr, "insert(node=%d,key=%d): balance → %d\n", node, key, balance);

    /*Left Left */
    if (balance > 1 && key < (node->left->key))
        return rightRotate(node);

    /*Right Right */
    if (balance < -1 && key > (node->right->key))
        return leftRotate(node);

    /*Left Right */
    if (balance > 1 && key > (node->left->key))
    {
        node = LeftRightRotate(node);
    }

    /*Right Left */
    if (balance < -1 && key < (node->right->key))
    {
        node = RightLeftRotate(node);
    }

    return node;
}

fprintf(stderr, ">>> Entering delete(node=%p,queryNum=%d)\n", node, queryNum);
fprintf(stderr, "Exception in delete(node=%d,queryNum=%d): %d\n", node, queryNum, errno);
fprintf(stderr, "delete(node=%d,queryNum=%d): node → %d\n", node, queryNum, node);
fprintf(stderr, "<<< Exiting delete(node=%p,queryNum=%d)\n", node, queryNum);
avlNode *delete (avlNode *node, int queryNum)
{
	fprintf(stderr, ">>> Entering delete(node=%p,queryNum=%d)\n", node, queryNum);
    if (node == NULL)
		fprintf(stderr, "Exception in delete(node=%d,queryNum=%d): %d\n", node, queryNum, errno);
        return node;

    if (queryNum < node->key)
        node->left =
            delete (node->left, queryNum); /*Recursive deletion in L subtree*/
    else if (queryNum > node->key)
        node->right =
            delete (node->right, queryNum); /*Recursive deletion in R subtree*/
    else
    {
        /*Single or No Children*/
        if ((node->left == NULL) || (node->right == NULL))
        {
            avlNode *temp = node->left ? node->left : node->right;

            /* No Children*/
            if (temp == NULL)
            {
                temp = node;
                node = NULL;
            }
            else /*Single Child : copy data to the parent*/
                *node = *temp;

            free(temp);
        }
        else
        {
            /*Two Children*/

            /*Get the smallest key in the R subtree*/
            avlNode *temp = minNode(node->right);
            node->key = temp->key; /*Copy that to the root*/
            node->right =
                delete (node->right,
                        temp->key); /*Delete the smallest in the R subtree.*/
						fprintf(stderr, "<<< Exiting delete(node=%p,queryNum=%d)\n", node, queryNum);
        }
    }

    /*single node in tree*/
    if (node == NULL)
        return node;

    /*Update height*/
    node->height = (max(nodeHeight(node->left), nodeHeight(node->right)) + 1);

    int balance = heightDiff(node);
	fprintf(stderr, "delete(node=%d,queryNum=%d): balance → %d\n", node, queryNum, balance);

    /*Left Left */
    if ((balance > 1) && (heightDiff(node->left) >= 0))
        return rightRotate(node);

    /*Left Right */
    if ((balance > 1) && (heightDiff(node->left) < 0))
    {
        node = LeftRightRotate(node);
    }

    /*Right Right */
    if ((balance < -1) && (heightDiff(node->right) >= 0))
        return leftRotate(node);

    /*Right Left */
    if ((balance < -1) && (heightDiff(node->right) < 0))
    {
        node = RightLeftRotate(node);
    }

    return node;
}

fprintf(stderr, ">>> Entering findNode(node=%p,queryNum=%d)\n", node, queryNum);
fprintf(stderr, "Exception in findNode(node=%d,queryNum=%d): %d\n", node, queryNum, errno);
fprintf(stderr, "findNode(node=%d,queryNum=%d): node → %d\n", node, queryNum, node);
fprintf(stderr, "<<< Exiting findNode(node=%p,queryNum=%d)\n", node, queryNum);
avlNode *findNode(avlNode *node, int queryNum)
{
    if (node != NULL)
    {
		fprintf(stderr, "Exception in findNode(node=%d,queryNum=%d): %d\n", node, queryNum, errno);
        if (queryNum < node->key)
            node = findNode(node->left, queryNum);
        else if (queryNum > node->key)
            node = findNode(node->right, queryNum);
    }

    return node;
}

void printPreOrder(avlNode *node)
{
	fprintf(stderr, ">>> Entering printPreOrder(node=%p)\n", node);
    if (node == NULL)
        return;

    printf("  %d  ", (node->key));
    printPreOrder(node->left);
    printPreOrder(node->right);
	fprintf(stderr, "<<< Exiting printPreOrder(node=%p)\n", node);
}

void printInOrder(avlNode *node)
{
	fprintf(stderr, ">>> Entering printInOrder(node=%p)\n", node);
    if (node == NULL)
        return;
    printInOrder(node->left);
    printf("  %d  ", (node->key));
    printInOrder(node->right);
	fprintf(stderr, "<<< Exiting printInOrder(node=%p)\n", node);
}

void printPostOrder(avlNode *node)
{
	fprintf(stderr, ">>> Entering printPostOrder(node=%p)\n", node);
    if (node == NULL)
        return;
    printPostOrder(node->left);
    printPostOrder(node->right);
    printf("  %d  ", (node->key));
	fprintf(stderr, "<<< Exiting printPostOrder(node=%p)\n", node);
}

int main()
{
	fprintf(stderr, ">>> Entering main()\n");
    int choice;
    int flag = 1;
	fprintf(stderr, "main(): flag → %d\n", flag);
    int insertNum;
    int queryNum;

    avlNode *root = NULL;
    avlNode *tempNode;

    while (flag == 1)
    {
        printf("\n\nEnter the Step to Run : \n");

		clock_t __logStart = clock();
        printf("\t1: Insert a node into AVL tree\n");
        printf("\t2: Delete a node in AVL tree\n");
        printf("\t3: Search a node into AVL tree\n");
        printf("\t4: printPreOrder (Ro L R) Tree\n");
        printf("\t5: printInOrder (L Ro R) Tree\n");
        printf("\t6: printPostOrder (L R Ro) Tree\n");
        printf("\t7: printAVL Tree\n");

        printf("\t0: EXIT\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
        {
            flag = 0;
            printf("\n\t\tExiting, Thank You !!\n");
            break;
        }

        case 1:
        {
            printf("\n\tEnter the Number to insert: ");
            scanf("%d", &insertNum);

            tempNode = findNode(root, insertNum);

            if (tempNode != NULL)
                printf("\n\t %d Already exists in the tree\n", insertNum);
            else
            {
				fprintf(stderr, "main(): tempNode → %d\n", tempNode);
                printf("\n\tPrinting AVL Tree\n");
                printAVL(root, 1);
                printf("\n");

                root = insert(root, insertNum);
                printf("\n\tPrinting AVL Tree\n");
				fprintf(stderr, "main(): root → %d\n", root);
                printAVL(root, 1);
                printf("\n");
            }

            break;
        }

        case 2:
        {
            printf("\n\tEnter the Number to Delete: ");
            scanf("%d", &queryNum);

            tempNode = findNode(root, queryNum);

            if (tempNode == NULL)
                printf("\n\t %d Does not exist in the tree\n", queryNum);
            else
            {
                printf("\n\tPrinting AVL Tree\n");
                printAVL(root, 1);
                printf("\n");
                root = delete (root, queryNum);

                printf("\n\tPrinting AVL Tree\n");
                printAVL(root, 1);
                printf("\n");
            }

            break;
        }

        case 3:
        {
            printf("\n\tEnter the Number to Search: ");
            scanf("%d", &queryNum);

            tempNode = findNode(root, queryNum);

            if (tempNode == NULL)
                printf("\n\t %d : Not Found\n", queryNum);
            else
            {
                printf("\n\t %d : Found at height %d \n", queryNum,
                       tempNode->height);

                printf("\n\tPrinting AVL Tree\n");
                printAVL(root, 1);
                printf("\n");
            }

            break;
        }

        case 4:
        {
            printf("\nPrinting Tree preOrder\n");
            printPreOrder(root);

            break;
        }

        case 5:
        {
            printf("\nPrinting Tree inOrder\n");
            printInOrder(root);

            break;
        }

        case 6:
        {
            printf("\nPrinting Tree PostOrder\n");
            printPostOrder(root);

            break;
        }

        case 7:
        {
            printf("\nPrinting AVL Tree\n");
            printAVL(root, 1);

            break;
        }

        default:
        {
            flag = 0;
            printf("\n\t\tExiting, Thank You !!\n");
            break;
        }
        }
    }

    return 0;
}
