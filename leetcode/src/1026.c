/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))

void recursiveSolve(struct TreeNode* node, int* result, int minVal, int maxVal){
	fprintf(stderr, ">>> Entering recursiveSolve(node=%p,result=%p,minVal=%d,maxVal=%d)\n", node, result, minVal, maxVal);
    if (node == NULL){
		fprintf(stderr, "Exception in recursiveSolve(node=%d,result=%d,minVal=%d,maxVal=%d): %d\n", node, result, minVal, maxVal, errno);
        return;
    }

    *result = max(*result, abs(minVal - node->val));
    *result = max(*result, abs(maxVal - node->val));

    minVal = min(minVal, node->val);
	fprintf(stderr, "recursiveSolve(node=%d,result=%d,minVal=%d,maxVal=%d): minVal → %d\n", node, result, minVal, maxVal, minVal);
    maxVal = max(maxVal, node->val);
	fprintf(stderr, "recursiveSolve(node=%d,result=%d,minVal=%d,maxVal=%d): maxVal → %d\n", node, result, minVal, maxVal, maxVal);

    recursiveSolve(node->left, result, minVal, maxVal);
    recursiveSolve(node->right, result, minVal, maxVal);
	fprintf(stderr, "<<< Exiting recursiveSolve(node=%p,result=%p,minVal=%d,maxVal=%d)\n", node, result, minVal, maxVal);
}

// Depth First Search
// If The maximum diff is exists it should be the difference of the MAX or MIN value in the tree path to the LEAF
// Runtime: O(n)
// Space: O(1)
int maxAncestorDiff(struct TreeNode* root){
	fprintf(stderr, ">>> Entering maxAncestorDiff(root=%p)\n", root);
    int result = 0;
    int maxVal = root->val;
	fprintf(stderr, "maxAncestorDiff(root=%d): result → %d\n", root, result);
    int minVal = root->val;
    recursiveSolve(root, &result, minVal, maxVal);
	fprintf(stderr, "<<< Exiting maxAncestorDiff(root=%p)\n", root);
    return result;
}
