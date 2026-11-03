// Leetcode Problem 179: Largest Number
// C++ CODE
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // Convert integers to strings
        vector<string> strNums;
        for (int num : nums) {
            strNums.push_back(to_string(num));
        }
        
        // Custom sort: compare concatenated combinations to find optimal ordering
        sort(strNums.begin(), strNums.end(), [](const string &a, const string &b) {
            return a + b > b + a;
        });
        
        // Edge case: if the highest value is "0", the entire number is 0
        if (strNums[0] == "0") {
            return "0";
        }
        
        // Build the final result
        string result = "";
        for (const string &s : strNums) {
            result += s;
        }
        
        return result;
    }
};