# Leetcode Problem 101: Symmetric Tree
# PYTHON CODE
class Solution:
    def isSymmetric(self, root):
        
        def isMirror(left, right):
            # Both nodes are None
            if left is None and right is None:
                return True
            
            # One node is None and the other isn't
            if left is None or right is None:
                return False
            
            # Values are different
            if left.val != right.val:
                return False
            
            # Compare opposite subtrees
            return (isMirror(left.left, right.right) and
                    isMirror(left.right, right.left))
        
        return isMirror(root.left, root.right)