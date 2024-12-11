class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int ans = 0, len = nums.size(), temp;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < len; i++){
            temp = upper_bound(nums.begin(), nums.end(), nums[i] + 2 * k) - nums.begin() - i;
            ans = max(ans, temp);
        }
        return ans;
    }
};
