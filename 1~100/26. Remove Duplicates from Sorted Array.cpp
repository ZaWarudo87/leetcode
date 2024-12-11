class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size(), ans = 1;
        for(int i = 1; i < len; i++){
            if(nums[i] != nums[i - 1]){
                nums[ans++] = nums[i];
            }
        }
        return ans;
    }
};
