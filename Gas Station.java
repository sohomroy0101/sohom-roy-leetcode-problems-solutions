// Leetcode Problem 134: Gas Station
// JAVA CODE
class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int totalTank = 0;
        int currentTank = 0;
        int startingStation = 0;

        for (int i = 0; i < gas.length; i++) {
            int netGain = gas[i] - cost[i];
            totalTank += netGain;
            currentTank += netGain;

            // If tank drops below 0, reset starting station to the next index
            if (currentTank < 0) {
                startingStation = i + 1;
                currentTank = 0;
            }
        }

        // If overall net gain is non-negative, a valid route exists starting at startingStation
        return (totalTank >= 0) ? startingStation : -1;
    }
}