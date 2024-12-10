class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[10001] = {0}, i, j, mi, len = coins.size();
        sort(coins.begin(), coins.end());
        memset(dp + 1, -1, sizeof(int) * min(amount, coins[0] - 1));
        for(i = coins[0]; i <= amount; i++){
            mi = 10001;
            for(j = 0; j < len && coins[j] <= i; j++)
                mi = min(mi, (dp[i - coins[j]] == -1 ? 10001 : dp[i - coins[j]] + 1));
            dp[i] = (mi == 10001 ? -1 : mi);
        }
        return dp[amount];
    }
};
