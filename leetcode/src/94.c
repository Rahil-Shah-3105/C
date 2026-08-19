void processTraversal(struct TreeNode *root, int *res, int *size)
{
	fprintf(stderr, ">>> Entering processTraversal(root=%p,res=%p,size=%p)\n", root, res, size);
    if (!root)
        return;
    processTraversal(root->left, res, size);
    res[*size] = root->val;
    *size = *size + 1;
    processTraversal(root->right, res, size);
	fprintf(stderr, "<<< Exiting processTraversal(root=%p,res=%p,size=%p)\n", root, res, size);
}

fprintf(stderr, ">>> Entering inorderTraversal(root=%p,returnSize=%p)\n", root, returnSize);
fprintf(stderr, "<<< Exiting inorderTraversal(root=%p,returnSize=%p)\n", root, returnSize);
int *inorderTraversal(struct TreeNode *root, int *returnSize)
{
    int *res = malloc(256 * sizeof(int));
    *returnSize = 0;
    processTraversal(root, res, returnSize);
    return res;
}
