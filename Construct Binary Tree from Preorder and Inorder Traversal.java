// Leetcode Problem 105: Construct Binary Tree from Preorder and Inorder Traversal
// JAVA CODE
class Solution {

    private int preorderIndex = 0;
    private Map<Integer, Integer> inorderIndex = new HashMap<>();

    public TreeNode buildTree(int[] preorder, int[] inorder) {

        // Store the index of each value in inorder
        for (int i = 0; i < inorder.length; i++) {
            inorderIndex.put(inorder[i], i);
        }

        return build(preorder, 0, inorder.length - 1);
    }

    private TreeNode build(int[] preorder, int left, int right) {

        // No elements in this subtree
        if (left > right) {
            return null;
        }

        // First element in preorder is the root
        int rootValue = preorder[preorderIndex++];

        TreeNode root = new TreeNode(rootValue);

        // Find root position in inorder
        int mid = inorderIndex.get(rootValue);

        // Build left subtree
        root.left = build(preorder, left, mid - 1);

        // Build right subtree
        root.right = build(preorder, mid + 1, right);

        return root;
    }
}