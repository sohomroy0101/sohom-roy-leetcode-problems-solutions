# Leetcode Problem 142: Linked List Cycle II
# PYTHON CODE
from typing import Optional

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        slow = head
        fast = head

        # Phase 1: Detect if a cycle exists
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

            if slow == fast:
                # Phase 2: Locate the starting node of the cycle
                slow = head
                while slow != fast:
                    slow = slow.next
                    fast = fast.next
                return slow

        return None