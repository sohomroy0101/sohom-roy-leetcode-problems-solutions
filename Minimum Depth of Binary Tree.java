// Leetcode Problem 111: Minimum Depth of Binary Tree
// JAVA CODE
import java.util.*;

class Solution {

    public int minDepth(TreeNode root) {

        // Empty tree
        if (root == null) {
            return 0;
        }

        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);

        int depth = 1;

        while (!queue.isEmpty()) {

            int size = queue.size();

            // Process one level
            for (int i = 0; i < size; i++) {

                TreeNode node = queue.poll();

                // First leaf found = minimum depth
                if (node.left == null && node.right == null) {
                    return depth;
                }

                // Add left child
                if (node.left != null) {
                    queue.offer(node.left);
                }

                // Add right child
                if (node.right != null) {
                    queue.offer(node.right);
                }
            }

            depth++;
        }

        return 0;
    }
}