// Leetcode Problem 71: Simplify Path
// JAVA CODE
class Solution {
    public String simplifyPath(String path) {
        Deque<String> stack = new ArrayDeque<>();

        for (String part : path.split("/")) {
            if (part.equals("") || part.equals(".")) {
                continue;
            } else if (part.equals("..")) {
                if (!stack.isEmpty()) {
                    stack.pollLast();
                }
            } else {
                stack.offerLast(part);
            }
        }

        if (stack.isEmpty()) {
            return "/";
        }

        StringBuilder result = new StringBuilder();

        while (!stack.isEmpty()) {
            result.append("/").append(stack.pollFirst());
        }

        return result.toString();
    }
}