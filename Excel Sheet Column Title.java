// Leetcode Problem 168: Excel Sheet Column Title
// JAVA CODE
class Solution {
    public String convertToTitle(int columnNumber) {
        StringBuilder res = new StringBuilder();
        
        while (columnNumber > 0) {
            columnNumber -= 1; // Shift to 0-indexed (0 to 25)
            int remainder = columnNumber % 26;
            res.append((char) ('A' + remainder));
            columnNumber /= 26;
        }
        
        return res.reverse().toString();
    }
}