// Leetcode Problem 127: Word Ladder
// JAVA CODE
import java.util.*;

class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Set<String> wordSet = new HashSet<>(wordList);
        if (!wordSet.contains(endWord)) {
            return 0;
        }

        // Two sets representing frontiers from both start and end
        Set<String> beginSet = new HashSet<>();
        Set<String> endSet = new HashSet<>();

        beginSet.add(beginWord);
        endSet.add(endWord);

        int wordLen = beginWord.length();
        int step = 1;

        while (!beginSet.isEmpty() && !endSet.isEmpty()) {
            // Always expand the smaller frontier set to minimize branching
            if (beginSet.size() > endSet.size()) {
                Set<String> temp = beginSet;
                beginSet = endSet;
                endSet = temp;
            }

            Set<String> nextLevel = new HashSet<>();

            for (String word : beginSet) {
                char[] charArray = word.toCharArray();

                for (int i = 0; i < wordLen; i++) {
                    char originalChar = charArray[i];

                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == originalChar) continue;

                        charArray[i] = c;
                        String nextWord = new String(charArray);

                        // Intersection found between front and back search frontiers
                        if (endSet.contains(nextWord)) {
                            return step + 1;
                        }

                        if (wordSet.contains(nextWord)) {
                            nextLevel.add(nextWord);
                            wordSet.remove(nextWord); // Mark as visited
                        }
                    }
                    charArray[i] = originalChar; // Restore character
                }
            }

            beginSet = nextLevel;
            step++;
        }

        return 0;
    }
}