class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int len = nums.size();
        if(len < 2) return len;
        int ans = 0, mode = (nums[1] < nums[0] ? 1 : (nums[1] > nums[0] ? 2 : 0)), temp = (mode ? 2 : 1), now;
        for(int i = 2; i < len; ++i){
            now = (nums[i] < nums[i - 1] ? 1 : (nums[i] > nums[i - 1] ? 2 : 0));
            if(!mode || mode != now){
                ans = max(ans, temp);
                mode = now;
                temp = (mode ? 2 : 1);
            }else
                ++temp;
        }
        ans = max(ans, temp);
        return ans;
    }
};
