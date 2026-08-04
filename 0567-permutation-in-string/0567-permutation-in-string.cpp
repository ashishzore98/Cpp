class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }
        vector<int> s1Count(26, 0);
        vector<int> windowCount(26, 0);
        for (char c : s1) {
            s1Count[c - 'a']++;
        }
        int left = 0;
        for (int right = 0; right < s2.length(); right++) {
            windowCount[s2[right] - 'a']++;
            if (right - left + 1 > s1.length()) {
                windowCount[s2[left] - 'a']--;
                left++;
            }
            if (windowCount == s1Count) {
                return true;
            }
        }
        return false;
    }
};