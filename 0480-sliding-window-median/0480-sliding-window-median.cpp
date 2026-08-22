class Solution {
private:
    multiset<int> left;
    multiset<int> right;
    void balance() {
        while (left.size() > right.size() + 1) {
            auto it = prev(left.end());
            right.insert(*it);
            left.erase(it);
        }
        while (left.size() < right.size()) {
            auto it = right.begin();
            left.insert(*it);
            right.erase(it);
        }
    }
    void add(int num) {
        if (left.empty() || num <= *left.rbegin()) {
            left.insert(num);
        } else {
            right.insert(num);
        }
        balance();
    }
    void remove(int num) {
        auto it = left.find(num);
        if (it != left.end()) {
            left.erase(it);
        } else {
            it = right.find(num);

            if (it != right.end()) {
                right.erase(it);
            }
        }
        balance();
    }
    double getMedian() {
        if (left.size() > right.size()) {
            return *left.rbegin();
        }
        return ((double)*left.rbegin() + *right.begin()) / 2.0;
    }
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> result;
        for (int i = 0; i < k; i++) {
            add(nums[i]);
        }
        result.push_back(getMedian());
        for (int i = k; i < nums.size(); i++) {
            remove(nums[i - k]);
            add(nums[i]);
            result.push_back(getMedian());
        }
        return result;
    }
};