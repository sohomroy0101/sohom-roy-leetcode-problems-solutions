// Leetcode Problem 166: Fraction to Recurring Decimal
// JAVA CODE
import java.util.HashMap;
import java.util.Map;

class Solution {
    public String fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) {
            return "0";
        }
        
        StringBuilder res = new StringBuilder();
        
        // Handle sign: negative if exactly one of them is negative
        if ((numerator < 0) ^ (denominator < 0)) {
            res.append("-");
        }
        
        // Convert to long to prevent overflow with Integer.MIN_VALUE
        long num = Math.abs((long) numerator);
        long den = Math.abs((long) denominator);
        
        // Integer part
        res.append(num / den);
        long remainder = num % den;
        
        if (remainder == 0) {
            return res.toString();
        }
        
        res.append(".");
        
        // Map to store remainder -> index in res where its digit starts
        Map<Long, Integer> remMap = new HashMap<>();
        
        while (remainder != 0) {
            if (remMap.containsKey(remainder)) {
                res.insert(remMap.get(remainder), "(");
                res.append(")");
                break;
            }
            
            remMap.put(remainder, res.length());
            
            remainder *= 10;
            res.append(remainder / den);
            remainder %= den;
        }
        
        return res.toString();
    }
}