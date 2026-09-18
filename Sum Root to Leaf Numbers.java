// Leetcode Problem 129: Sum Root to Leaf Numbers
// JAVA CODE
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int sumNumbers(TreeNode root) {
        return dfs(root, 0);
    }

    private int dfs(TreeNode node, int currentSum) {
        if (node == null) {
            return 0;
        }

        // Build the accumulated number up to the current node
        currentSum = currentSum * 10 + node.val;

        // Leaf node reached: return the completed path number
        if (node.left == null && node.right == null) {
            return currentSum;
        }

        // Sum the results from left and right subtrees
        return dfs(node.left, currentSum) + dfs(node.right, currentSum);
    }
}