// Leetcode Problem 146: LRU Cache
// C++ CODE
#include <unordered_map>
#include <list>
#include <utility>

class LRUCache {
private:
    int capacity;
    // Stores pair of {key, value} to easily delete key from map during eviction
    std::list<std::pair<int, int>> dll; 
    // Maps key -> iterator pointing to the element in dll
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> map;

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        auto it = map.find(key);
        if (it == map.end()) {
            return -1;
        }

        // Move the accessed element to the front of the list (MRU)
        dll.splice(dll.begin(), dll, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = map.find(key);
        if (it != map.end()) {
            // Update value and move node to front
            it->second->second = value;
            dll.splice(dll.begin(), dll, it->second);
        } else {
            if (map.size() >= capacity) {
                // Evict LRU element from back of list and map
                int lruKey = dll.back().first;
                map.erase(lruKey);
                dll.pop_back();
            }

            // Insert new key-value pair at front
            dll.push_front({key, value});
            map[key] = dll.begin();
        }
    }
};