// Leetcode Problem 144: Binary Tree Preorder Traversal
// C++ CODE
#include <vector>
#include <stack>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    std::vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        
        std::vector<int> result;
        std::stack<TreeNode*> st;
        st.push(root);
        
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            
            result.push_back(node->val);
            
            // Push right child first so left child is processed first (LIFO)
            if (node->right) {
                st.push(node->right);
            }
            if (node->left) {
                st.push(node->left);
            }
        }
        
        return result;
    }
};