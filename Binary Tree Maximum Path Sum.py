# Leetcode Problem 124: Binary Tree Maximum Path Sum
# PYTHON CODE
from typing import Optional


# Definition for a binary tree node.
class TreeNode:

    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:

    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        max_sum = float("-inf")

        def gain_from_subtree(node: Optional[TreeNode]) -> int:
            nonlocal max_sum
            if not node:
                return 0

            # Compute maximum contribution from left and right subtrees
            # Ignore negative contributions by clamping to 0
            left_gain = max(0, gain_from_subtree(node.left))
            right_gain = max(0, gain_from_subtree(node.right))

            # Price of the current node acting as the root of the path
            current_path_sum = node.val + left_gain + right_gain

            # Update the global maximum path sum
            max_sum = max(max_sum, current_path_sum)

            # Return the maximum single-branch path sum to the parent
            return node.val + max(left_gain, right_gain)

        gain_from_subtree(root)
        return max_sum