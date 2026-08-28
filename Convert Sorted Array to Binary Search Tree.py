# Leetcode Problem 108: Convert Sorted Array to Binary Search Tree
# PYTHON CODE
class Solution:
    def sortedArrayToBST(self, nums):
        
        def build(left, right):
            
            # No elements
            if left > right:
                return None

            # Middle element becomes root
            mid = (left + right) // 2

            root = TreeNode(nums[mid])

            # Build left subtree
            root.left = build(left, mid - 1)

            # Build right subtree
            root.right = build(mid + 1, right)

            return root

        return build(0, len(nums) - 1)