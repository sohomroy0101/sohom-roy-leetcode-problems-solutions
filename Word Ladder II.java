// Leetcode Problem 126: Word Ladder II
// JAVA CODE
import java.util.*;

class Solution {
    public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
        List<List<String>> results = new ArrayList<>();
        Set<String> wordSet = new HashSet<>(wordList);
        
        if (!wordSet.contains(endWord)) {
            return results;
        }

        // Phase 1: BFS to find the shortest distance from beginWord to all reachable words
        Map<String, Integer> dist = new HashMap<>();
        dist.put(beginWord, 0);
        
        Queue<String> queue = new LinkedList<>();
        queue.offer(beginWord);
        
        boolean found = false;
        int wordLen = beginWord.length();

        while (!queue.isEmpty() && !found) {
            int levelSize = queue.size();
            
            for (int i = 0; i < levelSize; i++) {
                String curr = queue.poll();
                int currDist = dist.get(curr);
                char[] charArray = curr.toCharArray();

                for (int j = 0; j < wordLen; j++) {
                    char originalChar = charArray[j];
                    
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == originalChar) continue;
                        
                        charArray[j] = c;
                        String nextWord = new String(charArray);

                        if (wordSet.contains(nextWord)) {
                            if (!dist.containsKey(nextWord)) {
                                dist.put(nextWord, currDist + 1);
                                queue.offer(nextWord);
                                
                                if (nextWord.equals(endWord)) {
                                    found = true;
                                }
                            }
                        }
                    }
                    charArray[j] = originalChar; // Backtrack character
                }
            }
        }

        if (!dist.containsKey(endWord)) {
            return results;
        }

        // Phase 2: Backtracking DFS from endWord to beginWord
        List<String> path = new ArrayList<>();
        path.add(endWord);
        dfs(endWord, beginWord, dist, path, results, wordLen);

        return results;
    }

    private void dfs(String currWord, String beginWord, Map<String, Integer> dist, 
                     List<String> path, List<List<String>> results, int wordLen) {
        
        if (currWord.equals(beginWord)) {
            List<String> validPath = new ArrayList<>(path);
            Collections.reverse(validPath); // Reverse to start from beginWord
            results.add(validPath);
            return;
        }

        int currDist = dist.get(currWord);
        char[] charArray = currWord.toCharArray();

        for (int i = 0; i < wordLen; i++) {
            char originalChar = charArray[i];

            for (char c = 'a'; c <= 'z'; c++) {
                if (c == originalChar) continue;

                charArray[i] = c;
                String prevWord = new String(charArray);

                // Only step to valid predecessors with dist == currDist - 1
                if (dist.containsKey(prevWord) && dist.get(prevWord) == currDist - 1) {
                    path.add(prevWord);
                    dfs(prevWord, beginWord, dist, path, results, wordLen);
                    path.remove(path.size() - 1); // Backtrack
                }
            }
            charArray[i] = originalChar;
        }
    }
}