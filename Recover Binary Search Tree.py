# Leetcode Problem: 99. Recover Binary Search Tree
# PYTHON CODE

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def recoverTree(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """

        first = None
        second = None
        prev = None

        curr = root

        while curr:
            if curr.left is None:
                # Visit current node
                if prev and prev.val > curr.val:
                    if first is None:
                        first = prev
                    second = curr

                prev = curr
                curr = curr.right

            else:
                # Find inorder predecessor
                predecessor = curr.left

                while predecessor.right and predecessor.right != curr:
                    predecessor = predecessor.right

                if predecessor.right is None:
                    # Create temporary thread
                    predecessor.right = curr
                    curr = curr.left

                else:
                    # Remove temporary thread
                    predecessor.right = None

                    # Visit current node
                    if prev and prev.val > curr.val:
                        if first is None:
                            first = prev
                        second = curr

                    prev = curr
                    curr = curr.right

        # Swap the two incorrect values
        first.val, second.val = second.val, first.val