# Leetcode Problem 113: Path Sum II
# PYTHON CODE
class Solution:

    def pathSum(
        self, root: Optional[TreeNode], targetSum: int
    ) -> List[List[int]]:
        result = []

        def dfs(node, current_sum, path):
            if not node:
                return

            # Append current node to path and update current sum
            path.append(node.val)
            current_sum += node.val

            # Check if it's a leaf node and path sum matches targetSum
            if not node.left and not node.right and current_sum == targetSum:
                result.append(list(path))  # Append a copy of path

            # Recurse on left and right subtrees
            dfs(node.left, current_sum, path)
            dfs(node.right, current_sum, path)

            # Backtrack: remove node before returning to parent
            path.pop()

        dfs(root, 0, [])
        return result