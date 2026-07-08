// Leetcode Problem 19: Remove Nth Node from End of List
// C++ CODE

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* first = dummy;
        ListNode* second = dummy;

        // Move first pointer n steps ahead
        for (int i = 0; i < n; i++) {
            first = first->next;
        }

        // Move both pointers until first reaches the end
        while (first->next != nullptr) {
            first = first->next;
            second = second->next;
        }

        // Remove the nth node from the end
        ListNode* nodeToRemove = second->next;
        second->next = second->next->next;
        delete nodeToRemove;

        return dummy->next;
    }
};