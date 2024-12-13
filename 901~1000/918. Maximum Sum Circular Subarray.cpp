class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        int totalSum = 0, maxSum = nums[0], minSum = nums[0], currentMax = 0, currentMin = 0;
        for(int i = 0; i < n; i++){
            totalSum += nums[i];
            currentMax = max(nums[i], currentMax + nums[i]);
            maxSum = max(maxSum, currentMax);
            currentMin = min(nums[i], currentMin + nums[i]);
            minSum = min(minSum, currentMin);
        }
      
        if(totalSum == minSum) return maxSum;
        return max(maxSum, totalSum - minSum);
    }
};
