// Leetcode Problem 65: Valid Number
// JAVA CODE
class Solution {
    public boolean isNumber(String s) {
        s = s.trim();
        return s.matches("[+-]?((\\d+(\\.\\d*)?)|(\\.\\d+))([eE][+-]?\\d+)?");
    }
}