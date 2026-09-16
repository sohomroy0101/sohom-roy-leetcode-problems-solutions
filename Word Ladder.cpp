// Leetcode Problem 127: Word Ladder
// C++ CODE
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
        std::unordered_set<std::string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) {
            return 0;
        }

        // Two sets representing search frontiers from both directions
        std::unordered_set<std::string> beginSet;
        std::unordered_set<std::string> endSet;

        beginSet.insert(beginWord);
        endSet.insert(endWord);

        int wordLen = beginWord.length();
        int step = 1;

        while (!beginSet.empty() && !endSet.empty()) {
            // Always expand the smaller frontier to minimize branching factor
            if (beginSet.size() > endSet.size()) {
                std::swap(beginSet, endSet);
            }

            std::unordered_set<std::string> nextLevel;

            for (const std::string& word : beginSet) {
                std::string tempWord = word;

                for (int i = 0; i < wordLen; ++i) {
                    char originalChar = tempWord[i];

                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == originalChar) continue;

                        tempWord[i] = c;

                        // Connection found between front and back search frontiers
                        if (endSet.count(tempWord)) {
                            return step + 1;
                        }

                        if (wordSet.count(tempWord)) {
                            nextLevel.insert(tempWord);
                            wordSet.erase(tempWord); // Mark as visited
                        }
                    }
                    tempWord[i] = originalChar; // Restore character
                }
            }

            beginSet = std::move(nextLevel);
            step++;
        }

        return 0;
    }
};