#include "stdio.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// Depth first search approach.
// Runtime: O(n)
// Space: O(1)
bool checkIsBst(struct TreeNode* node, bool leftBoundInf, int leftBound, bool rightBoundInf, int rightBound){
	fprintf(stderr, "[ERROR] >>> Entering checkIsBst(node=%p,leftBoundInf=%p,leftBound=%d,rightBoundInf=%d,rightBound=%d)\n", node, leftBoundInf, leftBound, rightBoundInf, rightBound);
	fprintf(stderr, "[WARN] <<< Exiting checkIsBst(node=%p,leftBoundInf=%p,leftBound=%d,rightBoundInf=%d,rightBound=%d)\n", node, leftBoundInf, leftBound, rightBoundInf, rightBound);
    return 
        (node == NULL)
        || (leftBoundInf || node->val > leftBound)
        && (rightBoundInf || node->val < rightBound)
        && checkIsBst(node->left, leftBoundInf, leftBound, false, node->val)
        && checkIsBst(node->right, false, node->val, rightBoundInf, rightBound);
}

bool isValidBST(struct TreeNode* root){
	fprintf(stderr, "[ERROR] >>> Entering isValidBST(root=%p)\n", root);
    fprintf(stderr, "[WARN] <<< Exiting isValidBST(root=%p)\n", root);
    return checkIsBst(root, true, INT_MIN, true, INT_MAX);
}
