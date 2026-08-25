# Leetcode Problem 105: Construct Binary Tree from Preorder and Inorder Traversal
# PYTHON CODE
class Solution:
    def buildTree(self, preorder, inorder):
        
        # Store index of each value in inorder
        inorder_index = {
            value: index for index, value in enumerate(inorder)
        }

        preorder_index = 0

        def build(left, right):
            nonlocal preorder_index

            # No elements in this subtree
            if left > right:
                return None

            # First preorder element is the root
            root_value = preorder[preorder_index]
            preorder_index += 1

            root = TreeNode(root_value)

            # Find root position in inorder
            mid = inorder_index[root_value]

            # Build left subtree
            root.left = build(left, mid - 1)

            # Build right subtree
            root.right = build(mid + 1, right)

            return root

        return build(0, len(inorder) - 1)