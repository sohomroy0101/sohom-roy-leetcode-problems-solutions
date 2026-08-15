# Leetcode Problem 95: Unique Binary Search Trees II
# PYTHON CODE
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
        if n == 0:
            return []

        def build(start, end):
            if start > end:
                return [None]

            result = []

            # Choose every value as the root
            for root in range(start, end + 1):
                left_trees = build(start, root - 1)
                right_trees = build(root + 1, end)

                # Combine every left subtree with every right subtree
                for left in left_trees:
                    for right in right_trees:
                        node = TreeNode(root)
                        node.left = left
                        node.right = right
                        result.append(node)

            return result

        return build(1, n)