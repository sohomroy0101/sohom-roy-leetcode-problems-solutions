// Leetcode Problem 117: Populating Next Right Pointers in Each Node II
// JAVA CODE
class Solution {
    public Node connect(Node root) {
        if (root == null) {
            return null;
        }

        Node curr = root; // Points to the head of the current level

        while (curr != null) {
            Node dummy = new Node(0); // Dummy head for building the next level's linked list
            Node tail = dummy; // Tracks the tail of the next level

            // Traverse the current level horizontally
            while (curr != null) {
                if (curr.left != null) {
                    tail.next = curr.left;
                    tail = tail.next;
                }
                if (curr.right != null) {
                    tail.next = curr.right;
                    tail = tail.next;
                }

                curr = curr.next; // Move to next node on current level
            }

            // Advance curr to the start of the next level
            curr = dummy.next;
        }

        return root;
    }
}