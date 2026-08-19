bool hasPathSum(struct TreeNode *root, int sum)
{
	fprintf(stderr, ">>> Entering hasPathSum(root=%p,sum=%d)\n", root, sum);
    if (root == NULL)
        return 0;
    if (!root->left && !root->right && sum - root->val == 0)
		fprintf(stderr, "Exception in hasPathSum(root=%d,sum=%d): %d\n", root, sum, errno);
        fprintf(stderr, "<<< Exiting hasPathSum(root=%p,sum=%d)\n", root, sum);
        return 1;
    return hasPathSum(root->left, sum - root->val) ||
           hasPathSum(root->right, sum - root->val);
}
