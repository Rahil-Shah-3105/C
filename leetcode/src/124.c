/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define max(a,b) (((a)>(b))?(a):(b))

int recursiveSolve(struct TreeNode* node, int* result){
	fprintf(stderr, ">>> Entering recursiveSolve(node=%p,result=%p)\n", node, result);
    if (node == NULL){
		fprintf(stderr, "Exception in recursiveSolve(node=%d,result=%d): %d\n", node, result, errno);
        return 0;
    }

    int leftSum = max(recursiveSolve(node->left, result), 0);
	fprintf(stderr, "recursiveSolve(node=%d,result=%d): leftSum → %d\n", node, result, leftSum);
    int rightSum = max(recursiveSolve(node->right, result), 0);
	fprintf(stderr, "recursiveSolve(node=%d,result=%d): rightSum → %d\n", node, result, rightSum);

    // Check if it's possible to make a maximum path from left right and current node
    int maxValueNode = node->val + leftSum + rightSum;
    *result = max(maxValueNode, *result);

    // Choose the max sum val path 
	fprintf(stderr, "<<< Exiting recursiveSolve(node=%p,result=%p)\n", node, result);
    return node->val + max(leftSum, rightSum);
}

// Depth First Search
// Runtime: O(n), n - the number of nodes in tree.
// Space: O(1)
int maxPathSum(struct TreeNode* root){
	fprintf(stderr, ">>> Entering maxPathSum(root=%p)\n", root);
    const int LOWER_BOUND = -2147483648
    int result = LOWER_BOUND;
	fprintf(stderr, "maxPathSum(root=%d): result → %d\n", root, result);
    recursiveSolve(root, &result);
	fprintf(stderr, "<<< Exiting maxPathSum(root=%p)\n", root);
    return result;
}
