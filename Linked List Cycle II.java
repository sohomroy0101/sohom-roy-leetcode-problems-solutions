// Leetcode Problem 142: Linked List Cycle II
// JAVA CODE
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {

    public ListNode detectCycle(ListNode head) {
        if (head == null) return null;

        ListNode slow = head;
        ListNode fast = head;

        // Phase 1: Detect if a cycle exists
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;

            if (slow == fast) {
                // Phase 2: Find the entry node of the cycle
                slow = head;
                while (slow != fast) {
                    slow = slow.next;
                    fast = fast.next;
                }
                return slow; // Both pointers meet at the cycle entry node
            }
        }

        return null; // No cycle found
    }
}