class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int dp[200][201], len = triangle.size(), i, j, ans = 2000001;
        if(len <= 1) return triangle[0][0];
        fill(&dp[0][0], &dp[0][0] + 200 * 201, 10001);
        dp[0][1] = triangle[0][0];
        for(i = 1; i < len - 1; i++)
            for(j = 0; j <= i; j++)
                dp[i][j + 1] = min(dp[i - 1][j], dp[i - 1][j + 1]) + triangle[i][j];
        for(i = 0; i < len; i++){
            dp[len - 1][i + 1] = min(dp[len - 2][i], dp[len - 2][i + 1]) + triangle[len - 1][i];
            ans = min(ans, dp[len - 1][i + 1]);
        }
        return ans;
    }
};
