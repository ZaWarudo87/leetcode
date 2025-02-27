class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int dp[1000][1000] = {}, table[1000][1000] = {}, len = arr.size(), i, j, k, ans = 0;
        memset(table, -1, 1000 * 1000 * sizeof(int));
        for(i = 2; i < len; ++i){
            j = 0;
            k = i - 1;
            while(j < k){
                if(arr[j] + arr[k] == arr[i])
                    table[k][i] = j;
                if(arr[j] + arr[k] > arr[i])
                    --k;
                else
                    ++j;
            }
        }

        for(i = 1; i < len; ++i){
            for(j = i - 1; j >= 0; --j){
                dp[j][i] = 2;
                if(table[j][i] != -1)
                    dp[j][i] += dp[table[j][i]][j] - 1;
                ans = max(ans, dp[j][i]);
            }
        }
        return (ans < 3 ? 0 : ans);
    }
};
