# Leetcode Problem 110: Balanced Binary Tree
# PYTHON CODE
class Solution:
    def isBalanced(self, root):

        def height(node):

            # Empty tree has height 0
            if node is None:
                return 0

            # Height of left subtree
            left = height(node.left)

            # If left subtree is unbalanced
            if left == -1:
                return -1

            # Height of right subtree
            right = height(node.right)

            # If right subtree is unbalanced
            if right == -1:
                return -1

            # If current node is unbalanced
            if abs(left - right) > 1:
                return -1

            # Return height of current subtree
            return 1 + max(left, right)

        return height(root) != -1