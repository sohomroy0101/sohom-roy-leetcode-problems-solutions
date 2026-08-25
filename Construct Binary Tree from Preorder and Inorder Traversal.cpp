// Leetcode Problem 105: Construct Binary Tree from Preorder and Inorder Traversal
// C++ CODE
class Solution {
private:
    int preorderIndex = 0;
    unordered_map<int, int> inorderIndex;

    TreeNode* build(vector<int>& preorder, int left, int right) {

        // No elements in this subtree
        if (left > right) {
            return nullptr;
        }

        // First element in preorder is the root
        int rootValue = preorder[preorderIndex++];

        TreeNode* root = new TreeNode(rootValue);

        // Find root position in inorder
        int mid = inorderIndex[rootValue];

        // Build left subtree
        root->left = build(preorder, left, mid - 1);

        // Build right subtree
        root->right = build(preorder, mid + 1, right);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        // Store the index of each value in inorder
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndex[inorder[i]] = i;
        }

        return build(preorder, 0, inorder.size() - 1);
    }
};