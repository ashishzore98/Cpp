class Solution {
public:
    pair<int, int> expand(string& s, int left, int right) {
        while (left >= 0 &&
               right < s.length() &&
               s[left] == s[right]) {
            left--;
            right++;
        }
        return {left + 1, right - left - 1};
    }
    string longestPalindrome(string s) {
        int start = 0;
        int maxLen = 1;
        for (int i = 0; i < s.length(); i++) {
            auto odd = expand(s, i, i);
            if (odd.second > maxLen) {
                start = odd.first;
                maxLen = odd.second;
            }
            auto even = expand(s, i, i + 1);
            if (even.second > maxLen) {
                start = even.first;
                maxLen = even.second;
            }
        }
        return s.substr(start, maxLen);
    }
};