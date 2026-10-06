# Leetcode Problem 148: Sort List
# PYTHON CODE
from typing import Optional

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head

        # Step 1: Split the list into two halves using slow/fast pointers
        prev = None
        slow, fast = head, head
        
        while fast and fast.next:
            prev = slow
            slow = slow.next
            fast = fast.next.next

        # Disconnect first half from second half
        prev.next = None

        # Step 2: Recursively sort both halves
        left = self.sortList(head)
        right = self.sortList(slow)

        # Step 3: Merge the two sorted lists
        return self._merge(left, right)

    def _merge(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0)
        tail = dummy

        while list1 and list2:
            if list1.val < list2.val:
                tail.next = list1
                list1 = list1.next
            else:
                tail.next = list2
                list2 = list2.next
            tail = tail.next

        # Attach remaining nodes
        if list1:
            tail.next = list1
        elif list2:
            tail.next = list2

        return dummy.next