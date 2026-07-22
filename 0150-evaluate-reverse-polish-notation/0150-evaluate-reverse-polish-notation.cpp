class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string t : tokens) {
            if (t == "+" || t == "-" ||
                t == "*" || t == "/") {
                int sec = st.top();
                st.pop();
                int fst = st.top();
                st.pop();
                if (t == "+")
                    st.push(fst + sec);
                else if (t == "-")
                    st.push(fst - sec);
                else if (t == "*")
                    st.push(fst * sec);
                else
                    st.push(fst / sec);
            }
            else {
                st.push(stoi(t));
            }
        }
        return st.top();
    }
};