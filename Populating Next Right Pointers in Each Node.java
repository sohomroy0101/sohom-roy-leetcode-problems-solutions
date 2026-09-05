// Leetcode Problem 116: Populating Next Right Pointers in Each Node
// JAVA CODE
class Solution {
    public Node connect(Node root) {
        if (root == null) {
            return null;
        }

        // Start with the root node
        Node leftmost = root;

        // Traverse down level by level using leftmost pointers
        while (leftmost.left != null) {
            Node curr = leftmost;

            // Traverse horizontally across nodes in the current level
            while (curr != null) {
                // Connection 1: Connect left child -> right child
                curr.left.next = curr.right;

                // Connection 2: Connect right child -> next parent's left child
                if (curr.next != null) {
                    curr.right.next = curr.next.left;
                }

                // Move to next node on the current level
                curr = curr.next;
            }

            // Move to the leftmost node of the next level
            leftmost = leftmost.left;
        }

        return root;
    }
}