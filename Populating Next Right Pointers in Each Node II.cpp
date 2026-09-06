// Leetcode Problem 117: Populating Next Right Pointers in Each Node II
// C++ CODE
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) {
            return nullptr;
        }

        Node* curr = root; // Points to the head of the current level

        while (curr) {
            Node dummy(0); // Dummy head for building the next level's linked list
            Node* tail = &dummy; // Tracks the tail of the next level

            // Traverse the current level horizontally
            while (curr) {
                if (curr->left) {
                    tail->next = curr->left;
                    tail = tail->next;
                }
                if (curr->right) {
                    tail->next = curr->right;
                    tail = tail->next;
                }

                curr = curr->next; // Move to next node on current level
            }

            // Advance curr to the start of the next level
            curr = dummy.next;
        }

        return root;
    }
};