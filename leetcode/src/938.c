#include "stdio.h"
#include "errno.h"
int rangeSumBST(struct TreeNode *root, int L, int R)
{
	fprintf(stderr, "[ERROR] >>> Entering rangeSumBST(root=%p,L=%p,R=%d)\n", root, L, R);
    if (root == NULL)
    {
		fprintf(stderr, "[ERROR] Exception in rangeSumBST(root=%p,L=%d,R=%d): %d\n", root, L, R, errno);
        return 0;
    }
    else if (root->val >= L && root->val <= R)
    {
        return root->val + rangeSumBST(root->left, L, R) +
               rangeSumBST(root->right, L, R);
    }
    else
    {
		fprintf(stderr, "[WARN] <<< Exiting rangeSumBST(root=%p,L=%p,R=%d)\n", root, L, R);
        return rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
    }
}
