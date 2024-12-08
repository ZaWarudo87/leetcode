class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        for(int i = 1, len = nums.size(); i < len; i++){
            nums[i] = max(nums[i], nums[i - 1] + nums[i]);
            if(nums[i] > ans)
                ans = nums[i]; 
        }
        return ans;
    }
};
