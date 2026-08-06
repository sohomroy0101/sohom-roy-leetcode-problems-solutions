// Leetcode Problem 85: Maximal Rectangle
// C++ CODE
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int maxArea = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }

            stack<int> st;

            for (int j = 0; j <= cols; j++) {
                int currHeight = (j == cols) ? 0 : heights[j];

                while (!st.empty() && heights[st.top()] > currHeight) {
                    int height = heights[st.top()];
                    st.pop();

                    int width = st.empty() ? j : j - st.top() - 1;
                    maxArea = max(maxArea, height * width);
                }

                st.push(j);
            }
        }

        return maxArea;
    }
};