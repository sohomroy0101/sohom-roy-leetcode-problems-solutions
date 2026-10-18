// Leetcode Problem 165: Compare Version Numbers
// C++ CODE
#include <string>
#include <sstream>

class Solution {
public:
    int compareVersion(std::string version1, std::string version2) {
        std::stringstream ss1(version1);
        std::stringstream ss2(version2);
        
        std::string segment1, segment2;
        
        while (true) {
            bool has1 = static_cast<bool>(std::getline(ss1, segment1, '.'));
            bool has2 = static_cast<bool>(std::getline(ss2, segment2, '.'));
            
            // If both streams are exhausted, versions are identical
            if (!has1 && !has2) {
                break;
            }
            
            int rev1 = has1 ? std::stoi(segment1) : 0;
            int rev2 = has2 ? std::stoi(segment2) : 0;
            
            if (rev1 < rev2) {
                return -1;
            } else if (rev1 > rev2) {
                return 1;
            }
        }
        
        return 0;
    }
};