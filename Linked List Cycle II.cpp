// Leetcode Problem 142: Linked List Cycle II
// C++ CODE
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head) return nullptr;

        ListNode *slow = head;
        ListNode *fast = head;

        // Phase 1: Detect if a cycle exists
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Phase 2: Find the entry node of the cycle
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow; // Both pointers meet at the cycle entry node
            }
        }

        return nullptr; // No cycle found
    }
};