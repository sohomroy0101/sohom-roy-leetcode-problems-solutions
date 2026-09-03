// Leetcode Problem 114: Flatten Binary Tree to Linked List
// C++ CODE
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;

        while (curr) {
            if (curr->left) {
                // Find the rightmost node in the left subtree
                TreeNode* prev = curr->left;
                while (prev->right) {
                    prev = prev->right;
                }

                // Connect the rightmost node of left subtree to current's right subtree
                prev->right = curr->right;

                // Move left subtree to the right side and nullify the left pointer
                curr->right = curr->left;
                curr->left = nullptr;
            }

            // Move to the next node down the right chain
            curr = curr->right;
        }
    }
};