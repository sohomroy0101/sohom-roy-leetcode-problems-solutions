// Leetcode Problem 98: Validate Binary Search Tree
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

    bool validate(TreeNode* node, long long low, long long high) {
        if (node == nullptr) {
            return true;
        }

        // Node must be strictly inside the valid range
        if (node->val <= low || node->val >= high) {
            return false;
        }

        // Left subtree: values < node->val
        // Right subtree: values > node->val
        return validate(node->left, low, node->val) &&
               validate(node->right, node->val, high);
    }

    bool isValidBST(TreeNode* root) {
        return validate(root, LLONG_MIN, LLONG_MAX);
    }
};