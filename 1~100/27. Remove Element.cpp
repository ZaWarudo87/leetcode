class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ans = 0;
        for(int i = 0, len = nums.size(); i < len; i++){
            if(nums[i] != val){
                nums[ans++] = nums[i];
            }
        }
        return ans;
    }
};
