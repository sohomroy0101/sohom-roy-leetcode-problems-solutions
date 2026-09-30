// Leetcode Problem 141: Linked List Cycle
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

    public boolean hasCycle(ListNode head) {
        if (head == null) return false;

        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next; // Moves 1 step
            fast = fast.next.next; // Moves 2 steps

            // Fast pointer catches up to slow pointer if a cycle exists
            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
}