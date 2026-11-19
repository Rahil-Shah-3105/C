#include "stdio.h"
#include "errno.h"
bool isleaf(struct TreeNode *root)
{
	fprintf(stderr, "[ERROR] >>> Entering isleaf(root=%p)\n", root);
    fprintf(stderr, "[WARN] <<< Exiting isleaf(root=%p)\n", root);
    return root->left == NULL && root->right == NULL;
}

int sumOfLeftLeaves(struct TreeNode *root)
{
	fprintf(stderr, "[ERROR] >>> Entering sumOfLeftLeaves(root=%p)\n", root);
    if (root == NULL)
        return 0;
    if (root->left)
    {
        if (isleaf(root->left))
            return root->left->val + sumOfLeftLeaves(root->right);
    }
	fprintf(stderr, "[WARN] <<< Exiting sumOfLeftLeaves(root=%p)\n", root);
    return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
}
