# Leetcode Problem 104: Maximum Depth of Binary Tree
# PYTHON CODE
class Solution:
    def maxDepth(self, root):
        
        # Empty tree
        if root is None:
            return 0
        
        # Find depth of left and right subtrees
        leftDepth = self.maxDepth(root.left)
        rightDepth = self.maxDepth(root.right)
        
        # Current node adds 1 to the maximum depth
        return 1 + max(leftDepth, rightDepth)