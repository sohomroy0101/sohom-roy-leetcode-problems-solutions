# Leetcode Problem 109: Convert Sorted List to Binary Search Tree
# PYTHON CODE
class Solution:
    def sortedListToBST(self, head):

        # Empty list
        if head is None:
            return None

        # Single node
        if head.next is None:
            return TreeNode(head.val)

        # Find middle node
        slow = head
        fast = head
        prev = None

        while fast and fast.next:
            prev = slow
            slow = slow.next
            fast = fast.next.next

        # Disconnect left half from middle node
        prev.next = None

        # Middle node becomes root
        root = TreeNode(slow.val)

        # Build left subtree
        root.left = self.sortedListToBST(head)

        # Build right subtree
        root.right = self.sortedListToBST(slow.next)

        return root