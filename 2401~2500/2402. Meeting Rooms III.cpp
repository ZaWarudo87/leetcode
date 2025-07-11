class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int ans = 0, ansv = 0, ms[100] = {};
        priority_queue<int, vector<int>, greater<int> > pqempty; // id
        priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int>>> pqfull; // [release_time, id]
        pair<long long, int> tmp;
        sort(meetings.begin(), meetings.end());
        for(int i = 0; i < n; ++i)
            pqempty.push(i);
        for(vector<int> &i : meetings){
            while(!pqfull.empty() && pqfull.top().first <= i[0]){
                pqempty.push(pqfull.top().second);
                pqfull.pop();
            }
            if(pqempty.empty()){
                tmp = pqfull.top();
                pqfull.pop();
                tmp.first = i[1] + tmp.first - i[0];
            }else{
                tmp = pair<long long, int>(i[1], pqempty.top());
                pqempty.pop();
            }
            ++ms[tmp.second];
            if(ansv < ms[tmp.second] || ansv == ms[tmp.second] && tmp.second < ans){
                ans = tmp.second;
                ansv = ms[tmp.second];
            }
            pqfull.push(tmp);
        }
        return ans;
    }
};
