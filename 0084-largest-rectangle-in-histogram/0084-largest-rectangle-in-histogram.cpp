class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int ma = 0;
        for (int i = 0; i <= n; i++) {
            int ch = (i == n) ? 0 : heights[i];
            while (!st.empty() && ch < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();
                int w;
                if (st.empty())
                    w = i;
                else
                    w = i - st.top() - 1;
                ma = max(ma, h * w);
            }
            st.push(i);
        }
        return ma;
    }
};