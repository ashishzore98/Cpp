class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> maxHeap;
        for (auto& point : points) {
            int x = point[0];
            int y = point[1];
            int dist = x * x + y * y;
            maxHeap.push({dist, {x, y}});
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
        vector<vector<int>> ans;
        while (!maxHeap.empty()) {
            ans.push_back({
                maxHeap.top().second.first,
                maxHeap.top().second.second
            });
            maxHeap.pop();
        }
        return ans;
    }
};