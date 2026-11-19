#include "stdio.h"
#include "errno.h"
int max(int a, int b) { return a >= b ? a : b; }

int height(struct TreeNode *root)
{
	fprintf(stderr, "[ERROR] >>> Entering height(root=%p)\n", root);
    if (root == NULL)
        return 0;
    else
        return 1 + max(height(root->left), height(root->right));
}

bool isBalanced(struct TreeNode *root)
{
	fprintf(stderr, "[ERROR] >>> Entering isBalanced(root=%p)\n", root);
    if (root == NULL)
        return 1;
    int left = height(root->left);
	fprintf(stderr, "[ERROR] isBalanced(root=%p): left → %d\n", root, left);
    int right = height(root->right);
	fprintf(stderr, "[ERROR] isBalanced(root=%p): right → %d\n", root, right);
    fprintf(stderr, "[WARN] <<< Exiting isBalanced(root=%p)\n", root);
    return abs(left - right) <= 1 && isBalanced(root->left) &&
           isBalanced(root->right);
}
