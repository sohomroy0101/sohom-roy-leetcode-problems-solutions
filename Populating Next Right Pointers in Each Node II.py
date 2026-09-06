# Leetcode Problem 117: Populating Next Right Pointers in Each Node II
# PYTHON CODE
class Solution:

    def connect(self, root: 'Node') -> 'Node':
        if not root:
            return None

        curr = root  # Points to the head of the current level

        while curr:
            dummy = Node(0)  # Dummy head for building the next level
            tail = dummy  # Tracks the tail of the next level list

            # Traverse the current level horizontally
            while curr:
                if curr.left:
                    tail.next = curr.left
                    tail = tail.next

                if curr.right:
                    tail.next = curr.right
                    tail = tail.next

                curr = curr.next  # Move to the next node on the current level

            # Move curr to the start of the next level
            curr = dummy.next

        return root