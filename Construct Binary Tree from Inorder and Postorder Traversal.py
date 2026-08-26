# Leetcode Problem 106: Construct Binary Tree from Inorder and Postorder Traversal
# PYTHON CODE
class Solution:
    def buildTree(self, inorder, postorder):
        
        # Store each value's index in inorder
        inorder_index = {
            value: index for index, value in enumerate(inorder)
        }

        # Start from the last element of postorder
        postorder_index = len(postorder) - 1

        def build(left, right):
            nonlocal postorder_index

            # No elements in this subtree
            if left > right:
                return None

            # Last postorder element is the root
            root_value = postorder[postorder_index]
            postorder_index -= 1

            root = TreeNode(root_value)

            # Find root position in inorder
            mid = inorder_index[root_value]

            # IMPORTANT:
            # Build right subtree first because we are
            # traversing postorder backwards.
            root.right = build(mid + 1, right)

            # Build left subtree
            root.left = build(left, mid - 1)

            return root

        return build(0, len(inorder) - 1)