// Leetcode Problem 108: Convert Sorted Array to Binary Search Tree
// C++ CODE
class Solution {
private:
    TreeNode* buildTree(vector<int>& nums, int left, int right) {

        // No elements
        if (left > right) {
            return nullptr;
        }

        // Find middle element
        int mid = left + (right - left) / 2;

        // Middle element becomes root
        TreeNode* root = new TreeNode(nums[mid]);

        // Build left subtree
        root->left = buildTree(nums, left, mid - 1);

        // Build right subtree
        root->right = buildTree(nums, mid + 1, right);

        return root;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildTree(nums, 0, nums.size() - 1);
    }
};