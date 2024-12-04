class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0, len = nums.size(); i < len; i++){
            for(int j = i+1; j < len; j++){
                if(nums[i] + nums[j] == target)
                    return {i, j};
            }
        }
        return {};
    }
};
