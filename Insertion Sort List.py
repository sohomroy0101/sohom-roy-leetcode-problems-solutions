# Leetcode Problem 147: Insertion Sort List
# PYTHON CODE
from typing import Optional

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def insertionSortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head

        dummy = ListNode(0)
        dummy.next = head
        
        prev = head
        curr = head.next

        while curr:
            # Optimization: If curr is already >= prev, it is in correct position
            if curr.val >= prev.val:
                prev = curr
                curr = curr.next
            else:
                # Find the position to insert curr (starting from dummy)
                scan = dummy
                while scan.next.val < curr.val:
                    scan = scan.next

                # Insert curr between scan and scan.next
                prev.next = curr.next
                curr.next = scan.next
                scan.next = curr

                # Move to next unsorted node
                curr = prev.next

        return dummy.next