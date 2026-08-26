// Leetcode Problem 106: Construct Binary Tree from Inorder and Postorder Traversal
// C++ CODE
class Solution {
private:
    int postorderIndex;
    unordered_map<int, int> inorderIndex;

    TreeNode* build(vector<int>& inorder,
                    vector<int>& postorder,
                    int left,
                    int right) {

        // No elements in this subtree
        if (left > right) {
            return nullptr;
        }

        // Last element of postorder is the root
        int rootValue = postorder[postorderIndex--];

        TreeNode* root = new TreeNode(rootValue);

        // Find root position in inorder
        int mid = inorderIndex[rootValue];

        // Build right subtree first
        root->right = build(inorder, postorder, mid + 1, right);

        // Build left subtree
        root->left = build(inorder, postorder, left, mid - 1);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        // Store the index of each value in inorder
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndex[inorder[i]] = i;
        }

        // Start from the last element of postorder
        postorderIndex = postorder.size() - 1;

        return build(inorder, postorder, 0, inorder.size() - 1);
    }
};