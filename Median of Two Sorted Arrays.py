# Leetcode Problem 4: Median of Two Sorted Arrays
# Python Code
class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        m, n = len(nums1), len(nums2)
        temp = []
        i, j = 0, 0

        while i < m and j < n:
            if nums1[i] < nums2[j]:
                temp.append(nums1[i])
                i += 1
            else:
                temp.append(nums2[j])
                j += 1

        temp.extend(nums1[i:])
        temp.extend(nums2[j:])

        size = m + n
        if size % 2 != 0:
            return temp[size // 2]
        else:
            return (temp[size // 2] + temp[size // 2 - 1]) / 2.0