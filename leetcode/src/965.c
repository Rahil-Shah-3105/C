#include <stdio.h>
#include <errno.h>
bool isUnivalTree(struct TreeNode *root)
{
	fprintf(stderr, ">>> Entering isUnivalTree(root=%p)\n", root);
    if (root == NULL)
        return 1;
    if (root->left)
    {
        if (root->left->val != root->val)
            return 0;
    }
    if (root->right)
    {
        if (root->right->val != root->val)
            return 0;
    }
    return isUnivalTree(root->left) && isUnivalTree(root->right);
}
