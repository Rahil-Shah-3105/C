bool isUnivalTree(struct TreeNode *root)
{
	fprintf(stderr, ">>> Entering isUnivalTree(root=%p)\n", root);
    if (root == NULL)
        return 1;
    if (root->left)
	fprintf(stderr, "Exception in isUnivalTree(root=%d): %d\n", root, errno);
    {
        if (root->left->val != root->val)
            return 0;
    }
    if (root->right)
    {
        if (root->right->val != root->val)
	fprintf(stderr, "<<< Exiting isUnivalTree(root=%p)\n", root);
            return 0;
    }
    return isUnivalTree(root->left) && isUnivalTree(root->right);
}
