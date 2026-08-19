// Leetcode Problem: 99. Recover Binary Search Tree
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
 */

class Solution {
    public void recoverTree(TreeNode root) {

        TreeNode first = null;
        TreeNode second = null;
        TreeNode prev = null;

        TreeNode curr = root;

        while (curr != null) {

            if (curr.left == null) {

                // Visit current node
                if (prev != null && prev.val > curr.val) {
                    if (first == null) {
                        first = prev;
                    }

                    second = curr;
                }

                prev = curr;
                curr = curr.right;

            } else {

                // Find inorder predecessor
                TreeNode predecessor = curr.left;

                while (predecessor.right != null &&
                       predecessor.right != curr) {
                    predecessor = predecessor.right;
                }

                if (predecessor.right == null) {

                    // Create temporary thread
                    predecessor.right = curr;
                    curr = curr.left;

                } else {

                    // Remove temporary thread
                    predecessor.right = null;

                    // Visit current node
                    if (prev != null && prev.val > curr.val) {
                        if (first == null) {
                            first = prev;
                        }

                        second = curr;
                    }

                    prev = curr;
                    curr = curr.right;
                }
            }
        }

        // Swap the values of the two incorrect nodes
        int temp = first.val;
        first.val = second.val;
        second.val = temp;
    }
}