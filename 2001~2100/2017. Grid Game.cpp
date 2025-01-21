class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        if(n < 2) return 0;
        long long a = 0, b = 0, ans;
        for(int i = 1; i < n; ++i)
            a += grid[0][i];
        ans = a;
        for(int i = 1; i < n; ++i){
            a -= grid[0][i];
            b += grid[1][i - 1];
            ans = min(ans, max(a, b));
        }
        return ans;
    }
};
