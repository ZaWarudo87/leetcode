class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int i, nlen = nums.size(), qlen = queries.size();
        vector<bool> ans(qlen);
        vector<int> dp(nlen);
        for(i = 1; i < nlen; i++)
            dp[i] = (nums[i] + nums[i - 1]) % 2 + dp[i - 1];

        for(i = 0; i < qlen; i++)
            ans[i] = dp[queries[i][1]] - dp[queries[i][0]] == queries[i][1] - queries[i][0];
        return ans;
    }
};
