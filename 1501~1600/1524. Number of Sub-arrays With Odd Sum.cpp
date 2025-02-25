class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int mod = 1000000007;
        int len = arr.size(), ans = 0;
        int dp[2] = {};
        for(int i = 0; i < len; ++i){
            dp[1] = (arr[i] % 2 ? (i - dp[0] + 1) % mod : dp[0]);
            ans = (ans + dp[1]) % mod;
            dp[0] = dp[1];
        }
        return ans;
    }
};
