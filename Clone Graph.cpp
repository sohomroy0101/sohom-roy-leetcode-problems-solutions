// Leetcode Problem 133: Clone Graph
// C++ CODE
#include <vector>
#include <unordered_map>

/*
// Definition for a Node.
class Node {
public:
    int val;
    std::vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = std::vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = std::vector<Node*>();
    }
    Node(int _val, std::vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    std::unordered_map<Node*, Node*> visited;

public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return nullptr;
        }

        // If the node has already been cloned, return its reference
        if (visited.count(node)) {
            return visited[node];
        }

        // Clone current node
        Node* clone = new Node(node->val);
        visited[node] = clone;

        // Recursively clone all adjacent neighbors
        for (Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(cloneGraph(neighbor));
        }

        return clone;
    }
};