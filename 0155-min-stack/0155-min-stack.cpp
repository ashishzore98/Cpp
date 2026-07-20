class MinStack {
public:
    stack<int> st;
    stack<int> ms;
    MinStack() {
    }
    void push(int v) {
        st.push(v);
        if (ms.empty())
            ms.push(v);
        else
            ms.push(min(v, ms.top()));
    }
    void pop() {
        st.pop();
        ms.pop();
    }
    int top() {
        return st.top();
    }
    int getMin() {
        return ms.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */