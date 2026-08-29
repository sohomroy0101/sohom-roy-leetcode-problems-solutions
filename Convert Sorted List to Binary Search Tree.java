// Leetcode Problem 109: Convert Sorted List to Binary Search Tree
// JAVA CODE
class Solution {

    public TreeNode sortedListToBST(ListNode head) {

        // Empty list
        if (head == null) {
            return null;
        }

        // Single node
        if (head.next == null) {
            return new TreeNode(head.val);
        }

        // Find the middle node
        ListNode slow = head;
        ListNode fast = head;
        ListNode prev = null;

        while (fast != null && fast.next != null) {
            prev = slow;
            slow = slow.next;
            fast = fast.next.next;
        }

        // Disconnect the left half from the middle node
        prev.next = null;

        // Middle node becomes root
        TreeNode root = new TreeNode(slow.val);

        // Build left subtree
        root.left = sortedListToBST(head);

        // Build right subtree
        root.right = sortedListToBST(slow.next);

        return root;
    }
}