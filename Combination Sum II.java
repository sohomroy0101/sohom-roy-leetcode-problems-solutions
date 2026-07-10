// Leetcode Problem 40: Combination Sum II
// JAVA CODE
class Solution {
    private List<List<Integer>> ans = new ArrayList<>();
    private List<Integer> path = new ArrayList<>();

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        backtrack(candidates, target, 0);
        return ans;
    }

    private void backtrack(int[] candidates, int target, int start) {
        if (target == 0) {
            ans.add(new ArrayList<>(path));
            return;
        }

        for (int i = start; i < candidates.length; i++) {
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }

            if (candidates[i] > target) {
                break;
            }

            path.add(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1);
            path.remove(path.size() - 1);
        }
    }
}