// Leetcode Problem 166: Fraction to Recurring Decimal
// C++ CODE
#include <string>
#include <unordered_map>
#include <cstdlib>

class Solution {
public:
    std::string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) {
            return "0";
        }
        
        std::string res = "";
        
        // Handle sign: negative if exactly one of them is negative
        if ((numerator < 0) ^ (denominator < 0)) {
            res += "-";
        }
        
        // Convert to long long to prevent overflow with INT_MIN
        long long num = std::abs(static_cast<long long>(numerator));
        long long den = std::abs(static_cast<long long>(denominator));
        
        // Integer part
        res += std::to_string(num / den);
        long long remainder = num % den;
        
        if (remainder == 0) {
            return res;
        }
        
        res += ".";
        
        // Map to store remainder -> index in res where its digit starts
        std::unordered_map<long long, int> rem_map;
        
        while (remainder != 0) {
            if (rem_map.find(remainder) != rem_map.end()) {
                res.insert(rem_map[remainder], "(");
                res += ")";
                break;
            }
            
            rem_map[remainder] = res.length();
            
            remainder *= 10;
            res += std::to_string(remainder / den);
            remainder %= den;
        }
        
        return res;
    }
};