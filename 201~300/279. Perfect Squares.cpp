class Solution {
public:
    int numSquares(int n) {
        int dp[10001] = {0, 1};
        set<int> sq;
        for(int i = 1; i <= 100; ++i)
            sq.insert(i * i);
        set<int>::iterator st = sq.begin();
        
        for(int i = 2; i <= n; ++i){
            ++st;
            if(st == sq.end() || *st > i) --st;
            if(*st == i)
                dp[i] = 1;
            else{
                dp[i] = 10001;
                for(auto j = st; j != sq.begin(); j--)
                    dp[i] = min(dp[i], dp[i - *j] + 1);
                dp[i] = min(dp[i], dp[i - *sq.begin()] + 1);
            }
        }
        return dp[n];
    }
};
