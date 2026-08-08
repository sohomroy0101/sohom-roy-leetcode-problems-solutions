// Leetcode Problem 87: Scramble String
// JAVA CODE
class Solution {
    private HashMap<String, Boolean> memo = new HashMap<>();

    public boolean isScramble(String s1, String s2) {
        return solve(s1, s2);
    }

    private boolean solve(String a, String b) {
        if (a.equals(b)) {
            return true;
        }

        String key = a + "#" + b;

        if (memo.containsKey(key)) {
            return memo.get(key);
        }

        char[] ca = a.toCharArray();
        char[] cb = b.toCharArray();

        Arrays.sort(ca);
        Arrays.sort(cb);

        if (!Arrays.equals(ca, cb)) {
            memo.put(key, false);
            return false;
        }

        int n = a.length();

        for (int i = 1; i < n; i++) {

            // No swap
            if (solve(a.substring(0, i), b.substring(0, i)) &&
                solve(a.substring(i), b.substring(i))) {

                memo.put(key, true);
                return true;
            }

            // Swap
            if (solve(a.substring(0, i), b.substring(n - i)) &&
                solve(a.substring(i), b.substring(0, n - i))) {

                memo.put(key, true);
                return true;
            }
        }

        memo.put(key, false);
        return false;
    }
}