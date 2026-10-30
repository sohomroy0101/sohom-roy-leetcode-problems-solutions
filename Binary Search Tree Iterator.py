# Leetcode Problem 173: Binary Search Tree Iterator
# PYTHON CODE
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class BSTIterator:

    def __init__(self, root: TreeNode):
        self.stack = []
        self._push_left(root)

    def _push_left(self, node: TreeNode):
        while node:
            self.stack.append(node)
            node = node.left

    def next(self) -> int:
        # The top of the stack is the next smallest element
        node = self.stack.pop()
        
        # If there is a right subtree, process its leftmost path
        if node.right:
            self._push_left(node.right)
            
        return node.val

    def hasNext(self) -> bool:
        return len(self.stack) > 0