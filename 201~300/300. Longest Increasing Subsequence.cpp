class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int lis[2500] = {nums[0]}, len = nums.size(), ans = 1;
        for(int i = 1; i < len; i++){
            if(nums[i] > lis[ans - 1])
                lis[ans++] = nums[i];
            else
                *lower_bound(lis, lis + ans, nums[i]) = nums[i];
        }
        return ans;
    }
};
