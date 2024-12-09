//TLE O(n^2)
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int ans = nums[0], temp, len = nums.size(), i, j;
        nums.insert(nums.end(), nums.begin(), nums.end());
        for(j = 0; j < len; j++){
            vector<int> sum(nums.begin() + j, nums.begin() + j + len);
            temp = sum[0];
            for(i = 1; i < len; i++){
                sum[i] = max(sum[i], sum[i - 1] + sum[i]);
                if(sum[i] > temp)
                    temp = sum[i];
            }
            if(temp > ans)
                ans = temp;
        }
        return ans;
    }
};
