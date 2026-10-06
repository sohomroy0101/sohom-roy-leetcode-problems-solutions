// Leetcode Problem 147: Insertion Sort List
// JAVA CODE
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {

    public ListNode insertionSortList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }

        ListNode dummy = new ListNode(0);
        dummy.next = head;

        ListNode prev = head;
        ListNode curr = head.next;

        while (curr != null) {
            // Optimization: If curr is already in sorted order relative to prev
            if (curr.val >= prev.val) {
                prev = curr;
                curr = curr.next;
            } else {
                // Find the insertion position starting from dummy
                ListNode scan = dummy;
                while (scan.next.val < curr.val) {
                    scan = scan.next;
                }

                // Insert curr between scan and scan.next
                prev.next = curr.next;
                curr.next = scan.next;
                scan.next = curr;

                // Move to the next unsorted node
                curr = prev.next;
            }
        }

        return dummy.next;
    }
}