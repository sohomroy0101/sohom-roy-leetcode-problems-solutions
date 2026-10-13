// Leetcode Problem 155: Min Stack
// C++ code
#include <stack>

class MinStack {
private:
    std::stack<int> st;
    std::stack<int> min_st;

public:
    MinStack() {
        // Constructor is implicitly handled by std::stack
    }
    
    void push(int val) {
        st.push(val);
        // Push to min_st if it's smaller or equal to the current minimum
        if (min_st.empty() || val <= min_st.top()) {
            min_st.push(val);
        }
    }
    
    void pop() {
        if (!st.empty()) {
            // If the top element is the current minimum, pop it from min_st too
            if (st.top() == min_st.top()) {
                min_st.pop();
            }
            st.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_st.top();
    }
};