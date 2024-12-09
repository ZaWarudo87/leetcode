class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len < 2)
            return nums[0];
        int dp[100][2] = {{nums[0], 0}, {nums[1], nums[0]}};
        for(int i = 2; i < len; i++){
            dp[i][0] = max(dp[i - 2][0], dp[i - 2][1]) + nums[i];
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
        }
        return max(dp[len - 1][0], dp[len - 1][1]);
    }
};
