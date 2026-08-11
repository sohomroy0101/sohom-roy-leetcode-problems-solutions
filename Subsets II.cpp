// Leetcode Problem 90: Subsets II
// C++ CODE
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        vector<int> path;

        backtrack(nums, 0, path, result);

        return result;
    }

private:
    void backtrack(vector<int>& nums, int start,
                   vector<int>& path,
                   vector<vector<int>>& result) {

        result.push_back(path);

        for (int i = start; i < nums.size(); i++) {
            // Skip duplicates at the same recursion level
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }

            path.push_back(nums[i]);

            backtrack(nums, i + 1, path, result);

            path.pop_back();
        }
    }
};