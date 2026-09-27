// Leetcode Problem 138: Copy List with Random Pointer
// C++ CODE
#include <cstddef>

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // Step 1: Create interleaved clone nodes (A -> A' -> B -> B')
        Node* curr = head;
        while (curr) {
            Node* clone = new Node(curr->val);
            clone->next = curr->next;
            curr->next = clone;
            curr = clone->next;
        }

        // Step 2: Assign random pointers for cloned nodes
        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // Step 3: Unweave original list and cloned list
        Node dummy(0);
        Node* copyCurr = &dummy;
        curr = head;

        while (curr) {
            Node* clone = curr->next;
            copyCurr->next = clone;
            copyCurr = copyCurr->next;

            // Restore original list pointers
            curr->next = clone->next;
            curr = curr->next;
        }

        return dummy.next;
    }
};