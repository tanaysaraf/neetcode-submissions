class Twitter {
public:
    using pii = pair<int, int>;

    map<int, vector<pii>> tweets;
    map<int, unordered_set<int>> followers;
    int time = 0;

    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        auto follow = followers[userId];
        follow.insert(userId);

        priority_queue<pii, vector<pii>, greater<pii>> pq;

        for (auto user : follow) {
            for (auto tweet : tweets[user]) {
                pq.push(tweet);

                if (pq.size() > 10) {
                    pq.pop();
                }
            }
        }

        vector<int> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};