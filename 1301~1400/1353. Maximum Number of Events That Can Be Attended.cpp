class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int ans = 0, now = 1, i = 0, len = events.size();
        priority_queue<int, vector<int>, greater<int> > pq;
        sort(events.begin(), events.end());
        while(i < len || !pq.empty()){
            for(; i < len && events[i][0] == now; ++i)
                pq.push(events[i][1]);
            if(!pq.empty()){
                ++ans;
                pq.pop();
            }
            while(!pq.empty() && pq.top() <= now)
                pq.pop();
            ++now;
        }
        return ans;
    }
};
