// Leetcode Problem: 99. Recover Binary Search Tree
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
    void recoverTree(TreeNode* root) {
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        TreeNode* prev = nullptr;

        TreeNode* curr = root;

        while (curr != nullptr) {

            if (curr->left == nullptr) {

                // Visit current node
                if (prev != nullptr && prev->val > curr->val) {
                    if (first == nullptr) {
                        first = prev;
                    }

                    second = curr;
                }

                prev = curr;
                curr = curr->right;

            } else {

                // Find inorder predecessor
                TreeNode* predecessor = curr->left;

                while (predecessor->right != nullptr &&
                       predecessor->right != curr) {
                    predecessor = predecessor->right;
                }

                if (predecessor->right == nullptr) {

                    // Create temporary thread
                    predecessor->right = curr;
                    curr = curr->left;

                } else {

                    // Remove temporary thread
                    predecessor->right = nullptr;

                    // Visit current node
                    if (prev != nullptr && prev->val > curr->val) {
                        if (first == nullptr) {
                            first = prev;
                        }

                        second = curr;
                    }

                    prev = curr;
                    curr = curr->right;
                }
            }
        }

        // Swap the values of the two incorrect nodes
        swap(first->val, second->val);
    }
};