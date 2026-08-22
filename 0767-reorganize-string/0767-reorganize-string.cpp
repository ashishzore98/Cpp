class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        priority_queue<pair<int, char>> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                pq.push({freq[i], 'a' + i});
            }
        }
        string result;
        char prevChar = '#';
        int prevFreq = 0;
        while (!pq.empty()) {
            auto [currentFreq, currentChar] = pq.top();
            pq.pop();
            result += currentChar;
            currentFreq--;
            if (prevFreq > 0) {
                pq.push({prevFreq, prevChar});
            }
            prevChar = currentChar;
            prevFreq = currentFreq;
        }
        if (result.length() == s.length()) {
            return result;
        }
        return "";
    }
};