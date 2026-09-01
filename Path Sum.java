// Leetcode Problem 112: Path Sum
// JAVA CODE
class Solution {
    public boolean hasPathSum(TreeNode root, int targetSum) {
        if (root == null) {
            return false;
        }

        // Subtract the current node's value from targetSum
        targetSum -= root.val;

        // If it's a leaf node, check if the remaining targetSum is 0
        if (root.left == null && root.right == null) {
            return targetSum == 0;
        }

        // Recursively check left and right subtrees
        return hasPathSum(root.left, targetSum) || hasPathSum(root.right, targetSum);
    }
}