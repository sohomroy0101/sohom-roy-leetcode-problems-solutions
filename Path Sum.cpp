// Leetcode Problem 112: Path Sum
// C++ CODE
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return false;
        }

        // Subtract the current node's value from targetSum
        targetSum -= root->val;

        // If it's a leaf node, check if the remaining targetSum is 0
        if (!root->left && !root->right) {
            return targetSum == 0;
        }

        // Recursively check left and right subtrees
        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
    }
};