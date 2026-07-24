class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> ng;
        for (int n : nums2) {
            while (!st.empty() && n > st.top()) {
                ng[st.top()] = n;
                st.pop();
            }
            st.push(n);
        }
        while (!st.empty()) {
            ng[st.top()] = -1;
            st.pop();
        }
        vector<int> ans;
        for (int n : nums1)
            ans.push_back(ng[n]);
        return ans;
    }
};