class Solution {
public:
    int maximumCount(vector<int>& nums) {
        vector<int>::iterator zero = lower_bound(nums.begin(), nums.end(), 0);
        int left = zero - nums.begin();
        while(zero != nums.end() && *zero == 0) ++zero;
        int right = nums.size() - (zero - nums.begin());
        return max(left, right);
    }
};
