# Leetcode Problem 134: Gas Station
# PYTHON CODE
from typing import List


class Solution:

    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        # If total gas is less than total cost, complete circuit is impossible
        if sum(gas) < sum(cost):
            return -1

        total_tank = 0
        current_tank = 0
        starting_station = 0

        for i in range(len(gas)):
            net_gain = gas[i] - cost[i]
            total_tank += net_gain
            current_tank += net_gain

            # If current tank falls below 0, reset starting position to i + 1
            if current_tank < 0:
                starting_station = i + 1
                current_tank = 0

        return starting_station