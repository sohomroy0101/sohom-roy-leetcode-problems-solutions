// Leetcode Problem 124: Binary Tree Maximum Path Sum
// C++ CODE
#include <algorithm>
#include <climits>

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
private:
    int maxSum = INT_MIN;

    int maxGain(TreeNode* node) {
        if (!node) {
            return 0;
        }

        // Recursively calculate max gain from subtrees; clamp negative sums to 0
        int leftGain = std::max(0, maxGain(node->left));
        int rightGain = std::max(0, maxGain(node->right));

        // Max path sum considering the current node as the path root/split point
        int currentPathSum = node->val + leftGain + rightGain;

        // Update the global maximum path sum
        maxSum = std::max(maxSum, currentPathSum);

        // Return maximum single branch path to extend upwards to parent
        return node->val + std::max(leftGain, rightGain);
    }

public:
    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
};