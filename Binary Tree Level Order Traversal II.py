# Leetcode Problem 107: Binary Tree Level Order Traversal II
# PYTHON CODE
from collections import deque

class Solution:
    def levelOrderBottom(self, root):
        
        if root is None:
            return []

        result = []
        queue = deque([root])

        while queue:
            level = []

            # Process current level
            for _ in range(len(queue)):
                node = queue.popleft()

                level.append(node.val)

                if node.left:
                    queue.append(node.left)

                if node.right:
                    queue.append(node.right)

            # Add current level
            result.append(level)

        # Reverse the result for bottom-up order
        result.reverse()

        return result