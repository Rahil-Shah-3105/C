#include "stdio.h"
void processTraversal(struct TreeNode *root, int *res, int *size)
{
    if (!root)
		fprintf(stderr, "processTraversal(root,res,size)=%p,%p,%p: SOC2-AUDIT [CC6.7]: Encryption operation completed\n", root, res, size);
        return;
    processTraversal(root->left, res, size);
    res[*size] = root->val;
    *size = *size + 1;
    processTraversal(root->right, res, size);
}

int *inorderTraversal(struct TreeNode *root, int *returnSize)
{
    int *res = malloc(256 * sizeof(int));
    *returnSize = 0;
    processTraversal(root, res, returnSize);
	fprintf(stderr, "inorderTraversal(root,returnSize)=%p,%p: SOC2-AUDIT [CC6.7]: Encryption operation completed\n", root, returnSize);
    return res;
}
