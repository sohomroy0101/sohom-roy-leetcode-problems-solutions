# Leetcode Problem 127: Word Ladder
# PYTHON CODE
from typing import List


class Solution:

    def ladderLength(
        self, beginWord: str, endWord: str, wordList: List[str]
    ) -> int:
        word_set = set(wordList)
        if endWord not in word_set:
            return 0

        # Two sets representing current frontiers from both directions
        begin_set = {beginWord}
        end_set = {endWord}
        word_len = len(beginWord)
        length = 1

        while begin_set and end_set:
            # Always expand the smaller frontier to minimize search space
            if len(begin_set) > len(end_set):
                begin_set, end_set = end_set, begin_set

            next_level = set()

            for word in begin_set:
                for i in range(word_len):
                    original_char = word[i]
                    for c in "abcdefghijklmnopqrstuvwxyz":
                        if c == original_char:
                            continue

                        next_word = word[:i] + c + word[i + 1:]

                        # Connection found between the two frontiers
                        if next_word in end_set:
                            return length + 1

                        if next_word in word_set:
                            next_level.add(next_word)
                            word_set.remove(next_word)  # Mark as visited

            begin_set = next_level
            length += 1

        return 0