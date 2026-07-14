// Leetcode Problem 60: Permutation Sequence
// C++ CODE
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> numbers;
        vector<int> factorial(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            numbers.push_back(i);
            factorial[i] = factorial[i - 1] * i;
        }

        k--;
        string result = "";

        for (int i = n; i >= 1; i--) {
            int index = k / factorial[i - 1];
            result += to_string(numbers[index]);
            numbers.erase(numbers.begin() + index);
            k %= factorial[i - 1];
        }

        return result;
    }
};