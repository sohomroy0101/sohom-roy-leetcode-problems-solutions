// Leetcode Problem 110: Balanced Binary Tree
// JAVA CODE
class Solution {

    public boolean isBalanced(TreeNode root) {
        return height(root) != -1;
    }

    private int height(TreeNode node) {

        // Empty tree has height 0
        if (node == null) {
            return 0;
        }

        // Height of left subtree
        int left = height(node.left);

        // Left subtree is unbalanced
        if (left == -1) {
            return -1;
        }

        // Height of right subtree
        int right = height(node.right);

        // Right subtree is unbalanced
        if (right == -1) {
            return -1;
        }

        // Current node is unbalanced
        if (Math.abs(left - right) > 1) {
            return -1;
        }

        // Return height of current subtree
        return 1 + Math.max(left, right);
    }
}