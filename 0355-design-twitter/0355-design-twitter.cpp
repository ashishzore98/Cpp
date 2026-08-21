class Twitter {
private:
    struct Tweet {
        int time;
        int tweetId;
        int userId;
        int index;
        bool operator<(const Tweet& other) const {
            return time < other.time;
        }
    };
    int timestamp = 0;
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int, int>>> tweets;
public:
    Twitter() {
    }
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }
    vector<int> getNewsFeed(int userId) {
        priority_queue<Tweet> pq;
        vector<int> users;
        users.push_back(userId);
        for (int followee : following[userId]) {
            users.push_back(followee);
        }
        for (int user : users) {
            if (!tweets[user].empty()) {
                int index = tweets[user].size() - 1;
                pq.push({
                    tweets[user][index].first,
                    tweets[user][index].second,
                    user,
                    index
                });
            }
        }
        vector<int> result;
        while (!pq.empty() && result.size() < 10) {
            Tweet current = pq.top();
            pq.pop();
            result.push_back(current.tweetId);
            if (current.index > 0) {
                int nextIndex = current.index - 1;
                pq.push({
                    tweets[current.userId][nextIndex].first,
                    tweets[current.userId][nextIndex].second,
                    current.userId,
                    nextIndex
                });
            }
        }
        return result;
    }
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) {
            return;
        }
        following[followerId].insert(followeeId);
    }
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */