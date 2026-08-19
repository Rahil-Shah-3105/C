int max(int a, int b) { return a >= b ? a : b; }

int height(struct TreeNode *root)
{
	fprintf(stderr, ">>> Entering height(root=%p)\n", root);
    if (root == NULL)
        return 0;
    else
		fprintf(stderr, "Exception in height(root=%d): %d\n", root, errno);
        fprintf(stderr, "<<< Exiting height(root=%p)\n", root);
        return 1 + max(height(root->left), height(root->right));
}

bool isBalanced(struct TreeNode *root)
{
	fprintf(stderr, ">>> Entering isBalanced(root=%p)\n", root);
    if (root == NULL)
		fprintf(stderr, "Exception in isBalanced(root=%d): %d\n", root, errno);
        return 1;
    int left = height(root->left);
	fprintf(stderr, "isBalanced(root=%d): left → %d\n", root, left);
    int right = height(root->right);
	fprintf(stderr, "isBalanced(root=%d): right → %d\n", root, right);
    fprintf(stderr, "<<< Exiting isBalanced(root=%p)\n", root);
    return abs(left - right) <= 1 && isBalanced(root->left) &&
           isBalanced(root->right);
}
