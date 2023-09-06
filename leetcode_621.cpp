#include "includes.h"

int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mapping;
        for(int i = 0; i < tasks.size(); i++){
            mapping[tasks[i]]++;
        }

        priority_queue<int> pq;
        queue<pair<int, int>> q;

        for(const auto v : mapping){
            pq.push(v.second);
        }

        int time = 0;
        while(!pq.empty()){
            auto val = pq.top();
            time++;
            pq.pop();

            if(--val > 0)
                q.push(make_pair(val, time + n));

            if(!q.empty() && time >= q.front().second){
                pq.push(q.front().first);
                q.pop();
            } else if(!q.empty() && pq.empty()){
                time = q.front().second;
                pq.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }