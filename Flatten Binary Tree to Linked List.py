# Leetcode Problem 114: Flatten Binary Tree to Linked List
# PYTHON CODE
class Solution:

    def flatten(self, root: Optional[TreeNode]) -> None:
        """Do not return anything, modify root in-place instead."""
        curr = root

        while curr:
            if curr.left:
                # Find the rightmost node in the left subtree
                prev = curr.left
                while prev.right:
                    prev = prev.right  # Advance pointer to find the tail

                # Connect the tail of left subtree to current's right subtree
                prev.right = curr.right

                # Move left subtree to the right side and clear left pointer
                curr.right = curr.left
                curr.left = None

            # Move to the next node down the right chain
            curr = curr.right