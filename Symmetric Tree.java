// Leetcode Problem 101: Symmetric Tree
// JAVA CODE
class Solution {
    public boolean isSymmetric(TreeNode root) {
        return isMirror(root.left, root.right);
    }

    private boolean isMirror(TreeNode left, TreeNode right) {

        // Both nodes are null
        if (left == null && right == null) {
            return true;
        }

        // One node is null and the other isn't
        if (left == null || right == null) {
            return false;
        }

        // Values are different
        if (left.val != right.val) {
            return false;
        }

        // Compare opposite subtrees
        return isMirror(left.left, right.right) &&
               isMirror(left.right, right.left);
    }
}