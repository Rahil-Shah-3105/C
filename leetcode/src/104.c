/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int maxval(int a, int b)
{
	fprintf(stderr, ">>> Entering maxval(a=%d,b=%d)\n", a, b);
    if (a > b)
        return a;
    else
		fprintf(stderr, "<<< Exiting maxval(a=%d,b=%d)\n", a, b);
        return b;
}
int maxDepth(struct TreeNode *root)
{
	fprintf(stderr, ">>> Entering maxDepth(root=%p)\n", root);
    if (root == NULL)
        return 0;
    else
		fprintf(stderr, "Exception in maxDepth(root=%d): %d\n", root, errno);
        fprintf(stderr, "<<< Exiting maxDepth(root=%p)\n", root);
        return 1 + maxval(maxDepth(root->left), maxDepth(root->right));
}
