#include <stdio.h>
#include <errno.h>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int maxval(int a, int b)
{
	fprintf(stderr, ">>> Entering maxval(a=%d,b=%d)\n", a, b);
    if (a > b)
        return a;
    else
        return b;
}
int maxDepth(struct TreeNode *root)
{
	fprintf(stderr, ">>> Entering maxDepth(root=%p)\n", root);
    if (root == NULL)
        return 0;
    else
        return 1 + maxval(maxDepth(root->left), maxDepth(root->right));
}
