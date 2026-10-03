# Leetcode Problem 145: Binary Tree Postorder Traversal
# PYTHON CODE
from typing import Optional, List

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        
        result = []
        stack = [root]
        
        # Traverse Root -> Right -> Left
        while stack:
            node = stack.pop()
            result.append(node.val)
            
            # Push left first so right is processed first
            if node.left:
                stack.append(node.left)
            if node.right:
                stack.append(node.right)
                
        # Reverse to get Left -> Right -> Root
        return result[::-1]