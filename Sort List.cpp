// Leetcode Problem 148: Sort List
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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        // Step 1: Find the middle of the linked list (Slow & Fast pointers)
        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Disconnect first half from second half
        prev->next = nullptr;

        // Step 2: Recursively sort both sublists
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);

        // Step 3: Merge sorted halves
        return merge(left, right);
    }

private:
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        // Attach remaining nodes
        if (list1) {
            tail->next = list1;
        } else if (list2) {
            tail->next = list2;
        }

        return dummy.next;
    }
};