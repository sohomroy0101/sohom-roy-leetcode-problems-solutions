// Leetcode Problem 113: Path Sum II
// JAVA CODE
class Solution {
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> currentPath = new ArrayList<>();
        dfs(root, targetSum, currentPath, result);
        return result;
    }

    private void dfs(TreeNode node, int targetSum, List<Integer> currentPath, List<List<Integer>> result) {
        if (node == null) {
            return;
        }

        // Choose: add current node value to path
        currentPath.add(node.val);

        // Check leaf condition and target sum match
        if (node.left == null && node.right == null && targetSum == node.val) {
            result.add(new ArrayList<>(currentPath)); // Copy currentPath to result
        } else {
            // Explore subtrees with reduced targetSum
            dfs(node.left, targetSum - node.val, currentPath, result);
            dfs(node.right, targetSum - node.val, currentPath, result);
        }

        // Backtrack: remove last element before returning to parent
        currentPath.remove(currentPath.size() - 1);
    }
}