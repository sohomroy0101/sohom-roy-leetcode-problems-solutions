# Leetcode Problem 93: Restore IP Addresses
# PYTHON CODE
class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        result = []

        def backtrack(start, parts):
            # If 4 parts are formed
            if len(parts) == 4:
                if start == len(s):
                    result.append(".".join(parts))
                return

            # Remaining characters must be enough for the remaining parts
            remaining = len(s) - start
            parts_left = 4 - len(parts)

            if remaining < parts_left or remaining > 3 * parts_left:
                return

            for length in range(1, 4):
                if start + length > len(s):
                    break

                part = s[start:start + length]

                # Leading zero is not allowed
                if len(part) > 1 and part[0] == '0':
                    break

                # Value must be between 0 and 255
                if int(part) > 255:
                    continue

                parts.append(part)
                backtrack(start + length, parts)
                parts.pop()

        backtrack(0, [])

        return result