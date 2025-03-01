class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        short n = 0, i = 1, len = nums.size();
        vector<int> ans(len);
        for(; i < len; ++i)
            if(nums[i - 1] != 0)
                ans[n++] = (nums[i - 1] == nums[i] ? nums[i++] * 2 : nums[i - 1]);
        if(i == len)
            ans[n++] = nums[i - 1];
        return ans;
    }
};
