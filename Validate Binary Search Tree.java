// Leetcode Problem 98: Validate Binary Search Tree
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

    public boolean isValidBST(TreeNode root) {
        return validate(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }

    private boolean validate(TreeNode node, long low, long high) {
        if (node == null) {
            return true;
        }

        // Node value must be strictly inside the valid range
        if (node.val <= low || node.val >= high) {
            return false;
        }

        // Left subtree: values must be smaller than node.val
        // Right subtree: values must be greater than node.val
        return validate(node.left, low, node.val)
                && validate(node.right, node.val, high);
    }
}