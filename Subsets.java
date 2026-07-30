// Leetcode Problem 78: Subsets
// JAVA CODE
class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> subset = new ArrayList<>();

        backtrack(0, nums, subset, result);

        return result;
    }

    private void backtrack(int start, int[] nums,
                           List<Integer> subset,
                           List<List<Integer>> result) {
        result.add(new ArrayList<>(subset));

        for (int i = start; i < nums.length; i++) {
            subset.add(nums[i]);
            backtrack(i + 1, nums, subset, result);
            subset.remove(subset.size() - 1);
        }
    }
}