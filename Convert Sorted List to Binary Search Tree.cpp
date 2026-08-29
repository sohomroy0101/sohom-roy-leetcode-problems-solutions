// Leetcode Problem 109: Convert Sorted List to Binary Search Tree
// C++ CODE
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {

        // Empty list
        if (head == nullptr) {
            return nullptr;
        }

        // Single node
        if (head->next == nullptr) {
            return new TreeNode(head->val);
        }

        // Find the middle node
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Disconnect the left half from the middle node
        prev->next = nullptr;

        // Middle node becomes the root
        TreeNode* root = new TreeNode(slow->val);

        // Build left subtree
        root->left = sortedListToBST(head);

        // Build right subtree
        root->right = sortedListToBST(slow->next);

        return root;
    }
};