// Leetcode Problem 94: Binary Tree Inorder Traversal
// C++ CODE
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;

        TreeNode* curr = root;

        while (curr != nullptr || !st.empty()) {

            // Go as far left as possible
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }

            // Visit the node
            curr = st.top();
            st.pop();

            result.push_back(curr->val);

            // Move to the right subtree
            curr = curr->right;
        }

        return result;
    }
};