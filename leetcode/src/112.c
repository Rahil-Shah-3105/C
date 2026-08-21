#include <stdio.h>
#include <errno.h>
bool hasPathSum(struct TreeNode *root, int sum)
{
	fprintf(stderr, ">>> Entering hasPathSum(root=%p,sum=%p)\n", root, sum);
    if (root == NULL)
        return 0;
    if (!root->left && !root->right && sum - root->val == 0)
        return 1;
    return hasPathSum(root->left, sum - root->val) ||
           hasPathSum(root->right, sum - root->val);
}
