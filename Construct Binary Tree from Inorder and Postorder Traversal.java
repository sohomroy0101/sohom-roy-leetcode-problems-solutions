// Leetcode Problem 106: Construct Binary Tree from Inorder and Postorder Traversal
// JAVA CODE
class Solution {

    private int postorderIndex;
    private Map<Integer, Integer> inorderIndex;

    public TreeNode buildTree(int[] inorder, int[] postorder) {

        // Store the index of each value in inorder
        inorderIndex = new HashMap<>();

        for (int i = 0; i < inorder.length; i++) {
            inorderIndex.put(inorder[i], i);
        }

        // Start from the last element of postorder
        postorderIndex = postorder.length - 1;

        return build(inorder, postorder, 0, inorder.length - 1);
    }

    private TreeNode build(int[] inorder, int[] postorder,
                           int left, int right) {

        // No elements in this subtree
        if (left > right) {
            return null;
        }

        // Last element of postorder is the root
        int rootValue = postorder[postorderIndex--];

        TreeNode root = new TreeNode(rootValue);

        // Find root position in inorder
        int mid = inorderIndex.get(rootValue);

        // Build right subtree first
        root.right = build(inorder, postorder, mid + 1, right);

        // Build left subtree
        root.left = build(inorder, postorder, left, mid - 1);

        return root;
    }
}