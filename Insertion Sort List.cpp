// Leetcode Problem 147: Insertion Sort List
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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = head;
        ListNode* curr = head->next;

        while (curr) {
            // Fast path: If curr is already >= prev, it is already in correct sorted order
            if (curr->val >= prev->val) {
                prev = curr;
                curr = curr->next;
            } else {
                // Search for insertion position starting from dummy
                ListNode* scan = &dummy;
                while (scan->next->val < curr->val) {
                    scan = scan->next;
                }

                // Splice curr out of its current position and insert after scan
                prev->next = curr->next;
                curr->next = scan->next;
                scan->next = curr;

                // Advance to the next unsorted node
                curr = prev->next;
            }
        }

        return dummy.next;
    }
};