# Leetcode Problem 146: LRU Cache
# PYTHON CODE
class Node:
    def __init__(self, key: int = 0, val: int = 0):
        self.key = key
        self.val = val
        self.prev = None
        self.next = None

class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cache = {}  # key -> Node
        
        # Dummy head and tail nodes to simplify edge cases during pointer manipulation
        self.head = Node()
        self.tail = Node()
        self.head.next = self.tail
        self.tail.prev = self.head

    def _remove(self, node: Node) -> None:
        """Removes an existing node from the doubly linked list."""
        prev_node = node.prev
        next_node = node.next
        prev_node.next = next_node
        next_node.prev = prev_node

    def _add_to_head(self, node: Node) -> None:
        """Inserts a node right after the dummy head (MRU position)."""
        node.next = self.head.next
        node.prev = self.head
        self.head.next.prev = node
        self.head.next = node

    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1
        
        node = self.cache[key]
        # Move node to head as it was recently accessed
        self._remove(node)
        self._add_to_head(node)
        return node.val

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            # Update value and move node to head
            node = self.cache[key]
            node.val = value
            self._remove(node)
            self._add_to_head(node)
        else:
            if len(self.cache) >= self.capacity:
                # Evict the least recently used node (before dummy tail)
                lru_node = self.tail.prev
                self._remove(lru_node)
                del self.cache[lru_node.key]
            
            # Add new node to head
            new_node = Node(key, value)
            self.cache[key] = new_node
            self._add_to_head(new_node)