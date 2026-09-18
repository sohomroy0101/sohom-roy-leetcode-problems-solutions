# Leetcode Problem 129: Sum Root to Leaf Numbers
# PYTHON CODE
from typing import Optional


# Definition for a binary tree node.
class TreeNode:

    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:

    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        def dfs(node: Optional[TreeNode], current_sum: int) -> int:
            if not node:
                return 0

            # Form the path number up to the current node
            current_sum = current_sum * 10 + node.val

            # If it's a leaf node, return the completed path number
            if not node.left and not node.right:
                return current_sum

            # Recurse for left and right subtrees and sum their path results
            return dfs(node.left, current_sum) + dfs(node.right, current_sum)

        return dfs(root, 0)