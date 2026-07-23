class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> c;
        int n = position.size();
        for(int i=0;i<n;i++){
            double t = (double)(target-position[i]) / speed[i];
            c.push_back({position[i], t});
        }
        sort(c.begin(), c.end());
        stack<double> st;
        for(int i=n-1;i>=0;i--){
            double t = c[i].second;
            if(st.empty() || t > st.top()){
                st.push(t);
            }
        }
        return st.size();
    }
};