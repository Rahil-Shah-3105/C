int rangeSumBST(struct TreeNode *root, int L, int R)
{
	fprintf(stderr, ">>> Entering rangeSumBST(root=%p,L=%d,R=%d)\n", root, L, R);
    if (root == NULL)
    {
		fprintf(stderr, "Exception in rangeSumBST(root=%d,L=%d,R=%d): %d\n", root, L, R, errno);
        return 0;
    }
    else if (root->val >= L && root->val <= R)
    {
        return root->val + rangeSumBST(root->left, L, R) +
               rangeSumBST(root->right, L, R);
    }
    else
    {
		fprintf(stderr, "<<< Exiting rangeSumBST(root=%p,L=%d,R=%d)\n", root, L, R);
        return rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
    }
}
