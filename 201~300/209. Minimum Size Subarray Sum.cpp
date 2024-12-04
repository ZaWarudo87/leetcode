class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int st = 0, ed = 0, ans = nums.size(), now = nums[0];
        int sz = ans;
        for(ed = 1; ed < sz; ed++){
            if(now >= target){
                while(now >= target)
                    now -= nums[st++];
                ans = min(ans, ed - st + 1);
            }
            now += nums[ed];
        }
        if(now >= target){
            while(now >= target)
                now -= nums[st++];
            ans = min(ans, ed - st + 1);
        }else if(ans >= sz)
            ans = 0;
        return ans;
    }
};
