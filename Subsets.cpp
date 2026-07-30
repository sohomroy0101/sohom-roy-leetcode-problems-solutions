// Leetcode Problem 78: Subsets
// C++ CODE
class Solution {
public:
    vector<vector<int>> result;
    vector<int> subset;

    void backtrack(int start, vector<int>& nums) {
        result.push_back(subset);

        for (int i = start; i < nums.size(); i++) {
            subset.push_back(nums[i]);
            backtrack(i + 1, nums);
            subset.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(0, nums);
        return result;
    }
};