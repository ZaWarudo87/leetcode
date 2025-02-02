class Solution {
public:
    bool check(vector<int>& nums) {
        bool skip = false;
        for(int i = 1, len = nums.size(); i <= len; ++i){
            if(nums[i % len] < nums[(i - 1) % len]){
                if(skip)
                    return false;
                else
                    skip = true;
            }
        }
        return true;
    }
};
