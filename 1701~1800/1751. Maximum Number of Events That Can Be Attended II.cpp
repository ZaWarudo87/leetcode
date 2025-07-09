class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int len = events.size(), l, m, r, i, j;
        vector<vector<int> > dp(2, vector<int>(len + 1, 0));
        sort(events.begin(), events.end());

        vector<int> next(len);
        for(i = 0; i < len; ++i){
            l = 0; r = len;
            while(l < r){
                m = (l + r) / 2;
                if(events[m][0] <= events[i][1])
                    l = m + 1;
                else
                    r = m;
            }
            next[i] = l;
        }

        for(i = 1; i <= k; ++i)
            for(j = len - 1; j >= 0; --j)
                dp[i % 2][j] = max(dp[i % 2][j + 1], dp[(i + 1) % 2][next[j]] + events[j][2]);
        return dp[k % 2][0];
    }
};
