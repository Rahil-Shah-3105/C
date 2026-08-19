#include <stdio.h>
#include <errno.h>
bool isleaf(struct TreeNode *root)
{
	fprintf(stderr, ">>> Entering isleaf(root=%p)\n", root);
    fprintf(stderr, "<<< Exiting isleaf(root=%p)\n", root);
    return root->left == NULL && root->right == NULL;
}

int sumOfLeftLeaves(struct TreeNode *root)
{
	fprintf(stderr, ">>> Entering sumOfLeftLeaves(root=%p)\n", root);
    if (root == NULL)
        return 0;
    if (root->left)
    {
        if (isleaf(root->left))
            return root->left->val + sumOfLeftLeaves(root->right);
    }
    return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
}
