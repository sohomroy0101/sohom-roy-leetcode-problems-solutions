# Leetcode Problem 43: Multiply Strings
# PYTHON CODE
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if num1 == "0" or num2 == "0":
            return "0"

        n, m = len(num1), len(num2)
        result = [0] * (n + m)

        for i in range(n - 1, -1, -1):
            for j in range(m - 1, -1, -1):
                mul = (ord(num1[i]) - ord('0')) * (ord(num2[j]) - ord('0'))
                total = mul + result[i + j + 1]

                result[i + j + 1] = total % 10
                result[i + j] += total // 10

        ans = []

        for digit in result:
            if not (len(ans) == 0 and digit == 0):
                ans.append(str(digit))

        return "".join(ans)