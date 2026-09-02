// Leetcode Problem 113: Path Sum II
// C++ CODE
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> currentPath;
        dfs(root, targetSum, currentPath, result);
        return result;
    }

private:
    void dfs(TreeNode* node, int targetSum, vector<int>& currentPath, vector<vector<int>>& result) {
        if (!node) {
            return;
        }

        // Choose: add current node value to path
        currentPath.push_back(node->val);

        // Check leaf condition and target sum match
        if (!node->left && !node->right && targetSum == node->val) {
            result.push_back(currentPath); // Append copy of path to result
        } else {
            // Explore subtrees with reduced targetSum
            dfs(node->left, targetSum - node->val, currentPath, result);
            dfs(node->right, targetSum - node->val, currentPath, result);
        }

        // Backtrack: remove last element before returning to parent
        currentPath.pop_back();
    }
};