# Leetcode Problem 133: Clone Graph
# PYTHON CODE
from typing import Optional


# Definition for a Node.
class Node:

    def __init__(self, val=0, neighbors=None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []


class Solution:

    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if not node:
            return None

        visited = {}

        def dfs(curr: 'Node') -> 'Node':
            # If the node has already been cloned, return its reference
            if curr in visited:
                return visited[curr]

            # Clone the current node (without neighbors initially)
            copy = Node(curr.val)
            visited[curr] = copy

            # Deep copy all neighbors recursively
            for neighbor in curr.neighbors:
                copy.neighbors.append(dfs(neighbor))

            return copy

        return dfs(node)