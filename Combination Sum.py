# Leetcode Problem 39: Combination Sum
# PYTHON CODE
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        ans = []
        path = []

        def backtrack(index, target):
            if target == 0:
                ans.append(path[:])
                return

            if target < 0:
                return

            for i in range(index, len(candidates)):
                path.append(candidates[i])
                backtrack(i, target - candidates[i])
                path.pop()

        backtrack(0, target)
        return ans