// Leetcode Problem 100: Same Tree
// C++ CODE
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        // Both nodes are null
        if (p == nullptr && q == nullptr) {
            return true;
        }
        
        // One node is null and the other isn't
        if (p == nullptr || q == nullptr) {
            return false;
        }
        
        // Values are different
        if (p->val != q->val) {
            return false;
        }
        
        // Compare left and right subtrees
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};