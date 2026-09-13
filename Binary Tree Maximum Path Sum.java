// Leetcode Problem 124: Binary Tree Maximum Path Sum
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
    private int maxSum = Integer.MIN_VALUE;

    public int maxPathSum(TreeNode root) {
        maxGain(root);
        return maxSum;
    }

    private int maxGain(TreeNode node) {
        if (node == null) {
            return 0;
        }

        // Recursively compute the maximum gain from left and right subtrees.
        // Clamped to 0 to ignore paths with negative sums.
        int leftGain = Math.max(0, maxGain(node.left));
        int rightGain = Math.max(0, maxGain(node.right));

        // Price of current node being the root of the path (split point)
        int currentPathSum = node.val + leftGain + rightGain;

        // Update the global maximum path sum
        maxSum = Math.max(maxSum, currentPathSum);

        // Return the maximum branch sum that can be extended to the parent
        return node.val + Math.max(leftGain, rightGain);
    }
}