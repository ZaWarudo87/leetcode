class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        if(nums1.size() % 2)
            for(int &i : nums2)
                ans = ans ^ i;
        if(nums2.size() % 2)
            for(int &i : nums1)
                ans = ans ^ i;
        return ans;
    }
};
