// Leetcode Problem 134: Gas Station
// C++ CODE
#include <vector>
#include <numeric>

class Solution {
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
        int totalTank = 0;
        int currentTank = 0;
        int startingStation = 0;

        for (int i = 0; i < gas.size(); ++i) {
            int netGain = gas[i] - cost[i];
            totalTank += netGain;
            currentTank += netGain;

            // If fuel becomes negative, reset starting candidate to i + 1
            if (currentTank < 0) {
                startingStation = i + 1;
                currentTank = 0;
            }
        }

        // If overall gas is insufficient to cover total cost, complete circuit is impossible
        return (totalTank >= 0) ? startingStation : -1;
    }
};