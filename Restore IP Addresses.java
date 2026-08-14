// Leetcode Problem 93: Restore IP Addresses
// JAVA CODE
class Solution {
    public List<String> restoreIpAddresses(String s) {
        List<String> result = new ArrayList<>();
        backtrack(s, 0, new ArrayList<>(), result);
        return result;
    }

    private void backtrack(String s, int start, List<String> parts,
                            List<String> result) {

        // If 4 parts are formed
        if (parts.size() == 4) {
            if (start == s.length()) {
                result.add(String.join(".", parts));
            }
            return;
        }

        // Remaining characters
        int remaining = s.length() - start;
        int partsLeft = 4 - parts.size();

        // Pruning
        if (remaining < partsLeft || remaining > 3 * partsLeft) {
            return;
        }

        // Try segment lengths from 1 to 3
        for (int len = 1; len <= 3; len++) {
            if (start + len > s.length()) {
                break;
            }

            String part = s.substring(start, start + len);

            // Leading zero is not allowed
            if (part.length() > 1 && part.charAt(0) == '0') {
                break;
            }

            // Value must be between 0 and 255
            if (Integer.parseInt(part) > 255) {
                continue;
            }

            parts.add(part);

            backtrack(s, start + len, parts, result);

            parts.remove(parts.size() - 1);
        }
    }
}