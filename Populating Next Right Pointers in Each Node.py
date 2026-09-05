# Leetcode Problem 116: Populating Next Right Pointers in Each Node
# PYTHON CODE
class Solution:

    def connect(self, root: 'Optional[Node]') -> 'Optional[Node]':
        if not root:
            return None

        # Start with the root node
        leftmost = root

        # Outer loop traverses level by level along the leftmost node
        while leftmost.left:
            curr = leftmost

            # Inner loop traverses nodes in the current level horizontally
            while curr:
                # Connection 1: Connect left child -> right child
                curr.left.next = curr.right

                # Connection 2: Connect right child -> next parent's left child
                if curr.next:
                    curr.right.next = curr.next.left

                # Move to next node in current level
                curr = curr.next

            # Move to the leftmost node of the next level
            leftmost = leftmost.left

        return root