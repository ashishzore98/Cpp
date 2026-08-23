class Solution {
private:
    vector<vector<int>> r;
    vector<int> c;
    void backtrack(vector<int>& candidates, int start, int remaining) {
        if (remaining == 0) {
            r.push_back(c);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > remaining) {
                break;
            }
            c.push_back(candidates[i]);
            backtrack(candidates, i, remaining - candidates[i]);
            c.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, 0, target);
        return r;
    }
};