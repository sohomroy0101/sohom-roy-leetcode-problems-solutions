# Leetcode Problem 68: Text Justification
# PYTHON CODE
class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        res = []
        i = 0
        n = len(words)

        while i < n:
            j = i
            line_len = 0

            while j < n and line_len + len(words[j]) + (j - i) <= maxWidth:
                line_len += len(words[j])
                j += 1

            gaps = j - i - 1
            line = ""

            # Last line or single word
            if j == n or gaps == 0:
                line = " ".join(words[i:j])
                line += " " * (maxWidth - len(line))
            else:
                total_spaces = maxWidth - line_len
                even_spaces = total_spaces // gaps
                extra_spaces = total_spaces % gaps

                for k in range(i, j - 1):
                    line += words[k]
                    line += " " * (even_spaces + (1 if k - i < extra_spaces else 0))
                line += words[j - 1]

            res.append(line)
            i = j

        return res