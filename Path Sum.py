# Leetcode Problem 112: Path Sum
# PYTHON CODE
class TreeNode:

  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:

  def hasPathSum(self, root: TreeNode | None, targetSum: int) -> bool:
    if not root:
      return False

    # Check if we are at a leaf node
    if not root.left and not root.right:
      return root.val == targetSum

    # Recursively check left and right subtrees with the reduced target sum
    remaining_sum = targetSum - root.val
    return self.hasPathSum(root.left, remaining_sum) or self.hasPathSum(
        root.right, remaining_sum
    )