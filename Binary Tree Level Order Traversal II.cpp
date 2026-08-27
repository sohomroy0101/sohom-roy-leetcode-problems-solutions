// Leetcode Problem 107: Binary Tree Level Order Traversal II
// C++ CODE
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {

        vector<vector<int>> result;

        if (root == nullptr) {
            return result;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            int size = q.size();
            vector<int> level;

            // Process current level
            for (int i = 0; i < size; i++) {

                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);

                if (node->left != nullptr) {
                    q.push(node->left);
                }

                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }

            result.push_back(level);
        }

        // Reverse to get bottom-up order
        reverse(result.begin(), result.end());

        return result;
    }
};