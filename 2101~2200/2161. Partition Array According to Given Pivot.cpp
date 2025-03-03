class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int len = nums.size(), idx = len - 1, tmp = 0, p = 0;
        vector<int> ans(len);
        for(int i = len - 1; i >= 0; --i){
            if(nums[i] == pivot)
                ++p;
            else
                ans[nums[i] > pivot ? idx-- : tmp++] = nums[i];
        }
        for(; p > 0; --p)
            ans[idx--] = pivot;
        reverse(ans.begin(), ans.begin() + tmp);
        return ans;
    }
};
