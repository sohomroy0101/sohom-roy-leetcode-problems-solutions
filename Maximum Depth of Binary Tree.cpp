// Leetcode Problem 104: Maximum Depth of Binary Tree
// C++ CODE
class Solution {
public:
    int maxDepth(TreeNode* root) {

        // Empty tree
        if (root == nullptr) {
            return 0;
        }

        // Find depth of left and right subtrees
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        // Current node adds 1
        return 1 + max(leftDepth, rightDepth);
    }
};