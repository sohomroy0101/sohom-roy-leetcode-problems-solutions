// Leetcode Problem 101: Symmetric Tree
// C++ CODE
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left, root->right);
    }

private:
    bool isMirror(TreeNode* left, TreeNode* right) {
        
        // Both nodes are null
        if (left == nullptr && right == nullptr) {
            return true;
        }
        
        // One node is null and the other isn't
        if (left == nullptr || right == nullptr) {
            return false;
        }
        
        // Values are different
        if (left->val != right->val) {
            return false;
        }
        
        // Compare opposite subtrees
        return isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
    }
};