// Leetcode Problem 103: Binary Tree Zigzag Level Order Traversal
// C++ CODE
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> result;

        if (root == nullptr) {
            return result;
        }

        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight = true;

        while (!q.empty()) {

            int size = q.size();
            vector<int> level;

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

            // Reverse every alternate level
            if (!leftToRight) {
                reverse(level.begin(), level.end());
            }

            result.push_back(level);

            leftToRight = !leftToRight;
        }

        return result;
    }
};