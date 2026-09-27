# Leetcode Problem 138: Copy List with Random Pointer
# PYTHON CODE
from typing import Optional


# Definition for a Node.
class Node:

    def __init__(
        self,
        x: int,
        next: 'Optional[Node]' = None,
        random: 'Optional[Node]' = None,
    ):
        self.val = int(x)
        self.next = next
        self.random = random


class Solution:

    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if not head:
            return None

        # Step 1: Interleave duplicate nodes: A -> A' -> B -> B'
        curr = head
        while curr:
            cloned = Node(curr.val, curr.next)
            curr.next = cloned
            curr = cloned.next

        # Step 2: Assign random pointers for cloned nodes
        curr = head
        while curr:
            if curr.random:
                curr.next.random = curr.random.next
            curr = curr.next.next

        # Step 3: Unweave original list and cloned list
        dummy = Node(0)
        copy_curr = dummy
        curr = head

        while curr:
            cloned = curr.next
            copy_curr.next = cloned
            copy_curr = copy_curr.next

            # Restore original list pointers
            curr.next = cloned.next
            curr = curr.next

        return dummy.next