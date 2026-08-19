class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> f(26, 0);
        for (char t : tasks) {
            f[t - 'A']++;
        }
        int mf = 0;
        for (int c : f) {
            mf = max(mf, c);
        }
        int mft = 0;
        for (int c : f) {
            if (c == mf) {
                mft++;
            }
        }
        int i =
            (mf - 1) * (n + 1) + mft;
        return max((int)tasks.size(), i);
    }
};