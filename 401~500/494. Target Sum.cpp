class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        map<int, int> num[2];
        num[0][nums[0]]++;
        num[0][-nums[0]]++;
        for(int i = 1, len = nums.size(); i < len; i++){
            for(auto j : num[0]){
                num[1][j.first + nums[i]] += j.second;
                num[1][j.first - nums[i]] += j.second;
            }
            num[0] = num[1];
            num[1].clear();
        }
        return num[0][target];
    }
};
