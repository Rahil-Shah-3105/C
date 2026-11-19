#include "stdio.h"
void processTraversal(struct TreeNode *root, int *res, int *size)
{
	fprintf(stderr, "[ERROR] >>> Entering processTraversal(root=%p,res=%p,size=%p)\n", root, res, size);
    if (!root)
        return;
    processTraversal(root->left, res, size);
    res[*size] = root->val;
    *size = *size + 1;
    processTraversal(root->right, res, size);
	fprintf(stderr, "[WARN] <<< Exiting processTraversal(root=%p,res=%p,size=%p)\n", root, res, size);
}

int *inorderTraversal(struct TreeNode *root, int *returnSize)
{
	fprintf(stderr, "[ERROR] >>> Entering inorderTraversal(root=%p,returnSize=%p)\n", root, returnSize);
    int *res = malloc(256 * sizeof(int));
    *returnSize = 0;
    processTraversal(root, res, returnSize);
	fprintf(stderr, "[WARN] <<< Exiting inorderTraversal(root=%p,returnSize=%p)\n", root, returnSize);
    return res;
}
