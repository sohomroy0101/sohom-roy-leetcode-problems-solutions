# Leetcode Problem 111: Minimum Depth of Binary Tree
# PYTHON CODE
from collections import deque

class Solution:
    def minDepth(self, root):

        # Empty tree
        if root is None:
            return 0

        queue = deque([(root, 1)])

        while queue:

            node, depth = queue.popleft()

            # First leaf found = minimum depth
            if node.left is None and node.right is None:
                return depth

            # Add left child
            if node.left is not None:
                queue.append((node.left, depth + 1))

            # Add right child
            if node.right is not None:
                queue.append((node.right, depth + 1))

        return 0