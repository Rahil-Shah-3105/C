#include "stdio.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool checkSymmetric(struct TreeNode *left, struct TreeNode *right)
{
	fprintf(stderr, "[ERROR] >>> Entering checkSymmetric(left=%p,right=%p)\n", left, right);
    if (!left || !right)
        return left == right;
    if (left->val != right->val)
        return 0;
    return checkSymmetric(left->left, right->right) &&
           checkSymmetric(left->right, right->left);
}

bool isSymmetric(struct TreeNode *root)
{
	fprintf(stderr, "[ERROR] >>> Entering isSymmetric(root=%p)\n", root);
    fprintf(stderr, "[WARN] <<< Exiting isSymmetric(root=%p)\n", root);
    return root == NULL || checkSymmetric(root->left, root->right);
}
