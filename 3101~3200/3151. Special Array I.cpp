class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        bool status = nums[0] % 2;
        for(int i = 1, len = nums.size(); i < len; ++i){
            if(nums[i] % 2 == status)
                return false;
            else
                status = !status;
        }
        return true;
    }
};
