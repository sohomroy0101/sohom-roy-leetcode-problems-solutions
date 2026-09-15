# Leetcode Problem 126: Word Ladder II
# PYTHON CODE
from collections import defaultdict, deque
from typing import List


class Solution:

    def findLadders(
        self, beginWord: str, endWord: str, wordList: List[str]
    ) -> List[List[str]]:
        word_set = set(wordList)
        if endWord not in word_set:
            return []

        # Step 1: BFS to find shortest distance from beginWord to all reachable words
        dist = {beginWord: 0}
        queue = deque([beginWord])
        found = False

        while queue and not found:
            level_size = len(queue)
            for _ in range(level_size):
                curr = queue.popleft()
                curr_dist = dist[curr]

                # Try changing every character from 'a' to 'z'
                for i in range(len(curr)):
                    original_char = curr[i]
                    for c in "abcdefghijklmnopqrstuvwxyz":
                        if c == original_char:
                            continue
                        next_word = curr[:i] + c + curr[i+1:]

                        if next_word in word_set:
                            if next_word not in dist:
                                dist[next_word] = curr_dist + 1
                                queue.append(next_word)
                                if next_word == endWord:
                                    found = True

        if endWord not in dist:
            return []

        # Step 2: DFS Backtracking from endWord to beginWord using distance map
        results = []

        def dfs(curr_word: str, path: List[str]):
            if curr_word == beginWord:
                results.append(path[::-1])  # Reverse path to start from beginWord
                return

            curr_dist = dist[curr_word]
            for i in range(len(curr_word)):
                original_char = curr_word[i]
                for c in "abcdefghijklmnopqrstuvwxyz":
                    if c == original_char:
                        continue
                    prev_word = curr_word[:i] + c + curr_word[i+1:]

                    # Only move to valid words in dist that are at (curr_dist - 1)
                    if prev_word in dist and dist[prev_word] == curr_dist - 1:
                        path.append(prev_word)
                        dfs(prev_word, path)
                        path.pop()

        dfs(endWord, [endWord])
        return results