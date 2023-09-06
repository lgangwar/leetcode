#include "includes.h"

class Twitter {
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        m_Tweets[userId].emplace_back(make_pair(m_Count++, tweetId));
    }
    
    vector<int> getNewsFeed(int userId) {
        //get users which this userid is following
        auto find = m_Followers.find(userId);
        unordered_set<int> users;
        if(find != m_Followers.end()){
            users = find->second;
        }
        users.insert(userId);


        priority_queue<pair<int, int> > pq;
        unordered_map<int, int> curr_idx;
        for(auto user : users){
            curr_idx[user] = m_Tweets[user].size() - 1;
        }

        for(int i = 0; i < 10; i++){
            for(auto user : users){
                if(curr_idx[user] < 0){
                    continue;
                }

                pq.push(m_Tweets[user][curr_idx[user]--]);
            }
        }

        vector<int> res;
        for(int i = 0; i < 10; i++){
            if(pq.empty()){
                break;
            }

            res.emplace_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        m_Followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        m_Followers[followerId].erase(followeeId);
    }
private:
    unordered_map<int, unordered_set<int> > m_Followers;
    unordered_map<int, vector<pair<int, int> > > m_Tweets;
    int m_Count {0};
};