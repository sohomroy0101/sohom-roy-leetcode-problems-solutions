# Leetcode Problem 94: Binary Tree Inorder Traversal
# PYTHON CODE
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        result = []
        stack = []
        curr = root

        while curr or stack:
            # Go as far left as possible
            while curr:
                stack.append(curr)
                curr = curr.left

            # Visit the node
            curr = stack.pop()
            result.append(curr.val)

            # Move to the right subtree
            curr = curr.right

        return result