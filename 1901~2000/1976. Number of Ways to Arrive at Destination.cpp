class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<vector<pair<int, int>>> mapu(n);
        for(vector<int> &i : roads){
            mapu[i[0]].push_back(make_pair(i[2], i[1]));
            mapu[i[1]].push_back(make_pair(i[2], i[0]));
        }

        int ans = 0;
        vector<long long> visit(n, LLONG_MAX);
        vector<int> path(n);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, std::greater<pair<long long, int>>> pq;
        pair<int, int> now;
        pq.push(make_pair(0, 0));
        visit[0] = 0;
        path[0] = 1;
        while(!pq.empty() && pq.top().first <= visit[n - 1]){
            now = pq.top();
            pq.pop();
            if(visit[now.second] >= now.first){
                for(pair<int, int> &i : mapu[now.second]){
                    long long w = visit[now.second] + (long long)i.first;
                    if(visit[i.second] > w){
                        visit[i.second] = w;
                        path[i.second] = path[now.second];
                        pq.push(make_pair(w, i.second));
                    }else if(visit[i.second] == w)
                        path[i.second] = (path[i.second] + path[now.second]) % MOD;
                }
            }
        }
        return path[n - 1];
    }
};
