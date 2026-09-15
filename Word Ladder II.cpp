// Leetcode Problem 126: Word Ladder II
// C++ CODE
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <algorithm>

class Solution {
private:
    void dfs(const std::string& currWord, 
             const std::string& beginWord, 
             std::unordered_map<std::string, int>& dist, 
             std::vector<std::string>& path, 
             std::vector<std::vector<std::string>>& results) {
        
        if (currWord == beginWord) {
            std::vector<std::string> validPath = path;
            std::reverse(validPath.begin(), validPath.end());
            results.push_back(validPath);
            return;
        }

        int currDist = dist[currWord];
        std::string word = currWord;

        for (size_t i = 0; i < word.length(); ++i) {
            char originalChar = word[i];

            for (char c = 'a'; c <= 'z'; ++c) {
                if (c == originalChar) continue;

                word[i] = c;

                // Step only to valid predecessors with distance == currDist - 1
                if (dist.count(word) && dist[word] == currDist - 1) {
                    path.push_back(word);
                    dfs(word, beginWord, dist, path, results);
                    path.pop_back(); // Backtrack
                }
            }
            word[i] = originalChar;
        }
    }

public:
    std::vector<std::vector<std::string>> findLadders(std::string beginWord, 
                                                      std::string endWord, 
                                                      std::vector<std::string>& wordList) {
        std::vector<std::vector<std::string>> results;
        std::unordered_set<std::string> wordSet(wordList.begin(), wordList.end());

        if (!wordSet.count(endWord)) {
            return results;
        }

        // Phase 1: BFS to calculate shortest distances from beginWord
        std::unordered_map<std::string, int> dist;
        dist[beginWord] = 0;

        std::queue<std::string> q;
        q.push(beginWord);

        bool found = false;

        while (!q.empty() && !found) {
            size_t levelSize = q.size();

            for (size_t k = 0; k < levelSize; ++k) {
                std::string curr = q.front();
                q.pop();

                int currDist = dist[curr];
                std::string word = curr;

                for (size_t i = 0; i < word.length(); ++i) {
                    char originalChar = word[i];

                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == originalChar) continue;

                        word[i] = c;

                        if (wordSet.count(word)) {
                            if (!dist.count(word)) {
                                dist[word] = currDist + 1;
                                q.push(word);

                                if (word == endWord) {
                                    found = true;
                                }
                            }
                        }
                    }
                    word[i] = originalChar;
                }
            }
        }

        if (!dist.count(endWord)) {
            return results;
        }

        // Phase 2: DFS Backtracking from endWord to beginWord
        std::vector<std::string> path;
        path.push_back(endWord);
        dfs(endWord, beginWord, dist, path, results);

        return results;
    }
};