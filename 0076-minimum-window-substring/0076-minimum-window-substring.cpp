class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> n;
        unordered_map<char, int> w;
        for (char c : t) {
            n[c]++;
        }
        int required = n.size();
        int f = 0;
        int l = 0;
        int r = 0;
        int ml = INT_MAX;
        int ms = 0;
        while (r < s.length()) {
            char c = s[r];
            w[c]++;
            if (n.count(c) && w[c] == n[c]) {
                f++;
            }
            while (l <= r && f == required) {
                int cl = r - l + 1;
                if (cl < ml) {
                    ml = cl;
                    ms = l;
                }
                char lc = s[l];
                w[lc]--;
                if (n.count(lc) &&
                    w[lc] < n[lc]) {
                    f--;
                }
                l++;
            }
            r++;
        }
        if (ml == INT_MAX) {
            return "";
        }
        return s.substr(ms, ml);
    }
};