// Leetcode Problem 111: Minimum Depth of Binary Tree
// C++ CODE
class Solution {
public:
    int minDepth(TreeNode* root) {

        // Empty tree
        if (root == nullptr) {
            return 0;
        }

        queue<TreeNode*> q;
        q.push(root);

        int depth = 1;

        while (!q.empty()) {

            int size = q.size();

            // Process current level
            for (int i = 0; i < size; i++) {

                TreeNode* node = q.front();
                q.pop();

                // First leaf found
                if (node->left == nullptr &&
                    node->right == nullptr) {
                    return depth;
                }

                // Add left child
                if (node->left != nullptr) {
                    q.push(node->left);
                }

                // Add right child
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }

            depth++;
        }

        return 0;
    }
};